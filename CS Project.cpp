//Shaikha Alhajri 2210003712 | Fouz Alkhaldi 2210003694 | Maria Alghamdi 2210003652 | Yasamen Alhaji 2210003632
#include <iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

	struct Customer
	{
		string Ncustomer;
  		string phone_customer;
  		char country;
	};
	
	struct Driver
	{
		string Dname,DNumber;
		char gender; 
		double Age, YearOS;
	};

char choice,Serv;
int Index=-1 ,resnum,size = 20,index = -1,sito=6, order[6], amount[6], price[6], total[6], ch; 
bool found,ccheck,check;
float bill, paym;
string dr_nm,dr_num;
ofstream outcomsug;

void add_DR(Driver dr[]);
void update_DR(Driver dr[], string dr_N);
void update_nDR(Driver dr[], string num);
void restaurants();
void menu1();
void menu2();
void menu3();


int ordernum; //Declare before the function
double billprice( double totalprice, int tprice[])
{
	for (int i=0; i<ordernum; i++)
	totalprice+=tprice[i];
	return totalprice;
}

int main ()
{
	Driver dr[size];
	string dr_nm,dr_num,name[6],comsug;
	struct Customer A;
	cout<<"-----------------------------------------------------------------------------------\n";
	cout<<"                       Welcome To Food Delivery Store                              \n";
	cout<<"-----------------------------------------------------------------------------------\n";
	cout<<"\t\t      We are here to serve you 24 hours\n";
	cout<<">>Please enter your name: \n";
  	getline(cin,A.Ncustomer);                   
	cout<<">>Please enter you phone number: \n";
  	cin>>A.phone_customer;
  
  	//check num is t or f 
    for (int i=0; i<A.Ncustomer.length(); i++)
		{
        	if( isdigit(A.phone_customer[i]) && A.phone_customer.length()==10 )
  	 
			    check=true; 
            else 
                check=false;
                while(A.phone_customer.length()!=10)
            	{  	
             		cout<<"Phone number is incorrect\nPlaese Enter correct number! \n";
            		cin>>A.phone_customer;
        		}  
		}
            
   //check country 
   
    country:
    cout<<"Please Choose your country: \n1)Jubail\n2)Dammam\n3)Khobar\n";
    cin>>A.country;
    
    if(A.country=='1')
    {
    	cout<<">>Wellcome "<<A.Ncustomer<<"\n";
    	Help:
		cout<<">>Please choose one of our services\n";
		cout<<"1)I want to order\n2)I want to order to my friend\n3)I would like to apply for a job\n4)Exit\n";
		cin>>Serv;
		
		if (Serv=='1'||Serv=='2')
		{
			Driver Driver1,Driver2,Driver3,Driver4;
	
			Driver1.Dname="SAMY";
			Driver1.DNumber="9452761845";
			Driver1.gender='M';
			Driver1.Age=25;
			Driver1.YearOS=2;
	
			Driver2.Dname="AMAL";
			Driver2.DNumber="8561039284";
			Driver2.gender='F';
			Driver2.Age=23;
			Driver2.YearOS=1;
	
			Driver3.Dname="RAMY";
			Driver3.DNumber="0037251943";
			Driver3.gender='M';
			Driver3.Age=30;
			Driver3.YearOS=5;
	
			Driver4.Dname="SAMA";
			Driver4.DNumber="6672109432";
			Driver4.gender='F';
			Driver4.Age=27;
			Driver4.YearOS=8;
	
	
			cout<<"Welcome, we have a number of drivers, please choose one of them: \n\n";

			cout<<"1) Driver 1 :\nRepresentative Name : "<<Driver1.Dname<<"\nNumber: "<<Driver1.DNumber<<"\nGender: "<<Driver1.gender<<"\nRepresentative age: "<<Driver1.Age<<"\nYears of service: "<<Driver1.YearOS<<"\n\n";
			cout<<"2) Driver 2 :\nRepresentative Name : "<<Driver2.Dname<<"\nNumber: "<<Driver2.DNumber<<"\nGender: "<<Driver2.gender<<"\nRepresentative age: "<<Driver2.Age<<"\nYears of service: "<<Driver2.YearOS<<"\n\n";
			cout<<"3) Driver 3 :\nRepresentative Name : "<<Driver3.Dname<<"\nNumber: "<<Driver3.DNumber<<"\nGender: "<<Driver3.gender<<"\nRepresentative age: "<<Driver3.Age<<"\nYears of service: "<<Driver3.YearOS<<"\n\n";
			cout<<"4) Driver 4 :\nRepresentative Name : "<<Driver4.Dname<<"\nNumber: "<<Driver4.DNumber<<"\nGender: "<<Driver4.gender<<"\nRepresentative age: "<<Driver4.Age<<"\nYears of service: "<<Driver4.YearOS<<"\n\n";
			
			choices: 
			cout<<">>your choice: \n";
			cin>>choice;
			cout<<"\n";
			switch (choice)
			{
				case '1':
					cout<<"Hello My Name is: "<<Driver1.Dname<<" Please Choose the restaurant you want\n";
					
					break;
					
			
				case '2':
					cout<<"Hello My Name is: "<<Driver2.Dname<<" Please Choose the restaurant you want\n";
				
					break;
			
				case '3':
					cout<<"Hello My Name is: "<<Driver3.Dname<<" Please Choose the restaurant you want\n";
				
					break;
			
				case '4':
					cout<<"Hello My Name is: "<<Driver4.Dname<<" Please Choose the restaurant you want\n";
				
					break;
					
				default:
					cout<<">>The choice is incorrect\nPlaese Enter correct choice\n";
					goto choices;	
			}
			
	restaurants();		
	do{
    cout<<"Enter the restaurant number: ";                                
    cin>>resnum;
    switch(resnum)
	{
    case 1:
    	ccheck=true;
    	menu1();
    	cout<<"How many types of menu do you want to order? ";
    	cin>>ordernum;
    	if (ordernum>0 && ordernum<=6)
    		{
     			for (int i=0; i<ordernum; i++)
     				{
     					 cout<<"Enter your #"<<i+1<<" choice: ";
     					 cin>>order[i]; 
     					 cout<<"Enter Amount: ";
     					 cin>>amount[i];
     					if (order[i]==1)
							{
      					 	name[i]= "Sichuan meat";
      						price[i]= 35;
      					 	total[i]= price[i]*amount[i];
      						}
      					else if(order[i]==2)
						  {
      						name[i]= "Kung pao chicken";
       						price[i]= 24;
      						total[i]= price[i]*amount[i];
      					  }
      					else if(order[i]==3)
						  {
      						 name[i]= "Canton Shrimp";
      						 price[i]= 35;
      						 total[i]= price[i]*amount[i];
      					  }
      					else if(order[i]==4)
						  {
       						name[i]= "Noodles";
      						price[i]= 15;
       						total[i]= price[i]*amount[i];
      					  }
      					else if(order[i]==5)
						  {
       						name[i]= "Pepsi";
       						price[i]= 4;
       						total[i]= price[i]*amount[i];
      					  }
      					else if(order[i]==6)
						  {
       						name[i]= "Water";
       						price[i]= 2;
       						total[i]= price[i]*amount[i];
      						}
      					bill= billprice(bill, total);
      		
     				}			
    				system ("cls");
    				 menu1();
    				 cout<<endl<<"Your Choice is: "<<endl;
    				 for (int i=0; i<ordernum; i++)
					 {
     				 	cout<<" "<<amount[i]<<" portion"<<" "<<name[i]<<endl;
     				 	cout<<"Price / Portion : "<<price[i]<<endl;
     				 	cout<<"Total Price: "<<name[i]<<" , "<<total[i]<<endl;
    					 }
    					 cout<<"Bill: "<<bill<<" SR"<<endl;
    					 cout<<"Enter payment method: "<<endl;
    					 cout<<"1. Apple pay \t2. STC pay \t3. mada card"<<endl;
    					 cin>>paym;
    					 cout<<"Thank you for choosing our resturant :D"<<endl;
    		} 
    	
    	break;
    
    
    case 2:
    	ccheck=true;
    	menu2();
    	cout<<"How many types of menu do you want to order? ";
    	cin>>ordernum;
    	if (ordernum>0 && ordernum<=6)
    		{
    			 for (int i=0; i<ordernum; i++)
    				 {
						cout<<"Enter your #"<<i+1<<" choice: ";
  					    cin>>order[i];
   					    cout<<"Enter Amount: ";
   					    cin>>amount[i];
      					if (order[i]==1)
						{
      					 name[i]= "I Burger";
      					 price[i]= 26;
      					 total[i]= price[i]*amount[i];}
      					else if(order[i]==2)
						{
       						name[i]= "Dynamite Shrimp";
       						price[i]= 30;
       						total[i]= price[i]*amount[i];}
     					else if(order[i]==3)
						{
       					 name[i]= "New York Buffalo";
      					 price[i]= 22;
      					 total[i]= price[i]*amount[i];}
      					else if(order[i]==4)
						  {
       					 name[i]= "Regular Fries";
       					 price[i]= 9;
       					 total[i]= price[i]*amount[i];}
      					else if(order[i]==5)
						  {
       					name[i]= "CocaCola";
       					price[i]= 5;
       					total[i]= price[i]*amount[i];}
      					else if(order[i]==6)
						  {
       					name[i]= "Sprite";
       					price[i]= 5;
      					 total[i]= price[i]*amount[i];}
      					bill= billprice(bill, total);
     				 }
     				 
     			system ("cls");
     			menu2();
     			cout<<endl<<"Your Choice is: "<<endl;
     			for (int i=0; i<ordernum; i++)
				 {
     			cout<<" "<<amount[i]<<" portion"<<" "<<name[i]<<endl;
      			cout<<"Price / Portion : "<<price[i]<<endl;
      			cout<<"Total Price: "<<name[i]<<" , "<<total[i]<<endl;
     			}
     			cout<<"Bill: "<<bill<<" SR"<<endl;
     			cout<<"Enter payment method: "<<endl;
     			cout<<"1. Apple pay \t2. STC pay \t3. mada card"<<endl;
     			cin>>paym;
     			cout<<"Thank you for choosing our resturant :D"<<endl; 
    		}
     	break;
     	
     	
    case 3:
    	ccheck=true;
    	menu3();
    	cout<<"How many types of menu do you want to order? ";
    	cin>>ordernum;
    	if (ordernum>0 && ordernum<=6)
    	{
     		for (int i=0; i<ordernum; i++)
     		{
      			cout<<"Enter your #"<<i+1<<" choice: ";
      			cin>>order[i];
      			cout<<"Enter Amount: ";
      			cin>>amount[i];
      			if (order[i]==1){
       				name[i]= "Chicken Biryani";
       				price[i]= 34;
       				total[i]= price[i]*amount[i];}
      			else if(order[i]==2){
       				name[i]= "Meat Biryani";
       				price[i]= 37;
       				total[i]= price[i]*amount[i];}
      			else if(order[i]==3){
      				name[i]= "Fish Biryani";
       				price[i]= 40;
       				total[i]= price[i]*amount[i];}
      			else if(order[i]==4){
       				name[i]= "Shrimp Masala";
       				price[i]= 38;
       				total[i]= price[i]*amount[i];}
      			else if(order[i]==5){
       				name[i]= "CocaCola";
       				price[i]= 5;
       				total[i]= price[i]*amount[i];}
      			else if(order[i]==6){
				  	name[i]= "Miranda";
       				price[i]= 5;
       				total[i]= price[i]*amount[i];}
      				bill= billprice(bill, total);
			}

    		 system ("cls");
    		 menu3();
    		 cout<<endl<<"Your Choice is: "<<endl;
    		 for (int i=0; i<ordernum; i++){
     		 cout<<" "<<amount[i]<<" portion"<<" "<<name[i]<<endl;
     		 cout<<"Price / Portion : "<<price[i]<<endl;
      		 cout<<"Total Price: "<<name[i]<<" , "<<total[i]<<endl;}
     		 cout<<"Bill: "<<bill<<" SR"<<endl;
     		 cout<<"Enter payment method: "<<endl;
     		 cout<<"1. Apple pay \t2. STC pay \t3. mada card"<<endl;
     		 cin>>paym;
     		 cout<<"Thank you for choosing our resturant :D"<<endl;  
    	}
    	
    	break;
    	
   	default:
    ccheck=false;
    cout<<"Wrong choice!"<<endl;
    cout<<"If you want to order again, enter any number and enter zero to end."<<endl;
    cin>>ch;
   	break;
	} 
}
	while (ch!=0);
	goto Help;			
		}
		else if(Serv=='3')
			{
				cout<<">>Welcome as a new employee,,\nplease fill in the details:\n";
				add_DR(dr);
				dr[index].Dname=A.Ncustomer;
				cout<<">>You are now a new driver, please check your information if you want to modify it for the last time\n";
				cout <<">>Your Name: "<<dr[index].Dname<<endl;
				cout <<">>Your Number: "<<dr[index].DNumber<<endl;
				cout <<">>Your Age: "<<dr[index].Age<<endl;
				cout <<">>Your Gender (F or M): "<<dr[index].gender<<endl;
				cout<<">>Year of Service: "<<dr[index].YearOS<<endl;
				
			
				cout<<"If you want to Appdate your information Please click 'Y'\n";
				cout<<"If all your information is correct, click'N' to continue\n ";
				cin>>choice; 
				if(choice=='Y'||choice=='y')
				{
					
					choiceY:
					cout<<"What do you want to update? \n";
					cout<<"1)My Name\n2)My Number\n";
					cin>>choice;
					switch (choice)
					{
					case '1':
						if (index >= 0)
							{
								cout << "Enter Your Name to update: ";
								cin >> dr_nm;
								update_DR(dr, dr_nm);
								
							}
						else
							cout<< "There are no Driver in this class. "<< "You can't update\n";
					break;
					
					case '2':
						if (index >= 0)
							{
								cout << "Enter Your Number to update: ";
								cin >> dr_num;
								update_nDR(dr, dr_num);	
							}
						else
							cout<< "There are no Driver in this class. "<< "You can't update\n";
					break;
					
					default: 
						cout<<">>The choice is incorrect\nPlaese Enter correct choice\n";
						goto choiceY;	
					}	
				}
				else if(choice=='N'||choice=='n')
				{
					cout<<"\n*We are pleased to have you as one of our employees*\n";
				}
				else 
					cout<<">>The choice is incorrect\n";
			goto Help;	
			}
		else if(Serv=='4')
		{
			cout<<"Thank you (:\n";
		}
		else
			{
				cout<<">>The value entered is wrong\nPlaese Enter correct value! \n";
				goto Help;	
			}
			
	}
	
    else if (A.country=='2'||A.country=='3')
    {
    	cout<<">>Sorry, we cannot serve you because the location is out of coverage";	
	}
    else 
    {
    	cout<<">>The value entered is wrong\nPlaese Enter correct value! \n";
    	goto country;
	}
	
	
	cout<<"------------------------------------------------------ \n";
	cout<<"           complaints and suggestions: \n";
	cout<<"------------------------------------------------------ \n";
	cout<<">>Please Open File (outcomsug.txt) to write complaints and suggestions(:"; 
    outcomsug.open("outcomsug.txt",ios::out);
			if(outcomsug.is_open()==true||outcomsug.is_open())
			{
			outcomsug<<"Your complaints and suggestions: \n";
    		outcomsug<<comsug;	
			}
			
			
}

