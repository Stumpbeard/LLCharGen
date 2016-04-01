#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iomanip>


class Character
{
public:
	Character();
	~Character();

	void changeAtr(int which, int val);
	int getAtr(int which){ return stats[which]; }
	void setJob(std::string jerb){ job = jerb; }
	void setHP(int die){ 
		hp = (rand() % die + 1) + conMod();
		if (hp < 0) hp = 1;
	}
	int getHP() { return hp; }
	void setAlign(std::string align){ alignment = align; }
	void setGold();
	void setThrows();
	void setName(std::string n){ name = n; }
	std::string getName() { return name; }

	void print(std::ostream& os);

	int strMod();
	int dexMod();
	int conMod();
	int intMod();
	int wisMod();
	int chaMod();

private:
	std::string name;
	std::string job;
	std::string alignment;
	int stats[6];
	int ac;
	int thac0;
	int hp;
	int throws[5];
	int gold;
};

