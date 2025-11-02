#ifndef SWORD_H
#define SWORD_H

class Sword{
	public:
		Sword(int = 5, int = 6);
		int damage();
		void wearAndTear();
		void sharpen();
		int getWeight();
		int getQuality();
		void checkWeight(int);
		void checkQuality(int); 
		~Sword();
	private:
		int weight;
		int quality;
};

#endif