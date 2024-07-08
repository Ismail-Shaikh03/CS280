//Postfix to Infix using a stack
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
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
        }else if(instr.at(i)=='('){
            operandStack.push(instr.at(i));
        }else if(instr.at(i)=='+' || instr.at(i)=='*' || instr.at(i)=='/'||instr.at(i)=='-'){
            operandStack.push(instr.at(i));
            outputStatement+=" ";
        }else if(instr.at(i)==')'){
            while(operandStack.top()!='('){
                outputStatement+=operandStack.top();
                operandStack.pop();
            }
            operandStack.pop();
        }else{
            while(!operandStack.empty() && precedenceChecker(instr[i])<=precedenceChecker(operandStack.top())){
                outputStatement+=operandStack.top();
                operandStack.pop();
            }
            operandStack.push(instr[i]);
        }
    }
    while(!operandStack.empty()){
        outputStatement+=operandStack.top();
        operandStack.pop();
    }
    return outputStatement;
}

string PostfixtoInfix(string token){
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
return operandStack.top();
}
