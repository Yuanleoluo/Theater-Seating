#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//flag a 15x30 grid to represent the seats in the teather
bool findTicket(bool [][30], int, int);

int main() 
{
	bool seats[15][30];
	char ticketSold;

	//set every seat as empty
	for (int i = 0; i<15; i++)
		for(int j = 0; j<30; j++)
			seats[i][j] = false;


   while (true)
   {
	//display column & row
	cout << "\t\tSeats\n";
	cout << "		 111111111122222222223\n";
	cout << "	123456789012345678901234567890\n";
	for (int i = 0; i<15; i++)
	{
		//"#"represents empty seats and "*" represents taken seats
		cout << "Row " << i+1 << "\t";
		for(int j = 0; j<30; j++)
		{
			if (findTicket(seats, i, j))
				cout << "*";
			else
				cout << "#"; 
		}
		cout << endl;
	}

	int i, j;
	//collect input from user
	cout << "any tickets sold?[N/n to quit]\n";
	cin >> ticketSold;
	if (ticketSold == 'n' || ticketSold == 'N')
		break;

	cout << "enter the row of the ticket that was sold: ";
	cin >> i;
	while (i<1 || i>15)
	{
		cout << "row range[1-15]: ";
		cin >> i;
	}

	cout << "enter the column of the ticket that was sold: ";
	cin >> j;
	while (j<1 || j>30)
	{
		cout << "column range[1-30]: ";
		cin >> j;
	}
	//set the seat row and column that the user enter as true
	seats[i-1][j-1]=true;

   } 
}


bool findTicket(bool seats[][30], int i, int j)
{
	if (seats[i][j])
		return true;
	else
		return false;
}