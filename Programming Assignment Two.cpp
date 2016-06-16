//
// Robert VanCleave
// Programming Assignment Two
// Uses cin, get, and getline input; and cout output
// Program loops and manipulates file data
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main()
{
	ifstream files;
	ofstream outfile;
	string 	filename, lastname, marital;
	int children;
	float income, pension;
	
	cout << "Please tell me your file name.\n";
	cin >> filename;
	files.open(filename.c_str());
	outfile.open("Outputfile.txt"); 	
			if (files.is_open())
			{
				do
				{
					files >> lastname >> marital >> children >> income >> pension;
					if (files)
					{
						cout << fixed << showpoint << setprecision(2);
						cout	<< "======================================================================\n";
						cout 	<< "Last Name: " 
										<< setw(9) << left << lastname << " ~~ " 
								<< "Marital Status: " 
										<< setw(4) << left << marital << " ~~ "
								<< "Number of Children: " 
										<< setw(4) << left << children  
								<< "Yearly Income: $" 
										<< setw(10) << left << income 
								<< " ~~ Pension Contribution: " 
										<< setw(4) << left << pension * 100 << "%" << "\n";
						outfile 	<< fixed << showpoint << setprecision(2);
						outfile		<< "======================================================================\n";
						outfile 	<< "Last Name: " 
										<< setw(9) << left << lastname << " ~~ " 
									<< "Marital Status: " 
										<< setw(4) << left << marital << " ~~ "
									<< "Number of Children: " 
										<< setw(4) << left << children 
									<< "Yearly Income: $" 
										<< setw(10) << left << income 
									<< " ~~ Pension Contribution: " 
										<< setw(4) << left << pension * 100 << "%" << "\n";	
					}
				} 	while (files);
				
			}
			
			//statement in case input file could not open
			else 
			{
				cout << "Could not open file.  Please exit program.\n";
			}
			
			// statement to validate that outfile saved successfully
			if (outfile.is_open()) 
			{
				cout << "======================================================================\n";
				cout << "Saved output file successfully.  You can find it as 'Outputfile.txt' at your convenience.\n";
			}
			
			// statement in case outfile did not save successfully
			else 
			{
				cout << "Could not save output file.\n";
			}
return 0;
}
