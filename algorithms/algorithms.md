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

## Selection Sort Documentation

### Introduction

Selection Sort is a simple comparison-based sorting algorithm. It works by repeatedly finding the smallest element from the unsorted portion of the array and placing it at the beginning. With each pass, the sorted portion of the array grows until the entire array is sorted.

genui{"computing_fundamentals_algorithms_learning_block":{"type_id":"SELECTION_SORT"}}

### How It Works

1. Start from the first element of the array.
2. Assume the first unsorted element is the smallest.
3. Compare it with all the remaining elements in the unsorted portion of the array.
4. If a smaller element is found, update the position of the smallest element.
5. After scanning the unsorted portion, swap the smallest element with the first unsorted element.
6. Move the boundary of the sorted portion one position to the right and repeat the process until the entire array is sorted.

### Example

Given the array:

`[5, 3, 8, 4, 2]`

* **Pass 1:** Find the smallest element (2) and swap it with 5 → `[2, 3, 8, 4, 5]`
* **Pass 2:** Find the smallest element in the remaining array (3) → No swap needed → `[2, 3, 8, 4, 5]`
* **Pass 3:** Find the smallest element (4) and swap it with 8 → `[2, 3, 4, 8, 5]`
* **Pass 4:** Find the smallest element (5) and swap it with 8 → `[2, 3, 4, 5, 8]`

The array is now sorted in ascending order.

### Advantages

* Easy to understand and implement.
* Performs fewer swaps than Bubble Sort.
* Requires no additional memory (in-place sorting).

### Disadvantages

* Inefficient for large datasets due to its quadratic time complexity.
* Always performs the same number of comparisons, even if the array is already sorted.

### Time and Space Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | **O(n²)**       |
| Average Case | **O(n²)**       |
| Worst Case   | **O(n²)**       |

**Space Complexity:** **O(1)**

### Conclusion

Selection Sort is a straightforward sorting algorithm that repeatedly selects the smallest element from the unsorted portion of the array and places it in its correct position. It is simple to implement and requires only a small amount of memory. Although it is more efficient than Bubble Sort in terms of the number of swaps, its overall time complexity makes it unsuitable for sorting large datasets. It is mainly used for educational purposes and for sorting small collections of data.

## Insertion Sort Documentation

### Introduction

Insertion Sort is a simple comparison-based sorting algorithm that builds the sorted array one element at a time. It works by taking each element from the unsorted portion of the array and inserting it into its correct position in the sorted portion.

genui{"computing_fundamentals_algorithms_learning_block":{"type_id":"INSERTION_SORT"}}

### How It Works

1. Assume the first element is already sorted.
2. Select the next element from the unsorted portion of the array (called the **key**).
3. Compare the key with the elements in the sorted portion, starting from the end.
4. Shift all elements that are greater than the key one position to the right.
5. Insert the key into its correct position.
6. Repeat the process until all elements have been inserted into the sorted portion.

### Example

Given the array:

`[5, 3, 8, 4, 2]`

* **Pass 1:** Insert 3 before 5 → `[3, 5, 8, 4, 2]`
* **Pass 2:** Insert 8 → No change → `[3, 5, 8, 4, 2]`
* **Pass 3:** Insert 4 between 3 and 5 → `[3, 4, 5, 8, 2]`
* **Pass 4:** Insert 2 at the beginning → `[2, 3, 4, 5, 8]`

The array is now sorted in ascending order.

### Advantages

* Easy to understand and implement.
* Efficient for small datasets.
* Performs well on nearly sorted arrays.
* Requires no additional memory (in-place sorting).
* Stable sorting algorithm (preserves the relative order of equal elements).

### Disadvantages

* Inefficient for large datasets due to its quadratic time complexity.
* Requires many shifts when sorting a reverse-ordered array.

### Time and Space Complexity

| Case                        | Time Complexity |
| --------------------------- | --------------- |
| Best Case (already sorted)  | **O(n)**        |
| Average Case                | **O(n²)**       |
| Worst Case (reverse sorted) | **O(n²)**       |

**Space Complexity:** **O(1)**

### Conclusion

Insertion Sort is a simple and efficient algorithm for sorting small or nearly sorted datasets. It builds the sorted array one element at a time by inserting each new element into its correct position. Although it is not suitable for large datasets due to its quadratic time complexity, its simplicity, stability, and efficiency on nearly sorted data make it a useful algorithm for educational purposes and practical applications involving small collections of data.


