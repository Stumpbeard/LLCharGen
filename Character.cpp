#include "Character.h"

using namespace std;

Character::Character()
{
	for (int i = 0; i < 6; i++){
		stats[i] = 0;
	}
	thac0 = 19;
	ac = 9 - dexMod();
}


Character::~Character()
{
}

void Character::changeAtr(int which, int val){
	stats[which] = val;
}

int Character::strMod(){
	switch (stats[0]){
	case 3:
		return -3;
	case 4:
	case 5:
		return -2;
	case 6:
	case 7:
	case 8:
		return -1;
	case 9:
	case 10:
	case 11:
	case 12:
		return 0;
	case 13:
	case 14:
	case 15:
		return 1;
	case 16:
	case 17:
		return 2;
	case 18:
		return 3;
	default:
		return 0;
	}
}

int Character::dexMod(){
	switch (stats[1]){
	case 3:
		return -3;
	case 4:
	case 5:
		return -2;
	case 6:
	case 7:
	case 8:
		return -1;
	case 9:
	case 10:
	case 11:
	case 12:
		return 0;
	case 13:
	case 14:
	case 15:
		return 1;
	case 16:
	case 17:
		return 2;
	case 18:
		return 3;
	default:
		return 0;
	}
}

int Character::conMod(){
	switch (stats[2]){
	case 3:
		return -3;
	case 4:
	case 5:
		return -2;
	case 6:
	case 7:
	case 8:
		return -1;
	case 9:
	case 10:
	case 11:
	case 12:
		return 0;
	case 13:
	case 14:
	case 15:
		return 1;
	case 16:
	case 17:
		return 2;
	case 18:
		return 3;
	default:
		return 0;
	}
}

int Character::intMod(){
	switch (stats[3]){
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		return 0;
	case 13:
	case 14:
	case 15:
		return 1;
	case 16:
	case 17:
		return 2;
	case 18:
		return 3;
	default:
		return 0;
	}
}

int Character::wisMod(){
	switch (stats[4]){
	case 3:
		return -3;
	case 4:
	case 5:
		return -2;
	case 6:
	case 7:
	case 8:
		return -1;
	case 9:
	case 10:
	case 11:
	case 12:
		return 0;
	case 13:
	case 14:
	case 15:
		return 1;
	case 16:
	case 17:
		return 2;
	case 18:
		return 3;
	default:
		return 0;
	}
}

int Character::chaMod(){
	switch (stats[5]){
	case 3:
		return 2;
	case 4:
	case 5:
		return 1;
	case 6:
	case 7:
	case 8:
		return 1;
	case 9:
	case 10:
	case 11:
	case 12:
		return 0;
	case 13:
	case 14:
	case 15:
		return -1;
	case 16:
	case 17:
		return -1;
	case 18:
		return -2;
	default:
		return 0;
	}
}

void Character::setGold(){
	gold = ((rand() % 8 + 1) + (rand() % 8 + 1) + (rand() % 8 + 1)) * 10;
	cout << "You have " << gold << " gold pieces." << endl;
}

void Character::setThrows(){
	if (job == "Cleric"){
		throws[0] = 16;
		throws[1] = 11;
		throws[2] = 14;
		throws[3] = 12;
		throws[4] = 15;
		return;
	}
	if (job == "Dwarf" || job == "Halfling"){
		throws[0] = 13;
		throws[1] = 8;
		throws[2] = 10;
		throws[3] = 9;
		throws[4] = 12;
		return;
	}
	if (job == "Elf"){
		throws[0] = 15;
		throws[1] = 12;
		throws[2] = 13;
		throws[3] = 13;
		throws[4] = 15;
		return;
	}
	if (job == "Fighter"){
		throws[0] = 15;
		throws[1] = 12;
		throws[2] = 14;
		throws[3] = 13;
		throws[4] = 16;
		return;
	}
	if (job == "Magic-User"){
		throws[0] = 16;
		throws[1] = 13;
		throws[2] = 13;
		throws[3] = 13;
		throws[4] = 14;
		return;
	}
	if (job == "Thief"){
		throws[0] = 16;
		throws[1] = 14;
		throws[2] = 13;
		throws[3] = 15;
		throws[4] = 14;
		return;
	}
	cout << "\n\n!!!!FLAIL IN PROGRESS, NO CLASS!!!\n\n" << endl;
}

void Character::print(ostream& os){
	os << "Name:  " << name << endl;
	os << "Class: " << job;
	os << "  Alignment: " << alignment << endl;
	os << setw(4) << "AC: " << setw(2) << ac;
	os << setw(8) << " THAC0: " << setw(2) << thac0;
	os << setw(5) << " HP: " << setw(2) << hp << endl << endl;
	os << setw(5) << "STR: " << setw(2) << stats[0] << setw(5) << strMod() << endl;
	os << setw(5) << "DEX: " << setw(2) << stats[1] << setw(5) << dexMod() << setw(12) << "  Breath:   " << setw(2) << throws[0] << endl;
	os << setw(5) << "CON: " << setw(2) << stats[2] << setw(5) << conMod() << setw(12) << "  Poison:   " << setw(2) << throws[1] << endl;
	os << setw(5) << "INT: " << setw(2) << stats[3] << setw(5) << intMod() << setw(12) << "  Paralyze: " << setw(2) << throws[2] << endl;
	os << setw(5) << "WIS: " << setw(2) << stats[4] << setw(5) << wisMod() << setw(12) << "  Wands:    " << setw(2) << throws[3] << endl;
	os << setw(5) << "CHA: " << setw(2) << stats[5] << setw(5) << chaMod() << setw(12) << "  Spells:   " << setw(2) << throws[4] << endl;
	os << endl;
	os << setw(6) << "Gold: " << setw(3) << gold << endl;
}