//Ismail Shaikh
//Lab 4
//CS280-008

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

void printMap(map<char,int>& inputMap){
    for(auto it=inputMap.begin();it!=inputMap.end();it++){
        cout<< (*it).first<<": "<<it->second<<endl;
    }

}
int main(int argc,char* argv[]){
    ifstream inputFile;
    string fileName;
    if(argc!=1){
        fileName=argv[1];
    }
    else{
        
        cerr << "NO SPECIFIED INPUT FILE NAME."<<endl;
        exit(1);
        
    }
    inputFile.open(fileName.c_str());
    if(!inputFile.is_open()){
        cerr << "CANNOT OPEN THE FILE: "<<argv[1]<<endl;
        exit(1);
    }
    string currentLine,currentWord;
    int totalNumLines=0;
    map<char,int> letterCount,digitCount,punctionCount;
    while(getline(inputFile,currentLine)){
        totalNumLines++;
        istringstream wStream(currentLine);
        while(wStream){
            wStream>>currentWord;
            if(wStream){
                for(char c : currentWord){
                    if(isalpha(c)){
                        letterCount[toupper(c)]++;
                    }
                    if(isdigit(c)){
                        digitCount[c]++;
                    }
                    if(ispunct(c)){
                        punctionCount[c]++;
                    }
                }
            }
            }
    }
    if(totalNumLines==0){
        cout<<"File is empty."<<endl;
        exit(1);
        }
    int highestOccurLetter=0,highestOccurDigit=0,highestOccurPunct=0;
    char highestLetter,highestDigit,highestPunct;
    for(auto it=letterCount.begin();it!=letterCount.end();it++){
        if(it->second>highestOccurLetter){
            highestLetter=it->first;
            highestOccurLetter=it->second;
        }
    }
    for(auto it=digitCount.begin();it!=digitCount.end();it++){
        if(it->second>highestOccurDigit){
            highestDigit=it->first;
            highestOccurDigit=it->second;
        }
    }
    for(auto it=punctionCount.begin();it!=punctionCount.end();it++){
        if(it->second>highestOccurPunct){
            highestPunct=it->first;
            highestOccurPunct=it->second;
        }
    }
    if(!letterCount.empty()){
        cout<<"Letter of Largest number of occurrences: "<<highestLetter<<" occurred "<<highestOccurLetter<<" times"<<endl;
    }
    if(!digitCount.empty()){
        cout<<"Digits of Largest number of occurrences: "<<highestDigit<<" occurred "<<highestOccurDigit<<" times"<<endl;
    }
    if(!punctionCount.empty()){
        cout<<"Punctuations of Largest number of occurrences: "<<highestPunct<<" occurred "<<highestOccurPunct<<" times"<<endl;
    }
    if( (argc>=4)&& (string(argv[2])=="-L" || string(argv[3])=="-L")){
        cout<<"List of Letters seen in the file and their number of occurrences:"<<endl;
        printMap(letterCount);
    }
    if((argc>=4)&& (string(argv[2])=="-D" || string(argv[3])=="-D")){
        cout<<"List of Digits seen in the file and their number of occurrences:"<<endl;
        printMap(digitCount);
    }
    if((argc>=4)&&(string(argv[2])=="-P" || string(argv[3])=="-P")){
        cout<<"List of Punctuations seen in the file and their number of occurrences:"<<endl;
        printMap(punctionCount);
    }
    if((argc>=4)&&(string(argv[2])=="-all")){
        cout<<"List of Letters seen in the file and their number of occurrences:"<<endl;
        printMap(letterCount);
        cout<<"List of Digits seen in the file and their number of occurrences:"<<endl;
        printMap(digitCount);
        cout<<"List of Punctuations seen in the file and their number of occurrences:"<<endl;
        printMap(punctionCount);
    }
    return 0;
}