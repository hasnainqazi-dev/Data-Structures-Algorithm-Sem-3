#include<iostream>
using namespace std;

class PrinterQueue
{
private:
    struct Node
    {
        int jobId;
        Node* next;
    };
    Node* front;
    Node* rear;
    int count;
public:
    PrinterQueue()
    {
        front=NULL;
        rear=NULL;
        count=0;
    }
    //Hasnain Qazi
    ~PrinterQueue()
    {
        while(front!=NULL)
        {
            Node* temp=front;
            front=front->next;
            delete temp;
        }
        rear=NULL;
    }
    bool isEmpty()
    {
        return front==NULL;
    }

    void addJob(int id)
    {
        Node* newNode=new Node;
        newNode->jobId=id;
        newNode->next=NULL;
        if(isEmpty())
        {
            front=newNode;
            rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
        count++;
        cout<<"Added Job ID : "<<id<<endl;
    }
    int processJob()
    {
        if(isEmpty())
        {
            return -1;
        }
        Node* temp=front;
        int id=front->jobId;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete temp;
        count--;

        cout<<"Processing Job ID : "<<id<<endl;
        return id;
    }
    int peek()
    {
        if(isEmpty())
            return -1;
        return front->jobId;
    }
    int size()
    {
        return count;
    }
    void display()
    {
        Node* current=front;
        cout<<"--- Pending Jobs ( Front to Rear ) ---"<<endl;
        while(current!=NULL)
        {
            cout<<current->jobId;
            if(current->next!=NULL)
                cout<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};
//Hasnain Qazi
int main()
{
    PrinterQueue q;
    cout<<"========== PRINTER QUEUE MANAGEMENT =========="<<endl;

    q.addJob(101);
    q.addJob(102);
    q.addJob(103);
    q.addJob(104);

    cout<<"\n";
    q.display();
    cout<<endl;
    q.processJob();
    q.processJob();
    cout<<endl;
    q.display();
    cout<<"\n";
    cout<<"Front Job : "<<q.peek()<<endl;
    cout<<"Queue Size : "<<q.size()<<endl;

    cout<<endl;
    q.processJob();
    q.processJob();
    //Hasnain Qazi
    cout<<"\n";
    if(q.isEmpty())
        cout<<"Queue is now empty ."<<endl;
    cout<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"All memory released successfully ."<<endl;
    cout<<"=========================================================="<<endl;
    return 0;
}
