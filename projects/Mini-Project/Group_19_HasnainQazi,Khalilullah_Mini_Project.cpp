#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
using namespace std;

struct Student {
    int roll;
    string name;
    int attended;  
    int total;   
};

Student *arr;      
int numStudents = 0; 
int capacity = 2;    

// Percentage fix: multiply by 100.0 first so the division is not an integer division
double percentage(Student s) {
    if (s.total == 0) return 0;
    return (s.attended * 100.0) / s.total;
}

// ---------- safe input (stops crashes and endless loops on wrong input) ----------
// Read a whole number; keeps asking until the user types a valid one
int readInt(string prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(1000, '\n');   
            return x;
        }
        if (cin.eof()) {            
            cout << "\nInput ended. Exiting.\n";
            exit(0);
        }
        cin.clear();                   
        cin.ignore(1000, '\n');         
        cout << "Please enter a number.\n";
    }
}

// Read a line of text that is not empty
string readLine(string prompt) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) {
            cout << "\nInput ended. Exiting.\n";
            exit(0);
        }
        if (s != "") return s;
        cout << "This cannot be empty.\n";
    }
}

// Read a name: letters and spaces only (no numbers or symbols)
string readName(string prompt) {
    while (true) {
        string s = readLine(prompt);
        bool ok = true;
        int letters = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (isalpha((unsigned char)s[i])) letters++;
            else if (s[i] != ' ') ok = false;
        }
        if (ok && letters > 0) return s;
        cout << "Name must contain letters only.\n";
    }
}

// Read P or A only
char readPA(string prompt) {
    while (true) {
        string s = readLine(prompt);
        if (s == "P" || s == "p") return 'P';
        if (s == "A" || s == "a") return 'A';
        cout << "Enter P or A only.\n";
    }
}

// Make the array twice as big when it is full
void growArray() {
    capacity = capacity * 2;
    Student *bigger = new Student[capacity];
    for (int i = 0; i < numStudents; i++)
        bigger[i] = arr[i];
    delete[] arr;
    arr = bigger;
    cout << "(Array grown to capacity " << capacity << ")\n";
}

void addStudent() {
    int roll = readInt("Roll number: ");
    if (roll <= 0) {
        cout << "Roll number must be positive.\n";
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        if (arr[i].roll == roll) {
            cout << "Roll number already exists.\n";
            return;
        }
    }

    string name = readName("Name: ");

    if (numStudents == capacity)
        growArray();

    arr[numStudents].roll = roll;
    arr[numStudents].name = name;
    arr[numStudents].attended = 0;
    arr[numStudents].total = 0;
    numStudents++;
    cout << "Student added.\n";
}

void markAttendance() {
    if (numStudents == 0) {
        cout << "No students yet.\n";
        return;
    }
    for (int i = 0; i < numStudents; i++) {
        cout << arr[i].roll << " " << arr[i].name;
        char c = readPA(" (P/A): ");
        arr[i].total++;
        if (c == 'P')
            arr[i].attended++;
    }
    cout << "Attendance recorded.\n";
}

void showOne(Student s) {
    cout << "Roll: " << s.roll << " | Name: " << s.name
         << " | Attended: " << s.attended << "/" << s.total
         << " | " << fixed << setprecision(2) << percentage(s) << "%\n";
}

void displayAll() {
    if (numStudents == 0) {
        cout << "No records.\n";
        return;
    }
    for (int i = 0; i < numStudents; i++)
        showOne(arr[i]);
}

// Insertion sort: by roll number, smallest first
void sortByRoll() {
    for (int i = 1; i < numStudents; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].roll > key.roll) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection sort: by attendance percentage, highest first
void sortByPercentage() {
    for (int i = 0; i < numStudents - 1; i++) {
        int best = i;
        for (int j = i + 1; j < numStudents; j++)
            if (percentage(arr[j]) > percentage(arr[best]))
                best = j;
        Student temp = arr[i];
        arr[i] = arr[best];
        arr[best] = temp;
    }
}

// Binary search by roll number (array must be sorted by roll first)
void binarySearch(int roll) {
    sortByRoll();
    int low = 0, high = numStudents - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].roll == roll) {
            showOne(arr[mid]);
            return;
        }
        if (arr[mid].roll < roll)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Student not found.\n";
}

// Linear search by name
void linearSearch(string name) {
    for (int i = 0; i < numStudents; i++) {
        if (arr[i].name == name) {
            showOne(arr[i]);
            return;
        }
    }
    cout << "Student not found.\n";
}

void showDefaulters() {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (arr[i].total > 0 && percentage(arr[i]) < 75) {
            showOne(arr[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No student is below 75%.\n";
}

void deleteStudent(int roll) {
    for (int i = 0; i < numStudents; i++) {
        if (arr[i].roll == roll) {
            for (int j = i; j < numStudents - 1; j++)
                arr[j] = arr[j + 1];      // shift left
            numStudents--;
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    arr = new Student[capacity];
    int choice;

    do {
        cout << "\n--- ATTENDANCE MANAGEMENT SYSTEM ---\n"
             << "1. Add student\n"
             << "2. Mark attendance\n"
             << "3. Display all\n"
             << "4. Search by roll number (binary search)\n"
             << "5. Search by name (linear search)\n"
             << "6. Sort by roll number (insertion sort)\n"
             << "7. Sort by percentage (selection sort)\n"
             << "8. Show students below 75%\n"
             << "9. Delete student\n"
             << "0. Exit\n";
        choice = readInt("Choice: ");

        if (choice == 1) addStudent();
        else if (choice == 2) markAttendance();
        else if (choice == 3) displayAll();
        else if (choice == 4) {
            binarySearch(readInt("Roll number: "));
        }
        else if (choice == 5) {
            linearSearch(readName("Name: "));
        }
        else if (choice == 6) { sortByRoll(); displayAll(); }
        else if (choice == 7) { sortByPercentage(); displayAll(); }
        else if (choice == 8) showDefaulters();
        else if (choice == 9) {
            deleteStudent(readInt("Roll number: "));
        }
        else if (choice != 0) cout << "Invalid choice.\n";
    } while (choice != 0);

    delete[] arr;
    return 0;
}