#include <iostream>

using namespace std;

// Função para trocar dois elementos em um array
void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

// Função para escolher o pivô (neste caso, o último elemento)
int choosePivot(int arr[], int high) {

    return arr[high]; // Escolhendo o último elemento como pivô
}

// Função para particionar o array em relação ao pivô
int partition(int arr[], int low, int high) {

    int pivot = choosePivot(arr, high); // Escolhendo o pivô

    int i = low - 1; // Inicializando um índice para elementos menores que o pivô

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) {
            i++; // Incrementa o índice dos elementos menores
            swap(arr[i], arr[j]); // Troca arr[i] pelo elemento q eh menor do que o pivo
        }
    }

    // troca o pivo do final para a posicao correta, separando os elementos menores dos maiores
    swap(arr[i + 1], arr[high]);
    return i + 1; // Retorna a posição exata do pivô após a partição
}

// Função Quicksort
void quicksort(int arr[], int low, int high) {

    if (low < high) {
        int pivot = partition(arr, low, high); // Obtém a posição do pivô após a partição

        // Chama o Quicksort recursivamente para as partições esquerda e direita
        // lembrando que o pivô não entra na brincadeira. ele serve apenas de ref. para as partições
        quicksort(arr, low, pivot - 1); // Classifica os elementos menores que o pivô
        quicksort(arr, pivot + 1, high); // Classifica os elementos maiores que o pivô
    }
}

int main(void) {

    int arr[] = {12, 21, 13, 5, 29, 7, 1205, 2112};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array antes do Quicksort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Array depois do Quicksort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}