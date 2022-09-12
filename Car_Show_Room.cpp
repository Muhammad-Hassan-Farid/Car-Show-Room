#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

struct Car
{
    string buyer_name;
    string cnic;
    string mobile_number;
    string car_name;
    string car_Model;
    string price;
    Car *next;
};
Car *first=NULL; //pointers
Car *last=NULL;


void display_Cars()
{ 
    cout<<"      Cars                   "<<"\t"<<"Model  "<<"\t"<<" Prices"<<endl<<endl;
    cout<<"1:  Honda Vizel              "<<"\t"<<"2010   "<<"\t"<<" 12,200,000"<<endl;
    cout<<"2:  Toyota Land Cruiser      "<<"\t"<<"2015   "<<"\t"<<" 22,000,000"<<endl;
    cout<<"3:  Toyota Mark X 250G       "<<"\t"<<"2019   "<<"\t"<<" 2,500,000"<<endl;
    cout<<"4:  Toyota 1.8 Grande X      "<<"\t"<<"2022   "<<"\t"<<" 4,649,000"<<endl;
    cout<<"5:  Toyota 1.8 Grande        "<<"\t"<<"2021   "<<"\t"<<" 4,450,000"<<endl;
    cout<<"6:  Marcides c63 AMG         "<<"\t"<<"2016   "<<"\t"<<" 11,500,000"<<endl;
    cout<<"7:  Mazda RX8                "<<"\t"<<"2004   "<<"\t"<<" 1,700,000"<<endl;
    cout<<"8:  GT Mustang               "<<"\t"<<"1999   "<<"\t"<<" 3,800,000"<<endl;
    cout<<"9:  Lexus 570                "<<"\t"<<"2007   "<<"\t"<<" 98,000,000"<<endl;
    cout<<"10: KIA sportage             "<<"\t"<<"2021   "<<"\t"<<" 5,300,000"<<endl;
    cout<<"11: MG HS                    "<<"\t"<<"2021   "<<"\t"<<" 8,499,000"<<endl;
    cout<<"12: Hyundai Sonata           "<<"\t"<<"2022   "<<"\t"<<" 7,299,000"<<endl;

}

void InsertDetails(string buyerName, string buyerCnic, string number, string c_name, string Model, string c_price)
{
    
     if( first == NULL && last == NULL )
     {
        Car *curr=new Car();
        curr->buyer_name=buyerName;
        curr->cnic=buyerCnic;
        curr->mobile_number=number;
        curr->car_name=c_name;
        curr->car_Model=Model;
        curr->price=c_price;
        curr->next=NULL;
        first=curr;
        last=curr;
    }
    else
    {
        Car *curr=new Car();
        curr->buyer_name=buyerName;
        curr->cnic=buyerCnic;
        curr->mobile_number=number;
        curr->car_name=c_name;
        curr->car_Model=Model;
        curr->price=c_price;
        curr->next=NULL;
        last->next=curr;
        last=curr;

    }

}



bool Search_Buyer_Details()
{
    cin.ignore();
    
    Car *curr=first;
    string Name;
    
    cout<<"Enter the Name of Car purchaser: ";
    getline(cin,Name);
    while(curr!=NULL)
    {
    if(curr->buyer_name==Name)
    {
        cout<<"Buyer Name:           "<<curr->buyer_name<<endl;
        cout<<"Buyer CNIC:           "<<curr->cnic<<endl;
        cout<<"Buyer Mobile Number:  "<<curr->mobile_number<<endl;
        cout<<"Car Name:             "<<curr->car_name<<endl;
        cout<<"Car Model:            "<<curr->car_Model<<endl;
        cout<<"Car Price:            "<<curr->price<<endl;

        return true;
    }
    curr=curr->next;
    }
    return false;
}



