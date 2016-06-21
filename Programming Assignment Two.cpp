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

ifstream files;
	ofstream outfile;
	string 	filename, lastname, errormessageM, errormessageP;
	char marital;
	int children;
	float income, pension, deductions, taxincome, taxowed, exemptions;
	void tax_calc();

int main()
{
	errormessageM = " ";
	errormessageP = " ";
	
	cout << "Please tell me your file name.\n";
	cin >> filename;
	files.open(filename.c_str());
	outfile.open("Outputfile.txt"); 	
			if (files.is_open())
			{
				
				cout	<< "=========================================================================================================\n";
				cout	<< setw(10) << left << "Name " << setw(10) << left << "Gross-Income "
						<< setw(10) << left << "Exemptions " << setw(10) << left << "Pension "
						<< setw(10) << left << "Taxable-Income " << setw(10) << left << "Tax-Owed: "
						<< setw(10) << left << "Notes: \n";
				cout	<< "=========================================================================================================\n";		
				
				outfile	<< "=========================================================================================================\n";
				outfile	<< setw(9) << left << "Name " << setw(9) << left << "Gross-Income "
						<< setw(9) << left << "Exemptions " << setw(8) << left << "Pension "
						<< setw(9) << left << "Taxable-Income " << setw(9) << left << "Tax-Owed: "
						<< setw(8) << left << "Notes: \n";
				outfile	<< "=========================================================================================================\n";
				do
				{
					files >> lastname >> marital >> children >> income >> pension;
					tax_calc();
//********************************************************************************************************************					
					if (files)
					{	
						cout 	<< fixed << showpoint << setprecision(2);
						cout 	<< setw(7)  << left << lastname << "  "   
								<< setw(11) << left << income << "  "
								<< setw(9)  << left << exemptions << "  "
								<< setw(4)  << left << pension * 100 << setw(4) << left << "% "
								<< setw(13) << left << taxincome << "  "
								<< setw(8)  << left << taxowed << "  "
								<< setw(15) << left << errormessageM << "  "
								<< setw(15) << left << errormessageP << "\n";
						outfile	<< fixed << showpoint << setprecision(2);
						outfile << setw(7)  << left << lastname << "  "   
								<< setw(11) << left << income << "  "
								<< setw(9)  << left << exemptions << "  "
								<< setw(4)  << left << pension * 100 << setw(4) << left << "% "
								<< setw(13) << left << taxincome << "  "
								<< setw(8)  << left << taxowed << "  "
								<< setw(15) << left << errormessageM << "  "
								<< setw(15) << left << errormessageP << "\n";	
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
return 0;
}
//********************************************************************************************************************
//********************************************************************************************************************
void tax_calc()
{
	//ifstream files;
	//ofstream outfile;
	//string 	filename, lastname, errormessageM, errormessageP;
	//char marital;
	//int children;
	//float income, pension, deductions, taxincome, taxowed, exemptions;
	//errormessageM = " ";
	//errormessageP = " ";
//********************************************************************************************************************	
	switch (marital)
	{
		case 'M':
			{
				exemptions = 6000 + (700 * 2) + (700 * children);
				errormessageM = " ";
				break;
			}
		case 'S':
			{
				exemptions = 3000 + (700) + (700 * children);
				errormessageM = " ";
				break;
			}
		default:
			{
				exemptions = 3000 + (700) + (700 * children);
				errormessageM = "Invalid status.";
				break;
			}
	}
//********************************************************************************************************************	
	if (pension >= .06)
	{
		errormessageP = "Invalid pension.";
		pension = 0.05;
	}
	
	if (pension <= .05)
	{
		errormessageP = " ";
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
}
