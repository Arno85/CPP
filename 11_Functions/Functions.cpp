#include <iostream>

using namespace std;

/********************************************************************************
* Function Prototypes:
* Allows to tell the compiler the definition of functions before they're written.
* Avoid "used before declaration" errors
********************************************************************************/
void area_circle();
void volume_cylinder();
double calc_area_circle(double radius);
double calc_volume_cylinder(double radius, double height);
void add_one_to_each_value(int arr[], size_t length);
void readonly_argument(const int num);
void modify_number(int& num);
void print(int arr[], size_t length);
void print(int num);
/*********************************
* Function Prototypes End
*********************************/

const double pi{ 3.14159 };

int main()
{
	area_circle();
	volume_cylinder();

	/********************************************************************************
	* Array function argument:
	* Arrays are passed by reference in functions. In fact it's only the reference of the 1st index (see Array section).
	* Since it's only the ref of the 1st index, we need to pass the size of the array to loop through.
	* If we modify arrays in function, it will modify directly the reference in memory
	********************************************************************************/
	int arr[]{ 1, 2, 3, 4, 5 };
	print(arr, 5);
	add_one_to_each_value(arr, 5);
	print(arr, 5);

	/********************************************************************************
	* Readonly argument
	* Adding const to the argument insure that we can't modify it in the function;
	********************************************************************************/
	readonly_argument(1);

	/********************************************************************************
	* Pass by reference
	* All types of variable can be passed by referenceby adding an '&' 
	********************************************************************************/
	int num = 1;
	print(num);
	modify_number(num);
	print(num);

	return 0;
}

void area_circle() {
	double radius{};

	cout << "\nEnter the radius of the circle: ";
	cin >> radius;
	cout << "The area of a circle with radius " << radius << " is: " << calc_area_circle(radius) << endl;
}

void volume_cylinder() {
	double radius{};
	double height{};

	cout << "\nEnter the radius of the cylinder: ";
	cin >> radius;
	cout << "\nEnter the height of the cylinder: ";
	cin >> height;
	cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is: " << calc_volume_cylinder(radius, height) << endl;
}

double calc_area_circle(double radius) {
	return pi * radius * radius;
}

double calc_volume_cylinder(double radius, double height) {
	return calc_area_circle(radius) * height;
}

void add_one_to_each_value(int arr[], size_t length) {
	for (int i{ 0 }; i < length; i++) {
		arr[i]++;
	}
}

void modify_number(int& num) {
	num = 500;
}

void readonly_argument(const int num) {
	// num++; Will throw a compiler error
}

void print(int arr[], size_t length) {
	cout << "\nValues of the array: ";

	for (int i{ 0 }; i < length; i++) {
		cout << arr[i] << ", ";
	}

	cout << endl;
}

void print(int num) {
	cout << "\nThe value of the number is: " << num;
}
