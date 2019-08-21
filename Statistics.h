#pragma once
#include "BattleManager.h"
#include "SceneManager.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Statistics {
	//player Ŭ������ ����ϸ� �ȵ�. player Ŭ������ �̱��� ������ �ı��Ǳ� ������.
private:
	static Statistics *instance;	//�ν��Ͻ�
	double winrate;	//�·�
	int wins;	//�¼�
	int loses;	//�м�
	int games;	//��ü ���Ӽ�

	Statistics() { ; }

public:
	/* Constructors */
	//�̱� �� ��� ������� ������ ��� ����.
	static Statistics *GetInstance();	//�ν��Ͻ� ����

	/* GET/SET Function */
	//Getter
	int Getwinrate() {
		return winrate * 100;
	}

	int Getwins() {
		return wins;
	}

	int Getloses() {
		return loses;
	}

	int Getgames() {
		return games;
	}

	//��/��/���� Ƚ���� ���Ƿ� �������� ���ϵ��� setter�� ������.

	/* Functionailty */
	void InitStatistics() {	//���� ���� �ʱ⿡ �÷��̾� ������ ������ ���� ��赵 ���� ����
		wins = 0;
		loses = 0;
		games = 0;
		winrate = 0.0;
		return;
	}

	void LoadStatistics(string playername);	//���� ���� �ʱ⿡ �÷��̾� ������ �ε��� ���� �� �Լ��� ȣ���Ͽ� ��� �ε�.
	void SaveStatistics(string playername);	//���� ���� ������ �� �Լ��� ȣ���Ͽ� ��� ����.
	void UpdateStatistics();                //��Ʋ ���� �� �������� ȣ��, �̰����� ������ ����

};