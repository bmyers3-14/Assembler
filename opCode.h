#ifndef OPCODE_H_EXISTS
#define OPCODE_H_EXISTS
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class opCodes
{
	private:
		string opCode;
	public:
		opCodes();
		void setOp (string op);
		string getOp ();
		map<string, string> opTab;
		map<string, string> opFormat;
		vector<string> reg;
		
};//end opCodes
#endif

