///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Sharome Burton
// Email:            koulkoudakis@gmail.com
// Label:            A08
// Title:            Copy Constructor
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       This program demonstrates a simple implementation of an RGB color palette
//		 which stores RGB colors in a ColorPallette object using composition
// Usage: 
//      - $ ./main filename
//   
// Files:            
//      A08.cpp    : driver program 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;


/**
 * This is an implementation of our single color rgb class.
 *
 */
class RgbColor {
	int r;                  //int 0-255 red
	int g;                  //int 0-255 green
	int b;                  //int 0-255 blue
public:
	RgbColor();             // default constructor
	RgbColor(int);          // overloaded 1
	RgbColor(int, int, int);  // overloaded 2

	void SetR(int);         // setter red
	void SetG(int);         // setter green
	void SetB(int);         // setter blue

	int GetR();             // getter red
	int GetG();             // getter green
	int GetB();             // getter blue

	void GrayScale();       // averages colors

	// print to stdout
	friend ostream& operator<<(ostream&, const RgbColor&);

	// add (mix) two colors
	RgbColor operator+(const RgbColor&);

};

RgbColor RgbColor::operator+(const RgbColor& rhs) {
	int r = (this->r + rhs.r) / 2;
	int g = (this->g + rhs.g) / 2;
	int b = (this->b + rhs.b) / 2;

	return *this;
}

RgbColor::RgbColor() {
	r = g = b = 0;
}

RgbColor::RgbColor(int color) {
	r = g = b = color;
}

RgbColor::RgbColor(int _r, int _g, int _b) {
	r = _r;
	g = _g;
	b = _b;
}

ostream& operator<<(ostream& os, const RgbColor& rhs) {
	os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
	return os;
}

/**
 * This class is a simple implementation of an RGB color palette
 * which stores RGB colors in a ColorPallette object
 */

class ColorPallette {
	int size = 0;
	vector<RgbColor> Pallette;

public:

	// default constructor
	ColorPallette() {
		size = 0;
	}

	// adds a color to end of pallette
	void addColor(RgbColor newColor) {
		Pallette.push_back(newColor);
		size += 1;
	}

	// removes last color from pallette
	void removeColor() {
		Pallette.pop_back();
		size -= 1;
	}

	// replace color
	void replaceColor(RgbColor newColor, int index) {

		if (index <= size) {
			Pallette[index] = newColor;
		}
		else
			cout << "Index out of range\n";

	}

	// gets size of pallette
	int getSize() {
		return size;
	}


	// gets color from pallette
	RgbColor getColor(int index) {
		RgbColor empty(0); // plain black, basically the 
						   // absence of color

		if (index <= size) {
			return Pallette[index];

		}
		else
			cout << "Index out of range\n";
		return empty;
	}

};

int main() {

	ColorPallette TestPallette; // Test of pallette object
	RgbColor read_Color;  // Stores read color objects

	cout << "Test 1 - Number of colors:" << TestPallette.getSize() << '\n';

	RgbColor Color1(255, 200, 11);
	RgbColor Color2(100, 14, 123);
	RgbColor Color3(33, 33, 33);
	RgbColor Color4(44, 44, 44);

	TestPallette.addColor(Color1);
	TestPallette.addColor(Color2);
	TestPallette.removeColor(); // removes 2nd color

	cout << "Test 2 - Number of colors:" << TestPallette.getSize() << '\n';

	TestPallette.addColor(Color2);
	TestPallette.addColor(Color3);
	TestPallette.addColor(Color4);

	cout << "Test 3 - Number of colors:" << TestPallette.getSize() << '\n';

	TestPallette.replaceColor(Color4, 0); // replace 1st color with 4th color

	cout << "Test 4 - Number of colors:" << TestPallette.getSize() << '\n';

	read_Color = TestPallette.getColor(0);
	cout << read_Color << '\n';
	read_Color = TestPallette.getColor(1);
	cout << read_Color << '\n';
	read_Color = TestPallette.getColor(2);
	cout << read_Color << '\n';
	read_Color = TestPallette.getColor(3);
	cout << read_Color << '\n';

	//RgbColor Color3 = Color1 + Color2;
	//cout<<Color3<<endl;
}