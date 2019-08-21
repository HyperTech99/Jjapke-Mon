#include "Scene.h"

//UI�� Ÿ��
const int TEXT = 0;
const int MENU = 1;
const int IMAGE = 2;

Scene::Scene()
{
	//in.open(_fileName, std::ifstream::in);
	//getline(in, sceneName);
	//getline(in, sceneIndex);
	//in.close();
}

Scene::~Scene()
{
	//in.close();
}

void Scene::LoadData()
{
	ifstream filePtr;
	int seqIndex = 1;
	while (true)
	{
		string filename = ".\\Text\\" + to_string(sceneIndex) + "\\text" + to_string(seqIndex)+".dat";
		
		filePtr.open(filename, ios::binary);
		if (filePtr.is_open() == false)
			break;

		filePtr.read((char*)&textBuffer, sizeof(TextBuffer));
		Text *t = new Text(textBuffer.x, textBuffer.y, textBuffer.title, textBuffer.text);
		AddText(t);
		filePtr.close();
		seqIndex++;
	}
}

void Scene::AddText(Text *t)
{
	UI *u;
	u = t;
	ui.push_back(u);
}

void Scene::AddMenu(Menu *m)
{
	UI *u;
	u = m;
	ui.push_back(u);
}

void Scene::AddImage(Image *image)
{
	UI *u;
	u = image;
	ui.push_back(u);
}

void Scene::Draw()
{
	//cout << "Draw() Called" << endl;
	//file�� ������Ʈ ���丮 ���� ���ο� ���� Scene�� �����ϱ� ������ ������ ��θ� sceneName�� �����Ѵ�
	//file�� ��� ����Ѵ�. ����� �ּ��� ������ ����Ѵ�
	/*if (in.fail())
	{
		//"������ �����ʰ� �ؽ�Ʈ�� ���"
	}
	else*/
	/*{
		in.open(sceneName.c_str(), std::ifstream::in);
		string in_line;
		system("cls");
		gotoxy(0, 0);
		while (getline(in, in_line))
		{
			cout << in_line << endl;
		 }
		in.close();
	}*/
	in.open(sceneName.c_str(), std::ifstream::in);
	string in_line;
	system("cls");
	gotoxy(0, 0);
	while (getline(in, in_line))
	{
		cout << in_line << endl;
	}
	in.close();
	//Print();
}

void Scene::Draw(string _menuTitle)
{
	//cout << "Draw() Called" << endl;
	//file�� ������Ʈ ���丮 ���� ���ο� ���� Scene�� �����ϱ� ������ ������ ��θ� sceneName�� �����Ѵ�
	//file�� ��� ����Ѵ�. ����� �ּ��� ������ ����Ѵ�
	/*if (in.fail())
	{
		//"������ �����ʰ� �ؽ�Ʈ�� ���"
	}
	else*/
	/*{
		in.open(sceneName.c_str(), std::ifstream::in);
		string in_line;
		system("cls");
		gotoxy(0, 0);
		while (getline(in, in_line))
		{
			cout << in_line << endl;
		 }
		in.close();
	}*/
	in.open(sceneName.c_str(), std::ifstream::in);
	string in_line;
	system("cls");
	gotoxy(0, 0);
	while (getline(in, in_line))
	{
		cout << in_line << endl;
	}
	in.close();
	Print(_menuTitle);
}

void Scene::Print(string _menuTitle)	// vector ui �� ����ִ� ��� ������Ʈ���� ����Ѵ�
{
	if (ui.size() == 0)	//ui ����Ʈ�� ��������� �����Ѵ�
		return;

	vector<UI*>::iterator iter;
	Text *t;
	Menu *m;
	Image *image;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			t->Display();
		}
		else if ((*iter)->GetType() == MENU)
		{
			m = (Menu*)(*iter);
			if (m->GetTitle() == _menuTitle)
			{
				m->Display();
			}
		}
		else if((*iter)->GetType() == IMAGE)
		{
			image = (Image*)(*iter);
			image->Display();
		}
	}
}

void Scene::CleanArea()
{
	gotoxy(menuArea.x, menuArea.y);
	for (int j = 0; j < menuArea.height; j++)
	{
		for (int i = 0; i < menuArea.width; i++)
		{
			cout << " ";
		}
		gotoxy(menuArea.x, menuArea.y + j);
	}
}

void Scene::gotoxy(int _x, int _y)
{
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Text* Scene::SearchText(string _textTitle)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				return t;
			}
		}
	}

	return NULL;
}

void Scene::UpdateText(string _textTitle, string _text)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				t->SetText(_text);
				//t->Display();
			}
		}
	}
}

void Scene::UpdateText(string _textTitle, int _value)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				t->SetText(_value);
				//t->Display();
			}
		}
	}
}

void Scene::UpdateNDisplayText(string _textTitle, int _value)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				t->SetText(_value);
				t->Display();
			}
		}
	}
}