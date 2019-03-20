#include"Lexical_analys.h"

int main() {
	ifstream fin("code.txt");
	ofstream toc("tocin.txt");
	ofstream err("errors.txt");
	Lex_analys A;
	A.Work(fin, toc, err);
	system("pause");
	return 0;
}