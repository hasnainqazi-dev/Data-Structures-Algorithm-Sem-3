#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

int getInt(string message)
{
    string input;
    int value;
    while(true)
    {
        cout<<message;
        getline(cin,input);
        stringstream ss(input);
        if(ss>>value)
        {
            char extra;

            if(!(ss>>extra))
                return value;
        }
        cout<<"Invalid input. Enter a number."<<endl;
    }
}
//Hasnain Qazi
double getDouble(string message)
{
    string input;
    double value;
    while(true)
    {
        cout<<message;
        getline(cin,input);

        stringstream ss(input);

        if(ss>>value)
        {
            char extra;

            if(!(ss>>extra))
                return value;
        }
        cout<<"Invalid input. Enter a valid number."<<endl;
    }
}
string getName(string message)
{
    string name;

    while(true)
    {
        cout<<message;
        getline(cin,name);
        bool valid=false;
        for(int i=0;i<name.length();i++)
        {
            if(isalpha(name[i]))
            {
                valid=true;
                break;
            }
        }
        if(valid)
            return name;
        cout<<"Invalid name. Enter a product name."<<endl;
    }
}
struct Product
{
    int id;
    string name;
    double price;
    int quantity;
    Product* next;
};
class Inventory
{
private:
    Product* head;
public:
    Inventory()
    {
        head=NULL;
    }
    void addProduct(int id,string name,double price,int quantity)
    {
        Product* newNode=new Product;
        newNode->id=id;
        newNode->name=name;
        newNode->price=price;
        newNode->quantity=quantity;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Product* current=head;

            while(current->next!=NULL)
            {
                current=current->next;
            }

            current->next=newNode;
        }
        cout<<"Product added successfully."<<endl;
    }
    void displayProducts()
    {
        if(head==NULL)
        {
            cout<<"No products available."<<endl;
            return;
        }
        Product* current=head;
        while(current!=NULL)
        {
            cout<<"ID : "<<current->id<<endl;
            cout<<"Name : "<<current->name<<endl;
            cout<<"Price : "<<current->price<<endl;
            cout<<"Quantity : "<<current->quantity<<endl;
            cout<<"--------------------"<<endl;

            current=current->next;
        }
    }
    void searchProduct(int id)
    {
        Product* current=head;

        while(current!=NULL)
        {
            if(current->id==id)
            {
                cout<<"Product Found"<<endl;
                cout<<"ID : "<<current->id<<endl;
                cout<<"Name : "<<current->name<<endl;
                cout<<"Price : "<<current->price<<endl;
                cout<<"Quantity : "<<current->quantity<<endl;
                return;
            }

            current=current->next;
        }
        cout<<"Product Not Found"<<endl;
    }
    void updateStock(int id,int quantity)
    {
        Product* current=head;
        while(current!=NULL)
        {
            if(current->id==id)
            {
                current->quantity=quantity;
                cout<<"Stock updated successfully."<<endl;
                return;
            }
            current=current->next;
        }
        cout<<"Product Not Found"<<endl;
    }
    void deleteProduct(int id)
    {
        if(head==NULL)
        {
            cout<<"Inventory is empty."<<endl;
            return;
        }
        if(head->id==id)
        {
            Product* temp=head;
            head=head->next;
            delete temp;

            cout<<"Product deleted successfully."<<endl;
            return;
        }
        Product* current=head;
        while(current->next!=NULL)
        {
            if(current->next->id==id)
            {
                Product* temp=current->next;
                current->next=temp->next;
                delete temp;

                cout<<"Product deleted successfully."<<endl;
                return;
            }
            current=current->next;
        }
        cout<<"Product Not Found"<<endl;
    }
    void lowStock()
    {
        Product* current=head;
        bool found=false;

        while(current!=NULL)
        {
            if(current->quantity<10)
            {
                cout<<"ID : "<<current->id;
                cout<<" Name : "<<current->name;
                cout<<" Quantity : "<<current->quantity<<endl;

                found=true;
            }
            current=current->next;
        }
        if(found==false)
            cout<<"No low-stock products."<<endl;
    }
    ~Inventory()
    {
        while(head!=NULL)
        {
            Product* temp=head;
            head=head->next;
            delete temp;
        }
    }
};
class Stack
{
private:
    int data[20];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    void push(int id)
    {
        if(top==19)
        {
            cout<<"Stack is full."<<endl;
            return;
        }
        top++;
        data[top]=id;
        cout<<"Stock operation added."<<endl;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty."<<endl;
            return;
        }
        cout<<"Removed Product ID : "<<data[top]<<endl;
        top--;
    }
    void display()
    {
        if(top==-1)
        {
            cout<<"Stack is empty."<<endl;
            return;
        }
        cout<<"Stack : ";
        for(int i=top;i>=0;i--)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};
