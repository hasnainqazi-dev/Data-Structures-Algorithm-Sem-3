
#include<iostream>
using namespace std;
class ArrayADT
{
    int a[100];
    int n;

public:
    void input()
    {
        cout<<"Enter size: ";
        cin>>n;

        if(n<1||n>100)
        {
            cout<<"Invalid size!"<<endl;
            n = 0;
            return;
        }

        cout<<"Enter numbers: ";

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void sort()
    {
        for (int i=0;i<n-1;i++)
        {
            for (int j=0;j<n-1;j++)
            {
                if (a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }

    void display()
    {
        cout<<"Sorted numbers: ";
        for (int i=0;i<n;i++)
        {
            cout<<a[i]<< " ";
        }
        cout << endl;
    }

    void binarySearch(int key)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high)
        {
            mid=(low + high) / 2;

            if (a[mid] == key)
            {
                cout << "Number found at position "
                    << mid + 1 << endl;
                return;
            }
            else if (a[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << "Number not found!" << endl;
    }
};
#Hasnain Qazi
int main()
{
    ArrayADT obj;
    int key;
    obj.input();
    obj.sort();
    obj.display();
    cout << "Enter number to search: ";
    cin >> key;
    obj.binarySearch(key);
    return 0;
}