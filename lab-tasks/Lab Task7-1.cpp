#include <iostream>
using namespace std;
int q[100];
int front=0,rear=-1;
void enqueue(int value)
{
    rear++;
    q[rear]=value;
}
void display(int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<q[i]<<" ";
    }
    cout << endl;
}
void search(int n,int key)
{
    int found = 0,pos=-1;
    for (int i=0;i<n;i++)
    {
        if (q[i]==key)
        {
            found=1;
            pos=i;
            break;
        }
    }
    if (found==1)
        cout<<"Element Found at Index: "<<pos;
    else
        cout<<"\nElement Not Found"<<endl;
}
void sortQueue(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if (q[j]>q[j+1]){
                int temp=q[j];
                q[j]=q[j + 1];
                q[j+1]=temp;
            }
        }}
}
int main(){
    int n,value,key;
    cout<<"Enter queue size: ";
    cin>>n;
    if(n<1||n>100){
        cout<<"Invalid size";
        return 0;
    }
    cout<<"Enter elements:"<<endl;

    for (int i=0;i<n;i++){
        cin>>value;
        enqueue(value);
    }

    cout<<"Original Queue: ";
    display(n);
    
    sortQueue(n);
    cout<<"Sorted Queue: ";
    display(n);
    
    cout<<"Enter element to search: ";
    cin>>key;
    search(n,key);
    return 0;
}
