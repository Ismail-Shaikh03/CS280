#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>


using namespace std;

string InfixToPostfix(string instr);
string PostfixToInfix(string token);

int main(int argc, char *argv [])
{
	string sentence, outStr;
	
	int Lcount=0;
	bool toinfix = false, topost=false;
	
	ifstream file;
	if( argc >= 2 ) {
		file.open(argv[1]);
		if( !file) 
		{
			/* error */ 
			cerr << "File cannot be opened: " << argv[1] << endl;
			exit (1);
        }
        
        string arg( argv[2] );
		if( arg == "-toinfix" )
		toinfix = true;
		else if( arg == "-topost" )
		topost = true;
			
		else {
			cerr << "UNRECOGNIZED FLAG " << arg << endl;
			return 0;
		}
				
	}
	else
	{
		cerr << "No file is found" << endl;
		exit (1);
	}
	
	getline(file, sentence);
	  
    while ( !file.eof()) {
       	Lcount++;
       	if (toinfix)
       	{
       		outStr = PostfixToInfix(sentence);
       		cout << "Result of convering Postfix expression \"" << sentence 
			   << "\" to Infix notation: \"" << outStr << "\"" << endl;
	   }
       	else if(topost)
       	{
       		outStr = InfixToPostfix(sentence);
       		cout << "Result of convering Infix expression \"" << sentence 
			   << "\" to Postfix notation: \"" << outStr << "\"" << endl;
		}
       		
       	else
		   break;
		    	 	
		getline(file, sentence); 
	}
	
	return 0;
}
