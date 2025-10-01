#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>

/**
 * Sorting Algorithms Implementation for AlgoVault
 * Includes: QuickSort, MergeSort, HeapSort, BubbleSort
 * Each algorithm includes step-by-step visualization
 */

class SortingAlgorithms
{
private:
    static int stepCount;
    static void resetStepCount();
    static void incrementStep();

public:
    // Bubble Sort
    static void bubbleSort(std::vector<int> &arr);
    static void bubbleSortVisualized(std::vector<int> &arr);

    // Quick Sort
    static void quickSort(std::vector<int> &arr);
    static void quickSortVisualized(std::vector<int> &arr, int low, int high);
    static int partition(std::vector<int> &arr, int low, int high);

    // Merge Sort
    static void mergeSort(std::vector<int> &arr);
    static void mergeSortVisualized(std::vector<int> &arr, int left, int right);
    static void merge(std::vector<int> &arr, int left, int mid, int right);

    // Heap Sort
    static void heapSort(std::vector<int> &arr);
    static void heapSortVisualized(std::vector<int> &arr);
    static void heapify(std::vector<int> &arr, int n, int i);
    static void buildMaxHeap(std::vector<int> &arr);

    // Menu and driver functions
    static void showSortingMenu();
    static void runSortingAlgorithms();

    // Utility functions specific to sorting
    static void printStep(const std::vector<int> &arr, const std::string &operation);
    static void showComplexityInfo(const std::string &algorithm);
};

#endif // SORTING_H