#pragma once
#include<stdlib.h>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#define N 62
using namespace std;

struct lexem {
	string name;
	bool type;
	bool vision;
};


class Dyn_table {
public:
	//добавление элемена в таблицу
	bool Add_element(string a);
	//проверка на наличие в таблице
	bool Is_in_table(string a);
	//загрузка программы из файла
	void Load_programm(ifstream &prog);
	//извлечение типа лексемы
	int Get_lexem_type(string a);
	//устанавление типа лексемы
	bool Set_lexem_type(string a);
	//извлечение видимости лексемы
	int Get_lexem_vision(string a);
	//установление видимости лексемы
	bool Set_lexem_vision(string a);
	//извлечение  лексемы по имени
	bool Get_lexem(string a, lexem &b);
	//извлечение лексемы по адресу
	bool Get_lexem(int n1, int n2, lexem &b);
	//установление лексемы
	bool Set_lexem(lexem a);
	//извлечение адреса лексемы по лексеме
	bool Get_lexem_address(lexem a,int &n1, int &n2);
	//извлечение адреса лексемы по имени
	bool Get_lexem_address(string a, int &n1, int &n2);
private:
	vector<lexem> element[N];
	//хэш-функция (Сначала числа -> строчные буквы -> заглавные буквы)
	int Hash_function(string a);
};