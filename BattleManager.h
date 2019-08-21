#pragma once
#include "Monster.h"
#include "Player.h"
#include "Pokemon.h"

class BattleManager {       //��Ʋ�� ����
private :
	BattleManager();
	static BattleManager *instance;   //�̱��� ������ ���� �ν��Ͻ�
	Monster *M;
	Pokemon *P;
	bool isWin;

public :
	static BattleManager *GetInstance();  //�̱��� ������ ���� getter

	//set
	void SetIsWin(bool _isWin) { isWin = _isWin; }

	//get
	Monster *GetMonster() { return M; }
	Pokemon *GetPokemon() { return P; }
	bool GetIsWin() { return isWin; }

	void CreateMonster();
	bool Action(int, Creature*, Creature*);
	bool Run();
	void CopyPokemon();
};