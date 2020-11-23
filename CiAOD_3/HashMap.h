	using namespace std;

	template<typename K, typename V, typename T>
	class HashNode
	{
	public:
		V value;
		K key;
		T name;
		int id;

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
		//Array of Node of pointers
		HashNode<K, V, T> **arr;
		int capacity;
		//counter of elements
		int size;
		//Mock-node
		HashNode<K, V, T> *mock;

	public:
		HashMap(int capacity)
		{
			this->capacity = capacity;
			size = 0;
			arr = new HashNode<K, V, T>*[capacity];

			//Initialize array of nullpointer
			for (int i = 0; i < capacity; i++)
				arr[i] = NULL;

			mock = new HashNode<K, V, T>(-1);

		}
	
		//hash-function
		int hashCode(K key)
		{
			return key % capacity;
		}

		//insert function
		bool insertNode(K key, V value, T name)
		{
			if (isFull()) { return false; };

			HashNode<K, V, T> *temp = new HashNode<K, V, T>(key, value, name);

			// get index
			int hashIndex = hashCode(key);
			//Search empty space 1if - if empty, 2if - if already taken, 3if - if is mock
			while (arr[hashIndex] != NULL && arr[hashIndex]->key != key
				&& arr[hashIndex]->key != -1)
			{
				hashIndex++;
				hashIndex %= capacity;
			}

			//if not replaced, then increase counter
			if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
				size++;
			else
				delete arr[hashIndex];
			arr[hashIndex] = temp;
			temp->id = hashIndex;
			return true;
		}

		//Node delete function
		bool deleteNode(int key)
		{
			//if empty, then exit
			if (isEmpty()) { return false; };

			// get index
			int hashIndex = hashCode(key);

			//Search node with key
			while (arr[hashIndex] != NULL)
			{
				//If found
				if (arr[hashIndex]->key == key)
				{
					//Instead searched Node insert mock-node
					arr[hashIndex] = mock;

					// decrease counter of element
					--size;
					return true;
				}
				hashIndex++;
				hashIndex %= capacity;

			}

			//If not found then exit the function
			return false;
		}

		//Node search function
		HashNode<K, V, T>* getNode(int key)
		{
			//Get index and create defense of infinity cycle
			int hashIndex = hashCode(key);
			int origIndex = hashIndex-1;

			//Find desired node
			while (arr[hashIndex] != NULL && hashIndex != origIndex)
			{
				// If found, it returns a pointer to the node
				if (arr[hashIndex]->key == key)
					return arr[hashIndex];
				hashIndex++;
				hashIndex %= capacity;
			}
			if (arr[hashIndex] != NULL && arr[hashIndex]->key == key)
				return arr[hashIndex];

			//If not found, return null pointer
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

		//Display all nodes
		void displayMap()
		{
			for (int i = 0; i < capacity; i++)
			{
				if (arr[i] != NULL && arr[i]->key != -1)
					cout << "key = " << arr[i]->key << " ID = " << arr[i]->id
					<< " price = " << arr[i]->value << " name = " << arr[i]->name << endl;
			}
		}
	};