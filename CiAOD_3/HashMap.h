using namespace std;
//template for generic type 
template<typename K, typename V, typename T>

//�������-���� �������
class HashNode
{
public:
	V value;//����
	K key;//����
	T name;//��������

	HashNode(K key)
	{
		this->key = key;
	}

	HashNode(K key, V value, T name)
	{
		this->value = value;
		this->key = key;
		this->name = name;
	}
};

template<typename K, typename V, typename T>
class HashMap
{
	//������ ���������� �� ����
	HashNode<K, V, T> **arr;
	int capacity;
	//������� ���������
	int size;
	//���������-����
	HashNode<K, V, T> *mock;

public:
	HashMap(int capacity)
	{
		this->capacity = capacity;
		size = 0;
		arr = new HashNode<K, V, T>*[capacity];

		//�������������� ������ ����-����������
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;

		mock = new HashNode<K, V, T>(-1);

	}
	
	//���-�������
	int hashCode(K key)
	{
		return key % capacity;
	}

	//������� �������
	bool insertNode(K key, V value, T name)
	{
		if (isFull()) { return false; };

		HashNode<K, V, T> *temp = new HashNode<K, V, T>(key, value, name);

		// ��������� �������
		int hashIndex = hashCode(key);

		//���� ������ ����� 1��� - ���� �����, 2 - ���� ��� ������, �� ��������, 3 - ���� ���������
		while (arr[hashIndex] != NULL && arr[hashIndex]->key != key
			&& arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		//���� �� ����������, �� ����������� �������
		if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
			size++;
		else
			delete arr[hashIndex];
		arr[hashIndex] = temp;
		return true;
	}

	//������� �������� ����
	bool deleteNode(int key)
	{
		//���� � ��� ������, �� �������
		if (isEmpty()) { return false; };

		// �������� ������
		int hashIndex = hashCode(key);

		//���� ���� � �������� ������
		while (arr[hashIndex] != NULL)
		{
			//���� �����
			if (arr[hashIndex]->key == key)
			{
				//������ ���������� ���� ��������� ���������-����
				arr[hashIndex] = mock;

				// �� � ��������� ������� ���������
				--size;
				return true;
			}
			hashIndex++;
			hashIndex %= capacity;

		}

		//���� �� ����� �� ������� �� �������
		return false;
	}

	//������� ������ ����
	HashNode<K, V, T>* getNode(int key)
	{
		//�������� ������, � ����� ������� ������ �� ������������ �����
		int hashIndex = hashCode(key);
		int origIndex = hashIndex-1;

		//����� ������� ����
		while (arr[hashIndex] != NULL && hashIndex != origIndex)
		{
			//���� ����� �� ��������� ��������� �� ����
			if (arr[hashIndex]->key == key)
				return arr[hashIndex];
			hashIndex++;
			hashIndex %= capacity;
		}
		if (arr[hashIndex] != NULL && arr[hashIndex]->key == key)
			return arr[hashIndex];

		//���� �� ����� �� ��������� ����.���������
		return NULL;
	}

	int mapSize(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

	//����� ���� �����
	void displayMap()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key
				<< " price = " << arr[i]->value << " name = " << arr[i]->name << endl;
		}
	}
};