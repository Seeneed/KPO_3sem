#include "Deserializer.h"
#include "stdafx.h"

void Deserializer::Deserialize(char* valueChar, char* literalChar)
{
    ifstream file(FILENAME, ios::binary);
    if (file.is_open())
    {
        file.read(reinterpret_cast<char*>(valueChar), sizeof(char));
        file.read(reinterpret_cast<char*>(literalChar), sizeof(char));
        file.close();
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
}
