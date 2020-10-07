#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

void showMenu() {
	cout << "===========================Меню выбора===========================\n"
		<< "1.  Вставка элемента\n"
		<< "2.  Удаление элемента\n"
		<< "3.  Поиск и считывание элемента\n"
		<< "4.  Вывод хешмапы\n"
		<< "5.  Завершить программу\n"
		<< "Введите команду: ";
}

int main()
{
	enum MyEnum
	{
		Insert = 1,
		Delete,
		Search,
		Display,
		Stop

	};

	setlocale(LC_ALL, "ru");
	cout << "Хеширование - прямой доступ к данным\n18вариант прямая адресация(линейное пробирование)\nТовар: Код - шестиразрядное число, название цена\n";
	int n;
	cout << "Введите количество элементов хешмапы: ";
	try
	{
		cin >> n;
		if (n < 1)
		{
			cout << "Недопустимое количество элементов";
			return -1;
		}
	}
	catch (const std::exception&)
	{
		cout << "Что-то пошло не так";
		return -1;
	}

	HashMap<int, double, string> *h = new HashMap<int, double, string>(n);
	showMenu();
	int key;
	double price;	
	string name;
	while (n != Stop)
	{
		cin >> n;
		switch (n)
		{
		case(Insert):
			cout << "Введите ключ/артикул 6-разрядный: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "Артикул не 6-разрядное число\n";
				return -1;
			}
			cout << "Введите название: ";
			cin >> name;
			cout << "Введите цену: ";
			cin >> price;
			if (h->insertNode(key, price, name))
				cout << "Успешно!" << endl;
			else
				cout << "Ошибка!" << endl;
			showMenu();
			break;

		case(Delete):
			cout << "Введите ключ/артикул 6-разрядный: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "Артикул не 6-разрядное число\n";
				return -1;
			}
			if (h->deleteNode(key))
				cout << "Успешно!" << endl;
			else
				cout << "Ошибка!" << endl;
			showMenu();
			break;

		case(Search):
			cout << "Введите ключ/артикул 6-разрядный: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "Артикул не 6-разрядное число\n";
				return -1;
			}
			try
			{
				cout << "Название = " << h->getNode(key)->name << "\nЦена = " << h->getNode(key)->value << endl;
				cout << "Успешно!" << endl;
			}
			catch (const std::exception&)
			{
				cout << "Ошибка!" << endl;
			}
			showMenu();
			break;

		case(Display):
			cout << "=============Все элементы=============" << endl;
			h->displayMap();
			cout << endl;
			showMenu();
			break;

		case(Stop):
			cout << "Выход из программы" << endl;
			return 0;

		default:
			cout << "Что-то пошло не так..";
			return -1;
		}
	}

	system("pause");
	return 0;
}
