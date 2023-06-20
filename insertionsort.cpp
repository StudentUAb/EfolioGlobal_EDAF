#include <iostream>
#include <vector>

// Função auxiliar para imprimir um vetor
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if(i != arr.size() - 1) std::cout << " ";
    }
    // for(int i = 0; i < arr.size(); i++) {
    std::cout << "]";
}

// Função que ordena um vetor usando o algoritmo Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Imprime o vetor e a chave que está sendo inserida
        std::cout << "Inserindo " << key << " no vetor ";
        printArray(std::vector<int>(arr.begin(), arr.begin() + i));
        std::cout << ": ";

        // Imprime o vetor antes da inserção
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Imprime o vetor durante a inserção
        arr[j + 1] = key;

        // Imprime o vetor após a inserção
        printArray(std::vector<int>(arr.begin(), arr.begin() + i + 1));
        std::cout << "\n";
    }
}

// Função principal
int main() {
    // Cria um vetor de inteiros
    std::vector<int> arr = {8, 6, 3, 2, 1, 9, 5, 4, 7};

    // int arr_size = arr.size();
    std::cout << "Para o vetor ";

    // Imprime o vetor
    printArray(arr);
    std::cout << ":\n\n";

    // Chama a função que ordena o vetor
    insertionSort(arr);

    // Imprime o vetor ordenado
    std::cout << "Assim, o vetor ordenado é ";
    printArray(arr);
    std::cout << ".\n";

    return 0;
}
