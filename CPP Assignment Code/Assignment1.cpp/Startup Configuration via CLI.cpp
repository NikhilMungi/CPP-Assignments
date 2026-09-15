#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error : Missing arguments." << endl;
        return 1;
    }

    double warn = atof(argv[1]);
    double critical = atof(argv[2]);
    int n = atoi(argv[3]);

    if (warn >= critical)
    {
        cout << "Error : Warn threshold must be less than critical threshold." << endl;
        return 1;
    }

    if (n < 1 || n > 500)
    {
        cout << "Error : Number of readings must be between 1 and 500." << endl;
        return 1;
    }

    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    cout << "Config : Warn=" << warn
         << "C Critical=" << critical
         << "C Readings=" << n << endl;

    for (int i = 0; i < n; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warn)
            normal++;
        else if (temperature < critical)
            warning++;
        else if (temperature < 60)
            criticalCount++;
        else
            shutdown++;
    }

    cout << "Results : Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << criticalCount
         << " Shutdown:" << shutdown << endl;

    return 0;
}