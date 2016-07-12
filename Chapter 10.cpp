#include<iostream>
#include<string>
#include<cstdlib> // for system("pause")
using namespace std;

enum ratingType {N, G, PG, PG_13, R, NC_17};

struct movieType
{
  string       name;
  ratingType   rating;
  string       year;
  string       starredIn;
  char         didSee;
  char         opinion;
  
};

int main () {
  
  movieType aMovie;
  int ratingIn;
  
  cout << "Enter movie name: ";
  getline(cin, aMovie.name);
//  cin.get();
  cout << "Enter rating: " << endl;
  cout << "  1 - G " << endl;
  cout << "  2 - PG " << endl;
  cout << "  3 - PG-13 " << endl;
  cout << "  4 - R " << endl;
  cout << "  5 - NC-17 " << endl;
  cin >> ratingIn;
  aMovie.rating = ratingType(ratingIn);
  cin.get();
  
  cout << "Enter year movie produced: ";
  cin >> aMovie.year;
  cin.get();
  
  cout << "Enter the main Star of the movie: ";
  getline(cin, aMovie.starredIn);
  
  cout << "Did you see the movie (Y or N): ";
  cin >> aMovie.didSee;
  
  if (toupper(aMovie.didSee) == 'Y') {
    cout << "Did you LIKE the movie (Y or N): ";
    cin >> aMovie.opinion;
  }
  
  cout << "This is the information on the movie entered: " << endl;
  cout << "  Movie name: " << aMovie.name << ". Year: " << aMovie.year << endl << endl;
  cout << "  " << aMovie.starredIn << " starred in the film. " <<  endl << endl;
    
  switch(aMovie.rating) {
    case G:      cout << "  This movie is rated G:  General Audiences" << endl; break;
    case PG:     cout << "  This movie is rated PG : Parental Guidance Suggested" << endl; break;
    case PG_13:  cout << "  This movie is rated PG-13:  Parent's Strongly Cautioned" << endl; break;
    case R:      cout << "  This movie is rated R:  Under 17 requires accompanying adult or adult guardian" << endl; break;
    case NC_17:  cout << "  This movie is rated NC-17: No one under 17 and under admitted" << endl; break;
    default:     cout << "  Could not determine movie rating" << endl;
  }
  cout << endl;
  if (toupper(aMovie.didSee) == 'Y') {
    cout << "  You did see the movie ";
    if (toupper(aMovie.opinion) == 'Y')
      cout << "and you liked it." << endl;
    else
      cout << "but you did not like it." << endl;
  }
  else {
    cout << "  You did not see the movie." << endl;
  }
  cout << endl;
  system("pause");
}
