#include "Serializer.h"
#include "stdafx.h"

void Serializer::Serialize(char valueChar, char literalChar)
{
    ofstream file(FILENAME, ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&valueChar), sizeof(char));
        file.write(reinterpret_cast<const char*>(&literalChar), sizeof(char));
        file.close();
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
}
