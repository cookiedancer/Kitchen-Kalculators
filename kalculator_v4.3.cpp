// Kitchen Kalculator determines a user's request and then converts it to their desired result
// Kitchen Kalculator offers conversions based on teaspoons, tablespoons, and cups
// Version 4.2

#include <iostream>
using namespace std;

    //int measure, teaspoons, tablespoons, cups, teatotab, tabtotea, teatocup, cuptotea, tabtocup, cuptotab;    
    // Declares variables
    
int main()
{
    
    int measure;
    double teaspoons, tablespoons, cups;
    double teatotab, teatocup, tabtotea, tabtocup, cuptotea, cuptotab;
    //declares variables
    
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
    
    //The following account for the possible user input
    
    if (measure == 1)
        {
            //This is the prompt if the user selects 'teaspoons to tablespoons'
            cout << "Please tell me how many teaspoons we're converting today." << endl;
            cin >> teaspoons;
            teatotab = (teaspoons / 3.00);
            cout << teaspoons << " teaspoons is equal to " << teatotab << " tablespoons." << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
    
    if (measure == 2)
        {
            //This is the prompt if the user selects 'teaspoons to cups'
            cout << "Please tell me how many teaspoons we're converting today." << endl;
            cin >> teaspoons;
            teatocup = (teaspoons / 48.00);
            cout << teaspoons << " teaspoons is equal to " << teatocup << " cups." << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
    
    if (measure == 3)
        {
            //This is the prompt if the user selects 'tablespoons to teaspoons'
            cout << "Please tell me how many tablespoons we're converting today." << endl;
            cin >> tablespoons;
            tabtotea = (tablespoons * 3.00);
            cout << tablespoons << " tablespoons is equal to " << tabtotea << " teaspoons." << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
        
     if (measure == 4)
        {
            //This is the prompt if the user selects 'tablespoons to cups'
            cout << "Please tell me how many tablespoons we're converting today." << endl;
            cin >> tablespoons;
            tabtocup = (tablespoons / 16.00);
            cout << tablespoons << " tablespoons is equal to " << tabtocup << " cups." << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
    
     if (measure == 5)
        {
            //This is the prompt if the user selects 'cups to teaspoons'
            cout << "Please tell me how many cups we're converting today." << endl;
            cin >> cups;
            cuptotea = (cups * 48.00);
            cout << cups << " cups is equal to " << cuptotea << " teaspoons." << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
        
    if (measure == 6)
        {
            //This is the prompt if the user selects 'cups to tablespoons'
            cout << "Please tell me how many cups we're converting today." << endl;
            cin >> cups;
            cuptotab = (cups * 16.00);
            cout << cups << " cups is equal to " << cuptotab << " tablespoons." << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
        
    if (measure > 6)
        {   
            //This is the prompt if the user inputs a number larger than 6
            cout << "Thinking outside the box?" << endl;
            cout << "Too bad this is just a calculator rather than expressive poetry." << endl;
            cout << "Hopefully you followed your recipe closer than you have these instructions." << endl;
            cout << "Maybe we should try again?" << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
        
    if (measure < 1)
        {
            //This is the prompt for input values less than 1
            cout << "You're a clever one." << endl;
            cout << "Too bad this is just a calculator rather than a pottery class." << endl;
            cout << "Maybe we should try again?" << endl << endl << endl;
            cout << "Click 'Execute' to initiate another conversion." << endl;
        }
        
    return 0;
}

