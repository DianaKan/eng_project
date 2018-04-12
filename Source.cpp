в﻿/*---------------------------------Проект--------------------------------------
Суть проги: Человек Х, читал книгу/смотрел кино/делал дз, увидел незнакомое английское слово, надо выучить.

Пользователь открывает программу, сам вводит английские слова и перевод. Все, что он ввел, 
добавляется в файл(или базу (но у меня сохраняется в файл)).
            Далее он может с этим делать следующее:     есть меню с функциями 
			                      1)добавить слово (добавляет английское и перевод)
			                      2)показать все слова
					      3)удалить слово (удаляет одно (вводит именно само слово и удаляется вся 
						строка с этим словом) или все)
					      4)выучить
					      5)выйти

Не знаю: 1) как удалять слово(строку) из файла (вот тут мне нужно очень помочь:( ). (Я думала создать из 
            содержимого файла массив, найти в этом массиве нужное слово, удалить его, и переписать это все 
	    заново в этот файл, уже без этого удаленного слова но не могу(не знаю) это сделать)
         
         2) как сделать режим изучения (как код написать не знаю, а логика вот:    
	                                                                       1)из файла(базы) выдается поочередно слово (англ или рус),
									       2)слово выдалось - надо ввести его перевод (и сравнивать слово 
									         с введенным с помощью strcmp (но необязательно, это я просто только это знаю)
							                 Вопрос: как брать поочередно эти слова?(

Сейчас в моей проге работает только 1)добавить слово (добаляется в файл в одну строку англ и рус слово 
                                     (до этого делала два файла: с англ словами и рус отдельно, но препод сказал, что лучше в одном)
				    2)показать все слова (тупо выводится всё из файла)) )

А ещё мне как-то надо (у меня сейчас структура) перейти к классу, переделать в общем наверное (?), да? */
								   

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
