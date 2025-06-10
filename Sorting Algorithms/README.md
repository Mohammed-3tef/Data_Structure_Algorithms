# Sorting Algorithms

### 🔁 Adaptive Algorithm

An **adaptive algorithm** is one that takes advantage of existing order in the input data.

* **Definition**: An algorithm is **adaptive** if its performance improves when the input is partially sorted.
* **Example**: Insertion Sort is adaptive—it runs faster on nearly sorted data (close to O(n)).

---

### ⚖️ Stable Algorithm

A **stable algorithm** maintains the relative order of records with equal keys.

* **Definition**: An algorithm is **stable** if, for any two equal elements, the one that appears first in the input also appears first in the output.
* **Example**: Merge Sort is stable; Quick Sort (in its typical form) is not.

---

### 💾 In-place Algorithm

An **in-place algorithm** minimizes memory usage during execution.

* **Definition**: An algorithm is **in-place** if it uses only a constant amount (O(1)) of extra memory space.
* **Example**: Selection Sort is in-place; Merge Sort is not (unless modified).