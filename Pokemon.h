#pragma once
#include "Creature.h"

class Pokemon : public Creature {
private :
	int selectAct;       //�ൿ �Է�
	int selectSkill;     //��ų �Է�
public :
	Pokemon();

	//setter

	//getter

	void TakeExp(int e_exp);    //EXPȹ��
	void PokemonLoad(int);
	void PlayerPokemonLoad(ifstream &);
};
