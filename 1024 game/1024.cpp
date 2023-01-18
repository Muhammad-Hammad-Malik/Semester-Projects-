#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
void credits();
void gameinitialize();
void tabdisp(int a[][4], int rows);
int  spacecount(int xyz);
void randgen(int a[][4], int rows);
void right(int a[][4], int rows);
void left(int a[][4], int rows);
void up(int a[][4], int rows);
void down(int a[][4], int rows);
void userdecison(int a[][4], int rows);
int endcondition(int a[][4], int rows);
int random = 0;
int main()
{
	credits();
	gameinitialize();
	int a[4][4] = { 0 };
	int endcheck = 0;
	srand(time(0));

	int rows = rand() % 4;
	int cols = rand() % 4;
	a[rows][cols] = rand() % 2 + 1;
	randgen(a, 4);
	while (endcheck == 0 || endcheck == 3)
	{
		tabdisp(a, 4);
		userdecison(a, 4);
		endcheck = endcondition(a, 4);
		if (random != 1)
		{
			randgen(a, 4);
		}
		system("cls");
	}
	if (endcheck == 1)
	{
		tabdisp(a, 4);
		cout << "\t\t\t\t\t" << "CONGRATULATIONS :)" << endl;
		cout << "\t\t\t\t\t" << " You won the game ";
	}
	else if (endcheck == 2)
	{
		tabdisp(a, 4);
		cout << "\t\t\t\t\t" << "     SORRY  :(       " << endl;
		cout << "\t\t\t\t\t" << "You Lost the game    ";
	}
}
void tabdisp(int a[][4], int rows)
{
	int count;
	cout << endl << endl;
	cout << "\t\t\t\t\t _____________________" << endl;
	for (int i = 0;i < 4;i++)
	{
		cout << "\t\t\t\t\t<|";
		for (int j = 0;j < 4;j++)
		{
			count = spacecount(a[i][j]);
			for (int k = 4 - count;k > 0;k--)
			{
				cout << " ";
			}
			if (a[i][j] == 0)
			{
				cout << "|";
				if (j==3)
				cout << ">";
				continue;
			}
			else
				cout << a[i][j] << "|";
				if (j==3)
				cout << ">";
		}
		cout << endl;
		cout << "\t\t\t\t\t<|____|____|____|____|>";
		cout << endl;
	}
	cout << endl;
}
int spacecount(int xyz)
{
	int digit = 0;
	int num = xyz;
	while (num > 0)
	{
		num = num / 10;
		digit = digit + 1;
	}
	return digit;
}
void randgen(int a[][4], int rows)
{
	int cols = 0;
	int itr = 0;
	int utility1 = 0;
	while (utility1 != 1)
	{
		rows = rand() % 4;
		cols = rand() % 4;
		if (a[rows][cols] == 0)
		{
			a[rows][cols] = rand() % 2 + 1;
			utility1 = 1;
		}

	}
}
void right(int a[][4], int rows)
{
	int sum = 0;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 3; col > 0; col--)
		{
			if (a[row][3] == a[row][2] && a[row][2] == a[row][1] && a[row][1] == a[row][0])
			{
				a[row][3] = a[row][3] + a[row][2];
				a[row][2] = a[row][1] + a[row][0];
				a[row][1] = 0;
				a[row][0] = 0;
			}
			else if (a[row][col] == a[row][col - 1])
			{
				sum = a[row][col] + a[row][col - 1];
				a[row][col] = sum;
				a[row][col - 1] = 0;
			}
			else if (a[row][col] == 0)
			{
				a[row][col] = a[row][col - 1];
				a[row][col - 1] = 0;
				if (col == 3 || (a[row][3] == a[row][2] && a[row][1] != 0 && a[row][3] != 0) /*|| a[row][0] != 0*/)
					continue;
				/*if (a[row][col] == a[row][col + 1])
				{
					sum = a[row][col] + a[row][col + 1];
					a[row][col + 1] = sum;
					a[row][col] = 0;
				}*/
				if (a[row][col + 1] == 0)
				{
					a[row][col + 1] = a[row][col];
					a[row][col] = 0;
					if (col == 2)
						continue;
					if (a[row][col + 2] == 0)
					{
						a[row][col + 2] = a[row][col + 1];
						a[row][col + 1] = 0;
					}
					if (a[row][col + 1] == a[row][col + 2])
					{
						sum = a[row][col + 1] + a[row][col + 2];
						a[row][col + 2] = sum;
						a[row][col + 1] = 0;
					}
				}
			}
		}
	}
}
void left(int a[][4], int rows)
{
	int sum = 0;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (a[row][0] == 0 && a[row][1] == a[row][2] && a[row][2] == a[row][3])
			{
				a[row][0] = a[row][1] + a[row][2];
				a[row][1] = a[row][3];
				a[row][2] = 0;
				a[row][3] = 0;
			}
			else if (a[row][col] == a[row][col + 1])
			{
				sum = a[row][col] + a[row][col + 1];
				a[row][col] = sum;
				a[row][col + 1] = 0;
			}
			else if (a[row][col] == 0)
			{
				a[row][col] = a[row][col + 1];
				a[row][col + 1] = 0;
				if (col == 0 || (a[row][0] == a[row][1] && a[row][2] != 0 && a[row][0] != 0) /*|| a[row][3] != 0*/)
					continue;
				/*if (a[row][col] == a[row][col - 1])
				{
					sum = a[row][col] + a[row][col - 1];
					a[row][col - 1] = sum;
					a[row][col] = 0;
				}*/
				if (a[row][col - 1] == 0)
				{
					a[row][col - 1] = a[row][col];
					a[row][col] = 0;
					if (col == 1)
						continue;
					if (a[row][col - 2] == 0)
					{
						a[row][col - 2] = a[row][col - 1];
						a[row][col - 1] = 0;
					}
					if (a[row][col - 1] == a[row][col - 2])
					{
						sum = a[row][col - 1] + a[row][col - 2];
						a[row][col - 2] = sum;
						a[row][col - 1] = 0;
					}
				}
			}
		}
	}
}
void up(int a[][4], int rows)
{
	int sum = 0;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (a[3][col] == a[2][col] && a[2][col] == a[1][col] && a[1][col] == a[0][col])
			{
				a[3][col] = a[3][col] + a[2][col];
				a[2][col] = a[1][col] + a[0][col];
				a[1][col] = 0;
				a[0][col] = 0;
			}
			else if (a[row][col] == a[row + 1][col])
			{
				sum = a[row][col] + a[row + 1][col];
				a[row][col] = sum;
				a[row + 1][col] = 0;
			}
			else if (a[row][col] == 0)
			{
				a[row][col] = a[row + 1][col];
				a[row + 1][col] = 0;
				if (row == 0 || (a[0][col] == a[1][col] && a[2][col] != 0 && a[0][col] != 0) /*|| a[3][col] != 0*/)
					continue;
				/*if (a[row][col] == a[row - 1][col])
				{
					sum = a[row][col] + a[row - 1][col];
					a[row - 1][col] = sum;
					a[row][col] = 0;
				}*/
				if (a[row - 1][col] == 0)
				{
					a[row - 1][col] = a[row][col];
					a[row][col] = 0;
					if (row == 1)
						continue;
					if (a[row - 2][col] == 0)
					{
						a[row - 2][col] = a[row - 1][col];
						a[row - 1][col] = 0;
					}
					if (a[row - 1][col] == a[row - 2][col])
					{
						sum = a[row - 1][col] + a[row - 2][col];
						a[row - 2][col] = sum;
						a[row - 1][col] = 0;
					}
				}
			}
		}
	}
}
void down(int a[][4], int rows)
{
	int sum = 0;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 3; row > 0; row--)
		{
			if (a[0][col] == 0 && a[1][col] == a[2][col] && a[2][col] == a[3][col])
			{
				a[0][col] = a[1][col] + a[2][col];
				a[1][col] = a[3][col];
				a[2][col] = 0;
				a[3][col] = 0;
			}
			else if (a[row][col] == a[row - 1][col])
			{
				sum = a[row][col] + a[row - 1][col];
				a[row][col] = sum;
				a[row - 1][col] = 0;
			}
			else if (a[row][col] == 0)
			{
				a[row][col] = a[row - 1][col];
				a[row - 1][col] = 0;
				if (row == 3 || (a[3][col] == a[2][col] && a[1][col] != 0 && a[3][col] != 0) /*|| a[0][col] != 0*/)
					continue;
				/*if (a[row][col] == a[row + 1][col])
				{
					sum = a[row][col] + a[row + 1][col];
					a[row + 1][col] = sum;
					a[row][col] = 0;
				}*/
				if (a[row + 1][col] == 0)
				{
					a[row + 1][col] = a[row][col];
					a[row][col] = 0;
					if (row == 2)
						continue;
					if (a[row + 2][col] == 0)
					{
						a[row + 2][col] = a[row + 1][col];
						a[row + 1][col] = 0;
					}
					if (a[row + 1][col] == a[row + 2][col])
					{
						sum = a[row + 1][col] + a[row + 2][col];
						a[row + 2][col] = sum;
						a[row + 1][col] = 0;
					}
				}
			}
		}
	}
}
void userdecison(int a[][4], int rows)
{
	int x = 0;
	int imp = 0;
	char decison;
	cout << "\t\t\t\t\tPRESS W/w FOR UP \n\t\t\t\t\tPRESS S/s FOR DOWN \n\t\t\t\t\tPRESS A/a FOR LEFT \n\t\t\t\t\tPRESS D/d FOR RIGHT \n" << endl;
	decison = getche();
	while (x == 0)
	{
		if (decison == 'w' || decison == 'W')
		{
			up(a, 4);
			x = 1;
		}
		else if (decison == 's' || decison == 'S')
		{
			down(a, 4);
			x = 1;
		}
		else if (decison == 'a' || decison == 'A')
		{

			left(a, 4);
			x = 1;
		}
		else if (decison == 'd' || decison == 'D')
		{
			right(a, 4);
			x = 1;
		}
		else
		{
			cout << "Wrong Input......Enter Again!!!!!! (W,A,S,D)		" << endl;
			decison = getche();
			x = 0;
		}
	}
}
int endcondition(int a[][4], int rows)
{
	int loss = 0;
	int z = 0;
	for (int x = 0;x < 4;x++)
	{
		for (int y = 0;y < 4;y++)
		{
			if (a[x][y] == 1024)
			{
				z = 1;
				return z;
			}
		}
	}
	for (int x = 0;x < 4;x++)
	{
		for (int y = 0;y < 4;y++)
		{
			if (a[x][y] == 0)
			{
				loss++;
			}
		}
	}
	if (loss > 0)
	{
		random = 0;
	}
	if (loss == 0)
	{
		random = 1;
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < 4;j++)
			{
				if (i == 0 || j == 0 || j == 3 || i == 3)
				{
					if (i == 0 && j != 0 && i != 3 && j != 3)
					{
						if (a[i][j] != a[i + 1][j] && a[i][j] != a[i][j + 1] && a[i][j] != a[i][j - 1])
						{
							loss++;
						}
					}
					if (i != 0 && j == 0 && i != 3 && j != 3)
					{
						if (a[i][j] != a[i + 1][j] && a[i][j] != a[i - 1][j] && a[i][j] != a[i][j + 1])
						{
							loss++;
						}
					}
					if (i != 0 && j != 0 && i == 3 && j != 3)
					{
						if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j + 1] && a[i][j] != a[i][j - 1])
						{
							loss++;
						}
					}
					if (i != 0 && j != 0 && i != 3 && j == 3)
					{
						if (a[i][j] != a[i + 1][j] && a[i][j] != a[i - 1][j] && a[i][j] != a[i][j - 1])
						{
							loss++;
						}
					}
					if (i == 0 && j == 0 && i != 3 && j != 3)
					{
						if (a[i][j] != a[i + 1][j] && a[i][j] != a[i][j + 1])
						{
							loss++;
						}
					}
					if (i == 0 && j != 0 && i != 3 && j == 3)
					{
						if (a[i][j] != a[i + 1][j] && a[i][j] != a[i][j - 1])
						{
							loss++;
						}
					}
					if (i != 0 && j == 0 && i == 3 && j != 3)
					{
						if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j + 1])
						{
							loss++;
						}
					}
					if (i != 0 && j != 0 && i == 3 && j == 3)
					{
						if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j - 1])
						{
							loss++;
						}
					}
				}
				else if (a[i][j] != a[i + 1][j] && a[i][j] != a[i - 1][j] && a[i][j] != a[i][j + 1] && a[i][j] != a[i][j - 1])
				{
					loss++;
				}
			}
		}
	}
	if (loss == 16)
	{
		z = 2;
		return z;
	}
	return 0;
}
void gameinitialize()
{
	cout << "\t\t\t\t" << ">>>>>>>>>>> <<<<<<<<<<<" << endl;
	cout << "\t\t\t\t" << ">>>>>> 1024 GAME <<<<<<" << endl;
	cout << "\t\t\t\t" << ">>>>>>>>>>> <<<<<<<<<<<" << endl << endl;
	cout << "\t\t\t\t" << "HERE ARE THE CONTROLS " << endl;
	cout << "\t\t\t\t" << "PRESS W TO MOVE UP" << endl;
	cout << "\t\t\t\t" << "PRESS A TO MOVE LEFT" << endl;
	cout << "\t\t\t\t" << "PRESS S TO MOVE DOWN" << endl;
	cout << "\t\t\t\t" << "PRESS D TO MOVE RIGHT" << endl << endl;
	system("pause");
	system("cls");
}
void credits()
{
	cout << "\t\t\t\t" << "FIRST SEMESTER PROJECT." << endl;
	cout << "\t\t\t\t" << "SECTION 1M BSCS." << endl;
	cout << "\t\t\t\t" << "SHEHROZ AZIZ 21L-7521." << endl;
	cout << "\t\t\t\t" << "MUHAMMAD HAMMAD 21L-5388." << endl;
	cout << "\t\t\t\t" << "SAAD KASHIF 21L-1789." << endl;
	cout << "\t\t\t\t" << "SUBMITTED TO MISS TAZEEM HAIDER." << endl;
	system("pause");
	system("cls");
}