## Merge Sort Documentation

### Introduction

Merge Sort is an efficient **divide-and-conquer** sorting algorithm. It works by repeatedly dividing the array into smaller subarrays until each subarray contains only one element. The subarrays are then merged back together in sorted order to produce the final sorted array.

### How It Works

1. Divide the array into two equal halves.
2. Recursively divide each half until every subarray contains only one element.
3. Compare the elements of the subarrays and merge them in sorted order.
4. Continue merging the sorted subarrays until the entire array is combined into one sorted array.

### Example

Given the array:

`[5, 3, 8, 4, 2]`

**Step 1: Divide**

* `[5, 3, 8, 4, 2]`
* `[5, 3]` and `[8, 4, 2]`
* `[5] [3]` and `[8] [4, 2]`
* `[4] [2]`

**Step 2: Merge**

* `[5]` and `[3]` → `[3, 5]`
* `[4]` and `[2]` → `[2, 4]`
* `[8]` and `[2, 4]` → `[2, 4, 8]`
* `[3, 5]` and `[2, 4, 8]` → `[2, 3, 4, 5, 8]`

The array is now sorted in ascending order.

### Advantages

* Very efficient for sorting large datasets.
* Has a guaranteed time complexity of **O(n log n)** in all cases.
* Stable sorting algorithm (preserves the relative order of equal elements).
* Well suited for linked lists and external sorting.

### Disadvantages

* Requires additional memory for the temporary arrays used during merging.
* More complex to implement than Bubble Sort, Selection Sort, or Insertion Sort.

### Time and Space Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | **O(n log n)**  |
| Average Case | **O(n log n)**  |
| Worst Case   | **O(n log n)**  |

**Space Complexity:** **O(n)**

### Conclusion

Merge Sort is a powerful and efficient sorting algorithm that uses the divide-and-conquer approach to sort data. It consistently performs in **O(n log n)** time regardless of the initial order of the elements, making it one of the best choices for sorting large datasets. Although it requires additional memory for merging, its stability and predictable performance make it widely used in real-world applications.


## Quick Sort Documentation

### Introduction

Quick Sort is a highly efficient **divide-and-conquer** sorting algorithm. It works by selecting a **pivot** element from the array and partitioning the remaining elements into two groups: those smaller than the pivot and those greater than the pivot. The same process is then applied recursively to each group until the entire array is sorted.

### How It Works

1. Select a pivot element from the array (commonly the first, last, middle, or a random element).
2. Rearrange the array so that:

   * Elements smaller than the pivot are placed to its left.
   * Elements greater than the pivot are placed to its right.
3. The pivot is now in its correct sorted position.
4. Recursively apply the same process to the left and right subarrays.
5. Continue until all subarrays contain one or zero elements.

### Example

Given the array:

`[5, 3, 8, 4, 2]`

* **Choose pivot:** 5
* **Partition:** `[3, 4, 2] 5 [8]`
* **Sort left subarray:** `[3, 4, 2]` → `[2, 3, 4]`
* **Sort right subarray:** `[8]` (already sorted)
* **Combine:** `[2, 3, 4, 5, 8]`

The array is now sorted in ascending order.

### Advantages

* Very fast and efficient for large datasets.
* Average time complexity is **O(n log n)**.
* Performs sorting in place, requiring very little extra memory.
* Widely used in practice due to its excellent average-case performance.

### Disadvantages

* Worst-case time complexity is **O(n²)** if poor pivot choices are made (such as always selecting the smallest or largest element in an already sorted array).
* Not a stable sorting algorithm (equal elements may change their relative order).
* Recursive implementation may lead to deep recursion for unfavorable input.

### Time and Space Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | **O(n log n)**  |
| Average Case | **O(n log n)**  |
| Worst Case   | **O(n²)**       |

**Space Complexity:**

* **O(log n)** (average, due to recursion)
* **O(n)** (worst case, due to recursion depth)

### Conclusion

Quick Sort is one of the fastest and most widely used sorting algorithms. It uses the divide-and-conquer technique by selecting a pivot, partitioning the array, and recursively sorting the resulting subarrays. Although its worst-case time complexity is **O(n²)**, careful pivot selection typically results in **O(n log n)** performance, making Quick Sort an excellent choice for sorting large datasets.
