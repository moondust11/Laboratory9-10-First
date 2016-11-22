#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include <deque>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//�������� ����������� multimap
	multimap<string, float> First;
	multimap<string, float> Second = { {"Sfirst", 3.5F},{"Ssecond", 4.0F},{"Sthird", 4.5F},{"Sfourth", 5.0F} };
	//�������������
	First.insert(pair<string, float>("Ffirst", 1.5F));
	First.insert(pair<string, float>("Fsecond", 2.0F));
	First.insert(pair<string, float>("Fthird", 2.5F));
	First.insert(pair<string, float>("Ffourth", 3.0F));
	//�������� �����������
	cout << "�������� ����������� First: " << endl;
	int i = 1;
	if (First.empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); ++it, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//�������� ���������
	First.clear();
	//�������� ����������� ����� ��������
	cout << "\n�������� ����������� First ����� ��������: " << endl;
	if (First.empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); ++it, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//����������� ����� ��������
	First = Second;
	//������������� ���������� ����� ������������
	cout << "\n�������� ����������� ����� ������������: " << endl;
	if (First.empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); ++it, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//�������� ����������� ��������� reverse-���������
	cout << "\n�������� ����������� ��������� reverse-���������: " << endl;
	if (First.empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First.crbegin(); it != First.crend(); it++, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//������ ��������� ���� deque
	deque<float> Deq;
	Deq.push_front(3.0F);
	Deq.push_back(3.5F);
	Deq.push_front(2.5F);
	//�������� multimap::First: ������� n ��������� ����� ��������� � ��������� �������� �� deque::Deq
	auto itb = ++First.begin(); ///�������� �� ��������� �������� ���������
	auto ite = itb; 
	for (; i < 4; i++, ++ite); ///�������� �� �������� �������� ���������
	i = 1;
	First.erase(itb, ite); ///������� 3 ��������
	//�������� ����������� First ����� �������� 3 ���������
	cout << "\n�������� ����������� First ����� �������� 3 ���������" << endl;
	if (First.empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First.crbegin(); it != First.crend(); it++, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//������������ ��������� Deq � First
	i = 0;
	char t = 'a';
	for (string str = ""; i < Deq.size(); i++, t++ , str = "")
		First.insert(pair<string, float>(str + t, Deq[i]));
	i = 1;
	//�������� ����������� First ����� ����������� � Deq
	cout << "\n�������� ����������� First ����� ����������� � Deq" << endl;
	if (First.empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); it++, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
}