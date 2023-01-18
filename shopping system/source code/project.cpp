#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
using namespace std;
bool security();
void clearbillinghistory();
void clearreviewhistory();
void viewspecialorders();
void viewbillinghistry();
void viewreviewhistory();
void addAAAgames();
void addAAgames();
void addindiegames();
void addcurrentgen();
void addnextgen();
void addcontroller();
void addheadphone();

class games
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter()
		{
			price=0;
			return price;
		}
		virtual string namegetter()
		{
			name="sdf";
			return name;
		}
		virtual void print()
		{
			
		}
};

class AAgames : public games
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter()
		{
			price=40;
			return price;
		}
		virtual string namegetter()
		{
		string abc;
		ifstream afile("AA.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("AA.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			req=search;
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<search << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		virtual void print()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}
	
};
class AAAgames : public games
{	
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter()
		{
			price=60;
			return price;
		}
		virtual string namegetter()
		{
		string abc;
		ifstream afile("AAA.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("AAA.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			req=search;
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		
		virtual void print()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		
		}
};
class indiegames : public games
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter()
		{
			price=20;
			return price;
		}
		virtual string namegetter()
		{
				string abc;
		ifstream afile("indie.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("indie.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		virtual void print()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}
	};
	

class consoles
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter1()
		{
			price=0;
			return price;
		}
		virtual string namegetter1()
		{
			name="o";
			return name;
		}
		virtual void print1()
		{
			
		}
};
class currentgen : public consoles
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter1()
		{
			price=350;
			return price;
		}
		virtual string namegetter1()
		{
					string abc;
		ifstream afile("currentgen.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("currentgen.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		virtual void print1()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}
	};
class nextgen : public consoles
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter1()
		{
			price=500;
			return price;
		}
		virtual string namegetter1()
		{
		string abc;
		ifstream afile("nextgen.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("nextgen.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		virtual void print1()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}
	};
class accesories
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter2()
		{
			price=0;
			return price;
		}
		virtual string namegetter2()
		{
			name="sdf";
			return name;
		}
		virtual void print2()
		{
			
		}
};
class controllers : public accesories
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter2()
		{
			price=80;
			return price;
		}
		virtual string namegetter2()
		{
					string abc;
		ifstream afile("controller.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("controller.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			req=search;
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		virtual void print2()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}
	};
	class headphones : public accesories
{
	protected:
		int price;
		string name;
	public:
		virtual int pricegetter2()
		{
			price=100;
			return price;
		}
		virtual string namegetter2()
		{
		string abc;
		ifstream afile("headphone.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		string search;
		string req;
		int offset;
		int check;
		string line;
		ifstream file;
		file.open("headphone.txt");
		cout<<"type name from the list that you want to search"<<endl;
		cin.ignore();
		getline(cin,search);
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			req=search;
			 check=1;
			 name=search;
		}
			
		}
		if(check!=1)
		{
		cout<<"Sorry we currently do not have this item in inventory"<<endl;
		cout<<"BUT we will place a special order for you anyways  "<<endl;
		name=search;
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		}
		return name;
		}
		virtual void print2()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}
	};
