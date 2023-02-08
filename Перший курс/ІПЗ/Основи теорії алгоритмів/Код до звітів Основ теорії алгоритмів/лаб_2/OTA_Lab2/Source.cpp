#include <iostream>
#include <cmath>

using namespace std;

struct ListItem
{
	int value;
	int key;
	ListItem* next;
};

struct HashEntry
{
	int key;
	ListItem* list;
	HashEntry* next;
};

double HashFunc(int k)
{
	const double A = 0.618033;
	return fmod(k * A, 1);
}

class HashTable
{
private:
	static const int TABLE_SIZE=16;
	HashEntry* buckets_[TABLE_SIZE];
	HashEntry* FindHashEntry(const int& key, HashEntry* firstEntry)
	{
		for (HashEntry* entry = firstEntry; entry!=nullptr ; entry=entry->next)
		{
			if (key == entry->key)
			{
				return entry;
			}
		}
	}

	

public:
	void Put(const int& key, const int& value)
	{
		const int hash = int(HashFunc(key)*TABLE_SIZE);
		cout << "���-��������: " << hash<<endl;
		HashEntry* entry = FindHashEntry(key, buckets_[hash]);
		if (entry)
		{	
			ListItem* temp = new ListItem;
			temp->next = entry->list;
			temp->key = key;
			temp->value = value;
			entry->list = temp;
		}
		else
		{
			entry = new HashEntry;
			entry->key = key;

			entry->list = nullptr;
			ListItem* temp = new ListItem;
			temp->next = entry->list;
			temp->key = key;
			temp->value = value;
			entry->list = temp;

			entry->next = buckets_[hash];
			buckets_[hash] = entry;
		}
	}

	HashEntry* Get(const int& key) 
	{
		const int hash = int(HashFunc(key) * TABLE_SIZE);
		HashEntry* entry = FindHashEntry(key, buckets_[hash]);
		if (entry)
		{
			return entry;
		}
		else
		{
			cout << "������� �� ��������"<<endl;
			return nullptr;
		}
		
	}

	HashTable()
	{
		memset(buckets_, 0, sizeof(HashEntry*) * TABLE_SIZE);
	}
};

void ReadHashTable(HashTable& hashTable)
{
	int N;
	cout << "����i�� �i���i��� ��� ���-������i N: ";
	cin >> N;
	while (N <= 1 || N >= 256)
	{
		cout << "Error; ����i�� �������� �i���i���: ";
		cin >> N;
	}
	int* check = new int[N] {};
	for (int i = 0; i < N; i++)
	{
		int key, value;
		cout << i+1 << " ���� (����, ��������): ";
		cin >> key >> value;
		int j=0;
		for (int j = 0; j < N; j++)
		{
			while (check[j] == key)
			{
				cout << "Error; ����i ������������; ����i�� �������� ���� (����, ��������): ";
				cin >> key >> value;
				j = 0;
			}
		}
		check[i] = key;
		hashTable.Put(key, value);
	}
	delete[] check;
}

void FindHash(HashTable& hashTable)
{
	int M;
	cout << "����i�� �i���i��� ����i� ��� ������: ";
	cin >> M;
	while (M <=1 || M >= 256)
	{
		cout << "Error; ����i�� �������� �i���i���: ";
		cin >> M;
	}
	for (int i = 0; i < M; ++i)
	{
		int key;
		cout << "����i�� ����: ";
		cin >> key;
		while (key <= 0)
		{
			cout << "Error; ���� <= 0; ����i�� ��������� ����: ";
			cin >> key;
		}
		HashEntry* elem = hashTable.Get(key);
		if (elem != nullptr)
		{
			ListItem* list = elem->list;
			while (list != nullptr)
			{
				if(list->key==key)
					cout << "��������: "<< list->value << '\t';
				list = list->next;
			}
			cout << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");

	HashTable hashTable;
	
	ReadHashTable(hashTable);

	FindHash(hashTable);

	return 0;
}