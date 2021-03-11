#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

class OrderedPair
{
public:

	OrderedPair();
	OrderedPair(int a, int b, bool p);
	int getA();
	int getB();
	void setA(int a);
	void setB(int b);
private:
	int intA;
	int intB;

};

#endif