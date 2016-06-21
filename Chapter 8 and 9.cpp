#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// global variables; are used anywhere within the program without re-definition

	int open_file(ifstream& inData, int count, string ifileName, string ofileName);
	void read_file(ifstream& inData, ofstream& outData, int count, string ofileName, string ifileName);
	void close_file(ifstream& inData, ofstream& outData, int count, string ofileName, string ifileName);

int main () 
{
	
	ifstream inData;
	ofstream outData;
	string ifileName, ofileName;
	int numValues, total, i, num, count;
	float avg;
	count = open_file(inData, count, ifileName, ofileName);
		if (count == 0)
		{
			cout << "File did not open.  Close program.\n";
			return 0;
		}
	read_file(inData, outData, count, ofileName, ifileName);
	close_file(inData, outData, count, ofileName, ifileName);
		
    return 0;
}

int open_file(ifstream& inData, int count, string ifileName, string ofileName)
{
	ifileName = "inFile.txt";
  	inData.open(ifileName.c_str());
  	if (!inData) 
  	{
    	cout << "Error opening file: " << ifileName << ".  Exiting program..." << endl;
	}
	if (inData.is_open())
	{
		count = 1;
	}
		return count;	
}

void read_file(ifstream& inData, ofstream& outData, int count, string ofileName, string ifileName)
{
	float avg;
	int i, num, total, numValues;

	inData >> numValues;

	for (i = 0; i < numValues; i++) 
	{
    	inData >> num;
    	total += num;
 	}
 		
 	avg = float(total) / float(numValues);

  	ofileName = "outFile.txt";
  	outData.open(ofileName.c_str());
  	if (!outData) 
  	{
    	cout << "Error opening file: " << ofileName << ".  Exiting program..." << endl;
  	}
	cout << "You entered " << numValues << " numbers totaling "  <<  total << " with a average of " << avg << endl;
  	outData <<  "You entered " << numValues << " numbers totaling "  <<  total << " with a average of " << avg << endl;
}

void close_file(ifstream& inData, ofstream& outData, int count, string ofileName, string ifileName)
{
	inData.close();
  	outData.close();
}

  	

  
  

  

  

