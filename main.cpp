#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <stdbool.h>
#include <math.h>
#include <map>
#include "opCode.h"
using namespace std;

void scanner();
void readinter();
void constructTables();
int checkSYM(string, int, bool);
void binaryAdd(string, string, int, int);
int strToInt(string);
void hexStrToBin(string, string);
void binaryToObjCode(string, string);


vector<string> opTab;
vector<string> SYMTAB;
map<string, string> opFormat;
int BASE = 0;


void constructTables(){
	SYMTAB.push_back("A");
	SYMTAB.push_back("0");
	SYMTAB.push_back("X");
	SYMTAB.push_back("1");
	SYMTAB.push_back("L");
	SYMTAB.push_back("2");
	SYMTAB.push_back("B");
	SYMTAB.push_back("3");
	SYMTAB.push_back("S");
	SYMTAB.push_back("4");
	SYMTAB.push_back("T");
	SYMTAB.push_back("5");
	SYMTAB.push_back("F");
	SYMTAB.push_back("6");
	

	opTab.push_back("ADD");
	opTab.push_back("18");
	opTab.push_back("ADDF");
	opTab.push_back("58");
	opTab.push_back("ADDR");
	opTab.push_back("90");
	opTab.push_back("AND");
	opTab.push_back("40");
	opTab.push_back("CLEAR");
	opTab.push_back("B4");
	opTab.push_back("COMP");
	opTab.push_back("28");
	opTab.push_back("COMPF");
	opTab.push_back("88");
	opTab.push_back("COMPR");
	opTab.push_back("A0");
	opTab.push_back("DIV");
	opTab.push_back("24");
	opTab.push_back("DIVF");
	opTab.push_back("64");
	opTab.push_back("DIVR");
	opTab.push_back("9C");
	opTab.push_back("FIX");
	opTab.push_back("C4");
	opTab.push_back("FLOAT");
	opTab.push_back("C0");
	opTab.push_back("HIO");
	opTab.push_back("F4");
	opTab.push_back("J");
	opTab.push_back("3C");
	opTab.push_back("JEQ");
	opTab.push_back("30");
	opTab.push_back("JGT");
	opTab.push_back("34");
	opTab.push_back("JLT");
	opTab.push_back("38");
	opTab.push_back("JSUB");
	opTab.push_back("48");
	opTab.push_back("LDA");
	opTab.push_back("00");
	opTab.push_back("LDB");
	opTab.push_back("68");
	opTab.push_back("LDCH");
	opTab.push_back("50");
	opTab.push_back("LDF");
	opTab.push_back("70");
	opTab.push_back("LDL");
	opTab.push_back("08");
	opTab.push_back("LDS");
	opTab.push_back("6C");
	opTab.push_back("LDT");
	opTab.push_back("74");
	opTab.push_back("LDX");
	opTab.push_back("04");
	opTab.push_back("LPS");
	opTab.push_back("D0");
	opTab.push_back("MUL");
	opTab.push_back("20");
	opTab.push_back("MULF");
	opTab.push_back("60");
	opTab.push_back("MULR");
	opTab.push_back("98");
	opTab.push_back("NORM");
	opTab.push_back("C8");
	opTab.push_back("OR");
	opTab.push_back("44");
	opTab.push_back("RD");
	opTab.push_back("D8");
	opTab.push_back("RMO");
	opTab.push_back("AC");
	opTab.push_back("RSUB");
	opTab.push_back("4C");
	opTab.push_back("SHIFTL");
	opTab.push_back("A4");
	opTab.push_back("SHIFTR");
	opTab.push_back("A8");
	opTab.push_back("SIO");
	opTab.push_back("F0");
	opTab.push_back("SSK");
	opTab.push_back("EC");
	opTab.push_back("STA");
	opTab.push_back("0C");
	opTab.push_back("STB");
	opTab.push_back("78");
	opTab.push_back("STCH");
	opTab.push_back("54");
	opTab.push_back("STF");
	opTab.push_back("80");
	opTab.push_back("STI");
	opTab.push_back("D4");
	opTab.push_back("STL");
	opTab.push_back("14");
	opTab.push_back("STS");
	opTab.push_back("7C");
	opTab.push_back("STSW");
	opTab.push_back("E8");
	opTab.push_back("STT");
	opTab.push_back("84");
	opTab.push_back("STX");
	opTab.push_back("10");
	opTab.push_back("SUB");
	opTab.push_back("1C");
	opTab.push_back("SUBF");
	opTab.push_back("5C");
	opTab.push_back("SUBR");
	opTab.push_back("94");
	opTab.push_back("SVC");
	opTab.push_back("B0");
	opTab.push_back("TD");
	opTab.push_back("E0");
	opTab.push_back("TIO");
	opTab.push_back("F8");
	opTab.push_back("TIX");
	opTab.push_back("2C");
	opTab.push_back("TIXR");
	opTab.push_back("B8");
	opTab.push_back("WD");
	opTab.push_back("DC");


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

}

