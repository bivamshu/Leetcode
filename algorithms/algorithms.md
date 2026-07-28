## Bubble Sort Documentation

### Introduction

Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly compares two adjacent elements in an array and swaps them if they are in the wrong order. This process continues until the entire array is sorted.

### How It Works

1. Start from the first element of the array.
2. Compare the current element with the next element.
3. If the current element is greater than the next element, swap them.
4. Continue comparing and swapping adjacent elements until the end of the array is reached. After the first pass, the largest element will be in its correct position.
5. Repeat the process for the remaining unsorted portion of the array, ignoring the last sorted elements.
6. Continue until no more swaps are needed or all passes have been completed.

### Example

Given the array:

`[5, 3, 8, 4, 2]`

* **Pass 1:** `[3, 5, 4, 2, 8]`
* **Pass 2:** `[3, 4, 2, 5, 8]`
* **Pass 3:** `[3, 2, 4, 5, 8]`
* **Pass 4:** `[2, 3, 4, 5, 8]`

The array is now sorted in ascending order.

### Advantages

* Easy to understand and implement.
* Requires no additional memory (in-place sorting).
* Works well for small datasets or nearly sorted arrays.

### Disadvantages

* Inefficient for large datasets due to its high time complexity.
* Performs many unnecessary comparisons and swaps compared to more efficient algorithms like Merge Sort or Quick Sort.

### Time and Space Complexity

| Case                                  | Time Complexity |
| ------------------------------------- | --------------- |
| Best Case (already sorted, optimized) | **O(n)**        |
| Average Case                          | **O(n²)**       |
| Worst Case                            | **O(n²)**       |

**Space Complexity:** **O(1)**

### Conclusion

Bubble Sort is one of the simplest sorting algorithms and is commonly used for educational purposes to demonstrate the concept of sorting through repeated comparisons and swaps. Although it is not suitable for large datasets because of its quadratic time complexity, it is useful for learning basic algorithm design and for sorting small collections of data.


