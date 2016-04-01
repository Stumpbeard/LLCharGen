#include "Character.h"

using namespace std;

void rollDice(int& d1, int& d2, int& d3, int& total);
bool charOptions();
bool alignOptions();
bool nameOptions();

Character player = Character();

int main(){

	srand(time(NULL));


	cout << "\nWelcome to chargen for Labyrinth Lord (an OSR clone of BECMI D&D)" << endl << endl;
	cout << "First thing's first: Let's roll up those stats. Just press enter" << endl;
	cout << "to see what the next roll is. We'll be rolling 3d6 in order of" << endl;
	cout << "STR, DEX, CON, INT, WIS, CHA." << endl << endl;


	bool tryagain = true;

	while (tryagain == true){
		int die1, die2, die3;
		int total;

		rollDice(die1, die2, die3, total);
		cout << "STR = " << total << " (" << die1 << ", " << die2 << ", " << die3 << ")";
		player.changeAtr(0, total);
		cin.get();

		rollDice(die1, die2, die3, total);
		cout << "DEX = " << total << " (" << die1 << ", " << die2 << ", " << die3 << ")";
		player.changeAtr(1, total);
		cin.get();

		rollDice(die1, die2, die3, total);
		cout << "CON = " << total << " (" << die1 << ", " << die2 << ", " << die3 << ")";
		player.changeAtr(2, total);
		cin.get();

		rollDice(die1, die2, die3, total);
		cout << "INT = " << total << " (" << die1 << ", " << die2 << ", " << die3 << ")";
		player.changeAtr(3, total);
		cin.get();

		rollDice(die1, die2, die3, total);
		cout << "WIS = " << total << " (" << die1 << ", " << die2 << ", " << die3 << ")";
		player.changeAtr(4, total);
		cin.get();

		rollDice(die1, die2, die3, total);
		cout << "CHA = " << total << " (" << die1 << ", " << die2 << ", " << die3 << ")";
		player.changeAtr(5, total);
		cin.get();

		cout << "\nTry again? [y,n]" << endl;
		cout << "> ";

		tryagain = false;

		if (tolower(cin.get()) == 'y'){
			tryagain = true;
			cout << endl;
			cin.ignore();
		}
	}

	cin.ignore();
	bool classChosen = false;
	while (classChosen == false){
		classChosen = charOptions();
	}

	cout << "\nYour HP is: " << player.getHP() << endl;

	bool alignChosen = false;
	while (alignChosen == false){
		alignChosen = alignOptions();
		cin.ignore();
	}

	cout << endl;
	player.setGold();
	cout << "\nSetting saving throws..." << endl;
	player.setThrows();

	while (nameOptions());

	cout << "\nHere is your character sheet. Finally!" << endl << endl;
	player.print(cout);
	cout << endl;

	cout << "Do you want to save your character to a text file? [y,n]" << endl;
	cout << "> ";
	if (tolower(cin.get()) == 'y'){
		ofstream os;
		os.open((player.getName() + ".txt").c_str());
		player.print(os);
	}
	else {
		cout << "\nOh well. Cya!";
		cin.ignore();
		cin.get();
	}

	return 0;
}

void rollDice(int& d1, int& d2, int& d3, int& total){
	d1 = rand() % 6 + 1;
	d2 = rand() % 6 + 1;
	d3 = rand() % 6 + 1;
	total = d1 + d2 + d3;
}

