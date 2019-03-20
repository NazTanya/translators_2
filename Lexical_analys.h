#pragma once
#include<fstream>
#include<string>
#include"Constant_table.h"
#include"Dynamic_table.h"
using namespace std;


class Lex_analys {
public:
	Lex_analys();
	bool comment = false;
	bool error = false;
	//������� - 0
	Const_table right_symbols;
	//������� - 1
	Const_table numbers;
	//������� - 2
	Const_table key_words;
	//������� - 3
	Const_table operations;
	//������� - 4
	Const_table separaters;
	//������� - 5
	Dyn_table constants;
	//������� - 6
	Dyn_table identifiers;
	//������
	void Work(ifstream &code_file, ofstream &tocin_file, ofstream &error_file);
	//
	void Analys(string p, ofstream &tocin_file, ofstream &error_file);
	//
	class tocin {
	public:
		int num_table;
		int num_chain;
		int num;
		tocin(int tb, int ch, int n) {
			num_table = tb;
			num_chain = ch;
			num = n;
		};
		friend ostream& operator << (ostream& out, tocin a) {
			out << a.num_table << "   " <<
				a.num_chain << "   " << a.num << endl;
			return out;
		}

	};

private:
	//
	int Check_right(char a);
	//
	void Make_error(ofstream &error_file, int option);
};