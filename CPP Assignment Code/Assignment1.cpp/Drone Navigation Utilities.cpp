#include <iostream>
#include <cmath>
using namespace std;

inline double distanceBetween(double x1, double y1,
                              double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

inline double toRadians(double degrees)
{
    return degrees * (3.14159 / 180.0);
}

inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
        return minVal;

    if (value > maxVal)
        return maxVal;

    return value;
}

inline bool isInSafeZone(double x, double y,
                         double cx, double cy,
                         double radius)
{
    double distance = distanceBetween(x, y, cx, cy);

    return distance <= radius;
}

int main()
{
    double homeX = 0.0;
    double homeY = 0.0;
    double radius = 50.0;

    double x1 = 20.0;
    double y1 = 30.0;

    double x2 = 40.0;
    double y2 = 30.0;

    double x3 = 60.0;
    double y3 = 20.0;

    double d1 = distanceBetween(homeX, homeY, x1, y1);
    double d2 = distanceBetween(homeX, homeY, x2, y2);
    double d3 = distanceBetween(homeX, homeY, x3, y3);

    cout << "Waypoint 1 Distance : " << d1 << endl;
    cout << "Inside Safe Zone : "
         << (isInSafeZone(x1, y1, homeX, homeY, radius)
             ? "Yes" : "No") << endl;

    cout << endl;

    cout << "Waypoint 2 Distance : " << d2 << endl;
    cout << "Inside Safe Zone : "
         << (isInSafeZone(x2, y2, homeX, homeY, radius)
             ? "Yes" : "No") << endl;

    cout << endl;

    cout << "Waypoint 3 Distance : " << d3 << endl;
    cout << "Inside Safe Zone : "
         << (isInSafeZone(x3, y3, homeX, homeY, radius)
             ? "Yes" : "No") << endl;

    return 0;
}
