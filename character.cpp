#include<iostream>
#include "character.h"
using namespace std;

Character::Character(string n, int l, int s, int swW, int swQ, int shS, int shP) : sw(swW, swQ), sh(shS, shP){
	name=n;
	checkLife(l);
	checkStrength(s);
} 

Character::~Character(){
	if(life <= 0)
		cout << "Game over for " << name << endl;
}

bool Character::hit(int h){
	if(life-h < 0) 
		life=0;
	else{
		life = life-h;
	}
	return life > 0;
} 

int Character::attack(){
	return life > 0 ? strength+sw.damage() : 0;
}

int Character::defence(){
	// for this part I used multiplication (strength * 2) instead of (strength / 2) which is shown in the HW.pptx
	// If had used division, the game would end very shortly because this function would return little number as defence
	return life > 0 ? (strength * 2) + sh.block() : 0;
}

int Character::getLife(){
	return life;
}

int Character::getStrength() {
	return strength;
}

void Character::go(char ch) {
	char lastChar[sizeof(path)];
	if(life > 0){
		switch(ch){
			case 'w':
			case 'a':
			case 's':
			case 'd':
				lastChar[0] = ch;	
				
				for(int i=0; i<sizeof(path); i++){
					if(i+1 < sizeof(path)){
						lastChar[i+1] = path[i];	
					}
				}
				for(int z=0; z<sizeof(lastChar); z++){
					path[z] = lastChar[z];
				};
				break;
			default:
				cout << "Directions should contain w, a, s, d !!!" << endl;
		}
	}
		
	
}

void Character::print(){
	bool isAlive = true ? life > 0 : false;
	
	cout << "Character's name = " << name << endl
	     << "Character's strength = " << getStrength() << endl;
	
	if(isAlive){	
		cout << "Character is " << "alive" << endl
		     << "Character's life points = " << life << endl;  	
	}
	else{
		cout << "Character is " << "dead" << endl;	     
	}
	
	cout << "Character's route = ";
	
	for(int i=0; i<sizeof(path); i++){
		cout << path[i] << ", "; 
	}
	cout << endl;
	cout << "Character's sword has " << sw.getQuality() << " quality, and " 
	     << sw.getWeight() << " weight" << endl
		 << "Character's shield has " << sh.getProtection() << " protection, and "
		 << sh.getSize() << " size." << endl;  
		 
}

void Character::checkLife(int l){
	if(l < 1){
		life=1;
		cout << "Life point cannot be below than 1 !!!" << endl;
	}
	else if(l > 10){
		life=10;
		cout << "Life point cannot be over than 10 !!!" << endl;
	}
	else{
		life=l;
	}
}

void Character::checkStrength(int s){
	if(s < 1){
		strength=1;
		cout << "Strength cannot be below than 1 !!!" << endl;
	}
	else if(s > 10){
		strength=10;
		cout << "Strength cannot be over than 10 !!!" << endl;
	}
	else{
		strength=s;
	}
} 

string Character::getName() {
	return name;
}

void Character::sharpenSW(){
	sw.sharpen();
}

void Character::repairSH() {
	sh.repair();
}