#include <iostream>
#include <string>
#include <limits>
using namespace std;

void clearInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct PatientNode {
    int id;
    string name;
    int age;
    string disease;
    PatientNode* next;
};

class PatientRegistration {
private:
    PatientNode* head;

public:
    PatientRegistration() : head(NULL) {}

    ~PatientRegistration() {
        while (head != NULL) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPatient() {
        PatientNode* newNode = new PatientNode;

        cout << "Enter Patient ID: ";
        cin >> newNode->id;
        clearInput();

        cout << "Enter Patient Name: ";
        getline(cin, newNode->name);

        cout << "Enter Age: ";
        cin >> newNode->age;
        clearInput();

        cout << "Enter Disease: ";
        getline(cin, newNode->disease);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            PatientNode* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Patient registered successfully.\n";
    }

    void searchPatient() {
        int searchID;
        cout << "Enter Patient ID to search: ";
        cin >> searchID;

        PatientNode* current = head;
        while (current != NULL) {
            if (current->id == searchID) {
                cout << "\nPatient Found\n";
                cout << "ID: " << current->id << '\n';
                cout << "Name: " << current->name << '\n';
                cout << "Age: " << current->age << '\n';
                cout << "Disease: " << current->disease << '\n';
                return;
            }
            current = current->next;
        }

        cout << "Patient not found.\n";
    }

    void removePatient() {
        int removeID;
        cout << "Enter Patient ID to remove: ";
        cin >> removeID;

        if (head == NULL) {
            cout << "Patient list is empty.\n";
            return;
        }

        if (head->id == removeID) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient removed successfully.\n";
            return;
        }

        PatientNode* current = head;
        while (current->next != NULL && current->next->id != removeID) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Patient not found.\n";
        } else {
            PatientNode* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Patient removed successfully.\n";
        }
    }

    void displayPatients() {
        if (head == NULL) {
            cout << "No registered patients.\n";
            return;
        }

        cout << "\n--- Registered Patients ---\n";
        PatientNode* current = head;
        while (current != NULL) {
            cout << "ID: " << current->id << '\n';
            cout << "Name: " << current->name << '\n';
            cout << "Age: " << current->age << '\n';
            cout << "Disease: " << current->disease << '\n';
            cout << "---------------------------\n";
            current = current->next;
        }
    }
};

struct HistoryNode {
    int id;
    string name;
    HistoryNode* prev;
    HistoryNode* next;
};

class PatientHistory {
private:
    HistoryNode* head;
    HistoryNode* tail;

public:
    PatientHistory() : head(NULL), tail(NULL) {}

    ~PatientHistory() {
        while (head != NULL) {
            HistoryNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }

    void addTreatedPatient() {
        HistoryNode* newNode = new HistoryNode;

        cout << "Enter Patient ID: ";
        cin >> newNode->id;
        clearInput();

        cout << "Enter Patient Name: ";
        getline(cin, newNode->name);

        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Patient added to treatment history.\n";
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Patient history is empty.\n";
            return;
        }

        cout << "\n--- Patient History (Forward) ---\n";
        HistoryNode* current = head;
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name << '\n';
            current = current->next;
        }
    }

    void displayReverse() {
        if (tail == NULL) {
            cout << "Patient history is empty.\n";
            return;
        }

        cout << "\n--- Patient History (Reverse) ---\n";
        HistoryNode* current = tail;
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name << '\n';
            current = current->prev;
        }
    }
};

struct AppointmentNode {
    int id;
    string name;
    AppointmentNode* next;
};

class AppointmentManagement {
private:
    AppointmentNode* head;
    AppointmentNode* currentAppointment;

public:
    AppointmentManagement() : head(NULL), currentAppointment(NULL) {}

