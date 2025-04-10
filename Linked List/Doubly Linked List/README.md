# Doubly Linked List

## UML Diagram
```mermaid
classDiagram
    class doubleNode~T~ {
        + data : T
        + next : doubleNode~T~**
        + prev : doubleNode~T~**
        + doubleNode()
        + doubleNode(data : const T)
    }

    class DoublyLinkedList~T~ {
        - head : doubleNode~T~**
        - tail : doubleNode~T~**
        - size : int
        + DoublyLinkedList()
        + ~DoublyLinkedList()
        + isEmpty() bool
        + length() int
        + front() T
        + back() T
        + search(data : const T) bool
        + insert(data : const T) void
        + pop_back() void
        + erase(position : const int) void
        + clear() void
        + print() void
        + at(position : const int) T
        + operator = (other : const DoublyLinkedList~T~*) void
    }

    class CircularLinkedList~T~ {
        + CircularLinkedList()
        + insert(data : const T) void
        + print() void
    }

    doubleNode~T~ --> doubleNode~T~ : next
    doubleNode~T~ --> doubleNode~T~ : prev
    DoublyLinkedList~T~ --> doubleNode~T~ : uses
    CircularLinkedList~T~ --|> DoublyLinkedList~T~
```

## Contributing
We welcome contributions to improve this Doubly Linked List implementation. To contribute:
1. Fork the repository.
2. Create a new branch (git checkout -b feature-branch).
3. Commit your changes (git commit -am 'Add new feature').
4. Push to the branch (git push origin feature-branch).
5. Create a new pull request.