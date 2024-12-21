#include "stdafx.h"
#include "AsmGeneration.h"
#include "Deserializer.h"

void main()
{
    setlocale(LC_ALL, "RU");
    char valueChar;
    char literalChar;
    Deserializer deserializer;
    deserializer.Deserialize(&valueChar, &literalChar);
    cout << valueChar << " " << literalChar << endl;

    AsmGeneration AG;
    const char* asmFilePath = "../SE_Asm04/asmFile.asm";
    AG.CreateFile(valueChar, literalChar, asmFilePath);
}
