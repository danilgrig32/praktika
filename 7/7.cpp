#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout << "Введите количество клиентов: ";
    cin >> n;

    vector<int> manager(n);
    vector<int> registration(n);
    vector<int> start(n);
    vector<int> end(n);
    vector<int> waitTime(n);
    vector<int> serviceTime(n);

    cout << "\nВведите данные для каждого клиента:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Клиент #" << i + 1 << endl;
        cout << "  Номер менеджера: ";
        cin >> manager[i];
        cout << "  Время регистрации: ";
        cin >> registration[i];
        cout << "  Время начала обслуживания: ";
        cin >> start[i];
        cout << "  Время окончания обслуживания: ";
        cin >> end[i];

        waitTime[i] = start[i] - registration[i];
        serviceTime[i] = end[i] - start[i];
    }

    int maxWait = *max_element(waitTime.begin(), waitTime.end());
    int minWait = *min_element(waitTime.begin(), waitTime.end());
    double avgWait = accumulate(waitTime.begin(), waitTime.end(), 0.0) / n;

    int maxService = *max_element(serviceTime.begin(), serviceTime.end());
    int minService = *min_element(serviceTime.begin(), serviceTime.end());
    double avgService = accumulate(serviceTime.begin(), serviceTime.end(), 0.0) / n;

    cout << "\nСтатистика времени ожидания:\n";
    cout << "  Минимальное: " << minWait << endl;
    cout << "  Максимальное: " << maxWait << endl;
    cout << "  Среднее: " << avgWait << endl;

    cout << "\nСтатистика времени обслуживания:\n";
    cout << "  Минимальное: " << minService << endl;
    cout << "  Максимальное: " << maxService << endl;
    cout << "  Среднее: " << avgService << endl;

    return 0;
}
