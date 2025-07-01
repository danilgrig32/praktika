#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>


using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double M, V, N;
    cout << "Введите ежемесячный вклад мужа (руб.): ";
    cin >> M;
    cout << "Введите ежемесячный вклад жены (руб.): ";
    cin >> V;
    cout << "Введите стоимость автомобиля (тыс. руб.): ";
    cin >> N;
    N *= 1000;

    double total = 0;
    double monthlyRate = 0.12 / 12;
    int month = 0;


    cout << "\nМесяц | Накопления (руб.) | Процент (руб.) | Итого (руб.)" << endl;
    cout << "-----------------------------------------------" << endl;

    while (total < N) {
        month++;
        double interest = total * monthlyRate;
        total += interest + M + V;


        cout << setw(5) << month << " | "
             << fixed << setprecision(2) << setw(15) << total - interest << " | "
             << setw(12) << interest << " | "
             << setw(10) << total << endl;
    }

    int years = month / 12;
    int remainingMonths = month % 12;

    cout << "\nАвтомобиль будет куплен через " << years << " лет и " << remainingMonths << " месяцев." << endl;
    cout << "Итоговая сумма: " << fixed << setprecision(2) << total << " руб." << endl;

    return 0;
}