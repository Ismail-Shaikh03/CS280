//Program for testing news paper subscribers 

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream> 
#include <iterator>

#include "NewsPaperSubscriber.h"    // Class definitions 
#include "Required_Classes.h"

void CheckMultipleSubscriptions(NewsPaperSubscriber * NewSubscriber, vector< NewsPaperSubscriber * > &SubscribersList, 
		vector< NewsPaperSubscriber * > &RejectedList);
		
using namespace std;
     
int main(int argc, char *argv [])
{
	ifstream file;
    vector< NewsPaperSubscriber * > SubscribersList;
    long zipcode;
	vector< NewsPaperSubscriber * >::iterator listitr, itr;
	NewsPaperSubscriber *NewSubscriber;
	vector< NewsPaperSubscriber * > RejectedList;
	
		
	string street, city, state, str;
	int type;
	
    if( argc >= 2 ) {
		
		file.open(argv[1]);
		if( !file) 
		{
			/* error */ 
			cerr << "File cannot be opened: " << argv[1] << endl;
			exit (1);
        }		
	}
	else
	{
		cerr << "No file is found." << endl;
		exit (1);
	}
    
        
   	while (file >> type )
    {
    	file.ignore();
    	getline(file, street);
    	file >> city >> state >> zipcode;
    	
    	Address custAddress(street, city, state, zipcode);
        	
    	if(type == 1 /*"weekly"*/)
    	{
			NewSubscriber = new WeeklySubscriber(custAddress);
		}
		else if (type == 2 /*"weekdays"*/)
		{
			NewSubscriber = new WeekdaysSubscriber(custAddress);
		}
		else if (type == 3 /*"weekend"*/)
		{
			NewSubscriber = new WeekendSubscriber(custAddress);	
		}
		else
		{
			cout << "Incorrect subscription type" << endl;
			return 0;
		}
		
		CheckMultipleSubscriptions(NewSubscriber, SubscribersList, RejectedList);
		
	}
	
	cout << "List of new subscribers:" << endl <<endl;
	
    for ( int i = 0; i < SubscribersList.size(); i++ ) 
    {
    	(*SubscribersList[i]).print();
                                                           
		cout << endl;                                
	}
		
	cout << "List of rejected subscriptions:" << endl << endl;
    for ( int i = 0; i < RejectedList.size(); i++ ) 
    {
    	(*RejectedList[i]).print();
                                                           
		cout << endl;                                
	}
	return 0;
}



