#include <iostream>
#include <iomanip>
using namespace std;

double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100);
}

double applyDiscount(double price, double discountPercent = 10.0)
{
    return price - (price * discountPercent / 100);
}

int main()
{
    double cost1 = reorderCost(10, 50.0);

    double cost2 = reorderCost(5.5, 50.0);

    double cost3 = reorderCost(10, 50.0, 18.0);

    double discount1 = applyDiscount(1000);

    double discount2 = applyDiscount(1000, 20);

    cout << fixed << setprecision(2);

    cout << "Integer Quantity Cost : Rs. "
         << cost1 << endl;

    cout << "Fractional Quantity Cost : Rs. "
         << cost2 << endl;

    cout << "Cost With Tax : Rs. "
         << cost3 << endl;

    cout << "10% Default Discount : Rs. "
         << discount1 << endl;

    cout << "20% Discount : Rs. "
         << discount2 << endl;

    return 0;
}