int main(int argc, char *argv[])
{
        system("clear");
 
	string line;
	string output;
	ofstream myfile;
	
	vector<string> data;

	string label = "";
	string period = ".";
	string hashtag = "#";
	string error;
	string token;
	
	constructTables();
	scanner();
	
	/* need to open the file to parse through the elements. Could have a menu for the user to choose from or just ask the user for the input. Then we will parse through the loop and break if there is a period. Then check for a # sign and remove it if it is found. */
	
}//end main

void scanner(){
  std::string filename;
  std::ifstream infile;
  std::ofstream outfile;
  std::string line, word;

  //gets name of file to read in
  std::cout << "What is the name of the text you want to process?" << std::endl; 
  getline(std::cin, filename);

  infile.open(filename);

  if (infile.is_open()){
    outfile.open("parsedFile.txt");

    while (!infile.eof()){
      std::getline(infile, line, '\r');
      std::stringstream ss(line);
      if (!line.empty()){
        while(std::getline (ss, word, '\t')){
          if (word[0] != '.'){
			  if (outfile.is_open()) {
					  outfile << word << std::endl;
			  }
          } else {
			  break;
          }  
        }
      } 
    }//end while
  std::cout << "The file was parsed and sent to 'parsedFile.txt'"  << std::endl;
  } else { 
    std::cout << "bad file name: file not found" << std::endl;
  }
  infile.close();
  outfile.close();
  readinter();
}//end scanner


