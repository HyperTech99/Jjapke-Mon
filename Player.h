#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"

using namespace std;

class Player {
private:
	Player();
	static Player *instance;	//�ν��Ͻ�
	string playerName;	//�÷��̾� �̸�
	int playerAge;	//�÷��̾� ����
	bool playerGender;	//0==����, 1==����
	Pokemon *P;	//�÷��̾ ���� ���ϸ�
public:
	static Player *GetInstance();	//�ν��Ͻ� ����

	//set
	void SetplayerName(string name) {
		playerName = name;
	}
	void SetplayerAge(int age) {
		playerAge = age;
	}
	void SetplayerGender(bool gender) {
		playerGender = gender;
	}
	void SetPokemon() {
		P = new Pokemon();
	}

	//get
	string GetplayerName() {
		return playerName;
	}
	int GetplayerAge() {
		return playerAge;
	}
	bool GetplayerGender() {
		return playerGender;
	}
	Pokemon *GetPokemon() {
		return P;
	}

	void SaveProfile();	//�������� ���Ͽ� ����
	void LoadProfile(string);	//�������� ���Ͽ��� �ε�
};