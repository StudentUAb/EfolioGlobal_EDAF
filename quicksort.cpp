#include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if(i != arr.size() - 1) std::cout << " ";
    }
    std::cout << "]";
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    std::cout << "Pivot: " << pivot << "\n";
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::cout << "Trocar " << arr[i] << " e " << arr[j] << ": ";
            std::swap(arr[i], arr[j]);
            printArray(arr);
            std::cout << "\n";
        }
    }
    std::cout << "Trocar " << arr[i + 1] << " e " << arr[high] << ": ";
    std::swap(arr[i + 1], arr[high]);
    printArray(arr);
    std::cout << "\n";

    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {8, 6, 3, 2, 1, 9, 5, 4, 7};

    std::cout << "Para o vetor ";
    printArray(arr);
    std::cout << ":\n\n";

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Assim, o vetor ordenado é ";
    printArray(arr);
    std::cout << ".\n";

    return 0;
}
