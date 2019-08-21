#pragma once
#include "Scene.h"
#include <io.h>
#include <vector>
#include <direct.h>

using namespace std;

class SceneManager
{
private:
	SceneManager();		
	char currentDir[1000];				// �����ʰ� ���ÿ� ������ ����� ��� ���ϵ��� �о� sceneList�� scene ������ �����Ѵ�
	string path;						// Scene ������ ��ġ, SceneManager�� �����ڿ��� �ʱ�ȭ��Ų��
	static SceneManager *instance;		// SceneManager �� �ϳ��� �����Ѵ� -> �̱��� �������� ����
	vector<Scene*> sceneList;			// Scene ������ �о� Scene ������ ������ �迭

public:
	static SceneManager* GetInstance();
	~SceneManager();

	//Getter
	vector<Scene*> GetSceneList() { return sceneList; }
	int GetListSize() { return sceneList.size(); }

	//Setter

	//Functionality
	void LoadScene();
	void AddScene(Scene *s);
	void ChangeScene(int _delay, int _index);	// _delay ��ŭ ��ٷȴٰ� Scene �� �ٲ۴�
	void ChangeScene(int _index);	// _delay ���� Scene �� �ٷ� �ٲ۴�
};

