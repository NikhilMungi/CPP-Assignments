#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2)
{
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV2(int& reading1, int& reading2)
{
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV3(int* reading1, int* reading2)
{
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main()
{
  

    int a = 55;
    int b = 12;

    cout << "--- V1: Call by Value ---" << endl;
    cout << "Before : A=" << a << " B=" << b << endl;

    resetSensorPairV1(a, b);

    cout << "After : A=" << a << " B=" << b << endl;

    cout << endl;

    cout << "--- V2: Call by Reference ---" << endl;
    cout << "Before : A=" << a << " B=" << b << endl;

    resetSensorPairV2(a, b);

    cout << "After : A=" << a << " B=" << b << endl;

    cout << endl;

    cout << "--- V3: Call by Pointer ---" << endl;
    cout << "Before : A=" << a << " B=" << b << endl;

    resetSensorPairV3(&a, &b);

    cout << "After : A=" << a << " B=" << b << endl;

    return 0;
}