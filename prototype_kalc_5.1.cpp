// Kitchen Kalculator by Robert VanCleave
// Kitchen Kalculator determines a user's request and then converts it to their desired result
// Kitchen Kalculator offers conversions based on teaspoons, tablespoons, and cups
// Version 5.1

#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    
    int measure;
    char again;
    double teaspoons, tablespoons, cups;
    double teatotab, teatocup, tabtotea, tabtocup, cuptotea, cuptotab;
    //declares variables
    
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
    getline (cin,measure);

    //The following account for the possible user input
    
if (cin.fail())   //failsafe in case user inputs non-integer value for 'measure'
    {
        cin.clear();
        cin.ignore(100,'\n')
        cout << "Thinking outside the box, eh?" << endl;
        cout << "How's it feel to be so clever?" << endl;
        cout << "Too bad this is just a calculator rather than a pottery class." << endl;
        cout << "Maybe we should try again?" << endl << endl;
    }
    
switch (measure)
    {
    
    case 1:
        {
            //This is the prompt if the user selects 'teaspoons to tablespoons'
            cout << "Please tell me how many teaspoons we're converting today." << endl;
            getline (cin,teaspoons);
            teatotab = (teaspoons / 3.00);
            cout << teaspoons << " teaspoons is equal to " << teatotab << " tablespoons." << endl << endl;
            break;
        }
    
    case 2:
        {
            //This is the prompt if the user selects 'teaspoons to cups'
            cout << "Please tell me how many teaspoons we're converting today." << endl;
            getline (cin,teaspoons);
            teatocup = (teaspoons / 48.00);
            cout << teaspoons << " teaspoons is equal to " << teatocup << " cups." << endl << endl;
            break;
        }
    
    case 3:
        {
            //This is the prompt if the user selects 'tablespoons to teaspoons'
            cout << "Please tell me how many tablespoons we're converting today." << endl;
            getline (cin,tablespoons);
            tabtotea = (tablespoons * 3.00);
            cout << tablespoons << " tablespoons is equal to " << tabtotea << " teaspoons." << endl << endl;
            break;
        }
        
     case 4:
        {
            //This is the prompt if the user selects 'tablespoons to cups'
            cout << "Please tell me how many tablespoons we're converting today." << endl;
            getline (cin,tablespoons);
            tabtocup = (tablespoons / 16.00);
            cout << tablespoons << " tablespoons is equal to " << tabtocup << " cups." << endl << endl;
            break;
        }
    
     case 5:
        {
            //This is the prompt if the user selects 'cups to teaspoons'
            cout << "Please tell me how many cups we're converting today." << endl;
            getline (cin,cups);
            cuptotea = (cups * 48.00);
            cout << cups << " cups is equal to " << cuptotea << " teaspoons." << endl << endl;
            break;
        }
        
    case 6:
        {
            //This is the prompt if the user selects 'cups to tablespoons'
            cout << "Please tell me how many cups we're converting today." << endl;
            getline (cin,cups);
            cuptotab = (cups * 16.00);
            cout << cups << " cups is equal to " << cuptotab << " tablespoons." << endl << endl;
            break;
        }
        
    default:
        {   
            //This is the prompt if the user inputs a number larger than 6
            cout << "You're a clever one" << endl;
            cout << "Too bad this is just a calculator rather than expressive poetry." << endl;
            cout << "Hopefully you followed your recipe closer than you have these instructions." << endl;
            cout << "Maybe we should try again?" << endl << endl;
            break;
        }

} // end switch
    
    cout << "Are you doing another conversion?" << endl;
    cout << "Type anything (except 'Q') to try again." << endl;
    cout << "Type 'Q' to quit." << endl << endl;
    getline (cin,again);
        
} while (again != 'Q');
        
    return 0;
}
