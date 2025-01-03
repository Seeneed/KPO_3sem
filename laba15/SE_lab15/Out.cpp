#include "stdafx.h"
#include "Out.h"

namespace Out {

    OUT getout(wchar_t outfile[]) {
        OUT out;
        out.stream = new std::ofstream;
        out.stream->open(outfile);
        if (!out.stream->is_open()) { throw ERROR_THROW(113); }
        wcscpy_s(out.outfile, outfile);
        return out;
    }
    void WriteToFile(OUT out, In::IN in) {
        *out.stream << in.text;
    }
    void Out::WriteToError(OUT out, Error::ERROR error) {
        if (out.stream && out.stream->is_open()) {
            *out.stream << "������ " << error.id << ": " << error.message << std::endl;
            if (error.inext.line != -1) {
                *out.stream << "������: " << error.inext.line << " �������: " << error.inext.col << std::endl << std::endl;
            }
        }
        else {
            cout << "�� ������� ������� ����" << endl;
        }
    }

    void CloseFile(OUT out) {
        out.stream->close();
        delete out.stream;
    }
}
