#include"Lexical_analys.h"

Lex_analys::Lex_analys() {
	ifstream fin("right_symbols.txt");
	right_symbols.Load_from_file(fin);
	fin.close();
	ifstream fin1("numbers.txt");
	numbers.Load_from_file(fin1);
	fin1.close();
	ifstream fin2("key_words.txt");
	key_words.Load_from_file(fin2);
	fin2.close();	
	ifstream fin3("operations.txt");
	operations.Load_from_file(fin3);
	fin3.close();
	ifstream fin4("separaters.txt");
	separaters.Load_from_file(fin4);
	fin4.close();
}

//bool Lex_analys::Analys(ifstream &code_file, ofstream &tocin_file, ofstream &error_file)
//{
//	int num, n1,n2;
//	string a,b;
//	char letter;
//	bool rez, k = false;
//	code_file >> a;
//	while (code_file) {
//		for (int i = 0; i < a.size(); i++)
//		{
//			letter = a[i];
//			rez = Check_right(letter);
//			if (!rez) {
//				k = true;
//				Make_error(error_file, 0);
//			}
//		}
//		if (!k) {
//			//проверка в key_words
//			rez = key_words.Is_in_table(a);
//			if (rez) {
//				key_words.Get_element_number(a, num);
//				tocin_file << tocin(2, -1, num);
//			}
//				else
//				{ 
//				//проверка в operations
//				rez = operations.Is_in_table(a);
//				if (rez) {
//					operations.Get_element_number(a, num);
//					tocin_file << tocin(3, -1, num);
//				}
//				else
//				{
//					//проверка в separaters
//					rez = separaters.Is_in_table(a);
//					if (rez) {
//						separaters.Get_element_number(a, num);
//						tocin_file << tocin(4, -1, num);
//					}
//					else
//					{
//						//проверка дл€ constants
//						b = a[0];
//						rez = numbers.Is_in_table(b);
//						if (rez) {
//							rez = constants.Is_in_table(a);
//							if (!rez) {
//								constants.Add_element(a);
//								constants.Get_lexem_address(a, n1, n2);
//								tocin_file << tocin(5, n1, n2);
//							}
//							else {
//								constants.Get_lexem_address(a, n1, n2);
//								tocin_file << tocin(5, n1, n2);
//							}
//						}
//						//проверка дл€ identifiers
//						else {
//							rez = identifiers.Is_in_table(a);
//							if (!rez) {
//								identifiers.Add_element(a);
//								identifiers.Get_lexem_address(a, n1, n2);
//								tocin_file << tocin(6, n1, n2);
//							}
//							else {
//								identifiers.Get_lexem_address(a, n1, n2);
//								tocin_file << tocin(6, n1, n2);
//							}
//						}
//					}
//				}
//			}
//		}
//		code_file >> a;
//	}
//	return false;
//}

//bool Lex_analys::Check_right(char a)
//{
//	string b;
//	b.push_back(a);
//	bool rez = numbers.Is_in_table(b);
//	if (rez) {
//		return 1;
//	}
//	rez = right_symbols.Is_in_table(b);
//	if (rez) {
//		return 1;
//	}
//	return 0;
//}

void Lex_analys::Make_error(ofstream &error_file, int option)
{
	switch (option) {
	case 0: {
		error_file << " Ќедопустимый символ";
		error = true;
		break;
	}
	case 1: {
		error_file << " ѕроблема с комментарием";
		error = true;
		break;
	}
	case 2:
	{
		error_file << "неверна€ операци€ !";
		error = true;
		break;
	}
	case 3:
	{
		error_file << "неверна€ константа";
		error = true;
		break;
	}
	case 4:
	{
		error_file << "неверна€ операци€";
		error = true;
		break;
	}
	}
}

int Lex_analys::Check_right(char a)
{
	string b;
	b.push_back(a);	
	bool rez = numbers.Is_in_table(b);
	if (rez) 	
		return 1;
	rez = operations.Is_in_table(b);
	if (rez) 	
		return 3;
	/////////////////////////
	if (b == "!") 
		return 5;
	rez = separaters.Is_in_table(b);
	if (rez)		
		return 4;
	if (b == " " || a == '\t') 
		return 9;
	if (b == "/")
		return 10;
	if (b == "*")
		return 11;
	if (a == '\0') 
		return 27;
	rez = right_symbols.Is_in_table(b);
	if (rez) 	
		return 0;
	return -1;
}

