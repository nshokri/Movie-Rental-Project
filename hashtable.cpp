#include "hashtable.h"

template <typename T>
HashTable<T>::HashTable()
{
	
	//initialize all array elemnts to point to null
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
}

template <typename T>
HashTable<T>::~HashTable()
{

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		//???????????????????????? POSSIBLE MEMORY LEAK ERROR HERE B/C OF NODE DATA
		Node* current = table[i];

		while (current != NULL)
		{
			//delete current->data;

			Node* temp = current;
			current = current->next;

			delete temp;
		}
	}
}

template <typename T>
int HashTable<T>::getHash(int id)
{
	return id % TABLE_SIZE;
}

template <typename T>
bool HashTable<T>::add(int key, T* item)
{
	int hash = getHash(key);
	
	Node* current = table[hash];

	Node* node = new Node();
	node->data = item;
	node->key = key;
	node->next = NULL;

	//Head is empty
	if (current == NULL)
	{
		table[hash] = node;
		return true;
	}

	while (current->next != NULL)
	{
		//There is a duplicate
		if (current->next->key == key)
		{
			delete node;
			return false;
		}

		current = current->next;
	}

	Node* temp = current->next;
	current->next = node;
	node->next = temp;

	return true;
}

//will return null if item doesn't exist
template <typename T>
T* HashTable<T>::retrieve(int key)
{
	int hash = getHash(key);

	Node* current = table[hash];

	while (current != NULL)
	{
		if (current->key == key)
		{
			return current->data;
		}
		
		current = current->next;
	}

	//Not found
	return NULL;
}

template <typename T>
bool HashTable<T>::remove(int key)
{
	int hash = getHash(key);

	Node* current = table[hash];

	if (current == NULL)
	{
		return false;
	}

	while (current->next != NULL)
	{
		if (current->next->key == key)
		{
			Node* temp = current->next;

			current->next = temp->next;
			delete temp;

			return true;
		}

		current = current->next;
	}

	//Was not found
	return false;
}

template <typename T>
T* HashTable<T>::find(T key)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		Node* current = table[i];

		while (current != NULL)
		{
			if (current->data == key)
			{
				return current->data;
			}
			
			current = current->next;
		}
	}

	//Was not found in entire table
	return NULL;
}