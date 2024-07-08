#ifndef Required_Classes_File
#define Required_Classes_File
#include <iostream>
#include<cctype>
#include "NewsPaperSubscriber.h"
using namespace std;
//Weekly Subscriber child class
class WeeklySubscriber:public NewsPaperSubscriber{
    public:
    WeeklySubscriber(Address personAddress)://constructor with person's address
    NewsPaperSubscriber(personAddress){
        setRate();//will set rate to 10.5
    }
    WeeklySubscriber()://constructor without person's adress
    NewsPaperSubscriber(){
        setRate();//will set rate to 10.5
    }
    //setRate function that will take the refrence to the current aka,this, and make the rate 10.5
    double setRate(){
        return this->rate=10.5;//will set rate to 10.5
    }
    //print function which will output the street address, the rate weekend rate, and service type
    void print() const{
        cout<<this->st_Address.AddrContents()<<endl;//prints out street address
        cout<<"Rate: 10.5"<<endl;
        cout<<"Service Type: Weekly Subscriber"<<endl;
    }
};
//Weekday child class
class WeekdaysSubscriber:public NewsPaperSubscriber{
    public:
    WeekdaysSubscriber(Address personAddress)://constructor that takes person's address
    NewsPaperSubscriber(personAddress){
        setRate();//will set rate to 7.5
    }
    WeekdaysSubscriber():
    NewsPaperSubscriber(){
        setRate();//will set rate to 7.5
    }
    double setRate(){
        return this->rate=7.5;//will set rate to 7.5
    }
    void print() const{
        cout<<this->st_Address.AddrContents()<<endl;//will print person's address
        cout<<"Rate: 7.5"<<endl;
        cout<<"Service Type: Week Days Subscriber"<<endl;
    }
};
//Weekend child class
class WeekendSubscriber:public NewsPaperSubscriber{
    public:
    WeekendSubscriber(Address personAddress)://constructor with address
    NewsPaperSubscriber(personAddress){
        setRate();//will set rate to 4.5
    }
    WeekendSubscriber()://constructor without address
    NewsPaperSubscriber(){
        setRate();//will set rate to 4.5
    }
    double setRate(){
        return this->rate=4.5;//will set rate to 4.5
    }
    void print() const{
        cout<<this->st_Address.AddrContents()<<endl;//will print person's address
        cout<<"Rate: 4.5"<<endl;
        cout<<"Service Type: Weekend Subscriber"<<endl;
    }
};
//this function will go to Required_Function.cpp
void CheckMultipleSubscriptions(NewsPaperSubscriber * NewSubscriber,vector< NewsPaperSubscriber * > &SubscribersList,vector< NewsPaperSubscriber * > &RejectedList);


#endif