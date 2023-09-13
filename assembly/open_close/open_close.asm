section .data
	filename db "test.txt", 0
	buffer db 128
	fd dq 0 ;파일 디스크립터 저장할 변수

section .text
	global _start

_start:
	;파일 열기
	mov rdi, filename
	mov rsi, 0 ;rsi 2는 O_RDWR
	mov rax, 2 ;sys_open 
	syscall

	;파일 디스크립터 rax에 저장
	mov [fd], rax

	;파일 읽기
	mov rdi, [fd]
	mov rsi, buffer
	mov rdx, 39
	mov rax, 0
	syscall

	;출력
	mov rdi,1
	mov rax,1
	syscall

	;파일 닫기
	mov rdi, [fd] 
	mov rax, 3 ;sys_close
	syscall

	mov rax, 60
	xor rdi, rdi ;반환값 0으로 초기화
	syscall

