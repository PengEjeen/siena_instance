section .data
	msg db "test", 10

section .text
	global _start

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 5 
	mov r10, 1

again
	cmp r10, 10
	je done
	syscall

	mov rax, 1
	inc r10
	jmp again

done:
	mov rax, 60
	mov rdi, 0
	syscall
	
