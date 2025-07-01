#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int K;
    cout << "Введите угол K (в градусах): ";
    cin >> K;

    int m = K / 6;
    int h = m / 60;
    int minutes = m % 60;

    h = h % 24;

    cout << "Время: " << h << " часов " << minutes << " минут" << endl;

    return 0;
}