#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double a[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int errors = 0;
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    double minTemp = 0;
    double maxTemp = 0;
    double sum = 0;

    bool first = true;

    cout << "Valid readings : ";

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            errors++;
            continue;
        }

        cout << a[i] << " ";

        if (first)
        {
            minTemp = a[i];
            maxTemp = a[i];
            first = false;
        }

        if (a[i] < minTemp)
            minTemp = a[i];

        if (a[i] > maxTemp)
            maxTemp = a[i];

        sum = sum + a[i];

        if (a[i] < 30)
            normal++;
        else if (a[i] < 45)
            warning++;
        else if (a[i] < 60)
            critical++;
        else
            shutdown++;
    }

    cout << endl;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 45)
        {
            cout << "First CRITICAL : Index " << i
                 << " -> " << a[i] << "C" << endl;
            found = true;
            break;
        }
    }

    int valid = n - errors;

    double average = 0;

    if (valid > 0)
        average = sum / valid;

    cout << "Skipped (errors) : " << errors << endl;

    if (valid > 0)
    {
        cout << fixed << setprecision(2);
        cout << "Min : " << minTemp << "C ";
        cout << "Max : " << maxTemp << "C ";
        cout << "Avg : " << average << "C" << endl;
    }

    cout << "Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}