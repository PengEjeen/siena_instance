%macro write_str 2 ;메크로 선언 (이름) (매개변수)
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

section .data
	msg1 db "this is msg1!", 10
	len1 equ $ - msg1 
	;$현재 메모리 주소 msg1메모리 주소를 빼 문자열 길이 구함
	
	msg2 db "this is msg2!",10
	len2 equ $ - msg2

	msg3 db "this is msg3!"
	len3 equ $ - msg3

section .text
	global _start

_start:
	write_str msg1, len1
	write_str msg2, len2
	write_str msg3, len3

	mov rax, 60
	syscall
