#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Skill {
private:
	//��� ����

	string name;
	double damageMultiplier;
	double attackMultiplier;
	double defenseMultiplier;
	int behaviour; //��ų�� ����(������ type)
	string type; //��ų�� �Ӽ�(Ÿ��, ������ type �ƴ�)
	int mp;
public:
	//������

	Skill() : name("missingno"), damageMultiplier(0.0), attackMultiplier(1.0), defenseMultiplier(1.0), behaviour(0), type("�븻"), mp(0) { }
	Skill(string name, double dmg, double atk, double def, int value, string type, int mp) : name(name), damageMultiplier(dmg), attackMultiplier(atk), defenseMultiplier(def), behaviour(value), type(type), mp(mp) { }

	//Get/Set

	string GetskillName() const {
		return name;
	}
	double GetskillDamageMultiplier() const {
		return damageMultiplier;
	}
	double GetskillAttackMultiplier() const {
		return attackMultiplier;
	}
	double GetskillDefenseMultiplier() const {
		return defenseMultiplier;
	}
	int GetskillBehaviour() const {
		return behaviour;
	}
	string GetskillType() const {
		return type;
	}
	int GetMp() const {
		return mp;
	}
	void SetskillName(string name) {
		this->name = name;
	}
	void SetskillDamageMultiplier(double multiplier) {
		damageMultiplier = multiplier;
	}
	void SetskillAttackMultiplier(double multiplier) {
		attackMultiplier = multiplier;
	}
	void SetskillDefenseMultiplier(double multiplier) {
		defenseMultiplier = multiplier;
	}
	void SetskillBehaviour(int value) {
		this->behaviour = value;
	}
	void SetskillType(string value) {
		this->type = value;
	}
	void SetMp(int _mp) {
		mp = _mp;
	}
	//�ٸ� ���

	void PrintskillName();

	bool Attacks();
	bool Upgrades();
	bool Heals();

	bool IsWater();
	bool IsGrass();
	bool IsElectricity();
	bool IsFire();
	bool IsNormal();

	void Save();
	double Use();
};