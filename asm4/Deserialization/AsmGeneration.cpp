#include "AsmGeneration.h"
#include "stdafx.h"
#include <string>

string Join(const string& str);

void AsmGeneration::CreateFile(char valueChar, char literalChar, const char* outputFilePath)
{
    ofstream file(outputFilePath);
    if (file.is_open())
    {
        file << ".586" << endl;
        file << ".MODEL FLAT, STDCALL" << endl;
        file << "includelib kernel32.lib" << endl;
        file << "ExitProcess PROTO : DWORD" << endl;
        file << "MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD" << endl;
        file << ".STACK 4096" << endl;
        file << ".CONST" << endl;
        file << ".DATA" << endl;
        file << "OK EQU 0" << endl;
        file << "TEXT_MESSAGE DB \"SE_Asm04\", 0" << endl;
        file << "HW DD ?" << endl;

        file << "CHARSTR DB \"char: " << valueChar << "\", 0" << endl;
        file << "CHARLITERALSTR DB \"charliteral: " << literalChar << "\", 0" << endl;

        file << ".CODE" << endl;
        file << "main PROC" << endl;

        file << "INVOKE MessageBoxA, 0, OFFSET CHARSTR, OFFSET TEXT_MESSAGE, OK" << endl;
        file << "INVOKE MessageBoxA, 0, OFFSET CHARLITERALSTR, OFFSET TEXT_MESSAGE, OK" << endl;

        file << "push 0" << endl;
        file << "call ExitProcess" << endl;

        file << "main ENDP" << endl;
        file << "END main" << endl;

        file.close();
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
}

string Join(const string& str)
{
    string newStr = "";
    for (size_t i = 0; i < str.size(); i++) {
        newStr += str[i];
        if (i + 1 != str.size()) {
            newStr += ", ";
        }
    }
    return newStr;
}
