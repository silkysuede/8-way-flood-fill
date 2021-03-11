#ifndef FLOODFILL_H
#define FLOODFILL_H
#include <iostream>
class FloodFill
{
public:
	FloodFill();
	FloodFill(int size);
	~FloodFill();
	void generateImage(int size);
	void displayImage();
	void fill(int row, int column, char newColor);
private:
	char** imagePtr;
	int imageSize;
	int getSize();
	void setSize(int size);
	void clear();
	bool check(int row, int column, char color);
	
};

#endif
