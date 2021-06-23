#include <iostream>
#include <cmath>
#include "classes.h"

int convertation(long long int& num, BinVect& vec) {
	int* tmp = new int[18];
	int i = 0, idx = 0;
	if (num == 0) {
		vec.len = i + 1;
		vec.data = new int[vec.len];
		vec.data[i] = 0;
	}
	else {
		while (num != 0)
		{
			tmp[i] = num % 10;
			if (tmp[i] < 0 || tmp[i] > 1)
				return -1;
			num = num / 10;
			i++;
		}
		vec.len = i;
		vec.data = new int[vec.len];
		for (int j = i - 1; j >= 0; j--) {
			vec.data[idx] = tmp[j];
			idx++;
		}
	}
	return 0;
}

BinVect::BinVect() {
	len = 1;
	data = new int;
}

BinVect:: ~BinVect() {
	delete[] data;
}

std::ostream& operator << (std::ostream& out, const BinVect& vec) {
	for (int i = 0; i < vec.len; i++) {
		std::cout << vec.data[i];
	}
	std::cout << "\nLenght of vector: " << vec.len << std::endl;
	return out;
}

std::istream& operator >>(std::istream& in, BinVect& vec) {
	long long int num = 0;
	std::cout << "\nInput vector: ";
	std::cin >> num;
	while (num < 0) {
		std::cout << "Incorrect input! Try again: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		num = 0;
		std::cin >> num;
	}
	while (convertation(num, vec) == -1) {
		std::cout << "Incorrect input! You can input only 1 or 0! Try again: ";
		num = 0;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> num;
	}
	return in;
}

BinVect::BinVect(BinVect& vec) {
	this->len = vec.len;
	this->data = new int[len];
	for (int i = 0; i < vec.len; i++)
		this->data[i] = vec.data[i];
}

BinVect& BinVect::operator=(const BinVect& vec) {
	if (&vec == this) {
		return *this;
	}
	delete[] data;
	this->len = vec.len;
	data = new int[this->len];
	for (int i = 0; i < this->len; i++) {
		this->data[i] = vec.data[i];
	}
	return *this;
}

int BinVect::set(int idx, int val) {
	if (idx < 0 || idx >= this->len)
		return -1;
	if (val != 0 && val != 1)
		return -2;
	data[idx] = val;
}

int BinVect::get(int idx) const {
	if (idx < 0 || idx >= this->len)
		return -1;
	return data[idx];
}

BinVect& BinVect::operator>>(int num) {
	if (num >= this->len) {
		for (int i = 0; i < this->len; i++)
			data[i] = 0;
	}
	else {
		int count = this->len - 1;
		for (int i = 0; i < num; i++) {
			data[count] = data[count - num];
			count--;
		}
		for (int i = 0; i < num; i++) {
			data[i] = 0;
		}
	}
	return *this;
}

BinVect& BinVect::operator<<(int num) {
	int count = 0;
	int i = this->len - 1;
	if (num >= this->len) {
		for (int i = 0; i < this->len; i++)
			data[i] = 0;
	}
	else {
		for (int j = num; j < this->len; j++) {
			data[count] = data[j];
			count++;
		}
		for (int j = 0; j < num; j++) {
			data[i] = 0;
			i--;
		}
	}
	return *this;
}

bool BinVect:: operator== (const BinVect& vec) const {
	return (!(*this < vec) && !(*this > vec));
}

bool BinVect::operator !=(const BinVect& vec) const {
	return !(*this == vec);
}

bool BinVect:: operator<(const BinVect& vec) const {
	int count = 0;
	if (this->len < vec.len)
		return true;
	if (this->len > vec.len)
		return false;
	for (int i = 0; i < vec.len; i++) {
		if (this->data[i] < vec.data[i])
			return true;
		if (this->data[i] > vec.data[i])
			return false;
	}
	return true;
}

bool BinVect::operator>(const BinVect& vec)const {
	return vec < *this;
}

bool BinVect::operator<=(const BinVect& vec)const {
	return !(*this > vec);
}

bool BinVect::operator>=(const BinVect& vec) const {
	return !(*this < vec);
}

BinVect BinVect::operator+(const BinVect& vec)const {
	BinVect vec1;
	int idx = 0;
	if (this->len - vec.len >= 0) {
		idx = this->len - 1;
		vec1 = *this;
		for (int j = vec.len - 1; j >= 0;

			j--) {
			vec1.data[idx] = vec.data[j] + this->data[idx];
			vec1.data[idx] %= 2;
			idx--;
		}
	}
	else if (vec.len - this->len > 0) {
		idx = vec.len - 1;
		vec1 = vec;
		for (int i = this->len - 1; i >= 0;

			i--) {
			vec1.data[idx] = vec.data[idx] + this->data[i];
			vec1.data[idx] %= 2;
			idx--;
		}
	}
	return vec1;
}

void BinVect::operator+= (const BinVect& vec) {
	int idx = 0;
	if (this->len - vec.len >= 0) {
		idx = this->len - 1;
		for (int j = vec.len - 1; j >= 0; j--) {
			this->data[idx] = vec.data[j] + this->data[idx];
			this->data[idx] %= 2;
			idx--;
		}
	}
	else if (vec.len - this->len > 0) {
		BinVect tmp;
		idx = vec.len - 1;
		tmp = vec;
		for (int i = this->len - 1; i >= 0; i--) {
			tmp.data[idx] = vec.data[idx] + this->data[i];
			tmp.data[idx] %= 2;
			idx--;
		}
		*this = tmp;
	}
}

BinVect BinVect::operator- (const BinVect& vec)const {
	BinVect vec1;
	vec1 = *this + vec;
	return vec1;
}

void BinVect::operator-= (const BinVect& vec) {
	*this += vec;
}