//
// Robert VanCleave
// Chapter Six In-Class Lab
// Uses cin, get, and getline input; and cout output
// Program loops and manipulates file data
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fail_cin();
void looping_question();
void data_process();


int main()
{
	looping_question();
	
	return 0;
}
//*************************************************************************************************
void fail_cin() // function to keep user from inputting non-integer value for "choice"
	{
		cin.clear();
        cin.ignore(100,'\n');
        cout << "Improper value, please try again.\n";
	}
//*************************************************************************************************
void looping_question() // function to ask user if they wish to enter file name or if they wish to quit
	{
		int choice;
		do
		{
			cout << "Press '1' to give me the name of the file you wish to calculate the average.\n";
			cout << "Or press '2' to exit.\n";
			cin >> choice;
				if (cin.fail()) // cites fail_cin() function to keep from non-integer "choice" value
				{
					fail_cin();
				}
				
				if (choice==1)
				{
					data_process();
				}
		
		} 	while (choice !=2);
	}
//*************************************************************************************************
void data_process() // function to ask user for file name, load the file, and average the data
	{
		ifstream files;
		string filename;
		int datacount, total;
		double data1, average;
		datacount = 0;
		total = 0;
		cout << "Please tell me your file name: \n";
		cin >> filename;
		files.open(filename.c_str());
			if (files.is_open())
			{
				while (datacount <= 19 && files)
				{
					files >> data1;
					if (files)
					{
						cout << data1 << "\n";
						total = total + data1;
						datacount ++;	
					}
					
				}
				if (datacount != 0)
				{
					average = total/datacount;
					cout << "The average of the data is: " << average << "\n\n";
					files.close();
				}
			}
			else 
			{
				cout << "Could not find data, please try again.\n";
			}
		
		
	}
//*************************************************************************************************

