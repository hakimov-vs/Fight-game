#ifndef SHIELD_H
#define SHIELD_H

class Shield{
	public:
		Shield(int = 4, int = 4);
		~Shield();
		int block();
		void destruction();
		void repair();
		int getSize();
		int getProtection();
		void checkSize(int);
		void checkProtection(int);
		
	private:
		int size;
		int protection;
};

#endif