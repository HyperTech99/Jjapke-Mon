#include "Text.h"

Text::Text() :UI()
{
	//�� ��ü�� Text ��ü�̴�
	type = 0;
}

Text::Text(int _x, int _y, string _title,string _text) : UI()
{
	SetCOORD(_x, _y);
	SetTitle(_title);
	SetText(_text);
	type = 0;
}

Text::Text(int _x, int _y, string _title, int _value) :UI()
{
	SetCOORD(_x, _y);
	SetTitle(_title);
	SetText(_value);
	type = 0;
}

Text::~Text()
{
}

void Text::SetText(string _text)
{
	text = _text;
}

void Text::SetText(int _value)
{
	//���� ���� string���� �ٲ��ش�
	text = to_string(_value);
}

void Text::Display()
{
	gotoxy(this->x, this->y);
	cout << "    ";
	gotoxy(this->x, this->y);
	cout << this->text;
}
