#include <string>
using namespace std;

int CountVowels(string str){
    char ch=str[0];
    if(str.length()==0){
        return 0;
    }
    if(ch=='A'|| ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return 1+CountVowels(str.substr(1));
    }
    else{
        return CountVowels(str.substr(1));
    }
}