void Lex_analys::Work(ifstream &code_file, ofstream &tocin_file, ofstream &error_file) {
	string p;
	getline(code_file, p);
	while (code_file && error == false) {
		if (comment == false)
		{
			Analys(p, tocin_file, error_file);
			getline(code_file, p);
		}
		else {
			bool k = p.find("*/");
			if (k != -1)
				comment = false;
			getline(code_file, p);
		}
	}
}

void Lex_analys::Analys(string p, ofstream &tocin_file, ofstream &error_file) {
	string q;
	int r = 0, b, n1, n2, num;
	bool rez;
	switch (Check_right(p[r])) {
	case -1: {
		Make_error(error_file, 0);
		break;
	}
	case 0: {
		bool h = false;
		b = r;
		r++; 
		while (Check_right(p[r]) != 3 && Check_right(p[r]) != 4 && Check_right(p[r]) != 9
			&& Check_right(p[r]) != 10 && Check_right(p[r]) != 27 && !h)
		{
			if (Check_right(p[r]) == -1)
				h = true;
			r++;
		}
		if (!h) {
			q = p.substr(b, r);
			//провер€ем €ввл€етс€ ли key word
			rez = key_words.Is_in_table(q);
			if (rez) {
				key_words.Get_element_number(q, num);
				tocin_file << tocin(2, -1, num);
			}
			else {
				//провер€ем €вл€етс€ ли idetifier
				rez = identifiers.Is_in_table(q);
				if (!rez) {
					identifiers.Add_element(q);
					identifiers.Get_lexem_address(q, n1, n2);
					tocin_file << tocin(6, n1, n2);
				}
				else {
					identifiers.Get_lexem_address(q, n1, n2);
					tocin_file << tocin(6, n1, n2);
				}
			}
			Analys(p.substr(r), tocin_file, error_file);
		}
		else
		{
			Make_error(error_file, 0);
		}
		break;
	}
	case 1: {
		bool k = false, h = false;
		b = r;
		r++;
		if (Check_right(p[r])== 1)  {
			k = true;
			while (Check_right(p[r]) == 1)
				r++;
		}
		if (k)
			q = p.substr(b, r);
		else
			if (Check_right(p[r]) == 4 || Check_right(p[r]) == 9)
				q = p[b];
			else
				h = true;
		if (!h)
		{
			rez = constants.Is_in_table(q);
			if (!rez) {
				constants.Add_element(q);
				constants.Get_lexem_address(q, n1, n2);
				tocin_file << tocin(5, n1, n2);
			}
			else {
				constants.Get_lexem_address(q, n1, n2);
				tocin_file << tocin(5, n1, n2);
			}
			if (k)
				Analys(p.substr(r), tocin_file, error_file);
			else
				Analys(p.substr(b + 1), tocin_file, error_file);
		}
		else {
			Make_error(error_file, 3);
		}
		break;
	}
	case 3: {
		bool g = false, h = false;
		b = r;
		r++;
		if (&p[r] == "=") {
			g = true;
			q = p.substr(b, r);
		}
		else {
			if (Check_right(p[r]) == 4 || Check_right(p[r]) == 9)
				q = p[b];
			else
				h = true;
		}
		if (!h)
		{
			operations.Get_element_number(q, num);
			tocin_file << tocin(3, -1, num);
			if (g)
				Analys(p.substr(r + 1), tocin_file, error_file);
			else
				Analys(p.substr(b + 1), tocin_file, error_file);
		}
		else {
			Make_error(error_file, 4);
		}
		break;
	}
	case 4: {
		q = p[r];
		separaters.Get_element_number(q, num);
		tocin_file << tocin(4, -1, num);
		Analys(p.substr(r + 1), tocin_file, error_file);
		break;
	}
	case 5:	{
		bool g = false;
		b = r;
		r++;
		if (&p[r] == "=") {
			g = true;
			q = p.substr(b, r);
		}
		else {
			Make_error(error_file, 2);
		}
		if (g){
			operations.Get_element_number(q, num);
			tocin_file << tocin(3, -1, num);
			Analys(p.substr(r + 1), tocin_file, error_file);
		}
		break;
	}
	case 9: {
		Analys(p.substr(r + 1), tocin_file, error_file);
		break;
	}
	case 10: {
		int s = p.size();
		b = r;
		char t = p[r + 1];
		if ( t != '/' && t != '*') {
			Make_error(error_file, 1);
		}
		else {
			if (t == '/') 
				Analys(p.substr(s), tocin_file, error_file);
			else
			{
				if (t == '*')
				{
					comment = true;
					Analys(p.substr(s), tocin_file, error_file);
				}
			}

		}
		break;
	}
	case 27: {
		break;
	}
	}
}