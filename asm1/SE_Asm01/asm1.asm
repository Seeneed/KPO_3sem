.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO :DWORD
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.CONST

.DATA
MB_OK EQU 0
STR1 DB "��� ������ ���������", 0
STR2 DB "������ ����!", 0
HW DD ?

.CODE

main PROC
START :
    ;INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK
    push MB_OK
    push OFFSET STR1
    push OFFSET STR2
    push HW
    call MessageBoxA

    INVOKE ExitProcess, -1
    ;push -1
    ;call ExitProcess
main ENDP

end main
