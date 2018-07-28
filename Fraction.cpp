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
#include "stdafx.h"
#include <iostream>


#include "Fraction.h"

bool Fraction::autoReduce = true;
double Fraction::evaluate() {
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}
void Fraction::reduce() {
	int gcf = Fraction::gcf(m_numerator, m_denominator);
	m_numerator /= gcf;
	m_denominator /= gcf;
}
void Fraction::set(int numerator, int denominator) {
	m_numerator = numerator;
	m_denominator = denominator;
}

Fraction Fraction::operator-() const {
	if (m_numerator > 0 && m_denominator > 0) {
		return Fraction(-m_numerator, m_denominator);
	}
	else if (m_numerator < 0 && m_denominator < 0) {
		return Fraction(-m_numerator, -m_denominator);
	}
	else if (m_numerator < 0 && m_denominator > 0) {
		return Fraction(-m_numerator, m_denominator);
	}
	else if (m_numerator > 0 && m_denominator < 0) {
		return Fraction(m_numerator, -m_denominator);
	}
}
Fraction Fraction::operator+() const {
	return Fraction(+m_numerator, +m_denominator);
}
Fraction& Fraction::operator++() {
	++m_numerator;
	return *this;
}
Fraction& Fraction::operator--() {
	--m_numerator;
	return *this;
}
Fraction Fraction::operator++(int) {
	Fraction temp(m_numerator, m_denominator);
	++m_numerator;
	return temp;
}
Fraction Fraction::operator--(int) {
	Fraction temp(m_numerator, m_denominator);
	--m_numerator;
	return temp;
}

Fraction operator*(Fraction &f1, Fraction &f2) {
	Fraction f((f1.m_numerator * f2.m_numerator), (f1.m_denominator * f2.m_denominator));
	if (Fraction::autoReduce == true) { f.reduce(); }
	return f;
}
Fraction operator*(Fraction &f1, int &f2) {
	Fraction f((f1.m_numerator * f2), f1.m_denominator);
	if (Fraction::autoReduce == true) { f.reduce(); }
	return f;
}
Fraction operator*(int &f1, Fraction &f2) {
	Fraction f((f2.m_numerator * f1), f2.m_denominator);
	if (Fraction::autoReduce == true) { f.reduce(); }
	return f;
}
Fraction operator/(Fraction &f1, Fraction &f2) {
	Fraction f((f1.m_numerator * f2.m_denominator), (f2.m_numerator * f1.m_denominator));
	if (Fraction::autoReduce == true) { f.reduce(); }
	return f;
}
Fraction operator/(Fraction &f1, int &f2) {
	Fraction f(f1.m_numerator, (f1.m_denominator * f2));
	if (Fraction::autoReduce == true) { f.reduce(); }
	return f;
}
Fraction operator/(int &f1, Fraction &f2) {
	Fraction f((f2.m_denominator * f1), f2.m_numerator);
	if (Fraction::autoReduce == true) { f.reduce(); }
	return f;
}
Fraction operator+(Fraction &f1, Fraction &f2) {
	if (f1.m_numerator == f1.m_denominator) {
		Fraction f(f2.m_denominator + f2.m_numerator, f2.m_denominator);
		if (Fraction::autoReduce == true) { f.reduce(); }
		return f;
	}
	else if (f2.m_numerator == f2.m_denominator) {
		Fraction f(f1.m_denominator + f1.m_numerator, f1.m_denominator);
		if (Fraction::autoReduce == true) { f.reduce(); }
		return f;
	}
	else if (f1.m_denominator == f2.m_denominator) {
		Fraction f(f1.m_numerator + f2.m_numerator, f1.m_denominator);
		if (Fraction::autoReduce == true) { f.reduce(); }
		return f;
	}
	else {
		int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
		Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
		Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
		Fraction f5(f3 + f4);
		if (Fraction::autoReduce == true) { f5.reduce(); }
		return f5;
	}
}
Fraction operator+(Fraction &f1, int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	Fraction f5(f1 + f4);
	if (Fraction::autoReduce == true) { f5.reduce(); }
	return f5;
}
Fraction operator+(int &f1, Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	Fraction f5(f3 + f2);
	if (Fraction::autoReduce == true) { f5.reduce(); }
	return f5;
}
Fraction operator-(Fraction &f1, Fraction &f2) {
	if (f1.m_numerator == f1.m_denominator) {
		Fraction f(f2.m_numerator - f2.m_denominator, f2.m_denominator);
		if (Fraction::autoReduce == true) { f.reduce(); }
		return f;
	}
	else if (f2.m_numerator == f2.m_denominator) {
		Fraction f(f1.m_numerator - f1.m_denominator, f1.m_denominator);
		if (Fraction::autoReduce == true) { f.reduce(); }
		return f;
	}
	else if (f1.m_denominator == f2.m_denominator) {
		Fraction f(f1.m_numerator - f2.m_numerator, f1.m_denominator);
		if (Fraction::autoReduce == true) { f.reduce(); }
		return f;
	}
	else {
		int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
		Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
		Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
		Fraction f5(f3 - f4);
		if (Fraction::autoReduce == true) { f5.reduce(); }
		return f5;
	}
}
Fraction operator-(Fraction &f1, int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	Fraction f5(f1 - f4);
	if (Fraction::autoReduce == true) { f5.reduce(); }
	return f5;
}
Fraction operator-(int &f1, Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	Fraction f5(f3 - f2);
	if (Fraction::autoReduce == true) { f5.reduce(); }
	return f5;
}

