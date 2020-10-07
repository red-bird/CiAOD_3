#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

void showMenu() {
	cout << "===========================���� ������===========================\n"
		<< "1.  ������� ��������\n"
		<< "2.  �������� ��������\n"
		<< "3.  ����� � ���������� ��������\n"
		<< "4.  ����� �������\n"
		<< "5.  ��������� ���������\n"
		<< "������� �������: ";
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
	cout << "����������� - ������ ������ � ������\n18������� ������ ���������(�������� ������������)\n�����: ��� - �������������� �����, �������� ����\n";
	int n;
	cout << "������� ���������� ��������� �������: ";
	try
	{
		cin >> n;
		if (n < 1)
		{
			cout << "������������ ���������� ���������";
			return -1;
		}
	}
	catch (const std::exception&)
	{
		cout << "���-�� ����� �� ���";
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
			cout << "������� ����/������� 6-���������: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "������� �� 6-��������� �����\n";
				return -1;
			}
			cout << "������� ��������: ";
			cin >> name;
			cout << "������� ����: ";
			cin >> price;
			if (h->insertNode(key, price, name))
				cout << "�������!" << endl;
			else
				cout << "������!" << endl;
			showMenu();
			break;

		case(Delete):
			cout << "������� ����/������� 6-���������: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "������� �� 6-��������� �����\n";
				return -1;
			}
			if (h->deleteNode(key))
				cout << "�������!" << endl;
			else
				cout << "������!" << endl;
			showMenu();
			break;

		case(Search):
			cout << "������� ����/������� 6-���������: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "������� �� 6-��������� �����\n";
				return -1;
			}
			try
			{
				cout << "�������� = " << h->getNode(key)->name << "\n���� = " << h->getNode(key)->value << endl;
				cout << "�������!" << endl;
			}
			catch (const std::exception&)
			{
				cout << "������!" << endl;
			}
			showMenu();
			break;

		case(Display):
			cout << "=============��� ��������=============" << endl;
			h->displayMap();
			cout << endl;
			showMenu();
			break;

		case(Stop):
			cout << "����� �� ���������" << endl;
			return 0;

		default:
			cout << "���-�� ����� �� ���..";
			return -1;
		}
	}

	system("pause");
	return 0;
}
