#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "opCode.h"
using namespace std;

opCodes::opCodes()
{
    opTab["ADD"] = "18";
    opTab["ADDF"] = "58";
    opTab["ADDR"] = "90";
    opTab["AND"] = "40";
    opTab["CLEAR"] = "B4";
    opTab["COMP"] = "28";
    opTab["COMPF"] = "88";
    opTab["COMPR"] = "A0";
    opTab["DIV"] = "24";
    opTab["DIVF"] = "64";
    opTab["DIVR"] = "9C";
    opTab["FIX"] = "C4";
    opTab["FLOAT"] = "C0";
    opTab["HIO"] = "F4";
    opTab["J"] = "3C";
    opTab["JEQ"] = "30";
    opTab["JGT"] = "34";
    opTab["JLT"] = "38";
    opTab["JSUB"] = "48";
    opTab["LDA"] = "00";
    opTab["LDB"] = "68";
    opTab["LDCH"] = "50";
    opTab["LDF"] = "70";
    opTab["LDL"] = "08";
    opTab["LDS"] = "6C";
    opTab["LDT"] = "74";
    opTab["LDX"] = "04";
    opTab["LPS"] = "D0";
    opTab["MUL"] = "20";
    opTab["MULF"] = "60";
    opTab["MULR"] = "98";
    opTab["NORM"] = "C8";
    opTab["OR"] = "44";
    opTab["RD"] = "D8";
    opTab["RMO"] = "AC";
    opTab["RSUB"] = "4C";
    opTab["SHIFTL"] = "A4";
    opTab["SHIFTR"] = "A8";
    opTab["SIO"] = "F0";
    opTab["SSK"] = "EC";
    opTab["STA"] = "0C";
    opTab["STB"] = "78";
    opTab["STCH"] = "54";
    opTab["STF"] = "80";
    opTab["STI"] = "D4";
    opTab["STL"] = "14";
    opTab["STS"] = "7C";
    opTab["STSW"] = "E8";
    opTab["STT"] = "84";
    opTab["STX"] = "10";
    opTab["SUB"] = "1C";
    opTab["SUBF"] = "5C";
    opTab["SUBR"] = "94";
    opTab["SVC"] = "B0";
    opTab["TD"] = "E0";
    opTab["TIO"] = "F8";
    opTab["TIX"] = "2C";
    opTab["TIXR"] = "B8";
    opTab["WD"] = "DC";
    
    opFormat["ADD"] = "3/4";
    opFormat["ADDF"] = "3/4";
    opFormat["ADDR"] = "2";
    opFormat["AND"] = "3/4";
    opFormat["CLEAR"] = "2";
    opFormat["COMP"] = "3/4";
    opFormat["COMPF"] = "3/4";
    opFormat["COMPR"] = "2";
    opFormat["DIV"] = "3/4";
    opFormat["DIVF"] = "3/4";
    opFormat["DIVR"] = "2";
    opFormat["FIX"] = "1";
    opFormat["FLOAT"] = "1";
    opFormat["HIO"] = "1";
    opFormat["J"] = "3/4";
    opFormat["JEQ"] = "3/4";
    opFormat["JGT"] = "3/4";
    opFormat["JLT"] = "3/4";
    opFormat["JSUB"] = "3/4";
    opFormat["LDA"] = "3/4";
    opFormat["LDB"] = "3/4";
    opFormat["LDCH"] = "3/4";
    opFormat["LDF"] = "3/4";
    opFormat["LDL"] = "3/4";
    opFormat["LDS"] = "3/4";
    opFormat["LDT"] = "3/4";
    opFormat["LDX"] = "3/4";
    opFormat["LPS"] = "3/4";
    opFormat["MUL"] = "3/4";
    opFormat["MULF"] = "3/4";
    opFormat["MULR"] = "2";
    opFormat["NORM"] = "1";
    opFormat["OR"] = "3/4";
    opFormat["RD"] = "3/4";
    opFormat["RMO"] = "2";
    opFormat["RSUB"] = "3/4";
    opFormat["SHIFTL"] = "2";
    opFormat["SHIFTR"] = "2";
    opFormat["SIO"] = "1";
    opFormat["SSK"] = "3/4";
    opFormat["STA"] = "3/4";
    opFormat["STB"] = "3/4";
    opFormat["STCH"] = "3/4";
    opFormat["STF"] = "3/4";
    opFormat["STI"] = "3/4";
    opFormat["STL"] = "3/4";
    opFormat["STS"] = "3/4";
    opFormat["STSW"] = "3/4";
    opFormat["STT"] = "3/4";
    opFormat["STX"] = "3/4";
    opFormat["SUB"] = "3/4";
    opFormat["SUBF"] = "3/4";
    opFormat["SUBR"] = "2";
    opFormat["SVC"] = "2";
    opFormat["TD"] = "3/4";
    opFormat["TIO"] = "1";
    opFormat["TIX"] = "3/4";
    opFormat["TIXR"] = "2";
    opFormat["WD"] = "3/4";
}//end opCodes
string opCode;
void setOp (string op)
{
	opCode = op;
}//end setOp

string opCodes::getOp()
{
	return opCode;
}//end getOp
