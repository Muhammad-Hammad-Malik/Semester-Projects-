#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
void userinfo();
void easyrecordset(int r);
void easyrecorddisplay();
void hardrecordset(int r);
void hardrecorddisplay();
void difficultychoice();
void easygame();
bool easygameplayed();
void easyinputgetter();
void easydisplay(char **arr);
bool CheckWord(char* search);
void hardgame();
bool hardgameplayed();
void hardinputgetter(char **arr);
void harddisplay(char **arr);
bool hardchecker(char * search);
void hardrecorddisplay()
{
	system("cls");
	cout<<"					THE HARD MODE RECORD IS AS FOLLOWS"<<endl;
	string abc;
		ifstream afile("hardrecord.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
	system("pause");
	system("cls");
}
void easyrecorddisplay()
{
	system("cls");
	cout<<"					THE EASY MODE RECORD IS AS FOLLOWS"<<endl;
	string abc;
		ifstream afile("easyrecord.txt");
		while(getline(afile,abc))
		{
		cout<<abc<<endl;
		}
	system("pause");
	system("cls");
}
void easyrecordset(int r)
{
	int arr[5];
	ifstream file;
	file.open("easyrecord.txt");
	for (int a=0;a<5;a++)
	{
		file>>arr[a];
	}
	for(int a=0;a<5;a++)
	{
		if(r>arr[a])
		{
			arr[a]=r;
			break;
		}
	}
	int temp;
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<5;b++)
		{
			if(arr[b]<arr[b+1])
			{
				temp=arr[b];
				arr[b]=arr[b+1];
				arr[b+1]=temp;
			}
		}
	}
	file.close();
	ofstream afile;
	afile.open("easyrecord.txt");
	for(int a=0;a<5;a++)
	{
		afile << arr[a]<<endl;
	}
}
void hardrecordset(int r)
{
	int arr[5];
	ifstream file;
	file.open("hardrecord.txt");
	for (int a=0;a<5;a++)
	{
		file>>arr[a];
	}
	for(int a=0;a<5;a++)
	{
		if(r>arr[a])
		{
			arr[a]=r;
			break;
		}
	}
	int temp;
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<5;b++)
		{
			if(arr[b]<arr[b+1])
			{
				temp=arr[b];
				arr[b]=arr[b+1];
				arr[b+1]=temp;
			}
		}
	}
	file.close();
	ofstream afile;
	afile.open("hardrecord.txt");
	for(int a=0;a<5;a++)
	{
		afile << arr[a]<<endl;
	}
}
void userinfo()
{
	cout<<"					Welcome to word puzzle game "<<endl;
	cout<<"enter your name "<<endl;
	string name;
	cin.ignore();
	getline(cin,name);
	system("pause");
	system("cls");
}
void hardgame()
{
	cout<<"						welcome to the hard mode "<<endl;
	cout<<"					here you need to search diognally as well"<<endl;
	system("pause");
	hardrecorddisplay();
	int record=0;
	char **hardarr=new char *[20];
	for(int a=0;a<20;a++)
	{
		hardarr[a]=new char[20];
	}
	hardinputgetter(hardarr);
	harddisplay(hardarr);
	for(int a=0;a<3;a++)
	{
		if(hardgameplayed())
		{
		record++;
		a--;
		}
	}
	system("cls");
	hardrecordset(record);
	cout<<"game over |||| your score is "<<record<<endl;
	system("pause");	
}
bool hardchecker(char* search)
{
    int offset; 
    int check=0;
    int check1=0;
    string line;
    ifstream file;
    file.open("hardwords.txt");
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check=1;
		}
		}
		ifstream afile;
		afile.open("alreadyfound.txt");
		while(!afile.eof())
		{
			getline(afile,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check1=2;
		}
		}
		if (check1==2)
		{
			cout<<"you have already found it beforehand"<<endl;
		}
		if(check1==2)
		{
			check=0;
		}
		if(check==1)
		{
			return true;
		}
		return false;
			
}
void harddisplay(char ** arr)
{
	for(int a=0;a<20;a++)
	{
		for(int b=0;b<20;b++)
		{
			cout << arr[a][b]<<" ";
		}
		cout<<endl;
	}
}
void hardinputgetter(char **arr)
{
	ifstream file;
	file.open("hardpuzzle.txt");
	for(int a=0;a<20;a++)
	{
		for(int b=0;b<20;b++)
		{
			file >> arr[a][b];
		}
	}
	
}
bool hardgameplayed()
{
	int record=0;
	char* search= new char[20];
	cout<<"enter the word you have found | make sure you havent found it earlier"<<endl;
	cin.ignore();
	cin.getline(search,20);
	while(strlen(search)<4)
	{
		cout<<"enter a longer word"<<endl;
		cin.ignore();
		cin.getline(search,20);
		
	}
	
	if(hardchecker(search))
	{
		cout<<" word found "<<endl;
		ofstream file;
		file.open("alreadyfound.txt");
		file<<search<<endl;
		file.close();
		return true;
		
	}
	else
	{
	cout<<"no this word does not exist in puzzle"<<endl;
	return false;
	}
}

