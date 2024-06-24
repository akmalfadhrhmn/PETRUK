#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


void bubbleSort(int array[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}


void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}


void selectionSort(int array[], int size) {
    for (int i = 0; i < size-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        swap(array[minIdx], array[i]);
    }
}


void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}


int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void measureSortTime(void (*sortFunc)(int[], int), int array[], int size, const string& sortName, const string& dataCondition, int n) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(array, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duration = end - start;
    cout << sortName << " (" << dataCondition << ") - N=" << n << " Time: " << duration.count() << " microseconds" << endl;
}

void measureSortTime(void (*sortFunc)(int[], int, int), int array[], int left, int right, const string& sortName, const string& dataCondition, int n) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(array, left, right);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duration = end - start;
    cout << sortName << " (" << dataCondition << ") - N=" << n << " Time: " << duration.count() << " microseconds" << endl;
}


void generateData(int array[], int size, const string& condition) {
    if (condition == "Random") {
        generate(array, array + size, []() { return rand() % 10000; });
    } else if (condition == "Sorted") {
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
    } else if (condition == "Reverse") {
        for (int i = 0; i < size; i++) {
            array[i] = size - i;
        }
    }
}

int main() {
    srand(time(0)); 
    int sizes[] = {10, 100, 500, 1000, 10000};
    string conditions[] = {"Random", "Sorted", "Reverse"};

    for (int size : sizes) {
        for (const string& condition : conditions) {
            int* array = new int[size];

            generateData(array, size, condition);
            measureSortTime(bubbleSort, array, size, "Bubble Sort", condition, size);

            generateData(array, size, condition);
            measureSortTime(insertionSort, array, size, "Insertion Sort", condition, size);

            generateData(array, size, condition);
            measureSortTime(selectionSort, array, size, "Selection Sort", condition, size);

            generateData(array, size, condition);
            measureSortTime(mergeSort, array, 0, size - 1, "Merge Sort", condition, size);

            generateData(array, size, condition);
            measureSortTime(quickSort, array, 0, size - 1, "Quick Sort", condition, size);

            delete[] array;
        }
    }

    return 0;
}
