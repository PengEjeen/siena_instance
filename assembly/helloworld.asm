section .data
	text db  "한글 테스트!", 10

section .text
	global _start

_start:
	call _printHello
	
	mov rax, 60
	mov rdi, 0
	syscall

_printHello:
	mov rax,1
	mov rdi,1
	mov rsi, text
	mov rdx, 18
	syscall
