#include "OrderedPair.h"
using namespace std;


OrderedPair::OrderedPair() : intA(0), intB(0)
{}

OrderedPair::OrderedPair(int a, int b, bool p) : intA(a), intB(b)
{}

int OrderedPair::getA()
{
	return intA;
}

int OrderedPair::getB()
{
	return intB;
}

void OrderedPair::setA(int a)
{
	intA = a;
}

void OrderedPair::setB(int b)
{
	intB = b;
}