    ~AppointmentManagement() {
        if (head == NULL) return;

        AppointmentNode* current = head->next;
        while (current != head) {
            AppointmentNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = NULL;
        currentAppointment = NULL;
    }

    void addAppointment() {
        AppointmentNode* newNode = new AppointmentNode;

        cout << "Enter Patient ID: ";
        cin >> newNode->id;
        clearInput();

        cout << "Enter Patient Name: ";
        getline(cin, newNode->name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            currentAppointment = head;
        } else {
            AppointmentNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = head;
        }

        cout << "Appointment added successfully.\n";
    }

    void displayAppointments() {
        if (head == NULL) {
            cout << "No appointments available.\n";
            return;
        }

        cout << "\n--- Appointment List ---\n";
        AppointmentNode* current = head;
        do {
            cout << "ID: " << current->id << ", Name: " << current->name << '\n';
            current = current->next;
        } while (current != head);
    }

    void moveToNextAppointment() {
        if (currentAppointment == NULL) {
            cout << "No appointments available.\n";
            return;
        }

        cout << "Current Appointment: "
             << currentAppointment->id << " - "
             << currentAppointment->name << '\n';

        currentAppointment = currentAppointment->next;

        cout << "Next Appointment: "
             << currentAppointment->id << " - "
             << currentAppointment->name << '\n';
    }
};

struct EmergencyNode {
    int id;
    string name;
    EmergencyNode* next;
};

class EmergencyStack {
private:
    EmergencyNode* top;

public:
    EmergencyStack() : top(NULL) {}

    ~EmergencyStack() {
        while (top != NULL) {
            EmergencyNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push() {
        EmergencyNode* newNode = new EmergencyNode;

        cout << "Enter Emergency Patient ID: ";
        cin >> newNode->id;
        clearInput();

        cout << "Enter Emergency Patient Name: ";
        getline(cin, newNode->name);

        newNode->next = top;
        top = newNode;

        cout << "Emergency patient pushed onto stack.\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Emergency stack is empty.\n";
            return;
        }

        EmergencyNode* temp = top;
        cout << "Removed Patient: " << temp->id << " - " << temp->name << '\n';
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "Emergency stack is empty.\n";
            return;
        }

        cout << "Top Emergency Patient: " << top->id << " - " << top->name << '\n';
    }

    void display() {
        if (top == NULL) {
            cout << "Emergency stack is empty.\n";
            return;
        }

        cout << "\n--- Emergency Patients (Top to Bottom) ---\n";
        EmergencyNode* current = top;
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name << '\n';
            current = current->next;
        }
    }
};

void registrationMenu(PatientRegistration& registration) {
    int choice;
    do {
        cout << "\n--- Patient Registration ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Remove Patient by ID\n";
        cout << "4. Display All Patients\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registration.addPatient(); break;
            case 2: registration.searchPatient(); break;
            case 3: registration.removePatient(); break;
            case 4: registration.displayPatients(); break;
            case 5: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

void historyMenu(PatientHistory& history) {
    int choice;
    do {
        cout << "\n--- Patient History ---\n";
        cout << "1. Add Treated Patient\n";
        cout << "2. Display History Forward\n";
        cout << "3. Display History Reverse\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: history.addTreatedPatient(); break;
            case 2: history.displayForward(); break;
            case 3: history.displayReverse(); break;
            case 4: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

void appointmentMenu(AppointmentManagement& appointment) {
    int choice;
    do {
        cout << "\n--- Appointment Management ---\n";
        cout << "1. Add Appointment\n";
        cout << "2. Display All Appointments\n";
        cout << "3. Move to Next Appointment\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: appointment.addAppointment(); break;
            case 2: appointment.displayAppointments(); break;
            case 3: appointment.moveToNextAppointment(); break;
            case 4: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

void emergencyMenu(EmergencyStack& emergency) {
    int choice;
    do {
        cout << "\n--- Emergency Management ---\n";
        cout << "1. Push Emergency Patient\n";
        cout << "2. Pop Emergency Patient\n";
        cout << "3. Peek Top Patient\n";
        cout << "4. Display All Emergency Patients\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: emergency.push(); break;
            case 2: emergency.pop(); break;
            case 3: emergency.peek(); break;
            case 4: emergency.display(); break;
            case 5: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

int main() {
    PatientRegistration registration;
    PatientHistory history;
    AppointmentManagement appointment;
    EmergencyStack emergency;

    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "   HOSPITAL PATIENT MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Patient Registration\n";
        cout << "2. Patient History\n";
        cout << "3. Appointment Management\n";
        cout << "4. Emergency Management\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registrationMenu(registration); break;
            case 2: historyMenu(history); break;
            case 3: appointmentMenu(appointment); break;
            case 4: emergencyMenu(emergency); break;
            case 5: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

