#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;

    cout<<"========== STUDENT MARKS MANAGEMENT SYSTEM =========="<<endl;
    cout<<"\nEnter number of students : ";
    cin>>n;

    int* marks=new int[n];
    int* p=marks;
    cout<<"\nEnter marks for "<<n<<" students :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Student "<<i+1<<": ";
        cin>>*(p+i);
    }

    cout<<"\n--- Student Marks ---"<<endl;
    for(int i=0;i<n;i++){
        cout<<*(p+i);

        if(i<n-1)
            cout<<" ";
    }
    cout<<endl;
    //Hasnain Qazi
    int searchMark;
    cout<<"\nEnter mark to search : ";
    cin>>searchMark;

    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(*(p+i)==searchMark)
        {
            cout<<"Mark found at index "<<i<<endl;
            found=true;
            break;
        }
    }
    if(found==false){
        cout<<"Not Found"<<endl;}

    int highest=*p;
    int lowest=*p;
    int total=0;
    for(int i=0;i<n;i++)
    {
        if(*(p+i)>highest)
            highest=*(p+i);

        if(*(p+i)<lowest)
            lowest=*(p+i);

        total=total+*(p+i);
    }

    double average=(double)total/n;

    cout<<"\n--- Statistics ---"<<endl;
    cout<<"Highest Mark : "<<highest<<endl;
    cout<<"Lowest Mark : "<<lowest<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Average Mark : "<<average<<endl;
    cout<<"\n";
    cout<<"=========================================================="<<endl;
    delete[] marks;
    cout<<"Memory released successfully."<<endl;
    cout<<"=========================================================="<<endl;
    //Hasnain Qazi
    return 0;
}
