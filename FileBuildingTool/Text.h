#pragma once
#include <fstream>
using namespace std;

class Text {

	/* ����ü ���� */
	typedef struct textunit {
		string title;	//�ؽ�Ʈ ����
		string text;	//�ؽ�Ʈ ����
		int type;	//�ؽ�Ʈ Ÿ��
		int x, y;	//�ؽ�Ʈ ��ǥ
	}TEXT;

private:
	TEXT buffer;	//�ӽ� ����ü(����)
	ifstream filePtr;
	ofstream filePtrForDebug;
	int fileindex, seqindex;	//���� �ε����� ������(n�� Scene�� m��° ��µǴ� �ؽ�Ʈ -> fileindex==n, seqindex==m)

public:
	//Constructor, Destructor
	Text() { ; }
	~Text() { ; }

	//Get/Set Function
	//Text Ŭ������ ���� ����
	void LoadText();	//����ü�� ���Ͽ� ����
	void SaveText();	//����ü�� �������κ��� �о��

	//UI �߻� �Լ� ����
	void Display();	//ȭ�� ���
};

