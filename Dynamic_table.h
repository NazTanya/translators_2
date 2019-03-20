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
	//���������� ������� � �������
	bool Add_element(string a);
	//�������� �� ������� � �������
	bool Is_in_table(string a);
	//�������� ��������� �� �����
	void Load_programm(ifstream &prog);
	//���������� ���� �������
	int Get_lexem_type(string a);
	//������������ ���� �������
	bool Set_lexem_type(string a);
	//���������� ��������� �������
	int Get_lexem_vision(string a);
	//������������ ��������� �������
	bool Set_lexem_vision(string a);
	//����������  ������� �� �����
	bool Get_lexem(string a, lexem &b);
	//���������� ������� �� ������
	bool Get_lexem(int n1, int n2, lexem &b);
	//������������ �������
	bool Set_lexem(lexem a);
	//���������� ������ ������� �� �������
	bool Get_lexem_address(lexem a,int &n1, int &n2);
	//���������� ������ ������� �� �����
	bool Get_lexem_address(string a, int &n1, int &n2);
private:
	vector<lexem> element[N];
	//���-������� (������� ����� -> �������� ����� -> ��������� �����)
	int Hash_function(string a);
};