#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string cnic;
public:
    Person(string n,int a,string c)
    {
        name=n;
        age=a;
        cnic=c;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getCnic()
    {
        return cnic;
    }
    void displayInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"CNIC : "<<cnic<<endl;
    }
};

class Student
{
private:
    string name;
    int age;
    string cnic;
    string rollNumber;
    double cgpa;
    int semester;
public:
    Student(string n,int a,string c,string r,double g,int s)
    {
        name=n;
        age=a;
        cnic=c;
        rollNumber=r;
        cgpa=g;
        semester=s;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getCnic()
    {
        return cnic;
    }
    string getRollNumber()
    {
        return rollNumber;
    }
    double getCgpa()
    {
        return cgpa;
    }
    int getSemester()
    {
        return semester;
    }
    string calculateGrade()
    {
        if(cgpa>=3.5)
            return "A";
        else if(cgpa>=3.0)
            return "B";
        else if(cgpa>=2.5)
            return "C";
        else if(cgpa>=2.0)
            return "D";
        else
            return "F";
    }
    void displayInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"CNIC : "<<cnic<<endl;
        cout<<"Roll Number : "<<rollNumber<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"CGPA : "<<cgpa<<endl;
        cout<<"Semester : "<<semester<<endl;
    }
};
//Hasnain Qazi
class Faculty
{
private:
    string name;
    int age;
    string cnic;
    string employeeId;
    double monthlySalary;
    string department;

public:
    Faculty(string n,int a,string c,string id,double salary,string dep)
    {
        name=n;
        age=a;
        cnic=c;
        employeeId=id;
        monthlySalary=salary;
        department=dep;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getCnic()
    {
        return cnic;
    }
    string getEmployeeId()
    {
        return employeeId;
    }
    double getMonthlySalary()
    {
        return monthlySalary;
    }
    string getDepartment()
    {
        return department;
    }
    double calculateAnnualSalary()
    {
        return monthlySalary*12;
    }
    void displayInfo()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"CNIC : "<<cnic<<endl;
        cout<<"Employee ID : "<<employeeId<<endl;
        cout<<"Department : "<<department<<endl;
        cout<<fixed<<setprecision(0);
        cout<<"Monthly Salary : "<<monthlySalary<<endl;
    }
};

int main()
{
    Student s1("Ali Raza",20,"35202-1234567-1","BSCS-2024-001",3.75,3);
    Student s2("Fatima Noor",21,"35202-7654321-2","BSCS-2024-002",3.20,3);

    Faculty f1("Dr. Ahmed Khan",45,"35202-1111111-3","EMP-101",150000,"Computer Science");
    Faculty f2("Ms. Sana Malik",38,"35202-2222222-4","EMP-102",120000,"Software Engineering");

    cout<<"========== RIPHAH UNIVERSITY MANAGEMENT SYSTEM =========="<<endl;

    cout<<"--- Student 1 ---"<<endl;
    s1.displayInfo();
    cout<<"Letter Grade : "<<s1.calculateGrade()<<endl;
    cout<<"--- Student 2 ---"<<endl;
    s2.displayInfo();
    cout<<"Letter Grade : "<<s2.calculateGrade()<<endl;

    cout<<"--- Faculty 1 ---"<<endl;
    f1.displayInfo();
    cout<<"Annual Salary : "<<f1.calculateAnnualSalary()<<endl;
    cout<<"--- Faculty 2 ---"<<endl;
    f2.displayInfo();
    cout<<"Annual Salary : "<<f2.calculateAnnualSalary()<<endl;
    
    double average=(s1.getCgpa()+s2.getCgpa())/2;
    int option=1;
    switch(option){
        case 1:
            break;

        default:
            break;
    }
    cout<<"=========================================================="<<endl;
    cout<<"Total Students : 2"<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Average CGPA : "<<average<<endl;
    cout<<"Total Faculty : 2"<<endl;
    cout<<"=========================================================="<<endl;
//Hasnain Qazi
    return 0;
}
