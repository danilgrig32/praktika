#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;


double P(double x) {
    double sum = 0.0;
    for (int i = 0; i <= 50; ++i) {
        sum += pow(x, i);
    }
    return sum;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Вычисление значений полинома P(x) = 1 + x + x^2 + ... + x^50" << endl;
    cout << "для x ∈ [-0.5, 0.5] с шагом 0.1:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "   x   |      P(x)      " << endl;
    cout << "----------------------------------------" << endl;


    for (double x = -0.5; x <= 0.5 + 1e-9; x += 0.1) {
        cout << fixed << setprecision(1) << setw(6) << x << " | " 
             << fixed << setprecision(6) << setw(12) << P(x) << endl;
    }

    return 0;
}