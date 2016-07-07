//
// Robert VanCleave
// Programming Assignment Three
// Uses float, int, and void return type functions
// Program requires .txt file input parameters as a prerequisite
// Program utilizes functions to calculate and output tax data
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::string;

float exemptionfunc(ifstream& files, char marital, int children, float exemptions);
int errordata_m(ifstream& files, char marital, int errordataM);
float taxincomefunc(ifstream& files, char marital, int children, float income, float pension, float deductions,
    float exemptions, float taxincome);
float taxowedfunc(ifstream& files, float taxincome, float taxowed);
int errordata_p(ifstream& files, int errordataP, float pension);
int openfiles(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, int errorcheck);
void closefiles(ifstream& files, ofstream& outfile, ofstream& errorfile);
void readdata(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, string lastname, string errormessageM,
	string errormessageP, char marital, int children, int errordataM, int errordataP, float income,
	float pension, float deductions, float taxincome, float taxowed, float exemptions);
void outputheader(ifstream& files, ofstream& outfile);
void outputdata(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, string lastname, string errormessageM,
	string errormessageP, char marital, int children, int errordataM, int errordataP, float income,
	float pension, float deductions, float taxincome, float taxowed, float exemptions);
void errorout(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, string lastname, string errormessageM,
	string errormessageP, char marital, int children, int errordataM, int errordataP, float income,
	float pension, float deductions, float taxincome, float taxowed, float exemptions);

