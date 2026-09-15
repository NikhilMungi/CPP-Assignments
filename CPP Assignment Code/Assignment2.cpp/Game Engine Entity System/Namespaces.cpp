#include <iostream>
using namespace std;

namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

int main()
{
    double speed = Physics::clamp(120.5, 0.0, 100.0);

    int health = GameMath::clamp(120, 0, 100);

    double physicsValue =
        Physics::lerp(10.0, 20.0, 0.5);

    double gameValue =
        GameMath::lerp(100.0, 200.0, 0.25);

    cout << "Physics Clamp : "
         << speed << endl;

    cout << "GameMath Clamp : "
         << health << endl;

    cout << "Physics Lerp : "
         << physicsValue << endl;

    cout << "GameMath Lerp : "
         << gameValue << endl;

    {
        using namespace Physics;

        cout << "Limited Scope Clamp : "
             << clamp(150.0, 0.0, 100.0)
             << endl;
    }

    return 0;
}