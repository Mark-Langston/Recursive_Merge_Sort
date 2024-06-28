#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void merge(std::vector<int>& arr, int l, int m, int r);
void mergeSort(std::vector<int>& arr, int l, int r);
bool is_increasing(const std::vector<int>& values);

int main() {
    // Program intro
    std::cout << "Recursive Merge Sorter\n" << "\n";

    const int SIZE = 100;
    std::vector<int> arr(SIZE);

    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "\nThe Array:" << "\n";
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nBefore sorting:" << "\n";
    if (is_increasing(arr)) {
        std::cout << "Array is non-strictly increasing." << "\n";
    }
    else {
        std::cout << "Array is not non-strictly increasing." << "\n";
    }

    mergeSort(arr, 0, SIZE - 1);

    std::cout << "\nAfter sorting:" << "\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    if (is_increasing(arr)) {
        std::cout << "Array is non-strictly increasing." << "\n";
    }
    else {
        std::cout << "Array is NOT non-strictly increasing." << "\n";
    }

    return 0;
}

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

bool is_increasing(const std::vector<int>& values) {
    for (size_t i = 0; i < values.size() - 1; ++i) {
        if (values[i] > values[i + 1]) {
            return false;
        }
    }
    return true;
}