## Introduction to data structures

A data structure is a way to store and organize data in a computer, 
so that it can be used efficiently.

we will talk about data structures as:

* Mathematical/Logical models or Abstract Data Type (ADT)
* Concrete Implementation

## List

### ADT

- Empty list has size 0
- Insert --- O(n) | Add --- O(n)
- Remove --- O(n)
- Count --- O(1)
- Read/Modify element at a position --- O(1)
- Specify data type

### Implementation

#### Array

If list is **full of array**, create a larger array of **double size of the previous array** and copy all the elements from the previous array into the new array, then free the memory for the previous array.

#### LinkedList

Get the address of the first node and treasure hunt.

#### Comparison

|                      |        Array        |                      LinkedList                       |
| :------------------: | :-----------------: | :---------------------------------------------------: |
|  Cost of accessing  |        O(1)         |                         O(n)                          |
| Memory requiremenets |     Fixed size      | No unused memory need memory for pointer var |
|  Cost of inserting  | O(n)/O(1);O(n)/O(n) |  O(1)/O(n)/O(n)(position at beginning, end, middle)   |
|Easy to use|Yes|No|

#### Doubly LinkedList

Linked list can be divided to two types: singly linked list and doubly linked list.

Advantages: Reverse look-up.

Disadvantages: Extra memory for pointer to previous node.

#### Circular LinkedList

------



## Stack(LIFO)

### ADT

A list with the restriction that insertion and deletion can be performed **only from one end**, called the top.

- Push --- O(1)
- Pop --- O(1)
- Top --- O(1)
- IsEmpty --- O(1)

### Implementation

#### Array

#### LinkedList