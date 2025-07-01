#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


vector<int> findPrimesInRange(int N1, int N2) {
    vector<int> primes;
    for (int i = N1; i <= N2; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char choice;

    do {
        int N1, N2;
        cout << "Введите начальное число диапазона (N1): ";
        cin >> N1;
        cout << "Введите конечное число диапазона (N2): ";
        cin >> N2;

        if (N1 > N2) {
            cout << "Ошибка: N1 должно быть меньше или равно N2." << endl;
            continue;
        }

        vector<int> primes = findPrimesInRange(N1, N2);

        cout << "Простые числа в диапазоне от " << N1 << " до " << N2 << ":" << endl;
        for (int prime : primes) {
            cout << prime << " ";
        }
        cout << endl;

        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Программа завершена." << endl;
    return 0;
}