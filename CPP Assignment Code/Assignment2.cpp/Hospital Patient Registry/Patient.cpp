#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    Patient()
        : patientId(0), name("Unknown"), age(0),
          ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered." << endl;
    }

    Patient(int id, const string& n)
        : patientId(id), name(n), age(0),
          ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Emergency: "
             << name << endl;
    }

    Patient(int id, const string& n, int a,
            const string& w, const string& bg)
        : patientId(id), name(n), age(a),
          ward(w), bloodGroup(bg)
    {
        cout << "[Constructor] Full admission: "
             << name << endl;
    }

    ~Patient()
    {
        cout << "[Destructor] Patient "
             << name << " discharged." << endl;
    }

    void displayRecord() const
    {
        cout << endl;
        cout << "Patient Record:" << endl;
        cout << "ID : " << patientId << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Ward : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
    }

    void transferWard(const string& newWard)
    {
        cout << "Ward Transfer: "
             << name << " -> "
             << newWard << endl;

        ward = newWard;
    }
};

int main()
{
    Patient p1(1001, "Meera", 34, "Cardiology", "B+");

    Patient p2(1002, "Raj");

    Patient p3;

    cout << endl;

    Patient* patients = new Patient[4];

    for (int i = 0; i < 4; i++)
    {
        patients[i].displayRecord();
    }

    patients[0].transferWard("ICU");

    delete[] patients;

    cout << endl;
    cout << "Stack objects will now be destroyed." << endl;

    return 0;
}