//Functions
//Function(1)
void add_DR(Driver dr[])
{
			Driver DriverNo;
			cout << "Hello \n";
			index++;
			cout << "Enter Your Number: ";
			cin >> dr[index].DNumber;
			cout << "Enter your Age: ";
			cin >> dr[index].Age;
			cout << "Enter Your Gender (F or M): ";
			cin >> dr[index].gender;
			dr[index].YearOS=0;
			cout << "\n**You have been added successfully**\n";			
}
//Function(2)
void update_DR(Driver dr[], string nm)
{
	found = true;
	for (int i = 0 ; i <= index ; i++)
		{
			if(nm == dr[i].Dname)
				{
					cout << "Enter new name: ";
					cin >> dr[i].Dname;
					cout << "**Driver name updated**\n";
					found = true;
					break;
				}
		}
	if (!found)
		cout << " not found\n";
}
//Function(3)
void update_nDR(Driver dr[], string num)
{
	found = true;
	
	for (int i = 0 ; i <= index ; i++)
	
		{
			if(num == dr[i].DNumber)
				{
					cout << "Enter new number: ";
					cin >> dr[i].DNumber;
					cout << "**Driver number updated**\n";
					found = true;
					break;
				}
		}
	if (!found)
		cout << " not found\n";
}
//Function(4)
void restaurants(){
 
 cout<<"Available restaurants: "<<endl;
 cout<<"1. Canton (for Asian and seafood)"<<endl;
 cout<<"2. Double i (for American food)"<<endl;
 cout<<"3. Curry'n Hurry (for Indian food)"<<endl;
}
//Function(5)
void menu1(){
 cout<<endl<<"\t\t Canton Resturant \t\t"<<endl;
 cout<<"_"<<endl;
 cout<<"Menu  \t\t          Price  \t  Calories  "<<endl;
 cout<<"1. Sichuan meat  \t  35SR  \t  952cal  "<<endl;
 cout<<"2. Kung pao chicken  \t  24SR  \t  897cal  "<<endl;
 cout<<"3. Canton Shrimp  \t  35SR  \t  899cal  "<<endl;
 cout<<"4. Noodles  \t\t  15SR  \t  435cal  "<<endl;
 cout<<"5. Pepsi  \t\t   4SR  \t  145cal  "<<endl;
 cout<<"6. Water  \t\t   2SR  \t  0cal  "<<endl;
 cout<<"_"<<endl;
}
//Function(6)
void menu2(){
 cout<<endl<<"\t\t Double i Resturant \t\t"<<endl;
 cout<<"_"<<endl;
 cout<<"Menu  \t\t          Price  \t  Calories  "<<endl;
 cout<<"1. I Burger  \t\t  26SR  \t  658cal  "<<endl;
 cout<<"2. Dynamite Shrimp  \t  30SR  \t  364cal  "<<endl;
 cout<<"3. New York Buffalo  \t  22SR  \t  532cal  "<<endl;
 cout<<"4. Regular Fries  \t   9SR  \t  468cal  "<<endl;
 cout<<"5. CocaCola  \t\t   5SR  \t  148cal  "<<endl;
 cout<<"6. Sprite  \t\t   5SR  \t  46cal  "<<endl;
 cout<<"_"<<endl; 
}

//Function(7)
void menu3(){
 cout<<endl<<"\t\t Curry'n Hurry Resturant \t\t"<<endl;
 cout<<"_"<<endl;
 cout<<"Menu  \t\t          Price  \t  Calories  "<<endl;
 cout<<"1. Chicken Biryani  \t  34SR  \t  1103cal  "<<endl;
 cout<<"2. Meat Biryani  \t  37SR  \t  1127cal  "<<endl;
 cout<<"3. Fish Biryani  \t  40SR  \t  1238cal  "<<endl;
 cout<<"4. Shrimp Masala  \t  38SR  \t  1227cal  "<<endl;
 cout<<"5. CocaCola \t\t   5SR  \t  148cal  "<<endl;
 cout<<"6. Miranda \t\t   5SR  \t  158cal  "<<endl;
 cout<<"_"<<endl;
}

    