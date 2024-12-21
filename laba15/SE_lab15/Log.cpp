#include "Parm.h"
#include "Log.h"

namespace Log
{
    LOG getlog(wchar_t* logfile)
    {
        LOG temp;
        temp.stream->open(logfile);
        temp.logfile = logfile;

        if (!temp.stream)
            throw ERROR_THROW(112);

        return temp;
    }

    void WriteLine(LOG log, const char* c, ...)
    {
        const char** ptr = &c;

        while (*ptr != "")
        {
            *log.stream << *ptr;
            ptr++;
        }
    }

    void WriteLine(LOG log, const wchar_t* wc, ...)
    {
        const wchar_t** ptr = &wc;

        char temp[100];

        while (*ptr != L"")
        {
            wcstombs(temp, *ptr++, sizeof(temp));
            *log.stream << temp;
        }
    }

    void WriteLog(LOG log)
    {
        time_t rawtime;
        struct tm timeinfo;
        char buffer[100];

        time(&rawtime);
        localtime_s(&timeinfo, &rawtime);

        *log.stream << "-----��������----- " << endl;
        strftime(buffer, 100, "���������: %d.%m.%Y %A %H:%M:%S", &timeinfo);
        *log.stream << buffer << endl;
    }

    void WriteParm(LOG log, Parm::PARM parm)
    {
        char inInfo[PARM_MAX_SIZE];
        char outInfo[PARM_MAX_SIZE];
        char logInfo[PARM_MAX_SIZE];

        wcstombs(inInfo, parm.in, sizeof(inInfo));
        wcstombs(outInfo, parm.out, sizeof(outInfo));
        wcstombs(logInfo, parm.log, sizeof(logInfo));

        *log.stream << "-----���������----- " << endl;
        *log.stream << "-in:\t" << inInfo << endl;
        *log.stream << "-log:\t" << logInfo << endl;
        *log.stream << "-out:\t" << outInfo << endl;
    }

    void WriteIn(LOG log, In::IN in)
    {
        *log.stream << "-----�������� ������----- " << endl;
        *log.stream << "���������� ��������: " << in.size << endl;
        *log.stream << "���������������: " << in.ignore << endl;
        *log.stream << "���������� �����: " << in.lines << endl;
    }

    void WriteError(LOG log, Error::ERROR error)
    {
        if (error.id == 100 || error.id == 113)
        {
            std::cout << "������ " << error.id << ": " << error.message << "\n";
        }
        else
        {
            (*log.stream) << "������ " << error.id << ": " << error.message << "\n"
                << "������ " << error.inext.line << ", �������: " << error.inext.col;
        }
        log.stream->close();
    }

    void Close(LOG log)
    {
        (*log.stream).close();
    }
}
