section .text
	global _start

_start:
	sub rsp, 100
	
	mov rax, 0
	mov rdi, 0
	mov rsi, rsp
	mov rdx, 99
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, rsp
	mov rdx, 99
	syscall

	mov rax, 60
	syscall
