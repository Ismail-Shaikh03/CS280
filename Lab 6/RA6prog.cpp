#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int CountVowels(string str);

int main(int argc, char *argv[])
{
	string instr;
	int result;
	
	ifstream  file ;

	if (argc == 1)
	{
		cerr << "NO SPECIFIED INPUT FILE." << endl;
		return 0;
	}
	else
	{
		file.open(argv[1]);
		if( file.is_open() == false ) {
			cerr << "CANNOT OPEN THE FILE " << argv[1] << endl;
			return 0;
		}

	}
	
	 getline(file, instr);
		
	//getline(cin, instr);
	
	result = CountVowels(instr);
	
	cout << "Number of vowels in string " << "\"" <<instr << "\"" << " is " << result <<endl;
	return 0;
}
