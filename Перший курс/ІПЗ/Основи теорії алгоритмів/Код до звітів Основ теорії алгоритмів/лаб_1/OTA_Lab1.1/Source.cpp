#include <iostream>

using namespace std;

struct ListItem
{
	int data;
	ListItem* next;
};

ListItem* ReadList(int);
void arithm(ListItem*);
int max(ListItem*);
int min(ListItem*);
void printElem(ListItem*, int);
void printElemBeforeMin(ListItem*);
void DeleteList(ListItem*);
void WriteList(ListItem*);
ListItem* addElem(ListItem*&);
void DeleteElem(ListItem*&);

ListItem* ReadList(int N)
{
	while (N < 1 || N>256)
	{
		cout << "Error; ����i�� �������� �i���i��� �������i�: ";
		cin >> N;
		cout << endl;
	}
	ListItem* check = nullptr;
	ListItem* last = nullptr;
	ListItem* first = nullptr;
	for (int i = 0; i < N; i++)
	{
		cout << "����i�� " << i+1 << "-� ������� ������: ";
		int k;
		cin >> k;
		check = first;
		while (check != nullptr)
		{
			while (k == check->data)
			{
				cout << "Error; �������� ������ ������������" << endl << "�������i�� ������i� �������: ";
				cin >> k;
			}
			check = check->next;
		}
		ListItem* link = new ListItem;
		link->data = k;
		link->next = 0;
		if (last == 0)
		{
			first = link;
		}
		else
		{
			last->next = link;
		}
		last = link;

	}
	return first;
}

void arithm(ListItem* a)
{
	int sa = 0, count=0;
	while (a != nullptr)
	{
		sa += a->data;
		count++;
		a = a->next;
	}
	cout <<"������ ����������� �������i� ������: " << double(sa) / double(count) << endl;
}

int max(ListItem* a)
{
	int max=a->data;
	while (a != nullptr)
	{
		max =max > a->data ? max : a->data;
		a = a->next;
	}
	return max;
	
}

int min(ListItem* a)
{
	int min = a->data;
	while (a != nullptr)
	{
		min = min < a->data ? min : a->data;
		a = a->next;
	}
	return min;
}

void printElem(ListItem* a, int number)
{
	int count=0;
	for (ListItem* i = a; i != nullptr; i = i->next)
		count++;
	if (count >= number)
	{
		for (int i = 1; i < number; i++)
		{
			a = a->next;
		}
		cout << number << "-� ������� ������: " << a->data << endl;
	}
	else
	{
		cout << number <<"-�� �������� ����"<<endl;
	}
}

void printElemBeforeMin(ListItem* a)
{
	int count = 0;
	ListItem* first = a;
	while (first->data!=min(a))
	{
		count++;
		first = first->next;
	}
	if (count == 0)
	{
		cout << "������ ������� �i�i�������: " << a->data << endl;
	}
	else {
		for (int i = 0; i < count-1; i++)
		{
			a = a->next;
		}
		cout << "�������, �� ��� ����� �i�i������� ���������: " << a->data << endl;
	}
}

ListItem* addElem(ListItem*& list)
{
	ListItem* check = list;
	cout << "����i�� ����� ������� ������: ";
	ListItem* item = new ListItem;
	int k;
	cin >> k;
	while (check != nullptr)
	{
		if (k == check->data)
			throw "Error; �������� ������ ������������";
		check = check->next;
	}
	item->next = list;
	item->data = k;
	list = item;
	return list;
}

void DeleteElem(ListItem*& list)
{
	ListItem* next = list->next;
	delete list;
	list = next;
}


void DeleteList(ListItem* list)
{
	while (list!=nullptr)
	{
		ListItem* next = list->next;
		delete list;
		list = next;
	}
}

void WriteList(ListItem* list)
{
	cout << "���������: ";
	while (list != nullptr) {
		cout.width(6);
		cout << list->data;
		list = list->next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");

	int N;
	cout << "����i�� �i���i��� �������i� ������'������ ������: ";
	cin >> N;
	ListItem* list = ReadList(N);
	WriteList(list);
	arithm(list);
	cout << "�i�i������� ������� ������: " << min(list) << endl;
	cout << "������������ ������� ������: " << max(list) << endl;
	printElem(list, 4);
	printElemBeforeMin(list);
	cout << endl;
	
	cout << "�������� ������ ������� ���������" << endl;
	DeleteElem(list);
	WriteList(list);
	arithm(list);
	cout << "�i�i������� ������� ������: " << min(list) << endl;
	cout << "������������ ������� ������: " << max(list) << endl;
	printElem(list, 4);
	printElemBeforeMin(list);
	cout << endl;
	
	addElem(list);
	WriteList(list);
	arithm(list);
	cout << "�i�i������� ������� ������: " << min(list) << endl;
	cout << "������������ ������� ������: " << max(list) << endl;
	printElem(list, 4);
	printElemBeforeMin(list);
	cout << endl;

	DeleteList(list);
	return 0;
}