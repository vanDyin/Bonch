section .data
        global input_signed_number, input_unsigned_number
        global print_signed_number, print_unsigned_number
        global print_string, print_newline

        ; Символ новой строки
        newline_str db 10, 0

section .bss
        input_buffer resb 16            ; Буфер для ввода строки
        output_buffer resb 6            ; Буфер для вывода числа (5 цифр + нуль-терминатор)
        output_buffer_sign resb 7       ; Буфер для вывода знаково числа (5 цифр + нуль-терминатор + знак)

section .text

;-----------------------------------------------------------
; print_string - выводит строку
; Вход: esi = указатель на строку
print_string:
        push eax
        push ebx
        push ecx
        push edx
        push esi

        mov ecx, esi    ; Указатель на строку для sys_write
        mov eax, 4      ; sys_write
        mov ebx, 1      ; stdout

        ; Вычисляем длину строки
        mov edx, 0      ; Счетчик длины
.length_loop:
        cmp byte [esi + edx], 0
        je .final_print
        inc edx
        jmp .length_loop

.final_print:
        int 0x80        ; Вызов системы syscall

        pop esi
        pop edx
        pop ecx
        pop ebx
        pop eax
        ret

;-----------------------------------------------------------
;print_newline - выводит перевод строки
print_newline:
        push esi
        mov esi, newline_str
        call print_string
        pop esi
        ret

-----------------------------------------------------------
; Функция для ввода беззнакового числа
; Выход: ax = число (0-65535)
; CF = 0 если успех, CF = 1 если ошибка
input_unsigned_number:
        push esi                ; Сохраняем регистры
        push edi
        push ebx
        push ecx
        push edx

        ; Читаем строку с stdin
        mov eax, 3              ; sys_read
        mov ebx, 0              ; stdin
        mov ecx, input_buffer   ; буфер для ввода
        mov edx, 15             ; максимальная длина (15 символов + нуль-терминатор)
        int 0x80

        mov esi, input_buffer   ; ESI = указатель на начало строки
        xor edx, edx            ; EDX = 0 (здесь будет накапливаться число)
        xor ecx, ecx            ; ECX = 0 (счетчик позиции в строке)
        xor ebx, ebx            ; EBX = 0 (для текущего символа)

.convert_loop:
        mov bl, byte [esi + ecx]; текущий символ

        cmp bl, 10              ; LF (Line feed - перевод строки)
        je .done
        cmp bl, 13              ; CR (Carriage Return - в начало строки)
        je .done
        cmp bl, 0               ; нуль-терминатор
        je .done

        cmp bl, '0'
        jb .error               ; если первое меньше '0' - ошибка
        cmp bl, '9'
        ja .error               ; если первое больше '9' - ошибка

        sub bl, '0'

        ; Пользователь ввел 5
        ;BL = 53 (ASCII код '5')
        ;sub bl, '0' -> 53 - 48 = 5
        ;BL = 5 (теперь это ЧИСЛО 5, а не символ)

        mov eax, edx            ; копируем текущий результат
        mov edi, 10
        mul edi                 ; EAX = EAX * 10
        jc .error               ; Проверяем не было ли переполнения

        mov edx, eax            ; возвращаем результат в EDX

        add dl, bl              ; добавляем новую цифру с итерации
        jc .error

inc ecx                 ; следующий символ
cmp ecx, 5              ; максимум 5 цифр (65535)
jae .error              ; если слишком длинное число - ошибка
jmp .convert_loop

.done:
; Проверяем что ввели хотя бы одну цифру
cmp ecx, 0
je .error               ; если нет цифр - ошибка

; Проверяем что число не превышает 65535
cmp edx, 65535
ja .error               ; если больше 65535 - ошибка


; Успех - очищаем флаг переноса
mov ax, dx
clc
pop edx                 ; Восстанавливаем регистры в обратном порядке
pop ecx
pop ebx
pop edi
pop esi
ret

.error:
; Ошибка - устанавливаем флаг переноса
stc

pop edx                 ; Восстанавливаем регистры в обратном порядке
pop ecx
pop ebx
pop edi
pop esi
ret


;-----------------------------------------------------------
; Функция для вывода беззнакового числа
; Вход: AX = число для вывода
print_unsigned_number:
push esi
push ecx
push edx
push ebx

mov esi, output_buffer + 5      ; ESI указывает на КОНЕЦ буфера
mov byte [esi], 0               ; 0-терминатор в конец строки
mov cx, ax                      ; копируем число в cx (чтобы сохранить оригинальное число)
mov ebx, 10                     ; делитель

    .digit_loop:
            dec esi                 ; смещает указатель буфера
            mov ax, cx
            xor dx, dx              ; DX = 0
            div bx                  ; Делим DX:AX на BX

            add dl, '0'             ; DL = DL + 48 (символ в таблице)
            mov [esi], dl           ; Записываем DL в буфер
            mov cx, ax              ; Новое число для обработки
            test cx, cx             ; Проверяем CX != 0
            jnz .digit_loop         ; Если флаг нуля не установлен, то снова

            mov eax, 4                      ; sys_write
            mov ebx, 1                      ; stdout
            mov ecx, esi                    ; ECX = адрес начала строки
            mov edx, output_buffer + 5      ; EDX = адрес конца буфера
            sub edx, esi                    ; EDX = длина строки
            int 0x80

            pop ebx
            pop edx
            pop ecx
            pop esi
            ret

    ;-----------------------------------------------------------
    ; Функция для ввода знакового числа
    ; Выход: AX = число (-32768..32767)
    input_signed_number:

            push esi
            push edi
            push ebx
            push ecx
            push edx

            ; Читаем строку с stdin
            mov eax, 3              ; sys_read
            mov ebx, 0              ; stdin
            mov ecx, input_buffer
            mov edx, 15
            int 0x80

            ; Преобразуем строку в число
            mov esi, input_buffer
            xor edx, edx            ; EDX будет накапливать число
            xor ecx, ecx            ; ECX = счетчик позиции
            xor ebx, ebx            ; EBX = для текущего символа
            xor edi, edi            ; EDI = флаг знака (0 = +, 1 = -)
