// Kitchen Kalculator by Robert VanCleave and Mallary Gilmore
// Kitchen Kalculator determines a user's request and then converts it to their desired result
// Kitchen Kalculator offers conversions based on teaspoons, tablespoons, and cups
// Version 5.4

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Defines failsafe functions
void troll_backup();
void troll_one();
void troll_two();
void troll_three();
void troll_four();
void troll_five();
void troll_six();
void troll_seven();
void troll_other();


int main()
{

    int measure;
    char again;
    double teaspoons, tablespoons, cups;
    double teatotab, teatocup, tabtotea, tabtocup, cuptotea, cuptotab;
    //declares variables

    ofstream intro;
    intro.open ("kalculator_intro.txt");
    intro << "Welcome to the Kitchen Kalculator.\n ";
    intro << "Making all of your Kulinary Konversion needs easier since yesterday afternoon.\n ";
    intro << "Need to convert teaspoons, tablespoons, or cups?\n ";
    intro << "Then you've come to the right place.\n ";
    intro << "If not, have fun on Google.\n " << endl << endl;
    intro.close();

    cout << "Welcome to the Kitchen Kalculator." << endl;
    cout << "Making all of your Kulinary Konversion needs easier since yesterday afternoon." << endl;
    cout << "Need to convert teaspoons, tablespoons, or cups?" << endl;
    cout << "Then you've come to the right place." << endl;
    cout << "If not, have fun on Google." << endl << endl << endl;

do
{

    //Prompt to determine what conversion type the user is seeking
    cout << "|--------------------------------------------|" << endl;
    cout << "Press 1 to convert teaspoons to tablespoons." << endl;
    cout << "Press 2 to convert teaspoons to cups." << endl;
    cout << "Press 3 to convert tablespoons to teaspoons." << endl;
    cout << "Press 4 to convert tablespoons to cups." << endl;
    cout << "Press 5 to convert cups to teaspoons." << endl;
    cout << "Press 6 to convert cups to tablespoons." << endl;
    cout << "|--------------------------------------------|" << endl;
    cin >> measure;

    //The following switch and if account for the possible user input

if (cin.fail())   //failsafe in case user inputs non-integer value for 'measure'
    {
        troll_other();
    }

if (measure > 6)
    {
        //This is the prompt if the user inputs a number larger than 6
        troll_seven();
    }

switch (measure)
    {

    case 1:
        {
            //This is the prompt if the user selects 'teaspoons to tablespoons'
            cout << "Please tell me how many teaspoons we're converting today." << endl;
            cin >> teaspoons;
                if (cin.fail())   //failsafe in case user inputs non-integer value for 'teaspoons'
                    {
                        troll_one();
                        cout << "How many teaspoons are we actually converting today?" << endl;
                        cin >> teaspoons;
                            if (cin.fail())   //failsafe in case user inputs a second non-integer value for 'teaspoons'
                            {
                                troll_backup();
                                cout << "How many teaspoons are we actually converting today?" << endl;
                                cin >> teaspoons;
                            }
                    }
            teatotab = (teaspoons / 3.00);
            cout << teaspoons << " teaspoons is equal to " << teatotab << " tablespoons." << endl << endl;
            break;
        }

    case 2:
        {
            //This is the prompt if the user selects 'teaspoons to cups'
            cout << "Please tell me how many teaspoons we're converting today." << endl;
            cin >> teaspoons;
                if (cin.fail())   //failsafe in case user inputs non-integer value for 'teaspoons'
                    {
                        troll_two();
                        cout << "How many teaspoons are we actually converting today?" << endl;
                        cin >> teaspoons;
                            if (cin.fail())   //failsafe in case user inputs a second non-integer value for 'teaspoons'
                            {
                                troll_backup();
                                cout << "How many teaspoons are we actually converting today?" << endl;
                                cin >> teaspoons;
                            }
                    }
            teatocup = (teaspoons / 48.00);
            cout << teaspoons << " teaspoons is equal to " << teatocup << " cups." << endl << endl;
            break;
        }

    case 3:
        {
            //This is the prompt if the user selects 'tablespoons to teaspoons'
            cout << "Please tell me how many tablespoons we're converting today." << endl;
            cin >> tablespoons;
                if (cin.fail())   //failsafe in case user inputs non-integer value for 'tablespoons'
                    {
                        troll_three();
                        cout << "How many tablespoons are we actually converting today?" << endl;
                        cin >> tablespoons;
                            if (cin.fail())   //failsafe in case user inputs a second non-integer value for 'tablespoons'
                            {
                                troll_backup();
                                cout << "How many tablespoons are we actually converting today?" << endl;
                                cin >> tablespoons;
                            }
                    }
            tabtotea = (tablespoons * 3.00);
            cout << tablespoons << " tablespoons is equal to " << tabtotea << " teaspoons." << endl << endl;
            break;
        }

     case 4:
        {
            //This is the prompt if the user selects 'tablespoons to cups'
            cout << "Please tell me how many tablespoons we're converting today." << endl;
            cin >> tablespoons;
                if (cin.fail())   //failsafe in case user inputs non-integer value for 'tablespoons'
                    {
                        troll_four();
                        cout << "How many tablespoons are we actually converting today?" << endl;
                        cin >> tablespoons;
                            if (cin.fail())   //failsafe in case user inputs a second non-integer value for 'tablespoons'
                            {
                                troll_backup();
                                cout << "How many tablespoons are we actually converting today?" << endl;
                                cin >> tablespoons;
                            }
                    }
            tabtocup = (tablespoons / 16.00);
            cout << tablespoons << " tablespoons is equal to " << tabtocup << " cups." << endl << endl;
            break;
        }

     case 5:
        {
            //This is the prompt if the user selects 'cups to teaspoons'
            cout << "Please tell me how many cups we're converting today." << endl;
            cin >> cups;
                if (cin.fail())   //failsafe in case user inputs non-integer value for 'cups'
                    {
                        troll_five();
                        cout << "How many cups are we actually converting today?" << endl;
                        cin >> cups;
                            if (cin.fail())   //failsafe in case user inputs a second non-integer value for 'cups'
                            {
                                troll_backup();
                                cout << "How many cups are we actually converting today?" << endl;
                                cin >> cups;
                            }
                    }
            cuptotea = (cups * 48.00);
            cout << cups << " cups is equal to " << cuptotea << " teaspoons." << endl << endl;
            break;
        }

    case 6:
        {
            //This is the prompt if the user selects 'cups to tablespoons'
            cout << "Please tell me how many cups we're converting today." << endl;
            cin >> cups;
                if (cin.fail())   //failsafe in case user inputs non-integer value for 'cups'
                    {
                        troll_six();
                        cout << "How many cups are we actually converting today?" << endl;
                        cin >> cups;
                            if (cin.fail())   //failsafe in case user inputs a second non-integer value for 'cups'
                            {
                                troll_backup();
                                cout << "How many cups are we actually converting today?" << endl;
                                cin >> cups;
                            }
                    }
            cuptotab = (cups * 16.00);
            cout << cups << " cups is equal to " << cuptotab << " tablespoons." << endl << endl;
            break;
        }

} // end switch

    cout << "Are you doing another conversion?" << endl;
    cout << "Type anything (except 'Q') to try again." << endl;
    cout << "Type 'Q' to quit." << endl << endl;
    cin >> again;

} while (again != 'Q');

    return 0;
}

