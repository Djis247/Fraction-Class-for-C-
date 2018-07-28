// This is a Fraction class developed to extend C++ compatibility with Fractions.
/* Copyright (C) 2018  'Julien Shishkovskiy' or 'Djis247'
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
	int m_numerator;
	int m_denominator = 1;
public:
	Fraction() : m_numerator(0) {}
	Fraction(int numerator) : m_numerator(numerator) {}
	Fraction(int numerator, int denominator)
		: m_numerator(numerator), m_denominator(denominator) {
		if(denominator == 0){ /*static_assert(false, "Error: Fraction denominator cannot be zero.\n");*/ 
		std::cerr << "Error: Fraction denominator cannot be zero.\n";
		}
		}
	static bool autoReduce;

	static int gcf(int a, int b) { return b == 0 ? a : gcf(b, a % b); }
	static int lcd(int a, int b) { return (a * b) / gcf(a, b); }

	double evaluate();
	void reduce();
	void set(int numerator, int denominator);
	int getNum() const { return m_numerator; }
	int getDen() const { return m_denominator; }

	operator double() { return evaluate(); }

	Fraction operator-() const;
	Fraction operator+() const;
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int);
	Fraction operator--(int);

	friend Fraction operator*(Fraction &f1, Fraction &f2);
	friend Fraction operator*(Fraction &f1, int &f2);
	friend Fraction operator*(int &f1, Fraction &f2);
	friend Fraction operator/(Fraction &f1, Fraction &f2);
	friend Fraction operator/(Fraction &f1, int &f2);
	friend Fraction operator/(int &f1, Fraction &f2);
	friend Fraction operator+(Fraction &f1, Fraction &f2);
	friend Fraction operator+(Fraction &f1, int &f2);
	friend Fraction operator+(int &f1, Fraction &f2);
	friend Fraction operator-(Fraction &f1, Fraction &f2);
	friend Fraction operator-(Fraction &f1, int &f2);
	friend Fraction operator-(int &f1, Fraction &f2);

	friend bool operator>(const Fraction &f1, const Fraction &f2);
	friend bool operator>(const Fraction &f1, const int &f2);
	friend bool operator>(const int &f1, const Fraction &f2);
	friend bool operator<(const Fraction &f1, const Fraction &f2);
	friend bool operator<(const Fraction &f1, const int &f2);
	friend bool operator<(const int &f1, const Fraction &f2);
	friend bool operator>=(const Fraction &f1, const Fraction &f2);
	friend bool operator>=(const Fraction &f1, const int &f2);
	friend bool operator>=(const int &f1, const Fraction &f2);
	friend bool operator<=(const Fraction &f1, const Fraction &f2);
	friend bool operator<=(const Fraction &f1, const int &f2);
	friend bool operator<=(const int &f1, const Fraction &f2);
	friend bool operator==(const Fraction &f1, const Fraction &f2);
	friend bool operator==(const Fraction &f1, const int &f2);
	friend bool operator==(const int &f1, const Fraction &f2);
	friend bool operator!=(const Fraction &f1, const Fraction &f2);
	friend bool operator!=(const Fraction &f1, const int &f2);
	friend bool operator!=(const int &f1, const Fraction &f2);

	friend std::ostream& operator<<(std::ostream &stream, Fraction &f1);
	friend std::istream& operator>>(std::istream &stream, Fraction &f1);
};
#endif