class specialorder
{
	protected:
		string name;
		int price;
	public:
		 int pricegetter3()
		{
			price=70;
			return price;
		}
		 string namegetter3()
		{
			cout<<"enter the name of game you want to order"<<endl;
			cin.ignore();
			getline(cin,name);
			return name;
		}
		 void print3()
		{
		fstream file("CART.txt",ios :: in|ios :: out| ios :: app);
		file <<name << "\t" << price<<endl;
		file.close();
		fstream afile("specialorder.txt",ios :: in|ios :: out| ios :: app);
		afile <<name << "\t" << price<<endl;
		afile.close();
		fstream mfile("billing.txt",ios :: in|ios :: out| ios :: app);
		mfile<< price<<endl;
		mfile.close();
		}		
	
};
class cart
{
	protected:
		games *obj;
		consoles *obj1;
		accesories *obj2;
		specialorder *obj3;
		int price;
	public:
		cart()
		{
			price=0;
		}
		cart(games *obj)
		{
			this->obj=obj;
		}
		cart(consoles *obj1)
		{
			this->obj1=obj1;
		}
		cart(accesories *obj2)
		{
			this->obj2=obj2;
		}
		cart(specialorder *obj3)
		{
			this->obj3=obj3;
		}
		void output()
		{
			obj->pricegetter();
			obj->namegetter();
			obj->print();
		}
		void output1()
		{
			obj1->pricegetter1();
			obj1->namegetter1();
			obj1->print1();
		}
		void output2()
		{
			obj2->pricegetter2();
			obj2->namegetter2();
			obj2->print2();
		}
		void output3()
		{
			obj3->pricegetter3();
			obj3->namegetter3();
			obj3->print3();
		}
		int billingprice()
		{
		fstream MyFile;  
        MyFile.open("billing.txt", ios::in); 
        int sum = 0;
        string line;
        while (getline(MyFile, line)) 
        {
            sum = sum + stoi(line); // stoi might give an error on old compilers 
        }
        MyFile.close();  
        price=sum;
        return price;
		}
		
};
class billing 
{
	private:
	string accountno;
	cart *obj;
	public:
	billing(cart *obj)
	{
		this->obj=obj;
	}
	string accountgetter()
	{
		cout<<"enter your account number please"<<endl;
		cin.ignore();
		getline(cin,accountno);
		return accountno;
	}
	void display()
	{
		cout<<"your cart has the following items"<<endl<<endl;
		string abc;
		ifstream afile("CART.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
		cout<<"your total payable bill is "<<obj->billingprice()<<"$"<<endl;
	}
	void billinghistory()
	{
		time_t now = time(0);
   		char* date = ctime(&now);
		fstream file("billinghistory.txt",ios :: in|ios :: out| ios :: app);
		file <<obj->billingprice()<<"$"<<"is the payed amount"<<"\t"<<"account number is "<<accountgetter()<<"\t"<<date;
		file.close();
	}
};
class reviews
{
		string stars;
		string name;
		string remarks;
	public:
		string stargetter()
		{
			return stars;
		}
		string namegetter()
		{
			return name;
		}
		string remarksgetter()
		{
			return remarks;
		}
		friend istream& operator >>(istream & input ,reviews &obj );
		friend  void output1(reviews &obj);
					
};

