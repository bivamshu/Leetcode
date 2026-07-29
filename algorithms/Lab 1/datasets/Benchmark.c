/* ============================================================
   Benchmark.c
   Self-contained benchmark: all six sorting algorithms are
   implemented directly in this file (no linking against your
   separate BubbleSort.c / selectionSort.c / etc., since those
   each have their own main()/printArray() and would collide
   at link time).

   Runs BubbleSort, SelectionSort, InsertionSort, MergeSort,
   QuickSort and HeapSort against the Master and fineGrained
   datasets, in best/average/worst case, and writes timing
   results to results.csv for plotting.

   Expected to live at:  Lab 1/datasets/Benchmark.c
   Datasets expected at: Lab 1/datasets/Master/<case>/sample_<n>.txt
                          Lab 1/datasets/fineGrained/<case>/fine_<n>.txt

   Compile (from the "Lab 1" folder):
     gcc datasets/Benchmark.c -O2 -o datasets/Benchmark

   Run (from "Lab 1" so relative dataset paths resolve):
     ./datasets/Benchmark
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define AVERAGE_TRIALS 5

/* ============================================================
   Sorting algorithms
   ============================================================ */

/* Bubble Sort */
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Selection Sort */
void selectioSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* Merge Sort */
static void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* Quick Sort */
static void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int *nums, int low, int high) {
    int random_index = low + rand() % (high - low + 1);
    swapInts(&nums[random_index], &nums[high]);

    int pivot = nums[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swapInts(&nums[i], &nums[j]);
        }
    }
    swapInts(&nums[i + 1], &nums[high]);
    return i + 1;
}

void quickSort(int *nums, int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high);
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

/* Heap Sort */
static void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;

    /* NOTE: build-heap loop goes down to i >= 0 (not i > 0) so that
       index 0 is heapified too - an i > 0 version skips it and
       produces an incorrectly sorted array. */
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

/* ============================================================
   Uniform wrapper signatures
   mergeSort/quickSort take low/high bounds instead of a count,
   so each gets a thin wrapper matching void f(int arr[], int n).
   ============================================================ */

static void wrap_bubble(int arr[], int n)    { bubbleSort(arr, n); }
static void wrap_selection(int arr[], int n) { selectioSort(arr, n); }
static void wrap_insertion(int arr[], int n) { insertionSort(arr, n); }
static void wrap_merge(int arr[], int n)     { if (n > 0) mergeSort(arr, 0, n - 1); }
static void wrap_quick(int arr[], int n)     { if (n > 0) quickSort(arr, 0, n - 1); }
static void wrap_heap(int arr[], int n)      { heapSort(arr, n); }

typedef void (*SortFn)(int[], int);

typedef struct {
    const char *name;
    SortFn fn;
} Algorithm;

static Algorithm ALGORITHMS[] = {
    { "BubbleSort",    wrap_bubble },
    { "SelectionSort", wrap_selection },
    { "InsertionSort", wrap_insertion },
    { "MergeSort",     wrap_merge },
    { "QuickSort",     wrap_quick },
    { "HeapSort",      wrap_heap },
};
#define NUM_ALGORITHMS (int)(sizeof(ALGORITHMS) / sizeof(ALGORITHMS[0]))

static const char *CASES[] = { "best", "average", "worst" };
#define NUM_CASES 3

typedef struct {
    const char *folder;   /* e.g. "Master" or "fineGrained" */
    const char *prefix;   /* e.g. "sample_" or "fine_" */
    int sizes[16];
    int numSizes;
} DatasetGroup;

/* ---------- I/O helpers ---------- */

static int *readDataset(const char *filename, int n) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "  [!] Could not open %s - skipping\n", filename);
        return NULL;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "  [!] malloc failed for %s\n", filename);
        fclose(fp);
        return NULL;
    }

    int readCount = 0;
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) break;
        readCount++;
    }
    fclose(fp);

    if (readCount != n) {
        fprintf(stderr, "  [!] %s: expected %d ints, found %d\n", filename, n, readCount);
        free(arr);
        return NULL;
    }
    return arr;
}

