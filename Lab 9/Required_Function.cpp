#include <iostream>
#include <cctype>
#include <vector>
#include "Required_Classes.h"
using namespace std;
//function will check if the person's is a newsubscriber or already on the list
void CheckMultipleSubscriptions(NewsPaperSubscriber * NewSubscriber,vector< NewsPaperSubscriber * > &SubscribersList,vector< NewsPaperSubscriber * > &RejectedList){
    //for loop check subscription list, if address foun then put on rejectec list
    for(int i=0;i<SubscribersList.size();i++){
        if(NewSubscriber->getAddress()==SubscribersList[i]->getAddress()){
            RejectedList.push_back(NewSubscriber);
            return;
        }
    }
    //if not found then put on subscribers list
    SubscribersList.push_back(NewSubscriber);
}
