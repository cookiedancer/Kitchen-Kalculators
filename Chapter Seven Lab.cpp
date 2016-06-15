//
// Robert VanCleave
// Chapter Seven In-Class Lab
// Uses cin, get, and getline input; and cout output
// Program loops and manipulates file data
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void looptest();
void switchtest();

int main()
{
	looptest();
	switchtest();	
	return 0;
}

//*********************************************************************************************
//*********************************************************************************************
void looptest()
{
	ifstream files;
	int counter;
	float sum, value;
//*********************************************************************************************
	files.open("loop.txt");
		if (files.is_open())
		{
			sum=0;
			counter = 0;
			while(counter <=3)
			{
				files >> value;
				if (files)
				{
					sum = sum + value;
					counter++;
				}
			}
			cout << "While: " << setw(3) << sum << "\n";
			files.close();
		}
		else
		{
			cout << "Cannot open file.  Please exit program.\n";
		}
//*********************************************************************************************
	files.open("loop.txt");
		if (files.is_open())
		{
			counter = 0;
			sum=0;
			do
			{
				files >> value;
				if (files)
				{
					sum = sum + value;
					counter++;
				}
			} while (counter <=3);
			cout << "Do: " << setw(6) << sum << "\n";
			files.close();
		}
		else
		{
			cout << "Cannot open file.  Please exit program.\n";
		}
//*********************************************************************************************
files.open("loop.txt");
		if (files.is_open())
		{
		sum=0;
			for (counter=0; counter<=3; counter++)
			{
				files >> value;
				if (files)
				{
					sum = sum + value;
				}
			}
			cout << "For: " << setw(5) << sum << "\n\n";
			files.close();
		}
		else
		{
			cout << "Cannot open file.  Please exit program.\n";
		}
//*********************************************************************************************
}
//*********************************************************************************************
//*********************************************************************************************
void switchtest()
{
	char color1;
	string color2;
	cout << "Please, of the following options, tell me your favorite color.\n";
	cout << "//=================================================================\\\n";
	cout << "|| 1 = Black || 2 = White || 3 = Yellow || 4 = Purple || 5 = Red  ||\n";
	cout << "|| 6 = Gray  || 7 = Clear || 8 = Green  || 9 = Pink   || 0 = Blue ||\n";
	cout << "\\=================================================================//\n";
	cin >> color1;
	switch (color1)
	{
		case '1':
			{
				color2="Black";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '2':
			{
				color2 = "White";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '3':
			{
				color2 = "Yellow";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '4':
			{
				color2 = "Purple";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '5':
			{
				color2 = "Red";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '6':
			{
				color2 = "Gray";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '7':
			{
				color2 = "Clear";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '8':
			{
				color2 = "Green";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '9':
			{
				color2 = "Pink";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		case '0':
			{
				color2 = "Blue";
				cout << "Your favorite color is: " << color2 << "\n";
				break;
			}
		default:
			{
				cout << "Your selection was not on the list.\n";
			}
	}
}
