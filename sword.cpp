#include<iostream>
#include "sword.h"
using namespace std;

Sword::Sword(int w, int q){
	checkWeight(w);
	checkQuality(q);
}

Sword::~Sword(){
}

int Sword::damage(){
	int powerOfDamage = weight*quality;
	wearAndTear(); 
	return powerOfDamage;
}

void Sword::wearAndTear(){
	checkQuality(quality-1);
}

void Sword::sharpen(){
	checkQuality(quality+2);
}

int Sword::getWeight(){
	return weight;
}

int Sword::getQuality(){
	return quality;
}

void Sword::checkWeight(int w){
	// I have an additional check. If input is over than 5, weight will be 5, if input is below than 2, weight will be 2
	if(w < 2){
		weight=2;
		cout << "Weight cannot be below than 2 !!!" << endl;
	}
	else if(w > 5){
		weight=5;
		cout << "Weight cannot be over than 5 !!!" << endl;
	}
	else{
		weight=w;
	}
}

void Sword::checkQuality(int q){
	// I have an additional check. If input is over than 6, quality will be 6, if input is below than 1, quality will be 1
	if(q < 1){
		quality=1;
		cout << "Quality cannot be below than 1 !!!" << endl;
	}
	else if(q > 6){
		quality=6;
		cout << "Quality cannot be over than 6 !!!" << endl;
	}
	else{
		quality=q;
	}
}