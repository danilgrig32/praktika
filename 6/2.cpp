#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

void inputArray(vector<int>& arr) {
    cout << "Введите элементы массива (для завершения введите -1):\n";
    int num;
    while (true) {
        cin >> num;
        if (num == -1) break;
        arr.push_back(num);
    }
}


void printArray(const vector<int>& arr) {
    cout << "Текущий массив: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}


void searchElement(const vector<int>& arr, int index) {
    if (index >= 0 && index < static_cast<int>(arr.size())) {
        cout << "Элемент с индексом " << index << ": " << arr[index] << endl;
    } else {
        cout << "Ошибка: неверный индекс " << index << endl;
    }
}

void deleteElements(vector<int>& arr, int m1, int m2, int m3) {
    vector<int> indices = {m1, m2, m3};
    sort(indices.rbegin(), indices.rend());
    
    for (int index : indices) {
        if (index >= 0 && index < static_cast<int>(arr.size())) {
            arr.erase(arr.begin() + index);
            cout << "Удален элемент с индексом " << index << endl;
        } else {
            cout << "Ошибка: неверный индекс " << index << " - пропуск" << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<int> array;

    inputArray(array);
    printArray(array);

    int m1, m2, m3;
    cout << "Введите три индекса для поиска (M1, M2, M3): ";
    cin >> m1 >> m2 >> m3;
    
    searchElement(array, m1);
    searchElement(array, m2);
    searchElement(array, m3);

    cout << "Введите три индекса для удаления (M1, M2, M3): ";
    cin >> m1 >> m2 >> m3;
    
    deleteElements(array, m1, m2, m3);
    printArray(array);
    
    return 0;
}