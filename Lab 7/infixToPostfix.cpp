//Postfix to Infix using a stack
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedenceChecker(char ch){
    if(ch== '^'){
        return 3;
    }else if(ch=='*' || ch=='/'){
        return 2;
    }else if(ch=='-' || ch=='+'){
        return 1;
    }else{
        return -1;
    }
}
string InfixToPostfix(string instr){
    string outputStatement;
    stack<char> operandStack;
    for(int i=0;i<instr.length();i++){
        if(isalpha(instr[i])){
            outputStatement+=instr[i];
        }else if(isspace(instr[i])){
            continue;
        }else if(instr[i]=='('){
            operandStack.push(instr[i]);
        }else if(instr[i]=='+' || instr[i]=='*' || instr[i]=='/'||instr[i]=='-' || instr[i]=='^'){
            while(!operandStack.empty() && precedenceChecker(instr[i])<=precedenceChecker(operandStack.top())){
                outputStatement+=" ";
                outputStatement+=operandStack.top();
                operandStack.pop();
            }
            operandStack.push(instr[i]);
            outputStatement+=" ";
        }else if(instr[i]==')'){
            while(!operandStack.empty()&&operandStack.top()!='('){
                outputStatement+=" ";
                outputStatement+=operandStack.top();
                operandStack.pop();
            }
            operandStack.pop();
        }
    }
    while(!operandStack.empty()){
        outputStatement+=" ";
        outputStatement+=operandStack.top();
        operandStack.pop();
    }
    if(outputStatement.length()==0){
        return outputStatement;
    }
    outputStatement+=" ";
    return outputStatement;
}

string PostfixToInfix(string token){
    string a, b;
    stack<string> operandStack;
    for(int i=0;i<token.length();i++){
        if(isspace(token[i])){
            continue;
        }
    if(islower(token[i])){
        operandStack.push(token.substr(i,1));
    }else{
        a=operandStack.top();
        operandStack.pop();
        b=operandStack.top();
        operandStack.pop();
        operandStack.push(
            "("+b+" "+token.substr(i,1)+" "+ a+")"
            );
        }
        }
    if(token.length()==0){
        return"";
    }
return operandStack.top();
}