//Reads intermediate file and Generates second intermediate file
void readinter() {
	int i;
	std::ifstream infile;
	std::ofstream outfile;
	std::string label;
	std::string operation;
	std::string operand;
	std::stringstream stream;
	std::string subOper;
	std::string tempOpCode;
	std::string subStr;
	std::string reg1 = "a ";
	std::string reg2;
	char * tempBin;
	char* litBin = new char[12];

	int * FinalobjCode = new int[20];
	for (i = 0; i < 20; i++) FinalobjCode[i] = 0;
	int memLoc = 0;
	bool res;
	bool reg;

	infile.open("parsedFile.txt");

	int n, ii, x, b, p, e;

	if (infile.is_open()) {
		outfile.open("pointerParse.txt");


		while (!infile.eof()) {
			n = 1, ii = 1, x = 0, b = 0, p = 1, e = 0;
			res = false;
			reg = false;
			reg1 = "a ";
			reg2 = "  ";
			std::getline(infile, label);
			std::getline(infile, operation);
			std::getline(infile, operand);

			if (operation.empty())
				continue;
			outfile << std::setfill('0') << std::setw(4) << std::hex << memLoc << std::endl;
			outfile << std::dec;

			

			if (operation.compare("START") == 0) {
				memLoc = strToInt(operand);
				std::getline(infile, label);
				std::getline(infile, operation);
				std::getline(infile, operand);
			}
			std::stringstream stream(operand);

			if (operation[operation.length() - 1] == 'R') {
				reg = true;
			}

			if (!label.empty()) {
				outfile << "SYMTAB[" << checkSYM(label, memLoc, true) << "]" << std::endl;
			}
			else {
				outfile << std::endl;
			}
			
			//LOCCTR and mem reservation Handler
			if (operation.compare("BASE") == 0)
				BASE = checkSYM(operand, memLoc, false);
			else {
				if (operation[0] == '+') {
					memLoc += 4;
					e = 1;
					p = 0;
					litBin = new char[16];
				}
				if (operand[0] == '@') {
					memLoc += 3;
					i = 0;
				}
				if (operand[0] == '#') {
					memLoc += 3;
					n = 0;
				}
				if (operation.compare("RESB") == 0) {
					memLoc += strToInt(operand);
					outfile << operation << std::endl;
					outfile << operand << endl;
					res = true;
				}
				else if (operation.compare("RESW") == 0) {
					memLoc += strToInt(operand) * 3;
					outfile << operation << std::endl;
					outfile << operand << endl;
					res = true;
				}
				else if (operation.compare("BYTE") == 0) {
					memLoc += 1;
					outfile << operation << std::endl;
					outfile << operand << endl;
					res = true;
					tempOpCode = operand;
					tempBin = new char[6];
				}
				else if (operation.compare("WORD") == 0) {
					memLoc += 3;
					outfile << operation << std::endl;
					outfile << operand << endl;
					res = true;
					tempOpCode = operand;
					tempBin = new char[6];
				}
				else
					memLoc += 3;

				//OPERATION HANDLER
				for (i = 0; i < 117; i = i + 2) {
					if (opTab[i].compare(operation) == 0) {
						outfile << "OPTAB[" << i << "]" << std::endl;
						tempOpCode = opTab[i + 1];
					}
				}

				//OPERAND HANDLER
				if (!res) {
					while (!stream.eof()) {
						std::getline(stream, subOper, ',');
						if (subOper[0] != '#') {
							outfile << "SYMTAB[" << checkSYM(subOper, memLoc, false) << "]";
							if (subOper.compare("X") == 0 || subOper.compare(opTab[BASE]) == 0){
								x = 1;
								b = 1;
								p = 0;
							}
							if (reg) {
								reg2 = SYMTAB[checkSYM(subOper, memLoc, false)];
								if (reg1[0] == 'a')
									reg1[0] = reg2[0];
								else
									reg1[1] = reg2[0];
							}
						}
						else {
							subStr.resize(subOper.length(), '\n');
							for (i = 1; i < subOper.length(); i++) {
								subStr[i-1] = subOper[i];
							}
							outfile << subOper;
						}
						if (!stream.eof())
							outfile << ",";
					}
					outfile << std::endl;
				}

				if (!res && !reg) {
					tempBin = new char[6];
					hexStrToBin(tempOpCode, tempBin);
					outfile << tempBin << n << ii << x << b << p << e << std::endl;
				}
				else if (operation.compare("BYTE") == 0)
					outfile << operand << std::endl;
				else if (operation.compare("WORD") == 0)
					outfile << operand << std::endl;
				else if (reg)
					outfile << tempOpCode << reg1 << std::endl;
				else
					outfile << std::endl;
			}
		}
	}
	infile.close();
	infile.open("pointerParse.txt");
	std::string LOCCTR;
	int opCode1;
	char opCode2c;
	int opCode2i;
	char opCode3c;
	int opCode3i;
	int opCodePlaces;
	int opCodei;
	char * binOPCode = new char[6];
	char* binObjCode;
	std::string opC;
	std::string objCode;
	int flag = 0;
	std::string format;
	std::string opr;
	std::string objinfo;
	std::string objC;
	std::string addr = "000";
	std::string TA;
	std::string DISP; 
	std::string TAbin;
	std::string DISPbin;
	int addrInt;
	int j;

	std::stringstream stream2;
	if (infile.is_open()) {
		outfile.open("Intermediate.txt");
		outfile << "LOCCTR\tLABEL\tOPERATION\tOPERAND\tOBJECTCODE" << std::endl;
		while (!infile.eof()) {
			opCodePlaces = 0;
			opCodei = 0;
			objC.clear;
			std::getline(infile, LOCCTR);
			std::getline(infile, label);
			std::getline(infile, operation);
			std::getline(infile, operand);
			std::getline(infile, objinfo);
			std::stringstream stream2(operand);

			outfile << LOCCTR << "\t" << label << "\t" << operation << "\t" << operand << "\t";
			switch (objinfo.length()) {
			case 2:
				outfile << objinfo << std::endl;
				break;
			case 4:
				outfile << objinfo << std::endl;
				break;
			case 12:
				binaryToObjCode(objinfo, objC);
				outfile << objC;
				while (!stream2.eof()) {
					std::getline(stream2, subStr, ',');
					for (i = 0; i < subStr.length(); i++) {
						if (subStr[i] = '[') {
							i++;
							j = 0;
							while (subStr[i + j] != ']')
								addr[j] = subStr[i + j++];
							for (j; j < 3; j++) addr[j] == '\n';
							addrInt = strToInt(addr);
							TA = SYMTAB[addrInt];
							if (objinfo[9] == 1) {
								TA = hexAdder(TA, SYMTAB[BASE], false);
								outfile << TA << std::endl;
							}
							else {
								TA = hexAdder(TA, LOCCTR, false);
								outfile << TA << std::endl;
							}
						}
					}
				}
				break;
			case 28:
				binaryToObjCode(objinfo, objC);
				outfile << objC << endl;
			default:
				break;
			}
			
		}
	}
}


