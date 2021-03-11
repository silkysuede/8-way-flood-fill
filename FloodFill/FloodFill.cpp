#include "FloodFill.h"
#include "OrderedPair.h"
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <queue>
#include <windows.h>
using namespace std;

//default constructor
FloodFill::FloodFill()
{
	setSize(0);
}//end FloodFill()

/**
*Parameterized FloodFill constructor.
*@param SIZE: the size of the image
**/
FloodFill::FloodFill(int size)
{
	setSize(size);
}//end FloodFill(int)

//deconstructor
FloodFill::~FloodFill()
{
	clear();
}//end ~FloodFill

/**
*Accessor for private member variable imageSize.
*@return imageSize
**/
int FloodFill::getSize()
{
	return imageSize;
}//end getSize()

/**
*Mutator for private member variable imageSize.
*@param SIZE: the size of the image
**/
void FloodFill::setSize(int size)
{
	imageSize = size;
}//end setSize()

/**
*Creates the image of "pixels". The pixels are
*represented as characters. Each of the four possible
*char choices has an equal but random chance of being generated.
*@param SIZE: the size of the image
**/
void FloodFill::generateImage(int size)
{
	if (size != getSize())
	{
		setSize(size);
	}//end if
	
	int random;
	//used to randomize the image
	srand(time(NULL));
	char charArray[4] = { 'c', 'm', 'y', 'k'};
	imagePtr = new char*[size];
	for (int i = 0; i < size; i++)
	{
		imagePtr[i] = new char[size];
	}//end for
	
	for (int i = 0; i < getSize(); i++)
	{
		for (int j = 0; j < getSize(); j++)
		{
			 random = ((rand() % 4) + 1);

			if (random == 1)
			{
				imagePtr[i][j] = charArray[0];
				
			}//end if

			if (random == 2)
			{
				imagePtr[i][j] = charArray[1];
				
			}//end if

			if (random == 3)
			{
				imagePtr[i][j] = charArray[2];
				
			}//end if

			if (random == 4)
			{
				imagePtr[i][j] = charArray[3];
				
			}//end if

		}//end for

	}//end for
	
}//end generateImage()

/**
*Displays the randomly generated image to the console with color!
**/
void FloodFill::displayImage()
{
	HANDLE hConsole;
	int k = 15;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
	int loopRow = 0;
	int loopCol = 0;
	cout << "  ";
	for (int i = 0; i < getSize(); i++)
	{
		cout << loopCol << " ";
		if (loopCol == 9)
		{
			loopCol = 0;
		}//end if
		else
		{
			loopCol++;
		}//end else
	}//end for
	cout << "" << endl;
	for (int i = 0; i < getSize(); i++)
	{
		k = 15;
		SetConsoleTextAttribute(hConsole, k);
		cout << loopRow << " ";

		for (int j = 0; j < getSize(); j++)
		{
			k = 15;
			if (imagePtr[i][j] == 'c')
			{
				k = 11;
			}//end if

			if (imagePtr[i][j] == 'm')
			{
				k = 10;
			}//end if

			if (imagePtr[i][j] == 'y')
			{
				k = 14;
			}//end if

			if (imagePtr[i][j] == 'k')
			{
				k = 12;
			}//end if
			SetConsoleTextAttribute(hConsole, k);
			cout << imagePtr[i][j] << " ";
		}//end for

		if (loopRow == 9)
		{
			loopRow = 0;
		}//end if
		else
		{
			loopRow++;
		}//end else
		cout << "" << endl; 
	}//end for
	cout << "" << endl;
}//end displayImage()

