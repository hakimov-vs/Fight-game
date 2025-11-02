#include <iostream>
#include<cstdlib>
#include<ctime>
#include "character.h"
using namespace std;

bool fight(Character ch1, Character ch2) {
    if (ch1.getLife() <= 0 || ch2.getLife() <= 0) {
        cout << "One of the characters is already dead!" << endl;
        return false;
    }
    
    int round = 1;
    char directions[4] = {'w', 'a', 's', 'd'};
    srand(time(0));
    while (ch1.getLife() > 0 && ch2.getLife() > 0) {
    	cout << endl;
        cout << "ROUND " << round << endl;

        int attack1 = ch1.attack() - ch2.defence();

        if (attack1 > 0) {
        	for(int i=0; i<=10; i++){
        		ch1.go(directions[rand() % 4]);
			}
            cout << ch1.getName() << " hit " << ch2.getName() 
                 << " with " << attack1 << " damage!" << endl;
            ch2.hit(attack1);
        } else {
            cout << ch1.getName() << " could not attack!" << endl;
        }

        if (ch2.getLife() > 0) {
            int attack2 = ch2.attack() - ch1.defence();

            if (attack2 > 0) {
	            for(int i=0; i<=10; i++){
	        		ch2.go(directions[rand() % 4]);
				}
                cout << ch2.getName() << " hit " << ch1.getName() 
                     << " with " << attack2 << " damage!" << endl;
                ch1.hit(attack2);
            } else {
                cout << ch2.getName() << " could not attack!" << endl;
            }
        }

		
        // each 2 round, they recover
        if (round % 2 == 0){
        	ch1.sharpenSW();
        	ch2.repairSH();
		} 
		// each 4 round, they again recover
		if(round % 4 == 0){
			ch2.sharpenSW();
			ch1.repairSH();
		}
        cout << ch1.getName() << " life: " << ch1.getLife() << endl;
        cout << ch2.getName() << " life: " << ch2.getLife() << endl;
        
        round++;
    }

    if (ch1.getLife() > 0)
        cout << ch1.getName() << " won!" << endl;
    else
        cout << ch2.getName() << " won!" << endl;
    
    cout << endl;
    ch1.print();
    cout << endl;
    ch2.print();
    cout << endl;

    return true;
}


int main() {
	
	//N1
//	Character djon("Djon", 10, 7, 5, 5, 4, 4);
//	Character jackson("Jackson", 10, 9, 5, 5, 4, 4);

    //N2
    Character djon("Djon", 10, 8, 5, 5, 4, 4);
	Character jackson("Jackson", 10, 7, 5, 5, 4, 4);
	
	fight(djon, jackson);
    
	return 0;
}