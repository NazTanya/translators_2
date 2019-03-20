#include"Dynamic_table.h"

int Dyn_table::Hash_function(string a) {
		if ('0' <= a[0] && a[0] <= '9')
			return a[0] - '0';
		if ('a' <= a[0] && a[0] <= 'z')
			return a[0] - 'a' + 10;
		if ('A' <= a[0] && a[0] <= 'Z')
			return a[0] - 'A' + 36;
		return 0;
}

bool Dyn_table::Add_element(string a) {
	if (!this->Is_in_table(a)) {
		int j = Hash_function(a);
		lexem u;
		u.name = a;
		u.type = 0;
		u.vision = 0;
		element[j].push_back(u);
		return true;
	}
	return false;
}

bool Dyn_table::Is_in_table(string a) {
	int j = Hash_function(a);
	for (int i = 0; i < element[j].size(); i++) 
		if (element[j][i].name == a) 
			return true;
	return false;
}

void Dyn_table::Load_programm(ifstream &fin) {
	string a;
	fin >> a;
	while (fin) {
		if (!Is_in_table(a)) Add_element(a);
		fin >> a;
	}
}

int  Dyn_table::Get_lexem_type(string a) {
	if (Is_in_table(a)) {
		int j = Hash_function(a);
		for (int i = 0; i < element[j].size(); i++)
			if (element[j][i].name == a)
				return element[j][i].type;
	}
	return -1;
}

bool Dyn_table::Set_lexem_type(string a) {
	if (Is_in_table(a)) {
		int j = Hash_function(a);
		for (int i = 0; i < element[j].size(); i++)
			if (element[j][i].name == a)
				element[j][i].type = 1;
		return true;
	}
	return false;
}

int Dyn_table::Get_lexem_vision(string a)
{
	if (Is_in_table(a)) {
		int j = Hash_function(a);
		for (int i = 0; i < element[j].size(); i++)
			if (element[j][i].name == a)
				return element[j][i].vision;
	}
	return -1;
}

bool Dyn_table::Set_lexem_vision(string a)
{
	if (Is_in_table(a)) {
		int j = Hash_function(a);
		for (int i = 0; i < element[j].size(); i++)
			if (element[j][i].name == a)
				element[j][i].vision = 1;
		return true;
	}
	return false;
}

bool Dyn_table::Get_lexem(string a, lexem & b)
{
	if (Is_in_table(a)) {
		int j = Hash_function(a);
		for (int i = 0; i < element[j].size(); i++)
			if (element[j][i].name == a)
				b = element[j][i];
		return true;
	}
	return false;
}

bool Dyn_table::Get_lexem(int n1, int n2, lexem & b)
{
	if (n1 < N) 
		if (n2 < element[n1].size()) {
			b = element[n1][n2];
			return true;
		}
	return false;
}

bool Dyn_table::Set_lexem(lexem a)
{
	if (!Is_in_table(a.name)) {
		int j = Hash_function(a.name);
		element[j].push_back(a);
		return true;
	}
	return false;
}

bool Dyn_table::Get_lexem_address(lexem a, int & n1, int & n2)
{
	if (Is_in_table(a.name)) {
		n1 = Hash_function(a.name);
		for (int i = 0; i < element[n1].size(); i++)
			if (element[n1][i].name == a.name)
				n2 = i;
		return true;
	}
	return false;
}

bool Dyn_table::Get_lexem_address(string a, int & n1, int & n2)
{
	if (Is_in_table(a)) {
		n1 = Hash_function(a);
		for (int i = 0; i < element[n1].size(); i++)
			if (element[n1][i].name == a)
				n2 = i;
		return true;
	}
	return false;
}
