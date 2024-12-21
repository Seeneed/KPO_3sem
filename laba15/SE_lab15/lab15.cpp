#include"stdafx.h"

#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "Out.h"

int _tmain(int argc, _TCHAR* argv[]) {

    setlocale(LC_ALL, "rus");

    std::cout << "---- ���� Parm::getparm ---" << std::endl << std::endl;
    try {
        Parm::PARM parm = Parm::getparm(argc, argv);

        wcout << "-in: " << parm.in << ", -out: " << parm.out << ", -log: " << parm.log << endl << endl;
    }
    catch (Error::ERROR e) {
        cout << "������ " << e.id << ":" << e.message << endl << endl;
    };

    std::cout << "---- ���� In::getin ---" << std::endl << std::endl;
    try {
        Parm::PARM parm = Parm::getparm(argc, argv);
        In::IN in = In::getin(parm.in);
        cout << in.text << endl;
        cout << "����� ��������: " << in.size << endl;
        cout << "����� �����: " << in.lines << endl;
        cout << "���������: " << in.ignore << endl;
    }
    catch (Error::ERROR e) {
        cout << "������ " << e.id << ":" << e.message << endl;
    }

    Log::LOG log;
    Out::OUT out = {};

    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);

        log = Log::getlog(parm.log);
        Log::WriteLine(log, (char*)"����:", (char*)" ��� ������\n", "");
        Log::WriteLine(log, (char*)"����:", (char*)" ��� ������\n", "");

        std::cout << "---- �������� ��������� ����� ---" << std::endl << std::endl;
        out = Out::getout(parm.out);

        Log::WriteParm(log, parm);

        In::IN in = In::getin(parm.in);
        Log::WriteIn(log, in);

        bool hasErrors = false;
        int currentLine = 0;

        for (int i = 0; i < in.size; ++i) {
            unsigned char symbol = in.text[i];
            if (symbol == '\n') {
                currentLine++;
            }
            if (in.code[symbol] == In::IN::F) {
                hasErrors = true;
                Error::ERROR symbolError = {
                    201,
                    "������������ ������",
                    { currentLine, i + 1 }
                };

                Log::WriteError(log, symbolError);

                Out::WriteToError(out, symbolError);
            }
            else if (in.code[symbol] == In::IN::I) {
                in.ignore++;
            }
        }

        if (!hasErrors) {
            Out::WriteToFile(out, in);
        }
        else {
            std::cout << "���������� ������, ������ �� ��������.\n";
            Log::WriteLine(log, (char*)"���������� ������, ������ �� ��������", "", "");
        }

        Out::CloseFile(out);
        Log::WriteLine(log, (char*)"������ ������� �������� � �������� ����", "", "");
        Log::Close(log);
        std::cout << "������ �������� � ����: " << parm.out << std::endl;
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);

        if (out.stream && out.stream->is_open()) {
            Out::WriteToError(out, e);
            Out::CloseFile(out);
        }
        Log::Close(log);
    }

    system("pause");
    return 0;
}
