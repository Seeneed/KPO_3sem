#include "FST.h"
#include <tchar.h>
#include <locale.h>
#include <iostream>

int _tmain(int argc, TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");

    char str1[] = "affg";
    char str2[] = "afbefg";
    char str3[] = "afcdefg";
    char str4[] = "afffcddeffg";
    char str5[] = "afbefffg";
    char str6[] = "affcddddeffffg";
    char str7[] = "affbefg";
    char str8[] = "aff";    
    char str9[] = "agcde"; 

    char* chains[] = { str1, str2, str3, str4, str5, str6, str7, str8, str9 };

    for (int i = 0; i < sizeof(chains) / sizeof(char*); i++)
    {
        FST::FST fst(chains[i], 9,
            FST::NODE(1, FST::RELATION('a', 1)), 
            FST::NODE(2, FST::RELATION('f', 2), FST::RELATION('f', 7)), 
            FST::NODE(3, FST::RELATION('f', 2), FST::RELATION('b', 5), FST::RELATION('c', 3)), 
            FST::NODE(1, FST::RELATION('d', 4)), 
            FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('e', 6)),
            FST::NODE(1, FST::RELATION('e', 6)),
            FST::NODE(3, FST::RELATION('b', 5), FST::RELATION('c', 3), FST::RELATION('f', 7)),
            FST::NODE(2, FST::RELATION('f', 7), FST::RELATION('g', 8)),
            FST::NODE() 
        );

        bool result = FST::execute(fst);
        std::cout << "Цепочка " << fst.string << " результат выполнения: " << result << std::endl;

        if (result)
            std::cout << "Цепочка " << fst.string << " распознана" << std::endl;
        else
            std::cout << "Цепочка " << fst.string << " не распознана" << std::endl;
    }
    system("pause");
    return 0;
}
