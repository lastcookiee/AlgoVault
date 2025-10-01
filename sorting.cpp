#include "sorting.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

// Static member initialization
int SortingAlgorithms::stepCount = 0;

void SortingAlgorithms::resetStepCount()
{
    stepCount = 0;
}

void SortingAlgorithms::incrementStep()
{
    stepCount++;
}

void SortingAlgorithms::printStep(const std::vector<int> &arr, const std::string &operation)
{
    Utils::setColor(LIGHT_GREEN);
    std::cout << "Step " << stepCount << " - " << operation << ": ";
    Utils::resetColor();
    Utils::printArray(arr);
    // Pause removed for compatibility
}

void SortingAlgorithms::showComplexityInfo(const std::string &algorithm)
{
    if (algorithm == "Bubble Sort")
    {
        Utils::printComplexity("Bubble Sort", "O(n²)", "O(1)");
    }
    else if (algorithm == "Quick Sort")
    {
        Utils::printComplexity("Quick Sort", "O(n log n) average, O(n²) worst", "O(log n)");
    }
    else if (algorithm == "Merge Sort")
    {
        Utils::printComplexity("Merge Sort", "O(n log n)", "O(n)");
    }
    else if (algorithm == "Heap Sort")
    {
        Utils::printComplexity("Heap Sort", "O(n log n)", "O(1)");
    }
}

// ==================== BUBBLE SORT ====================

void SortingAlgorithms::bubbleSort(std::vector<int> &arr)
{
    Utils::printHeader("BUBBLE SORT VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "Bubble Sort works by repeatedly swapping adjacent elements if they are in wrong order." << std::endl;
    Utils::resetColor();

    Utils::printArray(arr, "Initial array");
    resetStepCount();

    bubbleSortVisualized(arr);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nSorting completed!" << std::endl;
    Utils::resetColor();
    Utils::printArray(arr, "Final sorted array");
    showComplexityInfo("Bubble Sort");
}

void SortingAlgorithms::bubbleSortVisualized(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        Utils::setColor(YELLOW);
        std::cout << "\n--- Pass " << (i + 1) << " ---" << std::endl;
        Utils::resetColor();

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                incrementStep();
                printStep(arr, "Swapped " + std::to_string(arr[j + 1]) + " and " + std::to_string(arr[j]));
            }
        }

        if (!swapped)
        {
            Utils::setColor(LIGHT_CYAN);
            std::cout << "No swaps needed. Array is sorted!" << std::endl;
            Utils::resetColor();
            break;
        }
    }
}

// ==================== QUICK SORT ====================

void SortingAlgorithms::quickSort(std::vector<int> &arr)
{
    Utils::printHeader("QUICK SORT VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "Quick Sort uses divide-and-conquer by selecting a pivot and partitioning the array." << std::endl;
    Utils::resetColor();

    Utils::printArray(arr, "Initial array");
    resetStepCount();

    quickSortVisualized(arr, 0, arr.size() - 1);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nSorting completed!" << std::endl;
    Utils::resetColor();
    Utils::printArray(arr, "Final sorted array");
    showComplexityInfo("Quick Sort");
}

void SortingAlgorithms::quickSortVisualized(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        Utils::setColor(YELLOW);
        std::cout << "\nPartitioned around pivot " << arr[pivotIndex]
                  << " at index " << pivotIndex << std::endl;
        Utils::resetColor();

        incrementStep();
        printStep(arr, "After partitioning");

        // Recursively sort elements before and after partition
        quickSortVisualized(arr, low, pivotIndex - 1);
        quickSortVisualized(arr, pivotIndex + 1, high);
    }
}

int SortingAlgorithms::partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose last element as pivot
    int i = low - 1;       // Index of smaller element

    Utils::setColor(MAGENTA);
    std::cout << "Partitioning with pivot: " << pivot << std::endl;
    Utils::resetColor();

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ==================== MERGE SORT ====================

