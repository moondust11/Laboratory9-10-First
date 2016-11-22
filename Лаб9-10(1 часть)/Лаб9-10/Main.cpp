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
	//Создание контейнеров multimap
	multimap<string, float> First;
	multimap<string, float> Second = { {"Sfirst", 3.5F},{"Ssecond", 4.0F},{"Sthird", 4.5F},{"Sfourth", 5.0F} };
	//Инициализация
	First.insert(pair<string, float>("Ffirst", 1.5F));
	First.insert(pair<string, float>("Fsecond", 2.0F));
	First.insert(pair<string, float>("Fthird", 2.5F));
	First.insert(pair<string, float>("Ffourth", 3.0F));
	//Просмотр содержимого
	cout << "Просмотр содержимого First: " << endl;
	int i = 1;
	if (First.empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); ++it, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//Удаление элементов
	First.clear();
	//Просмотр содержимого после удаления
	cout << "\nПросмотр содержимого First после удаления: " << endl;
	if (First.empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); ++it, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//Присваиваем новые элементы
	First = Second;
	//Просматриваем содержимое после присваивания
	cout << "\nПросмотр содержимого после присваивания: " << endl;
	if (First.empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); ++it, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//Просмотр содержимого используя reverse-итераторы
	cout << "\nПросмотр содержимого используя reverse-итераторы: " << endl;
	if (First.empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First.crbegin(); it != First.crend(); it++, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//Создаём контейнер типа deque
	deque<float> Deq;
	Deq.push_front(3.0F);
	Deq.push_back(3.5F);
	Deq.push_front(2.5F);
	//Изменяем multimap::First: удаляем n элементов после заданного и добавляем элементы из deque::Deq
	auto itb = ++First.begin(); ///Итератор на начальное значение диапазона
	auto ite = itb; 
	for (; i < 4; i++, ++ite); ///Итератор на конечное значение диапазона
	i = 1;
	First.erase(itb, ite); ///Удаляем 3 элемента
	//Просмотр содержимого First после удаления 3 элементов
	cout << "\nПросмотр содержимого First после удаления 3 элементов" << endl;
	if (First.empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First.crbegin(); it != First.crend(); it++, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
	//Присваивание элементов Deq в First
	i = 0;
	char t = 'a';
	for (string str = ""; i < Deq.size(); i++, t++ , str = "")
		First.insert(pair<string, float>(str + t, Deq[i]));
	i = 1;
	//Просмотр содержимого First после манипуляций с Deq
	cout << "\nПросмотр содержимого First после манипуляций с Deq" << endl;
	if (First.empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First.begin(); it != First.end(); it++, i++)
			cout << i << ")" << it->first << " : " << it->second << endl;
		i = 1;
	}
}