#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <windows.h>


using namespace std;

void radiansToDegreesMinutes(double radians, int& degrees, int& minutes) {
    double totalDegrees = radians * 180.0 / M_PI;
    degrees = static_cast<int>(totalDegrees);
    double decimal = totalDegrees - degrees;
    minutes = static_cast<int>(round(decimal * 60));

    if (minutes >= 60) {
        minutes -= 60;
        degrees += 1;
    }
    if (degrees >= 360) {
        degrees -= 360;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char repeat;
    
    do {
        double x, y;
        cout << "Введите декартовы координаты точки (x y): ";
        cin >> x >> y;

        double radius = sqrt(x * x + y * y);

        double angleRad = atan2(y, x);
        

        int degrees, minutes;
        radiansToDegreesMinutes(angleRad, degrees, minutes);


        int quadrant;
        if (x > 0 && y > 0) quadrant = 1;
        else if (x < 0 && y > 0) quadrant = 2;
        else if (x < 0 && y < 0) quadrant = 3;
        else if (x > 0 && y < 0) quadrant = 4;
        else quadrant = 0;
        
        cout << "Полярные координаты:\n";
        cout << "Радиус: " << fixed << setprecision(4) << radius << endl;
        cout << "Угол: " << degrees << "° " << minutes << "'" << endl;
        cout << "Четверть: ";
        if (quadrant == 0) cout << "точка лежит на оси\n";
        else cout << quadrant << endl;
        
        cout << "\nХотите выполнить еще один расчет? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
    
    return 0;
}