void SortingAlgorithms::mergeSort(std::vector<int> &arr)
{
    Utils::printHeader("MERGE SORT VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "Merge Sort divides the array into halves, sorts them, and merges them back." << std::endl;
    Utils::resetColor();

    Utils::printArray(arr, "Initial array");
    resetStepCount();

    mergeSortVisualized(arr, 0, arr.size() - 1);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nSorting completed!" << std::endl;
    Utils::resetColor();
    Utils::printArray(arr, "Final sorted array");
    showComplexityInfo("Merge Sort");
}

void SortingAlgorithms::mergeSortVisualized(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        Utils::setColor(YELLOW);
        std::cout << "\nDividing array from index " << left << " to " << right
                  << " (mid: " << mid << ")" << std::endl;
        Utils::resetColor();

        // Sort first and second halves
        mergeSortVisualized(arr, left, mid);
        mergeSortVisualized(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);

        incrementStep();
        Utils::setColor(LIGHT_BLUE);
        std::cout << "Merged subarrays [" << left << ".." << mid << "] and ["
                  << (mid + 1) << ".." << right << "]" << std::endl;
        Utils::resetColor();
        Utils::printArrayRange(arr, left, right, "Current state");
    }
}

void SortingAlgorithms::merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// ==================== HEAP SORT ====================

void SortingAlgorithms::heapSort(std::vector<int> &arr)
{
    Utils::printHeader("HEAP SORT VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "Heap Sort builds a max heap and repeatedly extracts the maximum element." << std::endl;
    Utils::resetColor();

    Utils::printArray(arr, "Initial array");
    resetStepCount();

    heapSortVisualized(arr);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nSorting completed!" << std::endl;
    Utils::resetColor();
    Utils::printArray(arr, "Final sorted array");
    showComplexityInfo("Heap Sort");
}

void SortingAlgorithms::heapSortVisualized(std::vector<int> &arr)
{
    int n = arr.size();

    // Build max heap
    Utils::setColor(YELLOW);
    std::cout << "\n--- Building Max Heap ---" << std::endl;
    Utils::resetColor();

    buildMaxHeap(arr);
    incrementStep();
    printStep(arr, "Max heap built");

    // Extract elements from heap one by one
    Utils::setColor(YELLOW);
    std::cout << "\n--- Extracting Elements ---" << std::endl;
    Utils::resetColor();

    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        incrementStep();
        printStep(arr, "Moved max element " + std::to_string(arr[i]) + " to position " + std::to_string(i));

        // Call heapify on the reduced heap
        heapify(arr, i, 0);

        if (i > 1)
        {
            incrementStep();
            Utils::printArrayRange(arr, 0, i - 1, "Heap after heapify");
        }
    }
}

void SortingAlgorithms::buildMaxHeap(std::vector<int> &arr)
{
    int n = arr.size();

    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void SortingAlgorithms::heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// ==================== MENU FUNCTIONS ====================

void SortingAlgorithms::showSortingMenu()
{
    Utils::printHeader("SORTING ALGORITHMS MENU");
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Quick Sort" << std::endl;
    std::cout << "3. Merge Sort" << std::endl;
    std::cout << "4. Heap Sort" << std::endl;
    std::cout << "5. Back to Main Menu" << std::endl;
    Utils::printSeparator('-', 30);
}

void SortingAlgorithms::runSortingAlgorithms()
{
    int choice;
    std::vector<int> arr;

    while (true)
    {
        Utils::clearConsole();
        showSortingMenu();

        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            Utils::clearConsole();
            std::cout << "Getting array input from user..." << std::endl;
            arr = Utils::getArrayFromUser();
            Utils::clearConsole();
        }

        switch (choice)
        {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            quickSort(arr);
            break;
        case 3:
            mergeSort(arr);
            break;
        case 4:
            heapSort(arr);
            break;
        case 5:
            return;
        default:
            Utils::setColor(RED);
            std::cout << "Invalid choice! Please try again." << std::endl;
            Utils::resetColor();
        }

        if (choice >= 1 && choice <= 4)
        {
            Utils::pauseConsole();
        }
    }
}