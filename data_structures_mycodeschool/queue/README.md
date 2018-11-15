## Queue(FIFO)

### ADT

A list or collection with the restriction that **insertion can be performed at one end (rear)**, and deletion **can be performed at other end (front)**.

- Enqueue --- O(1)
- Dequeue --- O(1)
- Front --- O(1)
- IsEmpty --- O(1)

### Implementation

#### Array

- circular array
- front and rear (tail)

#### LinkedList

tail pointer to the last node


### Application

- Printer queue
- Process scheduling
- simulating wait
