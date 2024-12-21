;Задание с выводом окна с заголовком ФИО студента/курс/группа и сообщением в окне false/true, которое указывает на наличие нулевого элемента в массиве mass
;.586
;.model flat, stdcall
;
;includelib kernel32.lib
;includelib user32.lib
;
;ExitProcess PROTO : DWORD      
;MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD
;
;.stack 4096
;
;.const
;.data
;
;str1 BYTE "Мамонько Денис Александрович 1 курс 10 группа",0
;str2 BYTE "true",0
;str3 BYTE "false",0
;
;myBytes BYTE 10h, 20h, 30h, 40h
;myWords WORD 8Ah, 3Bh, 5Fh, 99h
;myDoubles DWORD 1, 2, 3, 4, 5, 6
;myPointer DWORD myDoubles
;
;mass DWORD 1, 2, 3, 4, 0, 6, 7
;
;.code
;
;main PROC
;
;mov ESI, OFFSET myWords
;mov AX, [ESI]       
;mov BX, [ESI + 2]   
;
;mov EAX, 0           
;mov ECX, 7           
;mov ESI, 0           
;
;CYCLE:
;    add eax, mass[ESI * 4] 
;    inc ESI                
;    loop CYCLE
;
;mov ECX, 7
;mov ESI, 0             
;
;CHECKZERO:
;    cmp mass[ESI * 4], 0 
;    je HAVEZERO          
;    inc ESI              
;    loop CHECKZERO
;
;    mov EBX, 1           
;    jmp HAVENTZERO
;
;HAVEZERO:
;    mov EBX, 0           
;    INVOKE MessageBoxA, 0, OFFSET str2, OFFSET str1, 1
;    jmp ENDPROGRAM
;
;HAVENTZERO:
;    INVOKE MessageBoxA, 0, OFFSET str3, OFFSET str1, 1
;    jmp ENDPROGRAM
;
;ENDPROGRAM:
;    push 0
;    call ExitProcess
;
;main ENDP
;end main


;Дополнительное задание к 3c, где нужно было вывести сумму элементов массива mass
.586
.model flat, stdcall

includelib kernel32.lib
includelib user32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.stack 4096

.const
.data

str1 BYTE "Мамонько Денис Александрович 1 курс 10 группа", 0
sumMessage BYTE "Сумма элементов массива: ", 0

myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles

mass DWORD 1, 2, 3, 4, 5, 6, 7

.code

main PROC

mov EAX, 0
mov ECX, 7
mov ESI, 0

CYCLE:
    add eax, mass[ESI * 4]
    inc ESI
    loop CYCLE

mov EBX, EAX               
mov ESI, OFFSET sumMessage 
add ESI, 27                
mov ECX, 10                

CONVERT:
    xor EDX, EDX           
    div ECX                
    add DL, '0'            
    dec ESI                
    mov [ESI], DL          
    test EAX, EAX          
    jnz CONVERT            

add ESI, 27 - 25           
mov byte ptr [ESI], 0      

INVOKE MessageBoxA, 0, OFFSET sumMessage, OFFSET str1, 1

ENDPROGRAM:
    push 0
    call ExitProcess

main ENDP
end main




