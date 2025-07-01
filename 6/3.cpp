#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

using namespace std;


void generateRandomArray(int* arr, int size, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}


int* findElementsInRange(int* arr, int size, int M1, int M2, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= M1 && arr[i] <= M2) {
            newSize++;
        }
    }


    int* newArr = new int[newSize];
    

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= M1 && arr[i] <= M2) {
            newArr[index++] = arr[i];
        }
    }

    return newArr;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size];

    generateRandomArray(arr, size, 0, 100);

    cout << "Сгенерированный массив:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int M1, M2;
    cout << "Введите границы диапазона [M1, M2]: ";
    cin >> M1 >> M2;

    int newSize;
    int* filteredArr = findElementsInRange(arr, size, M1, M2, newSize);

    cout << "Элементы в диапазоне [" << M1 << ", " << M2 << "]:\n";
    for (int i = 0; i < newSize; i++) {
        cout << filteredArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] filteredArr;

    return 0;
}