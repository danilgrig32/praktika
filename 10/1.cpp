#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Suitor {
    string name;
    int age;
    int appearance;
    int wealth;
};

vector<Suitor> readSuitorsFromFile(const string& filename) {
    ifstream file(filename);
    vector<Suitor> suitors;
    
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return suitors;
    }

    string header;
    getline(file, header);
    getline(file, header);
    
    Suitor s;
    while (file >> s.name >> s.age >> s.appearance >> s.wealth) {
        suitors.push_back(s);
    }
    
    file.close();
    return suitors;
}

int selectBestSuitor(const vector<Suitor>& suitors, int brideAge) {
    if (suitors.empty()) return -1;

    double avgAge = 0, avgAppearance = 0, avgWealth = 0;
    for (const auto& s : suitors) {
        avgAge += s.age;
        avgAppearance += s.appearance;
        avgWealth += s.wealth;
    }
    
    avgAge /= suitors.size();
    avgAppearance /= suitors.size();
    avgWealth /= suitors.size();

    int bestIndex = -1;
    double minDeviation = numeric_limits<double>::max();
    
    for (size_t i = 0; i < suitors.size(); ++i) {
        if (suitors[i].age < brideAge) continue;

        double deviation = pow(suitors[i].age - avgAge, 2) +
                          pow(suitors[i].appearance - avgAppearance, 2) +
                          pow(suitors[i].wealth - avgWealth, 2);
        
        if (deviation < minDeviation) {
            minDeviation = deviation;
            bestIndex = i;
        }
    }
    
    return bestIndex;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<Suitor> suitors = readSuitorsFromFile("10/file.txt");
    
    if (suitors.empty()) {
        cout << "Нет данных о женихах" << endl;
        return 1;
    }
    
    int brideAge;
    cout << "Введите возраст невесты: ";
    cin >> brideAge;
    
    int bestIndex = selectBestSuitor(suitors, brideAge);
    
    if (bestIndex == -1) {
        cout << "Нет подходящих женихов" << endl;
    } else {
        const Suitor& best = suitors[bestIndex];
        cout << "Лучший выбор: " << best.name << endl;
        cout << "Возраст: " << best.age << endl;
        cout << "Внешность: " << best.appearance << endl;
        cout << "Богатство: " << best.wealth << endl;
    }
    
    return 0;
}
