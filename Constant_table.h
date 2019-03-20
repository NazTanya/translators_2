#pragma once
#include<stdlib.h>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

class Const_table {
private:
	int count_of_elements;
	vector<string> vocabulary;
public:
	//загрузка таблицы с файла
	void Load_from_file(ifstream &fin);
	//добавление элемента в таблицу
	bool Add_element(string a);
	//проверка находится ли данный элемент в таблице
	bool Is_in_table(string a);
	//нахождение по номеру и значению
	bool Get_element_value(int num,string &a);
	bool Get_element_number(string a, int &num);
};