static void copyArray(const int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) destination[i] = source[i];
}

/* Fisher-Yates: used only to produce 5 independent shuffled copies
   of the average-case list for trial averaging. */
static void shuffleArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

static int isSorted(const int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) return 0;
    }
    return 1;
}

/* ---------- timing ---------- */

/* Times a single sort call in milliseconds. Sorts a scratch copy
   so the caller's buffer is left untouched if it needs reuse,
   and checks correctness so a buggy implementation is caught
   instead of silently producing bogus timing data. */
static double timeOneRun(SortFn fn, const char *algoName, const int base[], int n) {
    int *work = malloc(n * sizeof(int));
    copyArray(base, work, n);

    clock_t start = clock();
    fn(work, n);
    clock_t end = clock();

    if (!isSorted(work, n)) {
        fprintf(stderr, "  [!] WARNING: %s did not produce a sorted array (n=%d) - "
                         "timing recorded anyway, but check the implementation\n", algoName, n);
    }

    free(work);
    return (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

/* ---------- CSV ---------- */

static void writeRow(FILE *csv, const char *group, const char *caseName,
                      int n, const char *algoName, double timeMs) {
    fprintf(csv, "%s,%s,%d,%s,%.4f\n", group, caseName, n, algoName, timeMs);
    fflush(csv);
}

/* ---------- driver ---------- */

static void runGroup(const DatasetGroup *group, FILE *csv) {
    for (int c = 0; c < NUM_CASES; c++) {
        const char *caseName = CASES[c];

        for (int s = 0; s < group->numSizes; s++) {
            int n = group->sizes[s];

            char path[512];
            snprintf(path, sizeof(path), "%s/%s/%s%d.txt",
                     group->folder, caseName, group->prefix, n);

            printf("Reading %s ...\n", path);
            int *base = readDataset(path, n);
            if (base == NULL) continue;

            for (int a = 0; a < NUM_ALGORITHMS; a++) {
                const char *algoName = ALGORITHMS[a].name;
                SortFn fn = ALGORITHMS[a].fn;
                double avgMs;

                if (strcmp(caseName, "average") == 0) {
                    double total = 0.0;
                    for (int t = 0; t < AVERAGE_TRIALS; t++) {
                        int *shuffled = malloc(n * sizeof(int));
                        copyArray(base, shuffled, n);
                        shuffleArray(shuffled, n);
                        total += timeOneRun(fn, algoName, shuffled, n);
                        free(shuffled);
                    }
                    avgMs = total / AVERAGE_TRIALS;
                    printf("  %-14s n=%-7d [%s] avg over %d trials: %.4f ms\n",
                           algoName, n, caseName, AVERAGE_TRIALS, avgMs);
                } else {
                    /* best/worst are already fixed order - a single run is deterministic */
                    avgMs = timeOneRun(fn, algoName, base, n);
                    printf("  %-14s n=%-7d [%s]: %.4f ms\n", algoName, n, caseName, avgMs);
                }

                writeRow(csv, group->folder, caseName, n, algoName, avgMs);
            }

            free(base);
        }
    }
}

int main(void) {
    srand((unsigned int)time(NULL));

    DatasetGroup masterGroup = {
        .folder = "Master",
        .prefix = "sample_",
        .sizes = { 1000, 10000, 20000, 50000, 100000 },
        .numSizes = 5
    };

    DatasetGroup fineGroup = {
        .folder = "fineGrained",
        .prefix = "fine_",
        .sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 },
        .numSizes = 10
    };

    FILE *csv = fopen("results.csv", "w");
    if (csv == NULL) {
        fprintf(stderr, "Could not open results.csv for writing\n");
        return 1;
    }
    fprintf(csv, "dataset_group,case,n,algorithm,time_ms\n");

    printf("=== Master dataset group ===\n");
    runGroup(&masterGroup, csv);

    printf("\n=== fineGrained dataset group ===\n");
    runGroup(&fineGroup, csv);

    fclose(csv);
    printf("\nDone. Results written to results.csv\n");
    return 0;
}