/**
*An eight-way flood fill algorithm. Attempts to fill
*in pixels adjacent to the starting pixel and branches out from there
*until there are no more pixels of the same color that are able to be reached.
*@pre image must be generated.
*@param ROW: the row in imagePtr to start at.
*@param COLUMN: the column in imagePtr to start at.
*@param NEWCOLOR: the color that will replace the old color.
**/
void FloodFill::fill(int row, int column, char newColor)
{
	char matchColor = imagePtr[row][column];

	cout << "Beginning at " << '[' << row << ']' << '[' << column << ']';
	cout << " I will flood fill and replace " << matchColor << " with " << newColor << '.' << endl;

	queue<OrderedPair>* aQueue = new queue<OrderedPair>;
	OrderedPair currentPixel;
	OrderedPair startPixel;
	OrderedPair newPixel;
	startPixel.setA(row);
	startPixel.setB(column);
	imagePtr[startPixel.getA()][startPixel.getB()] = newColor;
	aQueue->push(startPixel);
	
	while (!aQueue->empty())
	{
		currentPixel = aQueue->front();
		aQueue->pop();
		
		//check left
		if (check((currentPixel.getA()),
			(currentPixel.getB() - 1), matchColor) == true) 
		{
			imagePtr[currentPixel.getA()][currentPixel.getB() - 1] = newColor;
			newPixel.setA(currentPixel.getA());
			newPixel.setB(currentPixel.getB() - 1);
			aQueue->push(newPixel);
		}//end if

		//check right
		if (check(currentPixel.getA(),
			(currentPixel.getB() + 1), matchColor) == true) 
		{
			imagePtr[currentPixel.getA()][currentPixel.getB() + 1] = newColor;	
			newPixel.setA(currentPixel.getA());
			newPixel.setB(currentPixel.getB() + 1);
			aQueue->push(newPixel);
		}//end if

		//check top
		if (check((currentPixel.getA() - 1),
			(currentPixel.getB()), matchColor) == true) 
		{
			imagePtr[currentPixel.getA() - 1][currentPixel.getB()] = newColor;
			newPixel.setA(currentPixel.getA() - 1);
			newPixel.setB(currentPixel.getB());
			aQueue->push(newPixel);
		}//end if

		//check bottom
		if (check((currentPixel.getA() + 1),
			currentPixel.getB(), matchColor) == true) 
		{
			imagePtr[currentPixel.getA() + 1][currentPixel.getB()] = newColor;	
			newPixel.setA(currentPixel.getA() + 1);
			newPixel.setB(currentPixel.getB());
			aQueue->push(newPixel);
		}//end if

		//check top left
		if (check((currentPixel.getA() - 1),
			(currentPixel.getB() - 1), matchColor) == true) 
		{
			imagePtr[currentPixel.getA() - 1][currentPixel.getB() - 1] = newColor;
			newPixel.setA(currentPixel.getA() - 1);
			newPixel.setB(currentPixel.getB() - 1);
			aQueue->push(newPixel);
		}//end if

		//check bottom left
		if (check((currentPixel.getA() + 1),
			(currentPixel.getB() - 1), matchColor) == true) 
		{
			imagePtr[currentPixel.getA() + 1][currentPixel.getB() - 1] = newColor;
			newPixel.setA(currentPixel.getA() + 1);
			newPixel.setB(currentPixel.getB() - 1);
			aQueue->push(newPixel);
		}//end if

		//check top right
		if (check((currentPixel.getA() - 1),
			(currentPixel.getB() + 1), matchColor) == true) 
		{
			imagePtr[currentPixel.getA() - 1][currentPixel.getB() + 1] = newColor;	
			newPixel.setA(currentPixel.getA() - 1);
			newPixel.setB(currentPixel.getB() + 1);
			aQueue->push(newPixel);
		}//end if

		//check bottom right
		if (check((currentPixel.getA() + 1),
			(currentPixel.getB() + 1), matchColor) == true) 
		{
			imagePtr[currentPixel.getA() + 1][currentPixel.getB() + 1] = newColor;	
			newPixel.setA(currentPixel.getA() + 1);
			newPixel.setB(currentPixel.getB() + 1);
			aQueue->push(newPixel);
		}//end if
		
	}//end while

	//cleanup
	delete aQueue;
}//end fill()

/**
*checks if the pixel is equal to the color that needs to be
*changed.
*@param ROW: the row the pixel to check is in
*@return true if pixel color in imagePtr matches the color we are looking for
*@param COLUMN: the column the pixel to check is in
**/
bool FloodFill::check(int row, int column, char color)
{
	if ((row >= 0) && (column >= 0))
	{
		if ((row >= getSize()) || (column >= getSize()))
		{
			return false;
		}//end if

		else
		{
			if (imagePtr[row][column] == color)
			{
				return true;
			}//end if

			else { return false; } //end else
		}//end else
		
	}//end if

	else
	{
		return false;
	}//end else
	
}//end checkLeft()

/**
*Deallocates imagePtr
**/
void FloodFill::clear()
{
	//loop through 2D array and delete the arrays inside of it
	for (int i = 0; i < getSize(); i++)
	{
		delete[] imagePtr[i];
	}//end for
	delete[] imagePtr;
}//end clear()


