# AVL Tree

## Features
- **Insert**: Add elements to the AVL.
- **Erase**: Remove nodes from the AVL.
- **Search**: Check if an element exists in the AVL.
- **Traversal**: Supports in-order, pre-order, post-order, and breadth-first traversals.
- **Find Min/Max**: Find the smallest and largest elements in the AVL.
- **Height Calculation**: Calculate the height of the tree.
- **Counting Nodes and Leaves**: Count the number of nodes and leaves in the tree.
- **Sum of Elements**: Calculate the sum of all elements in the AVL.

## UML Diagram
```mermaid
    classDiagram
        class AVLNode {
        - data : T
        - left : AVLNode~T~**
        - right : AVLNode~T~**
        - height : int
        + AVLNode()
        + AVLNode(T, AVLNode<T>*, AVLNode<T>*, int)
        + getLeft() AVLNode~T~**
        + setLeft(AVLNode<T>*) void
        + getRight() AVLNode~T~**
        + setRight(AVLNode<T>*) void
        + getData() T
        + setData(const T&) void
        + getHeight() int
        + setHeight(const int&) void
    }
    
    class AVL {
        - root : AVLNode~T~**
        + AVL()
        + ~AVL()
        + clear() void
        + empty() bool
        + level() int
        + countNodes() int
        + countLeaves() int
        + countInternalNodes() int
        + minElement() T
        + maxElement() T
        + findSum() T
        + search(const T&) bool
        + insert(const T&) void
        + erase(const T&) void
        + printBreadthFirst() void
        + printDepthFirst(const string&) void
        
        - findHeight(AVLNode<T>*) int
        - balanceFactor(AVLNode<T>*) int
        - updateHeight(AVLNode<T>*) void
        - inOrder(AVLNode<T>*) void
        - inOrder(AVLNode<T>*, const string&, T&) void
        - preOrder(AVLNode<T>*) void
        - postOrder(AVLNode<T>*) void
        - rotateRight(AVLNode<T>*) AVLNode~T~**
        - rotateLeft(AVLNode<T>*) AVLNode~T~**
        - updateBalance(AVLNode<T>*) AVLNode~T~**
        - insertNode(AVLNode<T>*, const T&) AVLNode~T~**
        - eraseNode(AVLNode<T>*, const T&) AVLNode~T~**
        - findMin(AVLNode<T>*) AVLNode~T~**
        - findMax(AVLNode<T>*) AVLNode~T~**
        - destroyTree(AVLNode<T>*) void
    }
    
    AVL o-- AVLNode : uses
```

## Contributing
We welcome contributions to improve this AVL Tree implementation. To contribute:
1. Fork the repository.
2. Create a new branch (git checkout -b feature-branch).
3. Commit your changes (git commit -am 'Add new feature').
4. Push to the branch (git push origin feature-branch).
5. Create a new pull request.