bool charOptions(){
	cout << "\nThese classes are available based on your stats." << endl;
	cout << "Type the letter to make a selection or learn more." << endl;
	cout << endl;
	cout << "c) Cleric" << endl;
	if (player.getAtr(2) >= 9) cout << "d) Dwarf" << endl;
	if (player.getAtr(3) >= 9) cout << "e) Elf" << endl;
	cout << "f) Fighter" << endl;
	if (player.getAtr(1) >= 9 && player.getAtr(2) >= 9) cout << "h) Halfling" << endl;
	cout << "m) Magic-User" << endl;
	cout << "t) Thief" << endl;
	cout << "> ";
	char choice = tolower(cin.get());
	cin.ignore();
	switch (choice){
	case 'c':
		cout << "\nCleric. A proud servant of god. Less of a passive priest, more of a holy crusader." << endl;
		cout << "Has the ability to turn away the undead and 1 cleric spell at first level. Creates" << endl;
		cout << "a stronghold at level 9. May use any armor and any weapons except those with sharp" << endl;
		cout << "edges." << endl << endl;
		cout << "Do you want to be a cleric? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Cleric");
			player.setHP(6);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	case 'd':
		cout << "\nDwarf. A short and stout warrior, capable with any armor and any weapon (that" << endl;
		cout << "isn't two handed or a longbow). Has excellent underground vision, can recognize" << endl;
		cout << "many kinds of stones, and will get his own mountainhome at level 9." << endl << endl;
		cout << "Do you want to be a dwarf? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Dwarf");
			player.setHP(8);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	case 'e':
		cout << "\nElf. Tall, skinny friends of the wilderness. Talented spellswords who excel at" << endl;
		cout << "both weapon and magic combat. They can use any kind of armor and any kind of weapon." << endl;
		cout << "Equipped with dark vision and an immunity to paralysis, an elf also gets their own" << endl;
		cout << "woodland hall at level 9." << endl << endl;
		cout << "Do you want to be an elf? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Elf");
			player.setHP(6);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	case 'f':
		cout << "\nFighter. The front lines of combat. Can proficiently wield any armor or weapon" << endl;
		cout << "and even gains extra attacks per round as they level up. At level 9, they get the" << endl;
		cout << "chance to become lord over their own parcel of land." << endl << endl;
		cout << "Do you want to be a fighter? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Fighter");
			player.setHP(8);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	case 'h':
		cout << "\nHalfing. A roguish kind of combatant. Much like dwarves they are unable to use" << endl;
		cout << "large or two handed weapons, but any armor is acceptable. Nimble and low-profile," << endl;
		cout << "they get bonuses against large foes and can hide as a thief. At level 8, they become" << endl;
		cout << "sheriff of their own tucked away valley, attracting like minded folk." << endl << endl;
		cout << "Do you want to be a halfling? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Halfling");
			player.setHP(6);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	case 'm':
		cout << "\nMagic-User. While they start frail and could fall to any foe, they quickly gain" << endl;
		cout << "an arsenal of powerful spells. However, they are unable to use anything but small" << endl;
		cout << "weapons and no armor or shields at all. At level 9, they gain the ability to research" << endl;
		cout << "magic themselves, and at level 11 build their own tower, attacting apprentices." << endl << endl;
		cout << "Do you want to be a magic-user? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Magic-User");
			player.setHP(4);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	case 't':
		cout << "\nThief. The skillful rogue necessary in any serious party. Adept at all kinds of" << endl;
		cout << "dungeon crawling, they are masters of wall scaling, lock picking, and trap disarming." << endl;
		cout << "While they can use any weapon, they are limited to no armor heavier than leather, and" << endl;
		cout << "no shields. This freedom of movement allows them to backstab foes for double damage." << endl;
		cout << "At level 9, a thief may start his own guild of ne'er-do-wells." << endl << endl;
		cout << "Do you want to be a thief? [y,n]" << endl;
		cout << "> ";
		if (tolower(cin.get()) == 'y'){
			cin.ignore();
			player.setJob("Thief");
			player.setHP(4);
			return true;
		}
		else {
			cin.ignore();
			return false;
		}
	default:
		return false;
	}
}

bool alignOptions(){

	cout << "\nChoose your alignment. [l,n,c]" << endl << endl;
	cout << "Lawful. Selfless. Tends towards putting others before themselves." << endl;
	cout << "Neutral. Middle of the road. Leans either way, or strives for balance." << endl;
	cout << "Chaotic. Selfish. Favors self-interest over helping others." << endl;
	cout << "> ";
	switch (tolower(cin.get())){
	case 'l':
		cout << "\nYour alignment is Lawful." << endl;;
		player.setAlign("Lawful");
		return true;
	case 'n':
		cout << "\nYour alignment is Neutral." << endl;
		player.setAlign("Neutral");
		return true;
	case 'c':
		cout << "\nYour alignment is Chaotic." << endl;
		player.setAlign("Chaotic");
		return true;
	default:
		cout << "\nTry again. Pick from [l,n,c]." << endl;
		return false;
	}
}

bool nameOptions(){
	cout << "\nFinally, what is your name?" << endl;
	cout << "> ";
	string charname;
	getline(cin, charname);
	cout << "\n" << charname << endl;
	cout << "Is this the name you want? [y,n]" << endl;
	cout << "> ";
	if (tolower(cin.get()) == 'y'){
		player.setName(charname);
		cin.ignore();
		return false;
	}
	else{
		cin.ignore();
		return true;
	}
}