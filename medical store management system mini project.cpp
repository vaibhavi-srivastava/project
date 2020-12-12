//header files
#include<iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std; 

//base class 
class medicine  
{
	public:
		void getorder();    //for taking order
		void orderlist();   //displaying reciept
		void modify();      //modifying order(make changes)
		void exit();        //exiting
		medicinetype();     //constructor
};


struct node                //constructing node
{    
     string your_name;
     int rec_no;
	 string date;
	 int no[5];
	 int x;
	 int menu[5];
	 double price[5];
	 string medicine_name[5]={"Paracetamol","Dolo","Thyronorm","Vitamin C","Nutrilite daily"};
	 double medicine_price[5]={2.00,3.00,1.00,4.00,5.00};
     double total;
     node *prev;
	 node *next;
	 node *link; 

}*c, *temp;                //pointer declaration 

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

//main function 
int main() 
{
	 medicine m;
	 int main_menu;
	 cout<<"\t\t\t\t\t\t\tMEDICAL STORE MANAGEMENT SYSTEM"<<endl;
	 cout<<endl;
	 do
	 {
	 cout<<"1. Take medicine order\n";
	 cout<<"2. Get the receipt\n";
	 cout<<"3. Changes in order{Modify}\n";
	 cout<<"4. Exit\n";
	 cout<<"Please Enter your choice (from 1 to 4):";
	 cin>>main_menu;
	
	 switch(main_menu)
	 {
	 	//for taking medicine order
	 case 1:
		
	 	{
	 	m.getorder();                  //function order
	 	break;
	 	}                              // end of case1
	 	
		
		// for reciept
	 case 2:
	 	{
	 		m.orderlist();             //function orderlist
	 		system("PAUSE");
	 		break;
		}                              //end of case2
		 
		 //for making changes 
	 case 3:
	 	{ 
	 		m.modify();               //function modify
	 		system("PAUSE");
	 		break;                   
		}                             //end of case 3
		 
		 
		//for exit
	 case 4:
	 	{
	 		m.exit();                 //function exit 	 		
			goto a;
	 		break;
		}                             //end of class 4
	
	 default :
	 	{
	 		cout<<"something went wrong try again please"<<endl;
	 		break;
	 		
		}                             //end default
	 		
	 }                                //end switch
}                                     //end do


while(main_menu!=4); 
a:                                    //goto
cout<<"THANK YOU"<<endl;
system("PAUSE");
	return 0;
		
}                                    //end main function

//function to take order
void medicine::getorder() 
{
	int i;
	int choice, quantity, price,none;
	cout<<"\n";
	cout<<"DETAILS:"<<endl;
	node*temp;
	temp=new node;
				cout<<"S.NO"<<"     \t\tMEDICINE NAME"<<"            PRICE(Rs)"<<endl;
				cout<<"---------------------------------------------------------------------------"<<endl;
                cout<<"01"<<"\t\t"<<"     Paracetamol"<<"		    Rs 3.00"<<endl;
                cout<<"02"<<"\t\t"<<"     Dolo"<<"		            Rs 4.00"<<endl;
                cout<<"03"<<"\t\t"<<"     Thyronorm"<<"		        Rs 2.00"<<endl;
                cout<<"04"<<"\t\t"<<"     Vitamin C"<<"		        Rs 5.00"<<endl;
                cout<<"05"<<"\t\t"<<"     Nutrilite daily"<<"	 	Rs 1.00"<<endl;
                cout<<" "<<endl;
    temp= new node;
    cout<<"RECIEPT.NO"<<endl;
    cin>>temp->rec_no;
    cout<<"CUSTOMER NAME"<<endl;
    cin>>temp->your_name;
    cout<<"DATE"<<endl;
	cin>>temp->date;
	cout << "How many medicine you want:"<< endl;
	cout<<"(NOTE:you can take maximum 5) \n";
	cout << "  " ;
	cin>>temp->x;
	if(temp->x>5)
	{
		cout<<"Maximum limit reached"<<endl;
		system("PAUSE");
	}
	else
	{
		for(i=0;i<temp->x;i++)
		{
		
		cout << "S.N0: "<<endl;
		cin>> temp->menu[i];
        cout<< "MEDICINE NAME: " <<temp->medicine_name[temp->menu[i]-1]<<endl;
        cout << "QUANTITY: "<<endl;
        cin >> temp->no[i];
        temp->price[i] = temp->no[i] * temp->medicine_price[temp->menu[i]-1];
        cout << "YOU HAVE TO PAY: " << temp->price[i]<<" Rs"<<endl;
        cout << "ORDER TAKEN"<<endl;
        cout << "RETURN TO MAIN MENU"<<endl;
        system("PAUSE");
        cout<<"\n";
                      
	}
	temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
}
	} //end of getting order
	
