#include "skill.h"

//��ų �̸� ���
void Skill::PrintskillName() {
	cout << name;
}

bool Skill::Attacks() {
	return behaviour == 0;
}

bool Skill::Upgrades() {
	return (behaviour == 1 || behaviour == 2);
}

bool Skill::Heals() {
	return behaviour == 3;
}

bool Skill::IsWater() {
	return type == "��";
}

bool Skill::IsGrass() {
	return type == "Ǯ";
}

bool Skill::IsElectricity() {
	return type == "����";
}

bool Skill::IsFire()
{
	return type == "��";
}

bool Skill::IsNormal() {
	return type == "�븻";
}

//���Ͽ� ��ų ����
void Skill::Save() {
	string word;
	ifstream i("skill_list.txt");
	if (!i.is_open()) return;
	while (i >> word) {
		if (word == name) {
			i.close();
			return;
		} //�ش� �̸��� ��ų�� �̹� �����ϸ� �������� ����
	}
	i.close();

	ofstream o("skill_list.txt", ios::app);
	if (!o.is_open()) return;
	o << name << ' ' << damageMultiplier << ' ' << attackMultiplier << ' ' << defenseMultiplier << ' ' << behaviour << ' ' << type << mp <<'\n';
	o.close();
}
//��ų ���
double Skill::Use() {
	switch (behaviour) {
	case 0:
		return damageMultiplier;
	case 1:
		return attackMultiplier;
	case 2:
		return defenseMultiplier;
	case 3:
		return  0.1;
	default:
		return 0;
		//����� ���� �� ��
	}
}