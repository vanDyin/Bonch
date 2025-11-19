section .text
        global asm_unsign

        extern a_unsign, b_unsign
        extern result_unsign

asm_unsign:
	mov ax, [a_unsign]
	mov bx, [b_unsign]
	cmp ax, bx

	ja greater		;jg для unsigned
	je equal
	jb less			;gl для unsigned

greater:
	mov ax, -127
	jmp get_result

equal:
	mov dx, 0
	div bx
	sub ax, 2
	jmp get_result

less:
	mov dx, 0
	div bx
	add ax, 11
	jmp get_result

get_result:
	mov [result_unsign], ax
	ret