//for displaying receipt
void medicine::orderlist()
	{
		int i,l,k;
		bool get;
		node*temp;
		temp=start_ptr;
		get=false;
		cout<<"Enter the Reciept Number To Get The Reciept\n";
	cin>>l;
	cout<<"\n";
	cout <<"\t\t\t\tFINAL DETAILS:\n"; 
    if(temp == NULL) //Invalid receipt code
	{
		cout << "NOT FOUND\n\n\n";
	}
	while(temp !=NULL && !get)
	{
		if (temp->rec_no==l)
		{
			get = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (get)//print the receipt
        {
        system("cls");
        
		cout <<"Reciept Number : "<<temp->rec_no;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->your_name<<endl;
				
		cout<<"Date : "<<temp->date<<endl;
		cout<<"\n";
				
		
			
		cout << "Medicine Name\t"<<"Quantity\t"<<"Total Price " << endl;
		
		for (i=0;i<temp->x;i++)
		{
			
			cout<<temp->medicine_name[temp->menu[i]-1]<<"\t";
			cout<<temp->no[i] <<"\t\t";
			cout<< temp->price[i]<<" Rs"<<endl;
		
		}
		
		temp->total = temp->price[0]+temp->price[1]+temp->price[2]+temp->price[3]+temp->price[4]+temp->price[5]+temp->price[6]+temp->price[7]
						+temp->price[8]+temp->price[9];
						cout<<"\n";
		cout<<"Your total bill is  : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> k;
        if(k==temp->total)
        {
		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done Successfully \nThank You\n";
		cout<<"\n";
		
		}
		else
		{
			cout<<"PAYMENT FAILED"<<endl;
			cout<<"RETURN TO MAIN MENU"<<endl;
		}
} 

}
}	//End function order_list

//for modifying order
void medicine::modify()		
{
 system("cls");
 int i, new_rec;
 bool get;
 get = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>new_rec;
 if (temp==NULL && new_rec==0)
 {
    cout<<"INVALID"<<endl;
 }

 else
 {
 	while(temp !=NULL && !get)
	{
		if (temp->rec_no==new_rec)
		{
			get = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (get)
    {
    	cout<<"\n";
    system("cls");
	cout << "Change  Reciept Number: "<<endl;
    cin >> temp->rec_no;
	cout<< "Change Customer Name: "<<endl;
	cin>> temp->your_name;
	cout<<"Change Date : "<<endl;
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"(Maximum is 5 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter S.No to Change: "<<endl;
		cin>> temp->menu[i];
        cout<< "Changed Medicine Name: " <<temp->medicine_name[temp->menu[i]-1]<<endl;
        cout << "How many New medicine do you want: "<<endl;
        cin >> temp->no[i];
        temp->price[i] = temp->no[i] * temp->medicine_price[temp->menu[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->price[i]<<" Rs"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"RECORD MODIFIED SUCCESSFULLY....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->rec_no != new_rec)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}//End modify function


	
//for exiting
void medicine::exit() 
{
	system("cls");
	cout<<"\nEXCITING..\n"<<endl;
}//end function exit