// Function Implementations

void troll_backup() //function called if user inputs invalid data consecutively
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "You're having fun.\n";
    }

void troll_other() //function called if user inputs invalid data for 'measure'
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Thinking outside the box, eh?" << endl;
        cout << "Too bad this is just a calculator rather than a pottery class." << endl;
        cout << "Maybe we should try again?" << endl << endl;
    }

void troll_seven() //function called if user inputs 'measure' value larger than 6
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "You're a clever one" << endl;
        cout << "Too bad this is just a calculator rather than expressive poetry." << endl;
        cout << "Hopefully you followed your recipe closer than you have these instructions." << endl;
        cout << "Maybe we should try again?" << endl << endl;
    }

void troll_one() //function called if user inputs invalid 'teaspoon' value
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Thinking outside the box, eh?" << endl;
        cout << "Too bad this is just a calculator rather than interpretative dance." << endl;
        cout << "Maybe we should try again?" << endl;
    }

void troll_two() //function called if user inputs invalid 'teaspoon' value
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "You're far too clever for me." << endl;
        cout << "Too bad this is just a calculator rather than a Shakespearian soliloquy." << endl;
        cout << "Maybe we should try again?" << endl;
    }

void troll_three()
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "That's an odd measurement." << endl;
        cout << "But this calculator works better with tangible numbers than metaphysical hypotheticals." << endl;
        cout << "Maybe we should try again?" << endl;
    }

void troll_four()
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Sure wish I could convert that kind of measurement." << endl;
        cout << "Unfortunately calculators are not as open to interpretation as political talking points." << endl;
        cout << "Maybe we should try again?" << endl;
    }

void troll_five()
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "You're too clever." << endl;
        cout << "Too bad this is just a calculator rather than that cultured masterpiece you're working on." << endl;
        cout << "Maybe we should try again?" << endl;
    }

void troll_six()
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "I sure can't fool you, can I?" << endl;
        cout << "And to think I assumed only numbers would be entered into this field?" << endl;
        cout << "Maybe we should try again?" << endl;
    }