bool Delete_Car_Details()
{
    cin.ignore();
    // Car *curr=first;
    string name;
    bool flag = false;
    Car* temp = first;
    Car* prev ;
    
    
    cout<<"Enter the Name for deletion: ";
    getline(cin,name);


    //For first node deleting
    if (temp == first && temp->buyer_name == name) 
    {   
        first = first->next;
        temp->next = NULL;
		delete temp;

        return true;
	}
    //For Mid Node deleting
    while(temp != last)
    {
        if(name == temp->buyer_name)
        {
            prev->next = temp->next;
           delete temp;
           return true;
        }
        prev = temp;
        temp = temp->next;
    }
    // For Last Node deleting
    while(temp != NULL)
    {
        if(name == temp->buyer_name)
        {
            prev->next = temp->next;
           delete temp;
           last = prev;
           return true;
        }
        prev = temp;
        temp = temp->next;
    }

    return false;

}

void display_Car_details()
{
    
    system("cls");
    Car *curr=first;
    cout<<"\n\n\t\t....Buyers Details...."<<endl<<endl;
    while(curr!=NULL)
    {    
        cout<<"Buyer Name:           "<<curr->buyer_name<<endl;
        cout<<"Buyer CNIC:           "<<curr->cnic<<endl;
        cout<<"Buyer Mobile Number:  "<<curr->mobile_number<<endl;
        cout<<"Car Name:             "<<curr->car_name<<endl;
        cout<<"Car Model:            "<<curr->car_Model<<endl;
        cout<<"Car Price:            "<<curr->price<<endl;
        curr=curr->next;
        cout<<endl;

    }
    
    getche();
}


void display()
{
    cout<<"1: Enter Data "<<endl;
    cout<<"2: Display All Data"<<endl;
    cout<<"3: Searching Data"<<endl;
    cout<<"4: Deleting Data"<<endl;
    cout<<"5: Exit"<<endl;
}


int main()
{
    p:
    system("cls");
    string C_name,cnic,mobile,car_name,car_Model,c_price;
    
    char a;
    char ch;
    display_Cars();
    cout<<endl;
    display();
    cout<<"\nEnter your Choice:";
    cin>>a;
    cout<<endl;
    
    switch (a)
    {
    case '1':
        {
            do
            {
                cin.ignore();
                cout<<"Enter the Buyer Name: ";
                getline(cin,C_name);
                cout<<"Enter the Cnic: ";
                getline(cin,cnic);
                cout<<"Enter Mobile Number: ";
                getline(cin,mobile);
                cout<<"Enter the Car Name: ";
                getline(cin,car_name);
                cout<<"Enter the Car Model: ";
                getline(cin,car_Model);
                cout<<"Enter the price of Car: ";
                getline(cin,c_price);
                InsertDetails(C_name,cnic,mobile,car_name,car_Model,c_price);
                

                cout<<"Want to Enter more details...(Y/N)";
                cin>>ch;
                cout<<endl<<endl;

            } 
            while (ch=='y' || ch=='Y');
            break;
        }

        case '2':
        {
            if(first==NULL)
            {
                cout<<"\n\n\t\tNo Data Available....."<<endl;
                getche();
            }
            else
            {
                display_Car_details();
              
            }
            break;
        }
        case '3':
        {
            
            do
            {
            if(first==NULL)
            {
            cout<<"\n\n\t\tNo Data Available....."<<endl;
            getche();
            break;
            }
            else
            {

            if(Search_Buyer_Details())
            {
                cout<<"\n\nWant to see more details...(Y/N): ";
                cin>>ch;
            }
            else
            {
                cout<<"\n\n\t\tNot Found....."<<endl;
                getche();
                break;
            }
            
            }
            }
            while (ch=='y' || ch=='Y');
            break;

        }
        
        case '4':
        {
            
            do
            {
                if(first==NULL)
                {
                cout<<"\n\n\t\tNo Data Available....."<<endl;
                getche();
                break;
                }
                else
                {
                    if(Delete_Car_Details())
                    {
                        cout<<"\n\nWant to Delete more details...(Y/N): ";
                        cin>>ch;
                    }
                    else
                    {
                        cout<<"\n\n\t\tNot Found....."<<endl;
                        getche();
                    
                    }
                
            }
            }
            while (ch=='y' || ch=='Y');
            break;

        }
        case '5':
        {
            cout<<"\n\n\t\tThank You....";
            exit(0);
        }

        default:
        {
            cout<<"You Entered a wrong number....try Again"<<endl;
            getche();
            break;
        }
    }
       
    goto p;


getch();
return 0;
}