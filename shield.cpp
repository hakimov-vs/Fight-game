#include<iostream>
#include "shield.h"
using namespace std;

Shield::Shield(int s, int p){
	checkSize(s);
	checkProtection(p);
}

Shield::~Shield(){
	
}

int Shield::block(){
	destruction();
	return size*protection;
}

void Shield::destruction(){
	checkSize(size-1);
}

void Shield::repair(){
	checkSize(size+2);
}

int Shield::getSize(){
	return size;
}

int Shield::getProtection(){
	return protection;
}

void Shield::checkSize(int s){
	// I have an additional check. If input is below than 0, size will be 0, if input is over than 4, size will be 4
	if(s < 0){
		size=0;
		cout << "Size cannot be below than 0 !!!" << endl;
	}
	else if(s > 4){
		size=4;
		cout << "Size cannot be over than 4 !!!" << endl;
	}
	else{
		size=s;
	}
} 

void Shield::checkProtection(int p){
	// I have an additional check. If input is below than 1, protecrion will be 1, if input is over than 5, protection will be 5
	if(p < 1){
		protection=1;
		cout << "Protection cannot be below than 1 !!!" << endl;
	}
	else if(p > 5){
		protection=5;
		cout << "Protection cannot be over than 5 !!!" << endl;
	}
	else{
		protection=p;
	}
}
