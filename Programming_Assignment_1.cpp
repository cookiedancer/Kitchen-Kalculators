//
//  Assignment One
//  Robert VanCleave
//  6/6/2016
//  cin, get, and getline inputs; cout and ifstream output
//  Program uses a series of functions to calculate studen names, majors, and grades
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//defines functions
void highest_grade(); 	//function to find the highest GPA
void average_grade(); 	//function to calculate average student GPA
void student_comparison();	//function to compare student grades to the average
void highest_comparison();	//function to compare student grades to the highest

ifstream records;
string 	students, firstname1, firstname2, firstname3, firstname4, firstname5,
					lastname1, lastname2, lastname3, lastname4, lastname5, 
		major1, major2, major3, major4, major5;
double gpa1, gpa2, gpa3, gpa4, gpa5, average1, highest1;

int main()
{
		cout << "Hello, I am Robert VanCleave going to compare student grades.\n";
		cout << "And I am going to be comparing studen data:\n\n";
		records.open("students.txt");
		records >> firstname1 >> lastname1 >> major1 >> gpa1;
		records.ignore(100, '\n');
		records >> firstname2 >> lastname2 >> major2 >> gpa2;
		records.ignore(100, '\n');
		records >> firstname3 >> lastname3 >> major3 >> gpa3;
		records.ignore(100, '\n');
		records >> firstname4 >> lastname4 >> major4 >> gpa4;
		records.ignore(100, '\n');
		records >> firstname5 >> lastname5 >> major5 >> gpa5;
		records.ignore(100, '\n');
		if (records.is_open())
		{
			highest_grade();
			average_grade();
			student_comparison();
			highest_comparison();
			records.close();
		}
		else 
		{
			"Could not find student records.  Exiting program...\n";
		}
	
	return 0;
}

void highest_grade() //function that calculates the highest grade
	{
		if (gpa1 >= gpa2 && gpa1 >= gpa3 && gpa1 >= gpa4 && gpa1 >= gpa5)
			{
			highest1 = gpa1;
			}
		if (gpa2 >= gpa1 && gpa2 >= gpa3 && gpa2 >= gpa4 && gpa2 >= gpa5)
			{
			highest1 = gpa2;
			}
		if (gpa3 >= gpa1 && gpa3 >= gpa2 && gpa3 >= gpa4 && gpa3 >= gpa5)
			{
			highest1 = gpa3;
			}
		if (gpa4 >= gpa1 && gpa4 >= gpa2 && gpa4 >= gpa3 && gpa4 >= gpa5)
			{
			highest1 = gpa4;
			}
		if (gpa5 >= gpa1 && gpa5 >= gpa2 && gpa5 >= gpa3 && gpa5 >= gpa4)
			{
			highest1 = gpa5;
			}
	}

void average_grade() //function that calculates the average grade
	{
		average1 = (gpa1 + gpa2 + gpa3 + gpa4 + gpa5) / 5;
	}

void student_comparison() //function that compares student grades to average grade
	{
		if (gpa1 < average1)
		{
			cout << firstname1 << " " << lastname1 << ", the " << major1 
			<< " major, is below the average grade of " << average1 << "\n";
		}
		if (gpa2 < average1)
		{
			cout << firstname2 << " " << lastname2 << ", the " 
			<< major2 << " major, is below the average grade of " << average1 << "\n";
		}
		if (gpa3 < average1)
		{
			cout << firstname3 << " " << lastname3 << ", the " << major3 
			<< " major, is below the average grade of " << average1 << "\n";
		}
		if (gpa4 < average1)
		{
			cout << firstname4 << " " << lastname4 << ", the " << major4 
			<< " major, is below the average grade of " << average1 << "\n";
		}
		if (gpa5 < average1)
		{
			cout << firstname5 << " " << lastname5 << ", the " << major5 
			<< " major, is below the average grade of " << average1 << "\n";
		}
	}

void highest_comparison() //function that compares student grades to highest grade
	{
		if (gpa1 == highest1)
		{
			cout << firstname1 << ", the " << major1 << " major, has reached the class's highest grade of " << highest1 << "\n";
		}
		if (gpa2 == highest1)
		{
			cout << firstname2 << ", the " << major2 << " major, has reached the class's highest grade of " << highest1 << "\n";
		}
		if (gpa3 == highest1)
		{
			cout << firstname3 << ", the " << major3 << " major, has reached the class's highest grade of " << highest1 << "\n";
		}
		if (gpa4 == highest1)
		{
			cout << firstname4 << ", the " << major4 << " major, has reached the class's highest grade of " << highest1 << "\n";
		}
		if (gpa5 == highest1)
		{
			cout << firstname5 << ", the " << major5 << " major, has reached the class's highest grade of " << highest1 << "\n";
		}
	}
