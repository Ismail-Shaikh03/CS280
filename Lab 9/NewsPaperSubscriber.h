// NewsPaperSubscriber.h
// NewsPaperSubscriber class definition.

#ifndef NewsPaperSubscriber_H
#define NewsPaperSubscriber_H

#include <string>  
#include "Address.h"

using std::string;

class NewsPaperSubscriber {
	//Abstarct Class
	protected:
		Address st_Address;
		double rate;
	
	public:
	
	NewsPaperSubscriber()
	{
		Address newAddr;
		st_Address = newAddr;
	}
	
	NewsPaperSubscriber(Address Addr)
	{
		st_Address = Addr;
				
	}
	
	Address getAddress()
	{
		return st_Address;
	}
	
	double getRate()
	{
		return rate;
	}
	
	void setAddress(Address newAddress)
	{
		st_Address = newAddress;
	}
	
	virtual double setRate() = 0;
	
	bool operator==(NewsPaperSubscriber* customer)
	{
		if (st_Address == customer->getAddress())
			return true;
		
		return false;
	}
	
   // displays subscriber's information: address, rate, and service type
   virtual void print() const = 0 ;     // output subscriber's info

}; // end class 


#endif

