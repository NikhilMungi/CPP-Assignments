#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <utility>
using namespace std;

class LedgerEntry
{
private:
    string description;
    double* amounts;
    int days;

public:
    static int totalEntries;

    LedgerEntry(const string& desc, int d)
    {
        description = desc;
        days = d;
        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = 0;
        }

        totalEntries++;

        cout << "[LedgerEntry Created] "
             << description << " (" << days << " days)" << endl;
    }

    LedgerEntry(const LedgerEntry& other)
    {
        description = other.description;
        days = other.days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        totalEntries++;

        cout << "[Copy Constructor]" << endl;
    }

    LedgerEntry(LedgerEntry&& other) noexcept
    {
        description = other.description;
        amounts = other.amounts;
        days = other.days;

        other.amounts = nullptr;
        other.days = 0;
        other.description = "Empty";

        totalEntries++;

        cout << "[Move Constructor] Ownership transferred from: "
             << description << endl;
    }

    LedgerEntry& operator=(const LedgerEntry& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] amounts;

        description = other.description;
        days = other.days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        cout << "[Copy Assignment]" << endl;

        return *this;
    }

    LedgerEntry& operator=(LedgerEntry&& other) noexcept
    {
        if (this != &other)
        {
            delete[] amounts;

            description = other.description;
            amounts = other.amounts;
            days = other.days;

            other.amounts = nullptr;
            other.days = 0;
            other.description = "Empty";

            cout << "[Move Assignment] Ownership transferred from: "
                 << description << endl;
        }

        return *this;
    }

    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;

        cout << "[Destructor] "
             << description << " destroyed" << endl;
    }

    double& operator[](int index)
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Invalid index");
        }

        return amounts[index];
    }

    const double& operator[](int index) const
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Invalid index");
        }

        return amounts[index];
    }

    LedgerEntry operator+(const LedgerEntry& other) const
    {
        int commonDays = days;

        if (other.days < commonDays)
        {
            commonDays = other.days;
        }

        LedgerEntry result("Combined", commonDays);

        for (int i = 0; i < commonDays; i++)
        {
            result.amounts[i] =
                amounts[i] + other.amounts[i];
        }

        return result;
    }

    bool operator==(const LedgerEntry& other) const
    {
        if (days != other.days)
        {
            return false;
        }

        for (int i = 0; i < days; i++)
        {
            if (amounts[i] != other.amounts[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator>(const LedgerEntry& other) const
    {
        double total1 = 0;
        double total2 = 0;

        for (int i = 0; i < days; i++)
        {
            total1 += amounts[i];
        }

        for (int i = 0; i < other.days; i++)
        {
            total2 += other.amounts[i];
        }

        return total1 > total2;
    }

    friend ostream& operator<<(ostream& out,
                               const LedgerEntry& entry);

    friend istream& operator>>(istream& in,
                               LedgerEntry& entry);
};

int LedgerEntry::totalEntries = 0;

ostream& operator<<(ostream& out,
                    const LedgerEntry& entry)
{
    double total = 0;

    out << entry.description << " : [";

    for (int i = 0; i < entry.days; i++)
    {
        out << fixed << setprecision(2)
            << entry.amounts[i];

        total += entry.amounts[i];

        if (i < entry.days - 1)
        {
            out << ", ";
        }
    }

    out << "] Total: " << total;

    return out;
}

istream& operator>>(istream& in,
                    LedgerEntry& entry)
{
    for (int i = 0; i < entry.days; i++)
    {
        in >> entry.amounts[i];
    }

    return in;
}

int main()
{
    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;

    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;

    cout << jan << endl;
    cout << feb << endl;

    LedgerEntry combined = jan + feb;

    cout << "Combined: "
         << combined << endl;

    cout << "Jan == Feb : "
         << (jan == feb ? "Yes" : "No")
         << endl;

    cout << "Jan > Feb : "
         << (jan > feb ? "Yes" : "No")
         << endl;

    LedgerEntry moved = move(jan);

    cout << "After move, jan.amounts is null: "
         << (jan[0] == 0 ? "YES" : "NO")
         << endl;

    cout << "Moved entry: "
         << moved << endl;

    LedgerEntry q1("Q1 Total", 5);

    q1 = move(feb);

    cout << "Q1 (moved from feb): "
         << q1 << endl;

    cout << "Live LedgerEntry objects: "
         << LedgerEntry::totalEntries
         << endl;

    return 0;
}