#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:

    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const
    {
        cout << productId << "\t"
             << name << "\t"
             << fixed << setprecision(2)
             << price << "\t"
             << quantity << "\t"
             << totalValue() << endl;
    }

    double totalValue() const
    {
        return price * quantity;
    }

    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }
};

int main()
{
    Product products[5];

    cout << "Enter details of 5 products" << endl;
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Product " << i + 1 << endl;
        products[i].acceptDetails();
        cout << endl;
    }

    cout << "===== INVENTORY REPORT =====" << endl;
    cout << "ID\tName\tPrice\tQty\tTotal Value" << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }

    int highest = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() > products[highest].totalValue())
        {
            highest = i;
        }
    }

    cout << endl;
    cout << "Highest Value Product : ";
    
    products[highest].displayDetails();

    int threshold;

    cout << endl;
    cout << "Enter low stock threshold: ";
    cin >> threshold;

    cout << "Low Stock Products:" << endl;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            products[i].displayDetails();
        }
    }

    return 0;
}