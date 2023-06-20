#include <iostream>
#include <vector>

// Função auxiliar para imprimir um vetor
void printArray(const std::vector<int>& arr, int start, int end) {
    std::cout << "[";
    for(int i = start; i <= end; i++) {
        std::cout << arr[i];
        if(i != end) std::cout << " ";
    }
    // for(int i = 0; i < arr.size(); i++) {
    std::cout << "]";
}

// Função que ordena um vetor usando o algoritmo Merge Sort
void merge(std::vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // Cria vetores temporários
    std::vector<int> L(n1), R(n2);

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Imprime os vetores temporários
    std::cout << "Combinar ";
    printArray(L, 0, n1 - 1);
    std::cout << " e ";
    printArray(R, 0, n2 - 1);
    std::cout << ": ";

    // Imprime o vetor antes da combinação
    i = 0;
    j = 0;
    k = l;
    // Imprime o vetor durante a combinação
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
    // Imprime o vetor após a combinação
    printArray(arr, l, r);
    std::cout << "\n";
}

// Função que ordena um vetor usando o algoritmo Merge Sort
void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;

        // Imprime o vetor antes da divisão
        std::cout << "Dividir ";
        printArray(arr, l, r);
        std::cout << " em duas metades: ";

        // Imprime o vetor durante a divisão
        printArray(arr, l, m);
        std::cout << " e ";

        // Imprime o vetor durante a divisão
        printArray(arr, m + 1, r);
        std::cout << "\n";

        // Imprime o vetor após a divisão
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Imprime o vetor antes da combinação
        merge(arr, l, m, r);
    }
}

// Função principal
int main() {

    // Cria um vetor de inteiros
    std::vector<int> arr = {3, 7, 8, 9, 5, 1, 4, 2, 6};
    int arr_size = arr.size();

    // Imprime o vetor
    std::cout << "Para o vetor ";
    printArray(arr, 0, arr_size - 1);
    std::cout << ":\n\n";

    // Chama a função que ordena o vetor
    mergeSort(arr, 0, arr_size - 1);
    
    // Imprime o vetor ordenado
    std::cout << "Assim, o vetor ordenado é ";
    printArray(arr, 0, arr_size - 1);
    std::cout << ".\n";

    return 0;
}
