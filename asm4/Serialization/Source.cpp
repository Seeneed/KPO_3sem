#include "stdafx.h"
#include "Serializer.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "RU");
	Serializer serializer;
	char valueChar[50];
	char literalChar[50];
	char Char;
	char charLiteral;
	cout << "Введите значение переменной char: ";
	cin.getline(valueChar, 50);
	cout << "Введите значение литерала char: ";
	cin.getline(literalChar, 50);
	Char = valueChar[0];
	charLiteral = literalChar[0];
	cout << Char << " " << charLiteral << endl;
	serializer.Serialize(Char, charLiteral);
}