class Queue
{
private:
    int data[20];
    int count;
public:
    Queue()
    {
        count=0;
    }
    void enqueue(int id)
    {
        if(count==20)
        {
            cout<<"Queue is full."<<endl;
            return;
        }
        data[count]=id;
        count++;

        cout<<"Order added successfully."<<endl;
    }
    void dequeue()
    {
        if(count==0)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        cout<<"Processed Order ID : "<<data[0]<<endl;
        for(int i=0;i<count-1;i++)
        {
            data[i]=data[i+1];
        }

        count--;
    }
    void display()
    {
        if(count==0)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        cout<<"Queue : ";
        for(int i=0;i<count;i++)
        {
            cout<<data[i]<<" ";
        }

        cout<<endl;
    }
};

int main()
{
    Inventory inventory;
    Stack stockStack;
    Queue orderQueue;
    Product products[5]={
        {101,"Laptop",120000,8,NULL},
        {102,"Mouse",2500,15,NULL},
        {103,"Keyboard",5000,6,NULL},
        {104,"Monitor",35000,12,NULL},
        {105,"USB",1500,4,NULL}
    };
    int choice=0;
    do
    {
        cout<<"\n============================================="<<endl;
        cout<<"INVENTORY MANAGEMENT SYSTEM"<<endl;
        cout<<"============================================="<<endl;
        cout<<"1. Add Product"<<endl;
        cout<<"2. Display Products"<<endl;
        cout<<"3. Search Product"<<endl;
        cout<<"4. Update Stock"<<endl;
        cout<<"5. Delete Product"<<endl;
        cout<<"6. Display Low - Stock Products"<<endl;
        cout<<"7. Add Stock Operation to Stack"<<endl;
        cout<<"8. Remove Last Stack Operation"<<endl;
        cout<<"9. Display Stack"<<endl;
        cout<<"10. Add Order to Queue"<<endl;
        cout<<"11. Process Order"<<endl;
        cout<<"12. Display Queue"<<endl;
        cout<<"13. Demonstrate Array"<<endl;
        cout<<"14. Exit"<<endl;

        choice=getInt("Enter your choice : ");
        switch(choice)
        {
            case 1:
            {
                int id=getInt("Enter Product ID : ");
                string name=getName("Enter Product Name : ");
                double price=getDouble("Enter Price : ");
                int quantity=getInt("Enter Quantity : ");

                inventory.addProduct(id,name,price,quantity);
                break;
            }
            case 2:
                inventory.displayProducts();
                break;
            case 3:
            {
                int id=getInt("Enter Product ID : ");
                inventory.searchProduct(id);
                break;
            }
            case 4:
            {
                int id=getInt("Enter Product ID : ");
                int quantity=getInt("Enter New Quantity : ");

                inventory.updateStock(id,quantity);
                break;
            }
            case 5:
            {
                int id=getInt("Enter Product ID : ");
                inventory.deleteProduct(id);
                break;
            }
            case 6:
                inventory.lowStock();
                break;
            case 7:
            {
                int id=getInt("Enter Product ID : ");
                stockStack.push(id);
                break;
            }
            case 8:
                stockStack.pop();
                break;
            case 9:
                stockStack.display();
                break;
            case 10:
            {
                int orderId=getInt("Enter Order ID : ");
                orderQueue.enqueue(orderId);
                break;
            }
            case 11:
                orderQueue.dequeue();
                break;

            case 12:
                orderQueue.display();
                break;

            case 13:
                cout<<"--- Array of 5 Products ---"<<endl;

                for(int i=0;i<5;i++)
                {
                    cout<<"ID : "<<products[i].id;
                    cout<<" Name : "<<products[i].name;
                    cout<<" Price : "<<products[i].price;
                    cout<<" Quantity : "<<products[i].quantity<<endl;
                }
                break;
            case 14:
                cout<<"Program Ended."<<endl;
                break;
            default:
                cout<<"Invalid Choice."<<endl;
        }
    }while(choice!=14);
    //Hasnain Qazi
    return 0;
}
