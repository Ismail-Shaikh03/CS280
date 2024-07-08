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
        cout<< (*it).first<<": "<<it->second<<endl<<endl;
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
    bool flagLetter=false,flagDigit=false,flagPunct=false;
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
    for(int i=2;i<argc;i++){
        if(string(argv[i])=="-all"){
            flagLetter=true;
            flagDigit=true;
            flagPunct=true;
            break;
        }
        if(string(argv[i])=="-L"){
            flagLetter=true;
        }
        if(string(argv[i])=="-D"){
            flagDigit=true;
        }
        if(string(argv[i])=="-P"){
            flagPunct=true;
        }
    }
    if(flagLetter &&!letterCount.empty()){
        cout<<"List of Letters seen in the file and their number of occurrences:"<<endl;
        printMap(letterCount);
    }
    if(flagDigit&&!digitCount.empty()){
        cout<<"List of Digits seen in the file and their number of occurrences:"<<endl;
        printMap(digitCount);
    }
    if(flagPunct&&!punctionCount.empty()){
        cout<<"List of Punctuations seen in the file and their number of occurrences:"<<endl;
        printMap(punctionCount);
    }
    return 0;
}