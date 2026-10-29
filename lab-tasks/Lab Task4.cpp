#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
//Hasnain Qazi
class StudentLinkedList{
private:
    Node* head;
public:
    StudentLinkedList()
    {
        head=NULL;
    }
    void append(int value)
    {
        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node* current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next=newNode;
        }
    }
    void insert(int position,int value)
    {
        Node* newNode=new Node;
        newNode->data=value;

        if(position==1)
        {
            newNode->next=head;
            head=newNode;
        }
        else
        {
            Node* current=head;
            for(int i=1;i<position-1;i++)
            {
                current=current->next;
            }
            newNode->next=current->next;
            current->next=newNode;
        }
    }
    void remove(int position)
    {
        if(position==1)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        else
        {
            Node* current=head;
            for(int i=1;i<position-1;i++)
            {
                current=current->next;
            }
            Node* temp=current->next;
            current->next=temp->next;
            delete temp;
        }
    }
    int search(int value)
    {
        Node* current=head;
        int position=1;

        while(current!=NULL)
        {
            if(current->data==value)
            {
                return position;
            }
            current=current->next;
            position++;
        }
        return -1;
    }
    void display()
    {
        Node* current=head;

        while(current!=NULL)
        {
            cout<<current->data;

            if(current->next!=NULL)
                cout<<" ";

            current=current->next;
        }
    }
    void clear()
    {
        while(head!=NULL)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};
//Hasnain Qazi
int main(){
    StudentLinkedList list;
    list.append(101);
    list.append(102);
    list.append(103);
    list.append(104);
    list.append(105);

    cout<<"========== STUDENT ROLL NUMBER MANAGEMENT ==========\n"<<endl;
    cout<<"Original List : ";
    list.display();
    cout<<endl;

    list.insert(3,999);
    cout<<"\nAfter Insert ( position 3 , value 999) : ";
    list.display();
    cout<<endl;

    list.remove(2);
    cout<<"\nAfter Delete ( position 2) : ";
    list.display();
    cout<<endl;

    int result=list.search(103);
    cout<<"\nSearching for 103... ";
    if(result!=-1)
        cout<<"Found at position "<<result<<endl;
    else
        cout<<"Not found"<<endl;

    result=list.search(555);
    cout<<"\nSearching for 555... ";
    if(result!=-1)
        cout<<"Found at position "<<result<<endl;
    else
        cout<<"Not found"<<endl;

    cout<<"\n=========================================================="<<endl;
    list.clear();
    cout<<"All memory released successfully ."<<endl;
    cout<<"=========================================================="<<endl;

    return 0;
}
