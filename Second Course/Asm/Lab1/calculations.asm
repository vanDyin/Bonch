section .data
        global asm_calculate_8bit
        global asm_calculate_16bit

        extern a_8, b_8, c_8
        extern numerator_16, denominator_16, result_16

        extern a_16, b_16, c_16
        extern numerator_32, denominator_32, result_32

section .text

asm_calculate_8bit:
        ;числитель

        mov al, [c_8]
        mov bl, 4
        imul bl                 ;вернул ax

        mov cx, ax

        mov al, [a_8]
        cbw                     ;convert byte to word (до _16 байт)
        mov bl, 3
        idiv bl                 ;возвращает al и ah (ax/bl)

        movsx bx, al

        sub cx, bx
        add cx, 11

        mov [numerator_16], cx

        ;знаменатель
        mov al, 1
        add al, [a_8]
        sub al, [b_8]
        cbw
        mov [denominator_16], ax

        ;результат

        mov ax, [numerator_16]
        mov bx, [denominator_16]
        mov dx, 0
        div bx
        mov [result_16], ax

        ret

asm_calculate_16bit:
        ;числитель
        movzx eax, word [c_16]
        mov ebx, 4
        mul ebx
        mov ecx, eax

        ;Если операнд _16-разрядный, то инструкция div делит
        ;_32-разрядное число в EDX:EAX на операнд, помещая частное в EAX, а остаток в EDX.

	movzx eax, word [a_16]
        mov ebx, 3
        mov edx, 0       ;EDX = 0 чтобы очистить EDX от мусора и EDX:EAX была чистой
        div ebx

        sub ecx, eax
        add ecx, 11
        mov [numerator_32], ecx

        ;знаменатель
        movzx eax, word [a_16]
	movzx ebx, word [b_16]
        add eax, 1
        sub eax, ebx
        mov [denominator_32], eax

        ;результат
        mov eax, [numerator_32]
        mov ebx, [denominator_32]
        mov edx, 0
        div ebx
        mov [result_32], eax
        ret
