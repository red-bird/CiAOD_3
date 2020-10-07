using namespace std;
//template for generic type 
template<typename K, typename V, typename T>

//Элемент-узел Хешмапы
class HashNode
{
public:
	V value;//цена
	K key;//ключ
	T name;//название

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
	//Массив указателей на узлы
	HashNode<K, V, T> **arr;
	int capacity;
	//счетчик элементов
	int size;
	//фиктивный-узел
	HashNode<K, V, T> *mock;

public:
	HashMap(int capacity)
	{
		this->capacity = capacity;
		size = 0;
		arr = new HashNode<K, V, T>*[capacity];

		//Инициализируем массив нуль-указателей
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;

		mock = new HashNode<K, V, T>(-1);

	}
	
	//Хеш-функций
	int hashCode(K key)
	{
		return key % capacity;
	}

	//Функция вставки
	bool insertNode(K key, V value, T name)
	{
		if (isFull()) { return false; };

		HashNode<K, V, T> *temp = new HashNode<K, V, T>(key, value, name);

		// Получение индекса
		int hashIndex = hashCode(key);

		//Ищем пустое место 1усл - если пусто, 2 - если уже занято, но заменяем, 3 - если фиктивный
		while (arr[hashIndex] != NULL && arr[hashIndex]->key != key
			&& arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		//Если не заменяется, то увеличиваем счетчик
		if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
			size++;
		else
			delete arr[hashIndex];
		arr[hashIndex] = temp;
		return true;
	}

	//Функция удаления узла
	bool deleteNode(int key)
	{
		//Если и так пустая, то выходим
		if (isEmpty()) { return false; };

		// Получаем индекс
		int hashIndex = hashCode(key);

		//Ищем узел с заданным ключом
		while (arr[hashIndex] != NULL)
		{
			//Если нашли
			if (arr[hashIndex]->key == key)
			{
				//Вместо найденного узла вставляем фиктивный-узел
				arr[hashIndex] = mock;

				// Ну и уменьшаем счетчик элементов
				--size;
				return true;
			}
			hashIndex++;
			hashIndex %= capacity;

		}

		//Если не нашли то выходим из функции
		return false;
	}

	//Функцию поиска узла
	HashNode<K, V, T>* getNode(int key)
	{
		//Получаем индекс, а также создаем защиту от бесконечного цикла
		int hashIndex = hashCode(key);
		int origIndex = hashIndex-1;

		//Поиск нужного узла
		while (arr[hashIndex] != NULL && hashIndex != origIndex)
		{
			//Если нашли то возращает указатель на узел
			if (arr[hashIndex]->key == key)
				return arr[hashIndex];
			hashIndex++;
			hashIndex %= capacity;
		}
		if (arr[hashIndex] != NULL && arr[hashIndex]->key == key)
			return arr[hashIndex];

		//Если не нашли то возращаем нуль.указатель
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

	//Вывод всех узлов
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