#include <iostream>
#include <string>
#include "Player.h"
#include "Creature.h"

using namespace std;

Player::Player() {

}

Player *Player::instance = nullptr;

Player *Player::GetInstance() {
	if (instance == nullptr) {
		instance = new Player();
	}
	return instance;
}

void Player::SaveProfile() {
	ofstream fileptr;

	fileptr.open(".\\Profile\\" + playerName + ".txt", ios::trunc);
	fileptr << playerName << endl;
	fileptr << playerAge << endl;
	fileptr << playerGender << endl;
	fileptr << P->GetName() << ' ';

	for (int i = 0; i < 4; i++) {
		fileptr << P->GetSkills()[i].GetskillName() << ' ';
	}

	fileptr << P->GetType() << ' ' << P->GetHp() << ' ' << P->GetMp() << ' ' << P->GetAtk() << ' ' << P->GetDef() << ' ' << P->GetLevel() << ' ' << P->GetExp();
	fileptr.close();

	return;
}

void Player::LoadProfile(string temp) {
	ifstream fileptr;

	//���� ����
	fileptr.open(".\\Profile\\" + temp + ".txt");
	//�÷��̾� �̸� �о����
	getline(fileptr, playerName);
	//�÷��̾� ���� �о����
	getline(fileptr, temp);
	playerAge = atoi(temp.c_str());
	//�÷��̾� ���� �о����
	getline(fileptr, temp);
	playerGender = atoi(temp.c_str());
	//�÷��̾� ���ϸ� �о����

	P->PlayerPokemonLoad(fileptr);
	

	//getline(fileptr,���⿡ ������ string�� �����ϸ� �˴ϴ�.);
	fileptr.close();

	return;
}