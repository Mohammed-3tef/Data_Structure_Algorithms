# Single Linked List

## UML Diagram
```mermaid
classDiagram
    class Node~T~ {
        + data : T
        + next : Node~T~**
        + Node()
        + Node(data : const T)
    }

    class unorderedLinkedList~T~ {
        - head : Node~T~**
        - size : int
        + unorderedLinkedList()
        + ~unorderedLinkedList()
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
        + operator = (other : const unorderedLinkedList<T>*) void
    }

    class OrderedLinkedList~T~ {
        + OrderedLinkedList()
        + ~OrderedLinkedList()
        + insert(data : const T) void
    }

    unorderedLinkedList~T~ --> Node~T~ : uses
    OrderedLinkedList~T~ --|> unorderedLinkedList~T~
```

## Contributing
We welcome contributions to improve this Single Linked List implementation. To contribute:
1. Fork the repository.
2. Create a new branch (git checkout -b feature-branch).
3. Commit your changes (git commit -am 'Add new feature').
4. Push to the branch (git push origin feature-branch).
5. Create a new pull request.