bool CheckWord(char* search)
{
    int offset; 
    int check=0;
    int check1=0;
    string line;
    ifstream file;
    file.open("easywords.txt");
		while(!file.eof())
		{
		getline(file,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check=1;
		}
		}
		ifstream afile;
		afile.open("alreadyfound.txt");
		while(!afile.eof())
		{
			getline(afile,line);
		if((offset = line.find(search,0))!= string :: npos)
		{
			 check1=2;
		}
		}
		if (check1==2)
		{
			cout<<"you have already found it beforehand"<<endl;
		}
		if(check1==2)
		{
			check=0;
		}
		if(check==1)
		{
			return true;
		}
		return false;
			
}
bool easygameplayed()
{
	int record=0;
	char* search= new char[12];
	cout<<"enter the word you have found | make sure you havent found it earlier"<<endl;
	cin.ignore();
	cin.getline(search,12);
	while(strlen(search)<4)
	{
		cout<<"enter a longer word"<<endl;
		cin.ignore();
		cin.getline(search,20);
		
	}
	
	if(CheckWord(search))
	{
		cout<<" word found "<<endl;
		ofstream file;
		file.open("alreadyfound.txt");
		file<<search<<endl;
		file.close();
		return true;
		
	}
	else
	{
	cout<<"no this word does not exist in puzzle"<<endl;
	return false;
	}
}
void easyinputgetter(char **arr)
{
	ifstream file;
	
	file.open("easypuzzle.txt");
	for(int a=0;a<14;a++)
	{
		for(int b=0;b<14;b++)
		{
			file >> arr[a][b];
		}
	}
	
}
void easydisplay(char ** arr)
{
	for(int a=0;a<14;a++)
	{
		for(int b=0;b<14;b++)
		{
			cout << arr[a][b]<<"  ";
		}
		cout<<endl;
	}
}
void easygame()
{
	cout<<"						welcome to the easy mode "<<endl;
	cout<<"					here you need to search only linearly"<<endl;
	system("pause");
	easyrecorddisplay();
	int record=0;
	char **easyarr=new char *[14];
	for(int a=0;a<14;a++)
	{
		easyarr[a]=new char[14];
	}
	easyinputgetter(easyarr);
	easydisplay(easyarr);
	for(int a=0;a<3;a++)
	{
		if(easygameplayed())
		{
		record++;
		a--;
		}
	}
	easyrecordset(record);
	system("cls");
	cout<<"game over |||| your score is "<<record;
	
}

void difficultychoice()
{
	int decision;
	cout<<"which difficulty would you like to play at"<<endl;
	cout<<"enter 1 for easy"<<endl<<"enter 2 for hard"<<endl;
	cin>>decision;
	while(decision<1||decision>2)
	{
		cout<<"wrong choice !!  enter again"<<endl;
		cin>>decision;
	}
	if(decision==1)
		easygame();
	if(decision==2);
		hardgame();
	system("cls");
	
}
int main()
{
	 userinfo();
	ofstream file;
	file.open("alreadyfound.txt");
	PlaySound(TEXT("audio.wav"),NULL,SND_ASYNC);
	difficultychoice();
}