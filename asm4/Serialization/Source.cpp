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
	cout << "������� �������� ���������� char: ";
	cin.getline(valueChar, 50);
	cout << "������� �������� �������� char: ";
	cin.getline(literalChar, 50);
	Char = valueChar[0];
	charLiteral = literalChar[0];
	cout << Char << " " << charLiteral << endl;
	serializer.Serialize(Char, charLiteral);
}
