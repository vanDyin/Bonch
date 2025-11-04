section .data
        global asm_calculate_8bit
        global asm_calculate_16bit

        extern a_8, b_8, c_8
        extern numerator_16, denominator_16, result_16

        extern a_16, b_16, c_16
        extern numerator_32, denominator_32, result_32

section .text

;(4*c - a/3 + 11) / (1+a-b)

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
        movzx ax, word [c_16]
        mov bx, 4
        mul bx
        mov ecx, eax

        movzx ax, word [a_16]
        mov bx, 3
        mov dx, 0
        div bx

        movzx eax, ax
        sub ecx, eax
        add ecx, 11
        mov [numerator_32], ecx

        ;знаменатель (знаковые вычисления)
        movzx eax, word [a_16]
        movzx ebx, word [b_16]
        add eax, 1
        sub eax, ebx
        mov [denominator_32], eax

        ;результат (знаковое деление)
        mov eax, [numerator_32]
        mov ebx, [denominator_32]
        cdq                       ; расширение знака для деления
        idiv ebx
        mov [result_32], eax
        ret
