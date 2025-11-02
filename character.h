#ifndef CHARACTER_H
#define CHARACTER_H
#include "sword.h"
#include "shield.h"
using namespace std;

class Character{
	public:
		Character(string, int=10, int=10, int=5, int=6, int=4, int=4);
		~Character();
		bool hit(int);	
		int attack();
		int defence();
		int getLife();
		int getStrength();
		string getName();
		void go(char);
		void print();
		void checkLife(int);
		void checkStrength(int);
		void sharpenSW();
		void repairSH();
	private:
		string name;
		int life;
		int strength;
		char path[10];
		int swWeight;
		int SwQuality;
		int shSize;
		int shProtection;
		Sword sw;
		Shield sh;
		
};

#endif