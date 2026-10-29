#include <iostream>
using namespace std;

class StudentList
{
private:
    int students[10];
    int length;
public:
    StudentList()
    {
        length=0;
    }
    int getLength()
    {
        return length;
    }
    void add(int roll)
    {
        if(length<10)
        {
            students[length]=roll;
            length++;
        }
    }
    void insert(int position,int roll)
    {
        if(position>=1&&position<=length+1&&length<10)
        {
            for(int i=length;i>=position;i--)
            {
                students[i]=students[i-1];
            }

            students[position-1]=roll;
            length++;
        }
    }
    void deleteElement(int position)
    {
        if(position>=1&&position<=length)
        {
            for(int i=position-1;i<length-1;i++)
            {
                students[i]=students[i+1];
            }

            length--;
        }
    }
    int search(int roll)
    {
        for(int i=0;i<length;i++)
        {
            if(students[i]==roll)
            {
                return i+1;
            }
        }

        return -1;
    }
    //Hasnain Qazi
    void display()
    {
        for(int i=0;i<length;i++)
        {
            cout<<students[i];

            if(i<length-1)
                cout<<" ";
        }

        cout<<endl;
    }
};

int main()
{
    StudentList list;

    cout<<"========== STUDENT RECORD MANAGEMENT SYSTEM ==========\n"<<endl;
    int n;
    cout<<"How many students do you want to add ? ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int roll;

        cout<<"Enter roll number : ";
        cin>>roll;

        list.add(roll);
    }
    cout<<"\n--- Student Roll Numbers ---"<<endl;
    list.display();

    cout<<"Length : "<<list.getLength()<<endl;

    int deletePosition;
    cout<<"\nEnter position to delete : ";
    cin>>deletePosition;

    list.deleteElement(deletePosition);
    cout<<"After Delete : ";
    list.display();

    cout<<"Length : "<<list.getLength()<<endl;

    int searchRoll;
    cout<<"\nEnter roll number to search : ";
    cin>>searchRoll;

    int position=list.search(searchRoll);
    if(position!=-1)
    {
        cout<<"Roll number found at position : "<<position<<endl;
    }
    else
    {
        cout<<"Roll number not found"<<endl;
    }

    int insertPosition;
    int insertRoll;
    cout<<"\nEnter position to insert : ";
    cin>>insertPosition;
    cout<<"Enter roll number to insert : ";
    cin>>insertRoll;

    list.insert(insertPosition,insertRoll);
    cout<<"After Insert : ";
    list.display();

    cout<<"Length : "<<list.getLength()<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"Final Length of List : "<<list.getLength()<<endl;
    cout<<"=========================================================="<<endl;
    //Hasnain Qazi
    return 0;
}
