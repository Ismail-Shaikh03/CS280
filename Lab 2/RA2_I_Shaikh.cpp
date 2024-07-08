//Ismail Shaikh
//Lab 2
//CS280-008

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ifstream inputFile;
    string fileName,maxLine="",maxWord="",currentLine="",currentWord;
    int totalNumLines=0,totalUnCommentedLines,totalCommentedLines=0,totalNumWords=0;
    cout << "Enter the name of a file to read from: "<<endl;
    cin >> fileName;

    inputFile.open(fileName.c_str());
    if(!inputFile){
        cerr <<endl;
        cerr << "File cannot be opened " <<fileName <<endl;
        exit(1);
    }
    while(getline(inputFile,currentLine)){
        totalNumLines++;
        if(currentLine.substr(0,1)=="#" || currentLine.substr(0,2)=="//"){
            totalCommentedLines++;
            continue;
        }
        if(currentLine.length()>maxLine.length()){
            maxLine=currentLine;
        }
        istringstream word(currentLine);
        while(word){
            word>>currentWord;
            if(word){
                totalNumWords++;
                if(currentWord.length()>maxWord.length()){
                    maxWord=currentWord;
                }
            }
            }
        }
    totalUnCommentedLines=totalNumLines-totalCommentedLines;
    cout<<endl;
    cout<<"Total Number of Lines: "<<totalNumLines<<endl;
    cout<<"Number of non-commented lines: "<<totalUnCommentedLines<<endl;
    cout<<"Line of Maximum Length: \""<<maxLine<<"\""<<endl;
    cout<<"Number of Words: "<<totalNumWords<<endl;
    cout<<"Word of Maximum Length: \""<<maxWord<<"\""<<endl; 
    return(0);
}