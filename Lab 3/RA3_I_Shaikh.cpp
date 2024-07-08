//Ismail Shaikh
//Lab 3
//CS280-008

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

bool checkUnSignedInteger(string word){
    if(isdigit(word[0])){
        for(char character : word){
            if(!isdigit(character)){
                return false;
            }
        }
        return true;
    }
    return false;
}
bool checkName(string word){
    if(isalpha(word[0])){
        for(char character : word){
            if(!isalnum(character)&&character!='_'&&character!='@'){
                return false;
            }
        }
        return true;
    }
    return false;
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
    int totalNumLines=0,blankLines=0,unBlankLines=0,totalNumWords=0,fiveCharMore=0,fiveCharLess=0,namesCounter=0,unSignedInteger=0;
    while(getline(inputFile,currentLine)){
        totalNumLines++;
        if(currentLine.empty()){
            blankLines++;
        }
        
        istringstream wStream(currentLine);
        while(wStream){
            wStream>>currentWord;
            if(wStream){
                totalNumWords++;
                if(currentWord.length()>5){
                    fiveCharMore++;
                }
                if(currentWord.length()<=5){
                    fiveCharLess++;
                }
                if(checkUnSignedInteger(currentWord)){
                    unSignedInteger++;
                }
                if(checkName(currentWord)){
                    namesCounter++;
                }
            
            }     
        
        }
    }
        if(totalNumLines==0){
            cout<<"File is empty."<<endl;
            exit(1);
            } 
    unBlankLines=totalNumLines-blankLines;
    cout<<"Total Number of Lines: "<<totalNumLines<<endl;
    cout<<"Number of non-blank lines: "<<unBlankLines<<endl;
    cout<<"Number of Words: "<<totalNumWords<<endl;
    cout<<"Number of Integers: "<<unSignedInteger<<endl;
    cout<<"Number of Names: "<<namesCounter<<endl;
    cout<<"Number of Words Less Than or Equal to 5 Characters: "<<fiveCharLess<<endl;
    cout<<"Number of Words Greater Than 5 Characters: "<<fiveCharMore<<endl;
    return 0;
}