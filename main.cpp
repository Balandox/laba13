#include <iostream>
#include "classes.h"
#include<stdlib.h>

int main(int argc, char* argv[]) {
	BinVect vec1;
	std::cin >> vec1;
	std::cout << "Resulting vector: " << vec1;
	BinVect vec2;
	std::cin >> vec2;
	std::cout << "Resulting vector: " << vec2;
	/*BinVect vec2(vec1);
	std::cout << "\nVector 2 after copy constructor: " << vec2; //copy constructor*/

	/*vec2 = vec1;														// assignment operator
	std::cout << "\nResulting vector after operator=: " << vec2;*/
	int idx_replace = 0, val = 0;
	std::cout << "\n\nInput the index of the element to replace: ";
	std::cin >> idx_replace;
	/*while (vec1.set(res, val) == -1) {
		std::cout << "Incorrect input! This index not find. Try again: ";
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> idx_replace;
		vec1.set(idx_replace, val);
	}																									// set
	std::cout << "Input value to replace: ";
	std::cin >> val;
	while (vec1.set(idx_replace, val) == -2) {
		std::cout << "Incorrect input! You can input only 1 or 0! Try again: ";
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> val;
		vec1.set(idx_replace, val);
	}*/
	std::cout << "Resulting vector: " << vec1;
	/*
	int idx = 0;
	std::cout << "\n\nInput the index of the element to get: ";
	std::cin >> idx;
	while (vec1.get(idx) == -1) {
		std::cout << "Incorrect input! This index not find. Try again: ";
		std::cin.clear();
		std::cin.ignore(100, '\n');															//get
		std::cin >> idx;
		vec1.get(idx);
	}
	std::cout << "\nvalue on index " << idx << ": " << vec1.get(idx) << std::endl;*/

	std::cout << "\nEnter right bit shift: ";
	int shift_r = 0;
	std::cin >> shift_r;												// bit shift to right
	vec1 = vec1 >> shift_r;
	std::cout << "\nResulting vector after bit shift: " << vec1;

	/*std::cout << "\nEnter left bit shift: ";
	int shift_l = 0;
	std::cin >> shift_l;																				// bit shift to left
	vec1 = vec1 << shift_l;
	std::cout << "\nResulting vector after left bit shift: " << vec1;

	std::cout << "\nResult operator<= : ";
	if (vec1 <= vec2)
		std::cout << "Vector1 <= Vector2";									 // operator <=
	else
		std::cout << "Vector1 > Vector2";

	std::cout << "\nResult operator< : ";
	if (vec1 < vec2)
		std::cout << "Vector1 < Vector2";										// operator <
	else
		std::cout << "Vector1 >= Vector2";


	std::cout << "\nResult operator>= : ";
	if (vec1 >= vec2)
		std::cout << "Vector1 >= Vector2";										// operator >=
	else
		std::cout << "Vector1 < Vector2";

	std::cout << "\nResult operator> : ";
	if (vec1 > vec2)
		std::cout << "Vector1 > Vector2";												// operator >
	else
		std::cout << "Vector1 <= Vector2";

	std::cout << "\nResult operator == : ";
	if (vec1 == vec2)																		// equallity operator
		std::cout << "These two vectors are equal\n";
	else
		std::cout << "These two vectors are not equal\n";

	std::cout << "\nResult operator != : ";
	if (vec1 != vec2)
		std::cout << "These two vectors are not equal\n";													// not equallity operator
	else
		std::cout << "These two vectors are equal\n";*/

	/*BinVect vec3;
	vec3 = vec1 + vec2;
	std::cout << "\nResalting vector after summ: " << vec3;					// operator+

	vec3 = vec1 - vec2;
	std::cout << "\nResalting vector after operator-: " << vec3;									// operator-

	vec1 += vec2;
	std::cout << "\nVector1 after operator +=: " << vec1;				// operator +=

	vec1 -= vec2;
	std::cout << "\nVector1 after operator -=: " << vec1;						// operator-=*/

	return 0;
}