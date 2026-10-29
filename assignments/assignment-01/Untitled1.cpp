#include <iostream>
#include <string>
using namespace std;
// Base Class
class Person
{
private:
    string name;
    int id;
    int age;
public:
    // Default Constructor
    Person()
    {
        name = "";
        id = 0;
        age = 0;
    }
    // Parameterized Constructor
    Person(string n, int i, int a)
    {
        name = n;
        id = i;
        age = a;
    }
    void setName(string n)
    {
        name = n;
    }
    void setId(int i)
    {
        id = i;
    }
    void setAge(int a)
    {
        age = a;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    int getAge()
    {
        return age;
    }
    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Patient Class
class Patient : public Person
{
private:
    string disease;
    int roomNumber;
public:
    Patient()
    {
        disease = "";
        roomNumber = 0;
    }
    Patient(
        string name,
        int id,
        int age,
        string d,
        int room
    ) : Person(name, id, age)
    {
        disease = d;
        roomNumber = room;
    }
    void setDisease(string d)
    {
        disease = d;
    }
    void setRoomNumber(int room)
    {
        roomNumber = room;
    }
    string getDisease()
    {
        return disease;
    }
    int getRoomNumber()
    {
        return roomNumber;
    }
    void displayPatient()
    {
        cout << "Name: " << getName()
             << " | ID: " << getId()
             << " | Age: " << getAge()
             << " | Disease: " << disease
             << " | Room: " << roomNumber
             << endl;
    }
};

// Derived Doctor Class
class Doctor : public Person
{
private:
    string specialization;
public:
    Doctor()
    {
        specialization = "";
    }
    Doctor(
        string name,
        int id,
        int age,
        string s
    ) : Person(name, id, age)
    {
        specialization = s;
    }
    void setSpecialization(string s)
    {
        specialization = s;
    }
    string getSpecialization()
    {
        return specialization;
    }
    void displayDoctor()
    {
        displayPerson();
        cout << "Specialization: "
             << specialization << endl;
    }
};


// Dynamic Container Class
class PatientContainer
{
private:
    Patient* patients;
    int capacity;
    int count;

public:

    // Constructor
    PatientContainer(int size = 2)
    {
        capacity = size;
        count = 0;
        patients = new Patient[capacity];
    }

    // Destructor
    ~PatientContainer()
    {
        delete[] patients;
    }

    // Resize Dynamic Array
    void resize()
    {
        int newCapacity = capacity * 2;
        Patient* newPatients =
            new Patient[newCapacity];
        for (int i = 0; i < count; i++)
        {
            newPatients[i] = patients[i];
        }
        delete[] patients;
        patients = newPatients;
        capacity = newCapacity;
    }

    // Add Patient
    void addPatient()
    {
        if (count == capacity)
        {
            resize();
        }
        string name;
        string disease;
        int id;
        int age;
        int room;
        cout << "\nEnter Patient ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Patient Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Disease: ";
        getline(cin, disease);
        cout << "Enter Room Number: ";
        cin >> room;
        Patient newPatient(name,id,age,disease,room);
        patients[count] = newPatient;
        count++;
        cout << "\nPatient added successfully."
             << endl;
    }

    // Search Patient
    void searchPatient()
    {
        int searchId;
        cout << "\nEnter Patient ID to search: ";
        cin >> searchId;
        for (int i = 0; i < count; i++)
        {
            if (patients[i].getId() == searchId)
            {
                cout << "\nPatient Found:" << endl;
                patients[i].displayPatient();
                return;
            }
        }
        cout << "\nPatient not found." << endl;
    }

    // Remove Patient
    void removePatient()
    {
        int removeId;
        cout << "\nEnter Patient ID to remove: ";
        cin >> removeId;
        for (int i = 0; i < count; i++)
        {
            if (patients[i].getId() == removeId)
            {
                for (int j = i;
                     j < count - 1;
                     j++)
                {
                    patients[j] =
                        patients[j + 1];
                }
                count--;
                cout << "\nPatient removed successfully."
                     << endl;
                return;
            }
        }
        cout << "\nPatient not found." << endl;
    }

    // Display All Patients
    void displayAllPatients()
    {
        if (count == 0)
        {
            cout << "\nNo patients available."<< endl;
            return;
        }
        cout << "\n===== Display All Patients ====="
             << endl;
        for (int i = 0; i < count; i++)
        {
            patients[i].displayPatient();
        }
    }
};

int main()
{
    PatientContainer hospital;
    int choice;
    do
    {
        cout << "\n===== Hospital Management System ====="<< endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Remove Patient" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Display All Patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            hospital.removePatient();
            break;
        case 3:
            hospital.searchPatient();
            break;
        case 4:
            hospital.displayAllPatients();
            break;
        case 5:
            cout << "\nProgram ended."
                 << endl;
            break;
        default:
            cout << "\nInvalid choice."
                 << endl;
        }
    }
    while (choice != 5);
    return 0;
}
