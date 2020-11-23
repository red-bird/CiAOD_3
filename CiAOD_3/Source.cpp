#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

void showMenu() {
	cout << "===========================Selection menu===========================\n"
		<< "1.  Enter element\n"
		<< "2.  Delete element\n"
		<< "3.  Search and read element\n"
		<< "4.  Display hashmap\n"
		<< "5.  Stop program\n"
		<< "Enter code: ";
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

	//setlocale(LC_ALL, "ru");
	cout << "Hashing - direct access to data\n18 Variant direct addressing (linear probing)\nProduct: Code - six-digit number, name, price\n";
	int n;
	cout << "Enter amount of hashmap: ";
	try
	{
		cin >> n;
		if (n < 1)
		{
			cout << "Wrong amount of elements";
			return -1;
		}
	}
	catch (const std::exception&)
	{
		cout << "Something gone wrong.. stop programm";
		return -1;
	}

	HashMap<int, double, string> *h = new HashMap<int, double, string>(n);
	showMenu();
	int key;
	n = 0;
	double price;	
	string name;
	HashNode<int, double, string>* tmp;
	while (n != Stop)
	{
		cin >> n;
		switch (n)
		{
		case(Insert):
			cout << "Enter key/article sit-digit: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "Article is not 6-digit number\n";
				return -1;
			}
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter price: ";
			cin >> price;
			if (h->insertNode(key, price, name))
				cout << "Success!" << endl;
			else
				cout << "Error!" << endl;
			showMenu();
			break;

		case(Delete):
			cout << "Enter key/article sit-digit: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "Article is not 6-digit number\n";
				return -1;
			}
			if (h->deleteNode(key))
				cout << "Success!" << endl;
			else
				cout << "Error!" << endl;
			showMenu();
			break;

		case(Search):
			cout << "Enter key/article sit-digit: ";
			cin >> key;
			if ((key / 100000 > 9) | (key / 100000 < 1))
			{
				cout << "Article is not 6-digit number\n";
				return -1;
			}
			tmp = h->getNode(key);
			if (tmp != NULL)
				cout << "key = " << tmp->key << " id = " << tmp->id << " name = " << tmp->name << " price = " << tmp->value << endl;
			else
				cout << "Error!" << endl;
			showMenu();
			break;

		case(Display):
			cout << "=============All elements=============" << endl;
			h->displayMap();
			cout << endl;
			showMenu();
			break;

		case(Stop):
			cout << "Exit from program" << endl;
			return 0;

		default:
			cout << "Something gone wrong...";
			return -1;
		}
	}

	system("pause");
	return 0;
}
