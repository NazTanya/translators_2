#include"Constant_table.h"

void Const_table::Load_from_file(ifstream &fin) {
	string a;
	fin >> a;
	while (fin) {
		vocabulary.push_back(a);
		fin >> a;		
	}
	sort(vocabulary.begin(), vocabulary.end());
	count_of_elements = vocabulary.size();
}

bool Const_table::Add_element(string a) {
	if (!this->Is_in_table(a)) {
		vocabulary.push_back(a);
		sort(vocabulary.begin(), vocabulary.end());
		count_of_elements++;
		return true;
	}
	return false;
}

bool Const_table::Is_in_table(string a) {
	for (int i = 0; i < count_of_elements; i++)
	{
		if (vocabulary[i]==a) 
			return true;
	}
	return false;
}

bool Const_table::Get_element_value(int num, string &a) {
	if (num < count_of_elements){
		a = vocabulary[num];
		return true;
	}
	return false;
}

bool Const_table::Get_element_number(string a, int &num) {
	int i = 0;
	while (i < count_of_elements) {
		if (vocabulary[i] == a)
		{
			num = i;
			return true;
		}
		i++;
	}
	return false;
}