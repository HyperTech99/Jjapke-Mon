#include "Menu.h"



Menu::Menu() :UI()
{
	//���� �� ��ü�� Menu Ÿ���̴�
	//�޴��� 0���� �׻� �ڷΰ����̴�
	AddItem("0. Back");
	type = 1;
}

Menu::Menu(int _x, int _y, string _title) :UI()
{
	SetCOORD(_x, _y);
	SetTitle(_title);
	AddItem("0. Back");
	type = 1;
}

Menu::~Menu()
{
}

void Menu::AddItem(string _item)
{
	items.push_back(_item);
}

void RemoveItem(int _index)
{

}

void Menu::Display()
{
	//�޴��� ��� �׸��� ������� ����Ѵ�
	//cout << "Menu::Display" << endl;
	int i, line = 0;
	for (i = 1; i < items.size(); i++)
	{
		gotoxy(x, y + (i - 1));
		cout << items[i];
	}
	cout << endl;
	//gotoxy(x, y + i);
	//cout << items[0];	//�� ������ �ٿ� Back �׸��� �����ش�
}