bool operator>(const Fraction &f1, const Fraction &f2) {
	int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
	Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
	Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
	return f3.m_numerator > f4.m_numerator;
}
bool operator>(const Fraction &f1,const int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	return f1.m_numerator > f4.m_numerator;
}
bool operator>(const int &f1, const Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	return f3.m_numerator > f2.m_numerator;
}
bool operator<(const Fraction &f1, const Fraction &f2) {
	int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
	Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
	Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
	return f3.m_numerator < f4.m_numerator;
}
bool operator<(const Fraction &f1, const int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	return f1.m_numerator < f4.m_numerator;
}
bool operator<(const int &f1, const Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	return f3.m_numerator < f2.m_numerator;
}
bool operator>=(const Fraction &f1, const Fraction &f2) {
	int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
	Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
	Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
	return f3.m_numerator >= f4.m_numerator;
}
bool operator>=(const Fraction &f1, const int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	return f1.m_numerator >= f4.m_numerator;
}
bool operator>=(const int &f1, const Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	return f3.m_numerator >= f2.m_numerator;
}
bool operator<=(const Fraction &f1, const Fraction &f2) {
	int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
	Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
	Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
	return f3.m_numerator <= f4.m_numerator;
}
bool operator<=(const Fraction &f1, const int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	return f1.m_numerator <= f4.m_numerator;
}
bool operator<=(const int &f1, const Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	return f3.m_numerator <= f2.m_numerator;
}
bool operator==(const Fraction &f1, const Fraction &f2) {
	int lcd = Fraction::lcd(f1.m_denominator, f2.m_denominator);
	Fraction f3(f1.m_numerator * (lcd / f1.m_denominator), f1.m_denominator * (lcd / f1.m_denominator));
	Fraction f4(f2.m_numerator * (lcd / f2.m_denominator), f2.m_denominator * (lcd / f2.m_denominator));
	return f3.m_numerator == f4.m_numerator;
}
bool operator==(const Fraction &f1, const int &f2) {
	int lcd = f1.m_denominator;
	Fraction f4(f2 * lcd, lcd);
	return f1.m_numerator == f4.m_numerator;
}
bool operator==(const int &f1, const Fraction &f2) {
	int lcd = f2.m_denominator;
	Fraction f3(f1 * lcd, lcd);
	return f3.m_numerator == f2.m_numerator;
}
bool operator!=(const Fraction &f1, const Fraction &f2) {
	return !(f1 == f2);
}
bool operator!=(const Fraction &f1, const int &f2) {
	return !(f1 == f2);
}
bool operator!=(const int &f1, const Fraction &f2) {
	return !(f1 == f2);
}

std::ostream& operator<<(std::ostream &stream, Fraction &f1) {
	stream << f1.m_numerator << "/" << f1.m_denominator;
	return stream;
}
std::istream& operator>>(std::istream &stream, Fraction &f1) {
	stream >> f1.m_numerator;
	stream.ignore(1, '/');
	stream >> f1.m_denominator;
	return stream;
}