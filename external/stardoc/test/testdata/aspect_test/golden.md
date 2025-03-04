<!-- Generated with Stardoc: http://skydoc.bazel.build -->

The input file for the aspect test

<a id="my_aspect_impl"></a>

## my_aspect_impl

<pre>
my_aspect_impl(<a href="#my_aspect_impl-ctx">ctx</a>)
</pre>



**PARAMETERS**


| Name  | Description | Default Value |
| :------------- | :------------- | :------------- |
| <a id="my_aspect_impl-ctx"></a>ctx |  <p align="center"> - </p>   |  none |


<a id="my_aspect"></a>

## my_aspect

<pre>
my_aspect(<a href="#my_aspect-name">name</a>, <a href="#my_aspect-first">first</a>, <a href="#my_aspect-second">second</a>)
</pre>

This is my aspect. It does stuff.

**ASPECT ATTRIBUTES**


| Name | Type |
| :------------- | :------------- |
| deps| String |
| attr_aspect| String |


**ATTRIBUTES**


| Name  | Description | Type | Mandatory | Default |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| <a id="my_aspect-name"></a>name |  A unique name for this target.   | <a href="https://bazel.build/concepts/labels#target-names">Name</a> | required |   |
| <a id="my_aspect-first"></a>first |  -   | <a href="https://bazel.build/concepts/labels">Label</a> | required |   |
| <a id="my_aspect-second"></a>second |  -   | <a href="https://bazel.build/rules/lib/dict">Dictionary: String -> String</a> | required |   |


<a id="other_aspect"></a>

## other_aspect

<pre>
other_aspect(<a href="#other_aspect-name">name</a>, <a href="#other_aspect-third">third</a>)
</pre>

This is another aspect.

**ASPECT ATTRIBUTES**


| Name | Type |
| :------------- | :------------- |
| *| String |


**ATTRIBUTES**


| Name  | Description | Type | Mandatory | Default |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| <a id="other_aspect-name"></a>name |  A unique name for this target.   | <a href="https://bazel.build/concepts/labels#target-names">Name</a> | required |   |
| <a id="other_aspect-third"></a>third |  -   | Integer | required |   |


