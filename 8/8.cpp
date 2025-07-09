#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> removeRow(const vector<vector<int>>& matrix, int rowToRemove) {
    vector<vector<int>> newMatrix;
    for (int i = 0; i < matrix.size(); ++i) {
        if (i != rowToRemove) {
            newMatrix.push_back(matrix[i]);
        }
    }
    return newMatrix;
}


vector<vector<int>> removeColumn(const vector<vector<int>>& matrix, int colToRemove) {
    vector<vector<int>> newMatrix;
    for (const auto& row : matrix) {
        vector<int> newRow;
        for (int j = 0; j < row.size(); ++j) {
            if (j != colToRemove) {
                newRow.push_back(row[j]);
            }
        }
        newMatrix.push_back(newRow);
    }
    return newMatrix;
}

vector<vector<int>> readMatrixFromFile(const string& filename, int& n, int& m) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        exit(1);
    }

    file >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();
    return matrix;
}


void writeMatrixToFile(const string& filename, const vector<vector<int>>& matrix) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    file << matrix.size() << " " << (matrix.empty() ? 0 : matrix[0].size()) << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            file << val << " ";
        }
        file << endl;
    }
    file.close();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    string inputFile = "8/input.txt";
    string outputFile = "8/output.txt";
    
    int n, m;
    vector<vector<int>> matrix = readMatrixFromFile(inputFile, n, m);

    cout << "Исходная матрица (" << n << "x" << m << "):" << endl;
    printMatrix(matrix);

    char choice;
    cout << "\nХотите удалить строку? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        int row;
        cout << "Введите номер строки для удаления (0.." << n-1 << "): ";
        cin >> row;
        if (row >= 0 && row < n) {
            matrix = removeRow(matrix, row);
            n--;
        } else {
            cout << "Некорректный номер строки!" << endl;
        }
    }

    if (!matrix.empty()) {
        cout << "\nХотите удалить столбец? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int col;
            cout << "Введите номер столбца для удаления (0.." << m-1 << "): ";
            cin >> col;
            if (col >= 0 && col < m) {
                matrix = removeColumn(matrix, col);
                m--;
            } else {
                cout << "Некорректный номер столбца!" << endl;
            }
        }
    }

    cout << "\nПреобразованная матрица (" << matrix.size() << "x" << (matrix.empty() ? 0 : matrix[0].size()) << "):" << endl;
    printMatrix(matrix);

    writeMatrixToFile(outputFile, matrix);
    cout << "\nРезультат сохранен в файл " << outputFile << endl;

    return 0;
}
