#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

const int N = 5;

struct PolarCoord {
    double r;
    int phi;
};

PolarCoord cartesianToPolar(double x, double y) {
    PolarCoord pc;
    pc.r = sqrt(x*x + y*y);

    pc.phi = static_cast<int>(round(atan2(y, x) * 180.0 / M_PI));

    if (pc.phi < 0) pc.phi += 360;
    return pc;
}

int findMaxIndex(const double arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findMaxAngleIndex(const PolarCoord polarCoords[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (polarCoords[i].phi > polarCoords[maxIndex].phi) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double X[N] = {3.0, -2.5, 0.0, 4.2, -1.8};
    double Y[N] = {4.0, 1.5, -3.0, -2.7, 2.4};

    PolarCoord polarCoords[N];
    double radii[N];

    for (int i = 0; i < N; i++) {
        polarCoords[i] = cartesianToPolar(X[i], Y[i]);
        radii[i] = polarCoords[i].r;
    }


    int maxRadiusIndex = findMaxIndex(radii, N);
    int maxAngleIndex = findMaxAngleIndex(polarCoords, N);


    cout << "Все точки:\n";
    cout << "№ |     X     |     Y     |     R     |  Угол\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        cout << i+1 << " | " << fixed << setprecision(3) 
             << setw(8) << X[i] << " | " 
             << setw(8) << Y[i] << " | "
             << setw(8) << polarCoords[i].r << " | "
             << setw(4) << polarCoords[i].phi << "°\n";
    }

    cout << "\nТочка с наибольшим радиусом-вектором:\n";
    cout << "№" << maxRadiusIndex+1 << ": X=" << X[maxRadiusIndex] 
         << ", Y=" << Y[maxRadiusIndex]
         << ", R=" << polarCoords[maxRadiusIndex].r 
         << ", φ=" << polarCoords[maxRadiusIndex].phi << "°\n";

    cout << "\nТочка с наибольшим углом:\n";
    cout << "№" << maxAngleIndex+1 << ": X=" << X[maxAngleIndex] 
         << ", Y=" << Y[maxAngleIndex]
         << ", R=" << polarCoords[maxAngleIndex].r 
         << ", φ=" << polarCoords[maxAngleIndex].phi << "°\n";

    return 0;
}