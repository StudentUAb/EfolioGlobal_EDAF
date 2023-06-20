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

void combSort(std::vector<int>& arr) {
    int gap = arr.size();
    float shrink = 1.3;
    bool sorted = false;

    while (!sorted) {
        gap = (int)((float)gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
        std::cout << "Pivot atual: " << gap << "\n";

        for (int i = 0; i + gap < arr.size(); i++) {
            if (arr[i] > arr[i + gap]) {
                std::cout << "Trocar " << arr[i] << " e " << arr[i + gap] << ": ";
                std::swap(arr[i], arr[i + gap]);
                printArray(arr);
                std::cout << "\n";
                sorted = false;
            }
        }
    }
}

int main() {
    std::vector<int> arr = {8, 6, 3, 2, 1, 9, 5, 4, 7};

    std::cout << "Para o vetor ";
    printArray(arr);
    std::cout << ":\n\n";

    combSort(arr);

    std::cout << "Assim, o vetor ordenado é ";
    printArray(arr);
    std::cout << ".\n";

    return 0;
}
