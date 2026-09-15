#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int rows;
    int columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    int** map = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        map[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            map[i][j] = rand() % 5;
        }
    }

    cout << endl;
    cout << "===== GAME MAP ("
         << rows << " x "
         << columns << ") =====" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << map[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    cout << "Legend: "
         << "0=Grass "
         << "1=Water "
         << "2=Mountain "
         << "3=Forest "
         << "4=Dungeon"
         << endl;

    int grass = 0;
    int water = 0;
    int mountain = 0;
    int forest = 0;
    int dungeon = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] == 0)
                grass++;

            else if (map[i][j] == 1)
                water++;

            else if (map[i][j] == 2)
                mountain++;

            else if (map[i][j] == 3)
                forest++;

            else if (map[i][j] == 4)
                dungeon++;
        }
    }

    cout << endl;
    cout << "Tile Count:" << endl;

    cout << "Grass : " << grass << endl;
    cout << "Water : " << water << endl;
    cout << "Mountain : " << mountain << endl;
    cout << "Forest : " << forest << endl;
    cout << "Dungeon : " << dungeon << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] map[i];
    }

    delete[] map;

    return 0;
}