 istream& operator >>(istream & input ,reviews &obj )
{
	cout<<"enter your name"<<endl;
	input>> obj.name;
	cout<<"enter the rating you want to give out of 5" <<endl;
	input>>obj.stars;
	cout<<"enter the  remarks if any"<<endl;
	input>>obj.remarks;
	return input;
}
void output1(reviews &obj)
{
		fstream file("review.txt",ios :: in|ios :: out| ios :: app);
		file <<"NAME: "<<obj.namegetter() << "\t" << "Rating= "<<obj.stargetter()<<"\t"<<"remarks: "<<obj.remarksgetter()<<endl;
		file.close();
}

void passwordupdate()
{
	string password;
	cout<<"enter new password"<<endl;
	cin.ignore();
	getline(cin,password);
	ofstream file;
	file.open("password.txt");
	file<<password;
}
void gamechoice()
{
	int a=0;
	cout<<"what kind of game do you want to buy"<<endl;
	cout<<"enter 1 for AAA titles"<<endl;
	cout<<"enter 2 for AA titles"<<endl;
	cout<<"enter 3 for indie games"<<endl;
	cout<<"enter 0 to exit"<<endl;
	cin>>a;
	system("cls");
	while((a<0)||(a>3))
	{
		cout<<"wrong input try again"<<endl;
	}
	if(a==1)
	{
	games *obj=new AAAgames;
	cart obj3(obj);
	obj3.output();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(a==2)
	{
	games *okj=new AAgames;
	cart okj3(okj);
	okj3.output();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(a==3)
	{
	games *ocj=new indiegames;
	cart ocj3(ocj);
	ocj3.output();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
}
void consolechoice()
{
	int a=0;
	cout<<"what kind of console do you want to buy"<<endl;
	cout<<"enter 1 for currentgen"<<endl;
	cout<<"enter 2 for nextgen"<<endl;
	cout<<"enter 0 to exit"<<endl;
	cin>>a;
	system("cls");
	while((a<0)||(a>2))
	{
		cout<<"wrong input try again"<<endl;
	}
	if(a==1)
	{
	consoles *obj=new currentgen;
	cart obj3(obj);
	obj3.output1();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(a==2)
	{
	consoles *onj=new nextgen;
	cart onj3(onj);
	onj3.output1();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
}
void accesorieschoice()
{
	int a=0;
	cout<<"what kind of accesories do you want to buy"<<endl;
	cout<<"enter 1 for controller"<<endl;
	cout<<"enter 2 for headphone"<<endl;
	cout<<"enter 0 to exit"<<endl;
	cin>>a;
	system("cls");
	while((a<0)||(a>2))
	{
		cout<<"wrong input try again"<<endl;
	}
	if(a==1)
	{
	accesories *obj=new controllers;
	cart obj3(obj);
	obj3.output2();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(a==2)
	{
	accesories *onj=new headphones;
	cart onj3(onj);
	onj3.output2();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
	}
}
void specialorderplacement()
{
	specialorder obj;
	cart obj2(&obj);
	obj2.output3();
	PlaySound(TEXT("cart.wav"),NULL,SND_SYNC);
	system("cls");
}
void erasepreviouscart()
{
	ofstream file("CART.txt");
	ofstream mfile("billing.txt");
}
void shopping()
{
	int x=1;
	while(x!=0)
	{
	
	cout<<"what is your choice"<<endl;
	cout<<"enter 1 for games "<<endl;
	cout<<"enter 2 for consoles"<<endl;
	cout<<"enter 3 for accesories"<<endl;
	cout<<"enter 4 for  pre-orders"<<endl;
	cout<<"enter 0 to exit to checkout"<<endl;
	cin>>x;
	system("cls");
	while((x>4||x<0))
	{
		cout<<"Invalid input Please try again"<<endl;
		cin>>x;
	}
	if(x==1)
	{
	system("cls");
	gamechoice();
	}
	if(x==2)
	{
	consolechoice();	
	}
	if(x==3)
	{
	accesorieschoice();
	}
	if(x==4)
	{
	specialorderplacement();	
	}
}
	cart obj;
	billing obj2(&obj);
	obj2.billinghistory();
	obj2.display();
	PlaySound(TEXT("shopping.wav"),NULL,SND_SYNC);
	erasepreviouscart();
	system("pause");
	system("cls");
	
}
void getreviews()
{
	system("cls");
	reviews obj;
	cin>>obj;
	output1(obj);
}
void clearbillinghistory()
{
	ofstream file("billinghistory.txt");
}
void clearreviewhistory()
{
	ofstream file("review.txt");
}
void viewspecialorder()
{
	    system("cls");
		string abc;
		ifstream afile("specialorder.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
}
void viewbillinghistory()
{
		system("cls");
		string abc;
		ifstream afile("billinghistory.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
}
void viewreviewhistory()
{
		system("cls");
		string abc;
		ifstream afile("review.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
		afile.close();
}
void addAAAgames()
{
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("AAA.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
		
}
void addAAgames()
{		
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("AA.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
}
void addindiegames()
{
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("indie.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
}
void addcurrentgen()
{
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("currentgen.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
}
void addnextgen()
{
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("nextgen.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
}
void addcontroller()
{
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("controller.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
}
void addheadphone()
{
		system("cls");
		string name;
		cout<<"enter the name of the item you want to add"<<endl;
		cin.ignore();
		getline(cin,name);
		fstream mfile("headphone.txt",ios :: in|ios :: out| ios :: app);
		mfile<< endl<< name ;
		mfile.close();
}
bool security()
{

	system("cls"); 
	string password;
	string attempt;
	fstream file;
	file.open("password.txt",ios::in);
	getline(file,password);
	int count=0;
	int checker=0;
	while(checker==0)
	{
		count++;
		cout<<"enter password "<<endl;
		cin.ignore();
		getline(cin,attempt);
		if(attempt==password)
		{checker=1;}
		else if(count>2)
		{
			checker=2;		
		}
		else
		cout<<"wrong !! try again"<<endl;		
		}
		if(checker==1)
		return true;
		else
		return false;
}

void usercontrols()
{
	int x=1;
	while(x!=0)
	{
	
	cout<<"what is your choice"<<endl;
	cout<<"enter 1 for shopping system  "<<endl;
	cout<<"enter 2 to leave a review" <<endl;
	cout<<"enter 0 to exit"<<endl;
	cin>>x;
	system("cls");
	while((x>2||x<0))
	{
		cout<<"Invalid input Please try again"<<endl;
		cin>>x;
	}
	if(x==1)
	{
	shopping();
	}
	if(x==2)
	{
	system("cls");
	getreviews();
	PlaySound(TEXT("reviewgetter.wav"),NULL,SND_SYNC);
	system("cls");	
	}
	}
}
void ownercontrols()
{
	int x=1;
	while(x!=0)
	{
	cout<<"what is your choice"<<endl;
	cout<<"enter 1 to clear billing history"<<endl;
	cout<<"enter 2 to clear review history"<<endl;
	cout<<"enter 3 for review billing history  "<<endl;
	cout<<"enter 4 for review review history  "<<endl;
	cout<<"enter 5 for review special orders to be fulfilled  "<<endl;
	cout<<"enter 6 for add AAA game  "<<endl;
	cout<<"enter 7 for add AA game  "<<endl;
	cout<<"enter 8 for add indie game  "<<endl;
	cout<<"enter 9 for add current gen console  "<<endl;
	cout<<"enter 10 for add next gen console  "<<endl;
	cout<<"enter 11 for add controller   "<<endl;
	cout<<"enter 12 for add headphone  "<<endl;
	cout<<"enter 13 to update password"<<endl;
	cout<<"enter 0 to exit"<<endl;
	cin>>x;
	system("cls");
	while((x>13||x<0))
	{
		cout<<"Invalid input Please try again"<<endl;
		cin>>x;
	}
	if(x==1)
	{
	system("cls");
	clearbillinghistory();
	PlaySound(TEXT("history.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==2)
	{
	system("cls");
	clearreviewhistory();
	PlaySound(TEXT("history.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==3)
	{
	system("cls");
	viewbillinghistory();
	system("pause");
	system("cls");
	}
	if(x==4)
	{
	system("cls");
	viewreviewhistory();
	system("pause");
	system("cls");
	}
	if(x==5)
	{
	system("cls");
	viewspecialorder();
	system("pause");
	system("cls");
	}
	if(x==6)
	{
	system("cls");
	addAAAgames();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==7)
	{
	system("cls");
	addAAgames();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==8)
	{
	system("cls");
	addindiegames();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==9)
	{
	system("cls");
	addcurrentgen();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==10)
	{
	system("cls");
	addnextgen();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==11)
	{
	system("cls");
	addcontroller();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==12)
	{
	system("cls");
	addheadphone();
	PlaySound(TEXT("inventory.wav"),NULL,SND_SYNC);
	system("cls");
	}
	if(x==13)
	{
	system("cls");
	passwordupdate();
	system("cls");
	}
}
}
int main()
{
	cout<<"                      WELOME FELLAS! "<<endl;
	PlaySound(TEXT("intro.wav"),NULL,SND_ASYNC);
	system("pause");
	erasepreviouscart();
	int x=1;
	while(x!=0)
	{
	
	cout<<"what is your choice"<<endl;
	cout<<"enter 1 for shopping system for the user "<<endl;
	cout<<"enter 2 for owner controls" <<endl;
	cout<<"enter 0 to exit"<<endl;
	cin>>x;
	system("cls");
	while((x>2||x<0))
	{
		cout<<"Invalid input Please try again"<<endl;
		cin>>x;
	}
	if(x==1)
	{
	usercontrols();
	}
	if(x==2)
	{
	bool sec = security();
	if(sec)
		ownercontrols();
	else
		{
		cout<<"access denied "<<endl;
		PlaySound(TEXT("passwordwrong.wav"),NULL,SND_SYNC);
		return 0;
		}
	}
	
	}
}