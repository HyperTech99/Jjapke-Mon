#include <iostream>
#include <fstream>
#include <string>
#include "Statistics.h"

using namespace std;

const int BattleWin = 5;
const int BattleLose = 6;

Statistics *Statistics::instance = nullptr;

Statistics* Statistics::GetInstance() {
	if (instance == nullptr) {
		instance = new Statistics();
	}
	return instance;
}

void Statistics::SaveStatistics(string playername) {
	ofstream fileptr;

	fileptr.open(".\\Stats\\" + playername + ".txt");
	fileptr << games << endl;
	fileptr << wins << endl;
	fileptr << loses << endl;
	fileptr << winrate << endl;

	return;
}

void Statistics::LoadStatistics(string playername) {
	ifstream fileptr;
	string temp;

	//���� ����
	fileptr.open(".\\Stats\\" + playername + ".txt");

	//����Ƚ�� �о����
	getline(fileptr, temp);
	games = atoi(temp.c_str());

	//�¸�Ƚ�� �о����
	getline(fileptr, temp);
	wins = atoi(temp.c_str());

	//�й�Ƚ�� �о����
	getline(fileptr, temp);
	loses = atoi(temp.c_str());

	//�·� �о����
	getline(fileptr, temp);
	winrate = atof(temp.c_str());

	return;
}

void Statistics::UpdateStatistics() {
	int WinorLose;

	games++;

	//��Ʋ�Ŵ����� ���� �̰���� Ȯ��
	if (BattleManager::GetInstance()->GetIsWin()) {  //�̰�����
		wins++;
		WinorLose = BattleWin;
	}
	else {                                           //������
		loses++;
		WinorLose = BattleLose;
	}

	winrate = (double)wins / (double)games;

	//�������� �ؽ�Ʈ ����
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("TotalGames")->SetText(games);
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("WinRates")->SetText(winrate * 100);
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("Wins")->SetText(wins);
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("Loses")->SetText(loses);
}