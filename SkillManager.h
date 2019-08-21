#pragma once
#include <string>
#include <vector>
#include "skill.h"
class SkillManager {
private:
	//��� ����

	static SkillManager* manager;

	vector<Skill*> skillList;

	//������

	SkillManager();

public:
	//Get/Set

	static SkillManager* GetInstance();

	vector<Skill*> GetskillList() const {
		return skillList;
	}

	Skill* GetSkill(int);

	Skill* GetSkill(string);

	void SetSkill(int, Skill*);

	//���

	void AddSkill(Skill*);
	
};