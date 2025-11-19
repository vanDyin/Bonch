section .text
	global asm_sign

	extern a_sign, b_sign
	extern result_sign
asm_sign:
	mov ax, [a_sign]
	mov bx, [b_sign]

	cmp ax, bx

	jg greater		;jump greater (если больше, то на метку greater)
	je equal		;jump equal (если равно)
	jl less			;jump less (если меньше)

greater:
	mov ax, -127
	jmp get_result

equal:
	cwd
	idiv bx
	sub ax, 2
	jmp get_result

less:
	cwd
	idiv bx
	add ax, 11
	jmp get_result

get_result:
	mov [result_sign], ax
	ret
