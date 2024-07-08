//
//
//  Lab1
//  Ismail Shaikh
//  CS280-008
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    string firstName,lastName;
    int sectionNumber;
    cout << "Please enter your first name >>" <<endl;
    cin >> firstName;
    cout << "Please enter your last name >>" <<endl;
    cin >> lastName;
    cout << "Please enter your CS 280 section number >>" <<endl;
    cin >> sectionNumber;
    cout << "Hello " << firstName << ", welcome to CS 280 section " << sectionNumber <<endl;
    return 0;
}