//Checks if the SYSTAB includes the label or not. If not, it creates it. Returns integer address in SYSTAB vector that follows the label
//If the calling function is checking for duplicates, label is true and flags duplicates as an error.
int checkSYM(string label, int loc, bool errCheck) {
	int i = 0;
	int length = SYMTAB.size();
	for (i = 0; i < length; i += 2) {
		if (SYMTAB[i].compare(label) == 0) {
			//if (errCheck) {
			//	std::cout << "\nERROR, DUPLICATE SYMBOL DECLARATIONS\n";
			//	abort();
			//}
				return (i + 1);
		}
	}
	SYMTAB.push_back(label);
	SYMTAB.push_back(std::to_string(loc));
	return length + 1;
}

//Function used to add together arrays of binary integers recursively.
void binaryAdd(string arr1, string arr2, int pos, int carry) {
	int newCarry;
	if (pos > 0) {
		arr1[pos] = arr1[pos] + ((int)arr2[pos] - 48) + carry;
		if (arr1[pos] > '1') {
			newCarry = 1;
			if (arr1[pos] > '2')
				arr1[pos] = '1';
			else
				arr1[pos] = '0';
		}
		else
			newCarry = 0;
	}
	else
		return;
	binaryAdd(arr1, arr2, pos - 1, newCarry);
}

void binarySub(string arr1, string arr2, int pos, int carry) {
	int newCarry;
	unsigned int i;
	for (i = 0; i < arr2.length(); i++) {
		if (arr2[i] == '0')
			arr2[i] = '1';
		else
			arr2[i] = '0';
	}
	std::string arr3;
	arr3.resize(arr2.length(), '0');
	//for (i = 0; i < arr2.length(); i++)
	//	arr3[i] = '0';
	arr3[arr3.length() - 1] = '1';
	binaryAdd(arr2, arr3, arr2.length() - 1, 0);
	binaryAdd(arr1, arr2, arr1.length() - 1, 0);
}

int strToInt(string str) {
	int j = 0;
	int i;
	int sint = 0;
	//std::cout << "NEW LOOP" << std::endl;
	for (i = str.length() - 1; i >= 0; i--) {
		//std::cout << (int)str[i] - 48 << std::endl;
		sint += (((long int)str[i]) - 48) * pow(10, j++);
	}
	return sint;
}


void hexStrToBin(string opC, string bin) {
	string set;
	int i, j, k = 0;
	for (i = 0; i < bin.length() / 4 + 1; i++) {
		switch (opC[i])
		{
		case '0': set = "0000"; break;
		case '1': set = "0001"; break;
		case '2': set = "0010"; break;
		case '3': set = "0011"; break;
		case '4': set = "0100"; break;
		case '5': set = "0101"; break;
		case '6': set = "0110"; break;
		case '7': set = "0111"; break;
		case '8': set = "1000"; break;
		case '9': set = "1001"; break;
		case 'A': set = "1010"; break;
		case 'B': set = "1011"; break;
		case 'C': set = "1100"; break;
		case 'D': set = "1101"; break;
		case 'E': set = "1110"; break;
		case 'F': set = "1111"; break;
		}
		for (j = 0; k < bin.length() && j < 4; j++) {
			bin[k++] = set[j];
		}
	}
}

void binaryToObjCode(string bin, string objCode) {
	int i, j;
	int objInt = 0;
	stringstream rawData;
	string data;
	int emptyBitsCount = 0;
	int length;
	length = objCode.length();

	for (i = 19, j = 0; i >= 0; i++, j++) {
		if (bin[i] == '1') {
			objInt += pow(2, j);
			emptyBitsCount = 0;
		}
		emptyBitsCount++;
	}
	rawData << std::hex << objInt;
	std::getline(rawData, data);
	for (i = 0; i < length; i++) {
		objCode[i] = data[i];
	}
}

void intToBin(string intStr, string binStr) {
	int i = 0, r;
	int num = strToInt(intStr);
	for (i = 0; i < binStr.length(); i++) {
		r = num % 2;
		num = num / 2;
		binStr[binStr.length() - i - 1] = r;
	}
}

string hexAdder(string hex1, string hex2, bool add) {
	std::string bin1;
	std::string bin2;
	std::string hexResult;
	hexStrToBin(hex1, bin1);
	hexStrToBin(hex2, bin2);
	if (add)
		binaryAdd(bin1, bin2, bin2.length() - 1, 0);
	else
		binarySub(bin1, bin2, bin2.length() - 1, 0);
	binaryToObjCode(bin1, hexResult);
	hex1 = hexResult;
	return hexResult;
}