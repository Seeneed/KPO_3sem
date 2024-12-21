.586P													
.MODEL FLAT, STDCALL									
includelib kernel32.lib									
includelib user32.lib

ExitProcess PROTO :DWORD								
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD		

.STACK 4096										

.CONST													

.DATA				
		a dd 1
		b dd 2
		str0 db "Результат программы", 0 
		str1 db "Результат сложения = < >", 0 

.CODE													

main PROC												
START :													
		mov eax, a									    
		add eax, b										
		add eax, 30h 								    
		
		mov str1+22, al									
		
		invoke MessageBoxA, 0, offset str1, offset str0, 0

		push 0											
		call ExitProcess								
main ENDP

end main