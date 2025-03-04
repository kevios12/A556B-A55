/*
 * Copyright (C) 2010 Samsung Electronics Co. Ltd.
 *	Jaswinder Singh <jassi.brar@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __SAMSUNG_DMA_H_
#define __SAMSUNG_DMA_H_

#include <linux/dmaengine.h>

struct dma_pl330_platdata {
	/*
	 * Number of valid peripherals connected to DMAC.
	 * This may be different from the value read from
	 * CR0, as the PL330 implementation might have 'holes'
	 * in the peri list or the peri could also be reached
	 * from another DMAC which the platform prefers.
	 */
	u8 nr_valid_peri;
	/* Array of valid peripherals */
	u8 *peri_id;
	/* Operational capabilities */
	dma_cap_mask_t cap_mask;
	/* Bytes to allocate for MC buffer */
	unsigned mcbuf_sz;
};

extern struct dma_async_tx_descriptor *__pl330_prep_dma_cyclic(
		struct dma_chan *chan, dma_addr_t dma_addr, size_t len,
		size_t period_len, enum dma_transfer_direction direction,
		unsigned long flags, void *context);
extern bool pl330_filter(struct dma_chan *chan, void *param);
extern int pl330_dma_getposition(struct dma_chan *chan,
		dma_addr_t *src, dma_addr_t *dst);
extern int pl330_dma_debug(struct dma_chan *chan);

/*
 * PL330 can assign any channel to communicate with
 * any of the peripherals attched to the DMAC.
 * For the sake of consistency across client drivers,
 * We keep the channel names unchanged and only add
 * missing peripherals are added.
 * Order is not important since DMA PL330 API driver
 * use these just as IDs.
 */
enum dma_ch {
	DMACH_MAX = 0,
};

struct s3c2410_dma_client {
	char	*name;
};

static inline bool samsung_dma_has_circular(void)
{
	return true;
}

static inline bool samsung_dma_is_dmadev(void)
{
	return true;
}

static inline bool samsung_dma_has_infiniteloop(void)
{
	return true;
}

struct samsung_dma_req {
	enum dma_transaction_type cap;
	struct s3c2410_dma_client *client;
};

struct samsung_dma_prep {
	enum dma_transaction_type cap;
	enum dma_transfer_direction direction;
	dma_addr_t buf;
	unsigned long period;
	unsigned long len;
	void (*fp)(void *data);
	void *fp_param;
	unsigned int infiniteloop;
};

struct samsung_dma_config {
	enum dma_transfer_direction direction;
	enum dma_slave_buswidth width;
	u32 maxburst;
	dma_addr_t fifo;
};

struct samsung_dma_ops {
	unsigned long(*request)(enum dma_ch ch, struct samsung_dma_req *param,
				struct device *dev, char *ch_name);
	int (*release)(unsigned long ch, void *param);
	int (*config)(unsigned long ch, struct samsung_dma_config *param);
	int (*prepare)(unsigned long ch, struct samsung_dma_prep *param, dma_cookie_t *cookie);
	int (*tx_status)(unsigned long ch, dma_cookie_t cookie, struct dma_tx_state *txstate);
	int (*trigger)(unsigned long ch);
	int (*started)(unsigned long ch);
	int (*getposition)(unsigned long ch, dma_addr_t *src, dma_addr_t *dst);
	int (*flush)(unsigned long ch);
	int (*stop)(unsigned long ch);
	int (*debug)(unsigned long ch);
};

/*
 * samsung_dma_get_ops
 * get the set of samsung dma operations
 */
#if defined(CONFIG_SAMSUNG_PDMA) || defined(CONFIG_SAMSUNG_PDMA_MODULE)
extern void *samsung_dmadev_get_ops(void);
extern void *s3c_dma_get_ops(void);

static inline void *samsung_dma_get_ops(void)
{
	if (samsung_dma_is_dmadev())
		return samsung_dmadev_get_ops();
	else
		return s3c_dma_get_ops();
}
#else
#define samsung_dma_get_ops() NULL
#endif

#endif	/* __SAMSUNG_DMA_H_ */

