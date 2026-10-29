#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string url;
    Node* next;
    Node(string u)
    {
        url=u;
        next=NULL;
    }
};
//Hasnain Qazi
class BrowserHistory{
private:
    Node* head;
    int count;
public:
    BrowserHistory()
    {
        head=NULL;
        count=0;
    }
    ~BrowserHistory()
    {
        while (head!=NULL)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        cout<<"All memory released successfully."<<endl;
        cout<<"================================================"<<endl;
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    void visit(string url)
    {
        Node* newNode=new Node(url);
        newNode->next=head;
        head=newNode;
        count++;
        cout<<"Visited: "<<url<<endl;
    }
    void back()
    {
        if (isEmpty())
        {
            cout<<"No pages in history."<<endl;
            return;
        }
        Node* temp = head;
        cout << "\nBack button pressed. Removed: "<<temp->url;
        head=head->next;
        delete temp;
        count--;
    }
    string currentPage()
    {
        if (isEmpty())
            return "No pages";

        return head->url;
    }
    int size()
    {
        return count;
    }
    void display()
    {
        cout<<"\n\n--- History (Top to Bottom) ---"<<endl;

        Node* current=head;

        while(current!=NULL)
        {
            cout<<current->url<<endl;
            current=current->next;
        }
    }
};

int main(){
    cout<<"========== BROWSER HISTORY MANAGEMENT ==========\n"<<endl;

    BrowserHistory history;

    history.visit("google.com");
    history.visit("youtube.com");
    history.visit("github.com");
    history.visit("stackoverflow.com");

    history.display();
    history.back();
    history.display();

    cout<<"\nCurrent Page: "<< history.currentPage()<<endl;
    cout<<"History Size: "<< history.size()<<endl;
    while (!history.isEmpty())
    {
        history.back();
    }
    if (history.isEmpty())
    {
        cout<<"\n\nHistory is now empty.\n"<<endl;
    }
    //Hasnain Qazi
    cout<<"================================================"<<endl;
    return 0;
}
