#include<iostream>
#include<cstring>
int lengthofstring(char mainstring[]);
int stringfinder(char mainstring[], char substring[]);
void equalString(char mainstring[], char replacestring[], int index);
void smallerString(char mainstring[], char replacestring[],int index, int lengthfindstring);
void biggerString(char mainstring[], char replacestring[], int index, int lengthfindstring);
using namespace std;
int main()
{
	int strlength=0, lengthfindstring=0;
	int FS;
	char mainstring[100],substring[50],replacestring[50];
	cout << "Main string:";
	cin.getline(mainstring, 100);
	cout << "Find string:";
	cin.getline(substring, 50);
	cout << "replace string:";
	cin.getline(replacestring, 50);
	strlength = lengthofstring(mainstring);
	FS = stringfinder(mainstring, substring);
	cout << "sub string is present at: "<<FS;
	lengthfindstring=strlen(substring);
	if (strlen(substring) == strlen(replacestring))
	{
		equalString(mainstring, replacestring, FS);
	}
	if (strlen(substring) > strlen(replacestring))
	{
		smallerString(mainstring, replacestring, FS, lengthfindstring);

	}
	if (strlen(substring) < strlen(replacestring))
	{

		biggerString(mainstring, replacestring, FS, lengthfindstring);
	}
		system("pause");
	return 0;
}
int lengthofstring(char mainstring[])
{
	int i = 0;
	for (;mainstring[i] != '\0';)
	{
		i++;
	}
	return i;
}
int stringfinder(char mainstring[], char substring[])
{
	int i, j, temp=0;
	for (i = 0;mainstring[i] != '\0';i++)
	{
		j = 0;
		if (mainstring[i] == substring[j])
		{
			temp = i;
			while (mainstring[i] == substring[j] && mainstring[i]!='\0')
			{
				
				i++;
				j++;

			}
			if (substring[j] == '\0')
			{

				return temp;
				break;
			}
			else
			{
				i = temp;
				temp = 0;
			}
		}


	}
	if (temp == 0)
	{
		return -1;
	}
}
void equalString(char mainstring[], char replacestring[], int index)
{
	int j,temp;
	for (int i = 0;mainstring[i] != '\0';i++)
	{
		if (i = index)
		{
			temp = i;
			j = 0;
			while (mainstring[i] != 32 && mainstring[i] != '\0' && mainstring[i]!=46 && mainstring[i] != '"'&& mainstring[i] != 39 && mainstring[i] != '!' && mainstring[i] != ':' && mainstring[i] != ';' && mainstring[i] != ',' && mainstring[i] != '?')
			{
				mainstring[i] = replacestring[j];
				i++;
				j++;
			}
			if (mainstring[i] == '\0')
			{
				i = temp + 1;
			}
			break;
		}
	}
	cout << endl;
	cout << "Main string changes to:";
	for (int k = 0;mainstring[k] != '\0';k++)
	{
		cout << mainstring[k];
	}
	cout << endl;
	cout << "replacement is made:";
	cout << endl;
}
void smallerString(char mainstring[], char replacestring[], int index, int lengthfindstring)
{
	int j, temp,t,mainstrl=strlen(mainstring);
	for (int i = 0;mainstring[i] != '\0';i++)
	{
		if (i = index)
		{
			j = 0;
			for (int l = 0; l < lengthfindstring;l++)
			{
				if (replacestring[j] != '\0')
				{
					mainstring[i] = replacestring[j];
					i++;
					j++;
				}
				else
				{
					mainstring[i] = 32;
					i++;
				}
			}
			i--;
			t = i;
			temp = i;
			for (;mainstring[i] == 32 || mainstring[i]==46 || mainstring[i - 1] == 32||mainstring[i] == '"' || mainstring[i] == 39 || mainstring[i] == '!' || mainstring[i] == ':' || mainstring[i] == ';' || mainstring[i] == ',' || mainstring[i] == '?';)
			{
				while (t<mainstrl)
				{
					mainstring[t] = mainstring[t + 1];
					mainstring[t + 1] = 32;
					t++;
				}
				i--;
				t = i;

			}
			break;
		}
	}
	cout << endl;
	cout << "Main string changes to:";
	for (int k = 0;mainstring[k] != '\0';k++)
	{
		cout << mainstring[k];
	}
	cout << endl;
	cout << "replacement is made:";
	cout << endl;
}
void biggerString(char mainstring[], char replacestring[], int index, int lengthfindstring)
{
	int j, temp, t, mainstrl = strlen(mainstring), replacestrl=strlen(replacestring);
	int tp = replacestrl - lengthfindstring;
	for (int i = tp;i >= 0;i--, mainstrl++)
	{
		if (i != 0)
		{
			mainstring[mainstrl] = 32;
		}
		else
		{
			mainstring[mainstrl] = '\0';
		}
	}
	int mainstrl2 = strlen(mainstring);
	temp = index + replacestrl;
	for (int i = mainstrl2 - 1;i >= temp;i--)
	{
		if (mainstring[temp] != 32)
		{
			t = mainstrl2 - 1;
			while (mainstring[temp] != 32 && t > (temp - tp))
			{
				mainstring[t] = mainstring[t - 1];
				mainstring[t - 1] == 32;
				t--;
			}
		}
		else
		{
			break;
		}

	}
	for (int i = 0;mainstring[i] != '\0';i++)
	{
		if (i = index)
		{
			temp = i;
			j = 0;
			while (replacestring[j]!='\0' )
			{
				mainstring[i] = replacestring[j];
				i++;
				j++;
			}
			break;
		}
	}
		
		cout << endl;
		cout << "Main string changes to:";
		for (int k = 0;mainstring[k] != '\0';k++)
		{
			cout << mainstring[k];
		}
		cout << endl;
		cout << "replacement is made:";
		cout << endl;

	


}