int main() {
	ifstream files;
	ofstream outfile, errorfile;
	string 	filename, lastname, errormessageM, errormessageP;
	char marital;
	int children, errorcheck, errordataM, errordataP;
	float income, pension, deductions, taxincome, taxowed, exemptions;

	errormessageM = "Invalid Marital Status.";
	errormessageP = "Invalid Pension Percentage.";
	errordataM = 0;
	errordataP = 0;

	openfiles(files, outfile, errorfile, filename, errorcheck);
	if (errorcheck=1) {
		readdata(files, outfile, errorfile, filename, lastname, errormessageM, errormessageP, marital, children,
			errordataM, errordataP, income, pension, deductions, taxincome, taxowed, exemptions);
		closefiles(files, outfile, errorfile);
		return 0;
	}
	else {
		cout << "Closing program.\n";
		return 0;
	}
}
//********************************************************************************************************************
//********************************************************************************************************************
float exemptionfunc(ifstream& files, char marital, int children, float exemptions) {
	switch (marital) {
		case 'M': {
				exemptions = 6000 + (700 * 2) + (700 * children);
				break;
		}
		case 'S': {
				exemptions = 3000 + 700 + (700 * children);
				break;
		}
		default: {
				exemptions = 700 + (700 * children);
				break;
		}
	}
	return exemptions;
}
//********************************************************************************************************************
//********************************************************************************************************************
int errordata_m(ifstream& files, char marital, int errordataM) {
	switch (marital) {
		case 'M': {
				errordataM = 0;
				break;
		}
		case 'S': {
				errordataM = 0;
				break;
		}
		default: {
				errordataM = 1;
				break;
		}
	}
	return errordataM;
}
//********************************************************************************************************************
//********************************************************************************************************************
float taxincomefunc(ifstream& files, char marital, int children, float income, float pension, float deductions,
    float exemptions, float taxincome) {
	deductions = pension * income;
	exemptions = exemptionfunc(files, marital, children, exemptions);
	taxincome = (income - exemptions) - deductions;
	return taxincome;
}
//********************************************************************************************************************
//********************************************************************************************************************
float taxowedfunc(ifstream& files, float taxincome, float taxowed) {
	if (taxincome <= 20000.00) {
		taxowed = (0.15 * taxincome);
	}
	if (taxincome >= 20000.01 && taxincome <= 50000.00) {
		taxowed = (0.25 * taxincome) + 2250;
	}
	if (taxincome >= 50000.01) {
		taxowed = (0.35 * taxincome) + 8460;
	}
	return taxowed;
}
//********************************************************************************************************************
//********************************************************************************************************************
int errordata_p(ifstream& files, int errordataP, float pension) {
	if (pension >= .06) {
		errordataP = 1;
	}
	if (pension <= .05) {
		errordataP = 0;
	}
	return errordataP;
}
//********************************************************************************************************************
//********************************************************************************************************************
int openfiles(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, int errorcheck) {
	cout << "Please tell me your file name.\n";
	cin >> filename;
	files.open(filename.c_str());
	outfile.open("Outputfile.txt");
	errorfile.open("Errorfile.txt");
	if (files.is_open()) {
		errorcheck=1;
	}
	else {
		cout << "Could not open file.  Please exit program.\n";
		errorcheck=0;
	}
	return errorcheck;
}
//********************************************************************************************************************
//********************************************************************************************************************
void closefiles(ifstream& files, ofstream& outfile, ofstream& errorfile) {
	files.close();
	outfile.close();
	errorfile.close();
}
//********************************************************************************************************************
//********************************************************************************************************************
void readdata(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, string lastname, string errormessageM,
	string errormessageP, char marital, int children, int errordataM, int errordataP, float income,
	float pension, float deductions, float taxincome, float taxowed, float exemptions) {
			if (files.is_open()) {
                outputheader(files, outfile);
				do {
					files >> lastname >> marital >> children >> income >> pension;
					errordataM = errordata_m(files, marital, errordataM);
					errordataP = errordata_p(files, errordataP, pension);
                    taxincome = taxincomefunc(files, marital, children, income, pension, deductions, exemptions, taxincome);
                    taxowed = taxowedfunc(files, taxincome, taxowed);
                    exemptions = exemptionfunc(files, marital, children, exemptions);
					outputdata(files, outfile, errorfile, filename, lastname, errormessageM, errormessageP, marital, children,
						errordataM, errordataP, income, pension, deductions, taxincome, taxowed, exemptions);
                } 	while (files);
			}
			if (outfile.is_open()) {
				cout << "======================================================================\n";
				cout << "Saved output file successfully.  You can find it as 'Outputfile.txt' at your convenience.\n";
			}
			else {
				cout << "Could not save output file.\n";
			}
			if (errorfile.is_open()) {
				cout << "Errors were successfully logged.  You can find them in 'Errorfile.txt' at your convenience.\n";
			}
			else {
				cout << "Could not save error log.\n";
			}
}
//********************************************************************************************************************
//********************************************************************************************************************
void outputheader(ifstream& files, ofstream& outfile) {
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
}
//********************************************************************************************************************
//********************************************************************************************************************
void outputdata(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, string lastname, string errormessageM,
	string errormessageP, char marital, int children, int errordataM, int errordataP, float income, float pension,
	float deductions, float taxincome, float taxowed, float exemptions) {
		if (files) {
			if (errordataM == 0 && errordataP == 0) {
				cout 	<< fixed << showpoint << setprecision(2);
				cout 	<< setw(7) << left << lastname << "  "
						<< setw(1) << left << "$" << setw(10)<< left << income << "  "
						<< setw(1) << left << "$" << setw(8) << left << exemptions << "  "
						<< setw(1) << left << "$" << setw(7) << left << pension * income << " "
						<< setw(1) << left << "$" << setw(12)<< left << taxincome << "  "
						<< setw(1) << left << "$" << setw(8) << left << taxowed << "  " << "\n";
				outfile	<< fixed << showpoint << setprecision(2);
				outfile << setw(7) << left << lastname << "  "
						<< setw(1) << left << "$" << setw(10)<< left << income << "  "
						<< setw(1) << left << "$" << setw(8) << left << exemptions << "  "
						<< setw(1) << left << "$" << setw(7) << left << pension * income << " "
						<< setw(1) << left << "$" << setw(12)<< left << taxincome << "  "
						<< setw(1) << left << "$" << setw(8) << left << taxowed << "  " << "\n";
			}
			else {
				errorout(files, outfile, errorfile, filename, lastname, errormessageM, errormessageP, marital,
					children, errordataM, errordataP, income, pension, deductions, taxincome, taxowed, exemptions);
			}
		}
}
//********************************************************************************************************************
//********************************************************************************************************************
void errorout(ifstream& files, ofstream& outfile, ofstream& errorfile, string filename, string lastname, string errormessageM,
	string errormessageP, char marital, int children, int errordataM, int errordataP, float income, float pension,
	float deductions, float taxincome, float taxowed, float exemptions) {

	errorfile	<< fixed << showpoint << setprecision(2);
    errorfile   << setw(7) << left << lastname << "  "
                << setw(1) << left << "$" << setw(10)<< left << income << "  "
                << setw(1) << left << "$" << setw(8) << left << exemptions << "  "
                << setw(1) << left << "$" << setw(7) << left << pension * income << " "
                << setw(1) << left << "$" << setw(12)<< left << taxincome << "  "
                << setw(1) << left << "$" << setw(8) << left << taxowed << "  ";
				if (errordataM == 1 && errordataP == 1) {
				errorfile  << setw(23)<< left << errormessageM
                           << setw(23)<< left << errormessageP
                           << "\n";
				}
				if (errordataM == 1 && errordataP == 0) {
				errorfile  << setw(23)<< left << errormessageM
                           << "\n";
				}
				if (errordataM == 0 && errordataP == 1) {
				errorfile  << setw(23)<< left << errormessageP
                           << "\n";
				}
}
//********************************************************************************************************************
//********************************************************************************************************************
