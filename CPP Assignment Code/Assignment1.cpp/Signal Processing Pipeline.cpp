#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double* signal, int n)
{
    double sum = 0;

    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (*ptr * *ptr);
        ptr++;
    }

    return sqrt(sum / n);
}

void normalise(double* signal, int n)
{
    double maxValue = 0;

    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        if (fabs(*ptr) > maxValue)
            maxValue = fabs(*ptr);

        ptr++;
    }

    ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr / maxValue;
        ptr++;
    }
}

int countZeroCrossings(double* signal, int n)
{
    int count = 0;

    double* ptr = signal;

    for (int i = 0; i < n - 1; i++)
    {
        if ((*ptr < 0 && *(ptr + 1) > 0) ||
            (*ptr > 0 && *(ptr + 1) < 0))
        {
            count++;
        }

        ptr++;
    }

    return count;
}

void applyGain(double* signal, int n, double gainFactor)
{
    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr * gainFactor;
        ptr++;
    }
}

void printArray(double* signal, int n)
{
    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }

    cout << endl;
}

int main()
{
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};

    int n = 7;

    cout << "Before : ";
    printArray(signal, n);

    cout << "RMS : " << computeRMS(signal, n) << endl;

    cout << "Zero Crossings : "
         << countZeroCrossings(signal, n) << endl;

    normalise(signal, n);

    cout << "After Normalise : ";
    printArray(signal, n);

    applyGain(signal, n, 2.0);

    cout << "After Gain : ";
    printArray(signal, n);

    return 0;
}