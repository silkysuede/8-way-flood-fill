#include <iostream>;
#include "FloodFill.h"
using namespace std;

int main()
{
	cout << "FIRST TEST" << endl;
	FloodFill image(12);
	image.generateImage(12);
	image.displayImage();
	image.fill(2, 2, 'G');
	
	cout << endl << endl;

	image.displayImage();
	
	cout << "SECOND TEST" << endl;
	image.generateImage(24);
	image.displayImage();
	image.fill(12, 12, 'Q');

	cout << endl << endl;

	image.displayImage();
	
	return 0;
}