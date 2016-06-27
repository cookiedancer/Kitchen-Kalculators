//
// Robert VanCleave
// Chapter 11 Lab
// Uses cin and ifstream input; and cout and outfile output
// Program utilizes functions to output data
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readfile(ifstream& files, ofstream& outfile, string filename, string outname, int howmany, int m, int first_array[]);
//*************************************************************************************************************************
//*************************************************************************************************************************
int main()
{
	ifstream files;
	ofstream outfile;
	int howmany, m, first_array[20];
	string filename, outname;
	
	cout << "Please tell me your input file name.\n";
	cin >> filename;
	cout << "Now please tell me your output file name.\n";
	cin >> outname;
	readfile(files, outfile, filename, outname, howmany, m, first_array);
			
return 0;
}
//*************************************************************************************************************************
//*************************************************************************************************************************
void readfile(ifstream& files, ofstream& outfile, string filename, string outname, int howmany, int m, int first_array[])
{
	files.open(filename.c_str());
	outfile.open(outname.c_str());
	
	if (files.is_open())
			{
				cout << "Please tell me how many numbers we're utilizing?\n";
				cin >> howmany;
				
				if (howmany<0 || howmany>20)
				{
					do
					{
						howmany=1;
						cout << "Please give a value over 0 but less than 20.\n";
						cin >> howmany;
					} while (howmany<0 || howmany>20);
				}
				
				if (howmany>0 && howmany<20)
				{
					for (m=0; m < howmany; m++)
					{
						files >> first_array[m];
						cout << "array[" << m << "]" << "=" << first_array[m] << "\n";
						outfile << "array[" << m << "]" << "=" << first_array[m] << "\n";
					}
					
				}
			}
			
			files.close();
			outfile.close();
}
