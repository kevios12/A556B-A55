#include "mif_reg.h"

#define DBUS_BAAW_COUNT 1
#define PBUS_BAAW_COUNT 16
#define BAAW_BIT_SHIFT 4

const u32 dbus_baaw_offset[DBUS_BAAW_COUNT][4] = {
	{BAAW0_D_WLBT_START, BAAW0_D_WLBT_END, BAAW0_D_WLBT_REMAP, BAAW0_D_WLBT_INIT_DONE},
};

const u32 dbus_baaw_value[DBUS_BAAW_COUNT][4] = {
	{WLBT_DBUS_BAAW_0_START, WLBT_DBUS_BAAW_0_END, 0 /* platform->mem_start */, WLBT_BAAW_ACCESS_CTRL},
};

const u32 pbus_baaw_offset[PBUS_BAAW_COUNT][4] = {
	{BAAW_C_WLBT_START_0, BAAW_C_WLBT_END_0, BAAW_C_WLBT_REMAP_0, BAAW_C_WLBT_INIT_DONE_0},
	{BAAW_C_WLBT_START_1, BAAW_C_WLBT_END_1, BAAW_C_WLBT_REMAP_1, BAAW_C_WLBT_INIT_DONE_1},
	{BAAW_C_WLBT_START_2, BAAW_C_WLBT_END_2, BAAW_C_WLBT_REMAP_2, BAAW_C_WLBT_INIT_DONE_2},
	{BAAW_C_WLBT_START_3, BAAW_C_WLBT_END_3, BAAW_C_WLBT_REMAP_3, BAAW_C_WLBT_INIT_DONE_3},
	{BAAW_C_WLBT_START_4, BAAW_C_WLBT_END_4, BAAW_C_WLBT_REMAP_4, BAAW_C_WLBT_INIT_DONE_4},
	{BAAW_C_WLBT_START_5, BAAW_C_WLBT_END_5, BAAW_C_WLBT_REMAP_5, BAAW_C_WLBT_INIT_DONE_5},
	{BAAW_C_WLBT_START_6, BAAW_C_WLBT_END_6, BAAW_C_WLBT_REMAP_6, BAAW_C_WLBT_INIT_DONE_6},
	{BAAW_C_WLBT_START_7, BAAW_C_WLBT_END_7, BAAW_C_WLBT_REMAP_7, BAAW_C_WLBT_INIT_DONE_7},
	{BAAW_C_WLBT_START_8, BAAW_C_WLBT_END_8, BAAW_C_WLBT_REMAP_8, BAAW_C_WLBT_INIT_DONE_8},
	{BAAW_C_WLBT_START_9, BAAW_C_WLBT_END_9, BAAW_C_WLBT_REMAP_9, BAAW_C_WLBT_INIT_DONE_9},
	{BAAW_C_WLBT_START_10, BAAW_C_WLBT_END_10, BAAW_C_WLBT_REMAP_10, BAAW_C_WLBT_INIT_DONE_10},
	{BAAW_C_WLBT_START_11, BAAW_C_WLBT_END_11, BAAW_C_WLBT_REMAP_11, BAAW_C_WLBT_INIT_DONE_11},
	{BAAW_C_WLBT_START_12, BAAW_C_WLBT_END_12, BAAW_C_WLBT_REMAP_12, BAAW_C_WLBT_INIT_DONE_12},
	{BAAW_C_WLBT_START_13, BAAW_C_WLBT_END_13, BAAW_C_WLBT_REMAP_13, BAAW_C_WLBT_INIT_DONE_13},
	{BAAW_C_WLBT_START_14, BAAW_C_WLBT_END_14, BAAW_C_WLBT_REMAP_14, BAAW_C_WLBT_INIT_DONE_14},
	{BAAW_C_WLBT_START_15, BAAW_C_WLBT_END_15, BAAW_C_WLBT_REMAP_15, BAAW_C_WLBT_INIT_DONE_15},
};

const u32 pbus_baaw_value[PBUS_BAAW_COUNT][4] = {
	{WLBT_CBUS_BAAW_0_START, WLBT_CBUS_BAAW_0_END, WLBT_CBUS_BAAW_0_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_1_START, WLBT_CBUS_BAAW_1_END, WLBT_CBUS_BAAW_1_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_2_START, WLBT_CBUS_BAAW_2_END, WLBT_CBUS_BAAW_2_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_3_START, WLBT_CBUS_BAAW_3_END, WLBT_CBUS_BAAW_3_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_4_START, WLBT_CBUS_BAAW_4_END, WLBT_CBUS_BAAW_4_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_5_START, WLBT_CBUS_BAAW_5_END, WLBT_CBUS_BAAW_5_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_6_START, WLBT_CBUS_BAAW_6_END, WLBT_CBUS_BAAW_6_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_7_START, WLBT_CBUS_BAAW_7_END, WLBT_CBUS_BAAW_7_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_8_START, WLBT_CBUS_BAAW_8_END, WLBT_CBUS_BAAW_8_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_9_START, WLBT_CBUS_BAAW_9_END, WLBT_CBUS_BAAW_9_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_10_START, WLBT_CBUS_BAAW_10_END, WLBT_CBUS_BAAW_10_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_11_START, WLBT_CBUS_BAAW_11_END, WLBT_CBUS_BAAW_11_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_12_START, WLBT_CBUS_BAAW_12_END, WLBT_CBUS_BAAW_12_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_13_START, WLBT_CBUS_BAAW_13_END, WLBT_CBUS_BAAW_13_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_14_START, WLBT_CBUS_BAAW_14_END, WLBT_CBUS_BAAW_14_VALUE, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_15_START, WLBT_CBUS_BAAW_15_END, WLBT_CBUS_BAAW_15_VALUE, WLBT_BAAW_ACCESS_CTRL},
};

