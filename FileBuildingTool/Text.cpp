#include "Text.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void gotoxy(int _x, int _y) {
	COORD pos = { _x,_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Text::LoadText() {
	string filename = to_string(fileindex) + "_" + to_string(seqindex) + "text.dat";
	filePtr.open(filename, ios::binary);
	filePtr.read((char*)&buffer, sizeof(TEXT));
	filePtr.close();
}

void Text::SaveText() {
	string filename;
	string temp;

	cout << "=========Jjap'ketmon Development Tool - DAT==========" << endl;
	cout << "�� ����� Jjap'ketmon �� ����׸� ���� ����Դϴ�." << endl;
	cout << "text�� �����ϱ� ���� binary ������ �����ϴ� Development Tool �Դϴ�." << endl;
	cout << "==============================================" << endl;
	
	cout << " 1�ܰ� : File �̸��� �����մϴ�. ������ �ؽ�Ʈ �޴� �κ��� 1ȸ �ٲ� ������ ���ο� ������ �ε��ؾ� �մϴ�. ��, 1ȸ�� �ؽ�Ʈ ��¿� 1���� ������ ����մϴ�." << endl;

	cout << "Setting File Index == �� �ε��� �ѹ��� �Է��Ͻÿ�" << endl;
	cin >> fileindex;
	cout << "Setting Seq Index == " << fileindex << "�� ���� �� ��° �ؽ�Ʈ���� ���� ��ȣ�� �Է��Ͻÿ�" << endl;
	cin >> seqindex;
	filename = to_string(fileindex) + "_" + to_string(seqindex) + "text.dat";

	cout << "2�ܰ� : ���� ������ �Է��մϴ�. ���ϸ��� " << filename << "�Դϴ�." << endl;

	cout << "Setting File Contents == �ܼ�â X ��ǥ�� �Է��Ͻÿ�" << endl;
	cin >> buffer.x;
	cout << "Setting File Contents == �ܼ�â Y ��ǥ�� �Է��Ͻÿ�" << endl;
	cin >> buffer.y;
	cout << "Setting File Contents == TEXT�� MENU Class�� �����ϴ� �����ڸ� �Է��Ͻÿ�" << endl;
	cin >> buffer.type;
	cout << "Setting File Contents == �ؽ�Ʈ ������ �Է��Ͻÿ�." << endl;
	cin.ignore();
	getline(cin, temp, '\n');	//���鹮�� ����
	buffer.title = temp;
	cout << "Setting File Contents == �ؽ�Ʈ ������ �Է��Ͻÿ�." << endl;
	getline(cin, temp, '\n');	//���鹮�� ����
	buffer.text = temp;

	filePtrForDebug.open(filename, ios::binary);
	filePtrForDebug.write((char*)&buffer, sizeof(TEXT));
	filePtrForDebug.close();

}

void Text::Display() {
	system("cls");
	cout << "�Ʒ��� ���� �б�, ��� �׽�Ʈ�Դϴ�." << endl;
	gotoxy(buffer.x, buffer.y);
	cout << buffer.text;
}

