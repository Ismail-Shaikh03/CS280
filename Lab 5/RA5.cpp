#include "lex.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, Token> stringToToken={
		{"PROGRAM", PROGRAM },
		{"PRINT", PRINT},
		{"IF",  IF},
		{"ELSE" ,  ELSE},	
		{ "IDENT", IDENT },
		{ "END", END },
		{ "INTEGER", INTEGER },
		{ "REAL", REAL },
		{ "CHARACTER", CHARACTER },
		{ "THEN", THEN },
        {"LEN",LEN},
        };
map<Token,string> tokenToString={
    {PROGRAM, "PROGRAM"},
    {PRINT,"PRINT"},
    {IF,"IF"},
    {ELSE,"ELSE"},
    {IDENT,"IDENT"},
    {END,"END"},
    {INTEGER,"INTEGER"},
    {REAL,"REAL"},
    {CHARACTER,"CHARACTER"},
    {THEN,"THEN"},
    {LEN,"LEN"},
    };
ostream& operator<<(ostream& out, const LexItem& tok){
    Token token=tok.GetToken();
    if(token==IDENT){
        out<<"IDENT: '"<<tok.GetLexeme()<<"'";
    }
    if(token>=IF && token<=LEN){
        out<<tokenToString[token]<<": Keyword";
    }
    if(token==ICONST){
        out<<"ICONST: ("<<tok.GetLexeme()<<")";
    }
    if(token==RCONST){
        out<<"RCONST: ("<<tok.GetLexeme()<<")";
    }
    if(token==SCONST){
        out<<"SCONST: \""<<tok.GetLexeme()<<"\"";
    }
    if(token==DOT){
        out<<"DOT: "<<"Delimiter Character \""<<tok.GetLexeme()<<"\"";
    }
    if(token==DCOLON){
        out<<"DCOLON: "<<"Delimiter Character \""<<tok.GetLexeme()<<"\"";
    }
    if(token==COMMA){
        out<<"COMMA: "<<"Delimiter Character \""<<tok.GetLexeme()<<"\"";
    }
    if(token==DEF){
        out<<"DEF: "<<"Delimiter Character \""<<tok.GetLexeme()<<"\"";
    }
    if(token==RPAREN){
        out<<"RPAREN: "<<"Delimiter Character \""<<tok.GetLexeme()<<"\"";
    }
    if(token==LPAREN){
        out<<"LPAREN: "<<"Delimiter Character \""<<tok.GetLexeme()<<"\"";
    }
    if(token==EQ){
        out<<"EQ: "<<"Operator Symbol \""<<tok.GetLexeme()<<"\"";
    }
    if(token==ASSOP){
        out<<"ASSOP: "<<"Operator Symbol \""<<tok.GetLexeme()<<"\"";
    }
    if(token==MULT){
        out<<"MULT: "<<"Operator Symbol \""<<tok.GetLexeme()<<"\"";
    }
    if(token==ERR){
        out<<"ERR: {"<<tok.GetLexeme()<<"} Error at line no. "<<tok.GetLinenum();
    }
    return out;

}
LexItem id_or_kw(const string& lexeme, int linenum){
    Token returnToken=IDENT;
    string newLexeme="";
    for(int i=0; i<lexeme.length();i++){
        newLexeme+=lexeme[i];
    }
    auto it=stringToToken.find(newLexeme);
    if(it!=stringToToken.end()){
        returnToken=it->second;
    }
    return LexItem(returnToken,newLexeme,linenum);
}