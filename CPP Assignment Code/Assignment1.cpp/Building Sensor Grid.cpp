#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double temp[3][3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter temperatures for Floor " << i + 1 << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Room " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }

    cout << endl;

    cout << "       Room1 Room2 Room3" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++)
        {
            cout << fixed << setprecision(1)
                 << temp[i][j] << " ";
        }

        cout << endl;
    }

    double hottest = temp[0][0];
    int hotFloor = 0;
    int hotRoom = 0;

    int warningRooms = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temp[i][j] > hottest)
            {
                hottest = temp[i][j];
                hotFloor = i;
                hotRoom = j;
            }

            if (temp[i][j] >= 30)
                warningRooms++;
        }
    }

    double highestAverage = 0;
    int highestFloor = 0;

    for (int i = 0; i < 3; i++)
    {
        double sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum = sum + temp[i][j];
        }

        double average = sum / 3;

        if (i == 0 || average > highestAverage)
        {
            highestAverage = average;
            highestFloor = i;
        }
    }

    cout << "Hottest Room : Floor " << hotFloor + 1
         << ", Room " << hotRoom + 1
         << " -> " << hottest << "C" << endl;

    cout << "Hottest Floor : Floor " << highestFloor + 1
         << " (avg " << highestAverage << "C)" << endl;

    cout << "Rooms at WARNING or above : "
         << warningRooms << endl;

    return 0;
}