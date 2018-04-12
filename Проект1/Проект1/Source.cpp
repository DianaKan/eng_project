#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#define size 100
using namespace std;

struct words {
	char angl[15];
	char rus[20];
};
struct words list_of_words[size];
struct words bad;
int current_size = 0;


void enter_new()
{
	setlocale(0, "");
	int r;
	cout << endl;
	cout << "\t\tВвод информации" << endl;
	cout << endl;

	ofstream file("file.txt",ios::app);
	/*ofstream rus("rus.txt",ios::app);*/
	if (current_size < size)
	{
		do {
			//cout << "Строка номер ";
			//cout << current_size + 1 << endl;
			/*	angl << current_size + 1<<".";*/
			cout << "Английское слово: ";
			cin >> list_of_words[current_size].angl;
			file << list_of_words[current_size].angl <<" ";
			
			cout << "Перевод: ";
			/*rus << current_size + 1 << ".";*/
			cin >> list_of_words[current_size].rus;
			file << list_of_words[current_size].rus <<endl;
			current_size++;
			cout << "Добавлено! Хотите завершить ввод? (1-да, 0-нет)";
			cin >> r;
			cout << endl;
		} while (r != 1);
		file.close();
		/*rus.close();*/
	}
	else
		cout << "Введено максимальное кол–во строк";
	exit;
}

void out()
{
	cout << "\t\tВывод информации" << endl;
	cout << endl;
	ifstream file("file.txt");
	char c;
	while ((c = file.get()) != EOF)
		cout << c;
	/*file >> list_of_words[current_size].angl;*/


	/*	for (int i = 0; i < current_size; i++)
		{
			cout << i+1<<". ";
			
			file >> list_of_words[i].angl;
			cout << list_of_words[i].angl << endl;
	
			file >> list_of_words[i].rus;
			cout << list_of_words[i].rus << endl;
			cout << endl;
		}*/
	
	cout << endl;
	cout << endl;
	exit;
}

void del()
{
	int d;
	cout << "\t\tУдаление информации" << endl;


	//cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 999)" << endl;
	//cin >> d;
	//if (d != 999)
	//{
	//	for (int de1 = (d - 1); de1 < current_size; de1++)
	//		list_of_words[de1] = list_of_words[de1 + 1];
	//	current_size = current_size - 1;
	//}
	//if (d == 999)
	//	for (int i = 0; i < size; i++)
	//		list_of_words[i] = bad;


	cout << endl;
	cout << endl;
	exit;

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	int a;
	do {
		cout << "      <<МЕНЮ>>      " << endl;
		cout << "1.Добавить слово" << endl;
		cout << "2.Показать все слова" << endl;
		cout << "3.Выучить слово" << endl;
		cout << "4.Удалить слово" << endl;
		cout << "5.Выйти" << endl;
		cin >> a;
		switch (a)
		{
		case 1: enter_new()/*cout<<"Ввод слов пока закомменитирован. Работа с готовым заполненным файлом."<<endl*/; break;
		case 2: out(); break;
		case 3: cout << "выбрано 3" << endl << endl; break;
		case 4:/*del()*/; break;
		}
	} while (a != 5);
	cout << endl;

}
