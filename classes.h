#ifndef _CLASSES_H_
#define _CLASSES_H_
#include <iostream>

class BinVect {
private:
	int len;
	int* data;
public:
	BinVect();
	~BinVect();
	BinVect(BinVect& vec);
	BinVect& operator=(const BinVect& vec);
	friend int convertation(long long int& num, BinVect& vec);
	bool operator== (const BinVect& vec) const;
	bool operator!= (const BinVect& vec)const;
	bool operator< (const BinVect& vec) const;
	bool operator>(const BinVect& vec) const;
	bool operator<= (const BinVect& vec) const;
	bool operator>= (const BinVect& vec) const;
	BinVect operator+ (const BinVect& vec) const;
	BinVect operator- (const BinVect& vec) const;
	void operator-= (const BinVect& vec);
	void operator+= (const BinVect& vec);
	BinVect& operator>>(int num);
	BinVect& operator<<(int num);
	int set(int idx, int val);
	int get(int idx) const;
	friend std::ostream& operator << (std::ostream& out, const BinVect& vec);
	friend std::istream& operator >> (std::istream& in, BinVect& vec);
};
#endif
