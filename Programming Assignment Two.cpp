//
// Robert VanCleave
// Programming Assignment Two
// Uses cin and ifstream input; and cout and outfile output
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
	ofstream outfile, errorfile;
	string 	filename, lastname, errormessageM, errormessageP;
	char marital;
	int children, errordataM, errordataP;
	float income, pension, deductions, taxincome, taxowed, exemptions;
	
	errormessageM = "Invalid Marital Status.";
	errormessageP = "Invalid Pension Percentage.";
	errordataM = 0;
	errordataP = 0;
	
	cout << "Please tell me your file name.\n";
	cin >> filename;
	files.open(filename.c_str());
	outfile.open("Outputfile.txt"); 
	errorfile.open("Errorfile.txt");
//********************************************************************************************************************
			if (files.is_open())
			{
				
				cout	<< "========================================================================\n";
				cout	<< setw(9) << left << "Name " << setw(9) << left << "Gross-Income "
						<< setw(9) << left << "Exemptions " << setw(9) << left << "Pension "
						<< setw(9) << left << "Taxable-Income " << setw(10) << left << "Tax-Owed: " << "\n";
				cout	<< "========================================================================\n";		
				
				outfile	<< "========================================================================\n";
				outfile	<< setw(9) << left << "Name " << setw(9) << left << "Gross-Income "
						<< setw(9) << left << "Exemptions " << setw(9) << left << "Pension "
						<< setw(9) << left << "Taxable-Income " << setw(10) << left << "Tax-Owed: " << "\n";
				outfile	<< "========================================================================\n";
				do
				{
					files >> lastname >> marital >> children >> income >> pension;
//********************************************************************************************************************	
//********************************************************************************************************************	
//********************************************************************************************************************	
	switch (marital)
	{
		case 'M':
			{
				errordataM = 0;
				errormessageM = " ";
				exemptions = 6000 + (700 * 2) + (700 * children);
				break;
			}
		case 'S':
			{
				errordataM = 0;
				errormessageM = " ";
				exemptions = 3000 + (700) + (700 * children);
				break;
			}
		default:
			{
				errordataM = 1;
				errormessageM = "Invalid Marital Status.";
				exemptions = 3000 + (700) + (700 * children);
				break;
			}
	}
//********************************************************************************************************************
	if (pension >= .06)
	{		
		errormessageP = "Invalid Pension Percentage.";
		errordataP = 1;
	}
	if (pension <= .05)
	{
		errormessageP = " ";
		errordataP = 0;
	}
//********************************************************************************************************************
	deductions = pension * income;
	taxincome = (income - exemptions) - deductions;
//********************************************************************************************************************
	if (taxincome <= 20000.00)
	{
		taxowed = (0.15 * taxincome);
	}
	
	if (taxincome >= 20000.01 && taxincome <= 50000.00)
	{
		taxowed = (0.25 * taxincome) + 2250;
	}
	
	if (taxincome >= 50000.01)
	{
		taxowed = (0.35 * taxincome) + 8460;
	}
//********************************************************************************************************************
//********************************************************************************************************************					
//********************************************************************************************************************
					if (files)
					{	
						if (errordataM == 0 && errordataP == 0)
							{
								cout 	<< fixed << showpoint << setprecision(2);
								cout 	<< setw(7)  << left << lastname << "  "   
										<< setw(11) << left << income << "  "
										<< setw(9)  << left << exemptions << "  "
										<< setw(5)  << left << pension * 100 << setw(4) << left << "% "
										<< setw(13) << left << taxincome << "  "
										<< setw(8)  << left << taxowed << "  " << "\n";
								outfile	<< fixed << showpoint << setprecision(2);
								outfile << setw(7)  << left << lastname << "  "   
										<< setw(11) << left << income << "  "
										<< setw(9)  << left << exemptions << "  "
										<< setw(5)  << left << pension * 100 << setw(4) << left << "% "
										<< setw(13) << left << taxincome << "  "
										<< setw(8)  << left << taxowed << "  " << "\n";
							}						
						else
						{	
							errorfile	<< fixed << showpoint << setprecision(2);
							errorfile	<< setw(6)  << left << lastname << "  "   
										<< setw(8) << left << income << "  "
										<< setw(6)  << left << exemptions << "  "
										<< setw(3)  << left << pension * 100 << setw(4) << left << "% "
										<< setw(9) << left << taxincome << "  "
										<< setw(7)  << left << taxowed << "  " 
										<< setw(23)	<< left << errormessageM
										<< setw(23)	<< left	<< errormessageP << "\n";
						}
					}
//********************************************************************************************************************
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
			if (errorfile.is_open())
			{
				cout << "Errors were successfully logged.  You can find them in 'Errorfile.txt' at your convenience.\n";
			}
			else
			{
				cout << "Could not save error log.\n";
			}
			
			files.close();
			outfile.close();
			errorfile.close();
return 0;
}
//********************************************************************************************************************
//********************************************************************************************************************
//********************************************************************************************************************
