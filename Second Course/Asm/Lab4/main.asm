section .data
	; Сообщения
	msg_usage db 'Используется ./lab4 <filename>', 0x0A, 0
	msg_enter_c db 'Введите C для выражения С <= a[i] <= D: ', 0
	msg_enter_d db 'Введите D для выражения С <= a[i] <= D: ', 0
	msg_error_file db 'Ошибка! Не удалось открыть файл', 0x0A, 0
	msg_input_error db 'Ошибка ввода! Введите число от -32768 до 32767', 0x0A, 0
	msg_error_read db 'Ошибка! Не удалось прочитать данные из файла', 0x0A, 0
	msg_parse_error db 'Ошибка: некорректный формат данных в файле', 0x0A, 0
	msg_range_input db 'Числа C и D должны быть в диапазоне от -32768 до 32767', 0x0A, 0
	msg_result db 'Результат: ', 0
	msg_newline db 0x0A, 0
	debug_parsed db 'Распарсено элементов: ', 0


	; Переменные
	c_value dw 0		; 2 байта
	d_value dw 0		; 2 байта
	array_size dd 0		; 4 байта
	result_count dd 0	; 4 байта

section .bss
	; Буферы
	file_buffer resb 2000	; 2000 байт
	array resw 1000		; 2000 байт (1000 * 2)
	input_buffer resb 16	; 16 байт
	file_buffer_len resd 1	; 4 байта для хранения реального размера файла

section .text
	global _start

_start:
	; 1. Проверка аргументов командной строки
	call check_arguments
	jc .exit		; если ошибка

	; 2. Чиение файла
	call read_file
	jc .exit		; если ошибка

	; 3. Парсим числа из файла в массив
	mov esi, file_buffer
	mov edi, 0		; индекс в массиве

.parse_loop:
	call parse_signed_number
	jc .check_if_end	; если конец или ошибка

	mov [array + edi*2], ax	; сохранение числа 2 байта
	inc edi
	mov [array_size], edi	; обновление размера массива
	jmp .parse_loop

.check_if_end:
	mov eax, [file_buffer_len]
	mov ebx, file_buffer
	add ebx, eax
	cmp esi, ebx
	jae .parse_done

	mov esi, msg_parse_error
	call print_string
	jmp .exit

.parse_done:
	mov esi, debug_parsed
	call print_string
	mov eax, edi
	call print_number
	mov esi, msg_newline
	call print_string

	; 4. Ввод C и D с консоли

	mov esi, msg_range_input
	call print_string

.input_c:
	; Ввод C
	mov esi, msg_enter_c
	call print_string
	call input_signed_number
	jc .input_error
	mov [c_value], ax

.input_d:
	; Ввод D
	mov esi, msg_enter_d
	call print_string
	call input_signed_number
	jc .input_error
	mov [d_value], ax

	; 5. Обработка массива
	call process_array

	; 6. Выводим результат
	mov esi, msg_result
	call print_string
	mov eax, [result_count]
	call print_number

	; Перевод строки
	mov esi, msg_newline
	call print_string
	jmp .exit

.input_error:
	mov esi, msg_input_error
	call print_string

.exit:
	mov eax, 1		; sys_exit
	mov ebx, 0
	int 0x80

;-----------------------------------------------------------
; Чтение файла в буфер
; Вход: EBX = указатель на имя файла
; Выход: CF=1 если ошибка
read_file:
	push eax
	push ebx
	push ecx
	push edx

	; Открытие файла
	mov eax, 5		; sys_open
	mov ecx, 0		; read only
	int 0x80

	cmp eax, 0
	jl .error_open

	mov edx, eax		; сохраняет файловый дескриптор

	; Чтение файла
	mov eax, 3		; sys_read
	mov ebx, edx		; file descriptor
	mov ecx, file_buffer	; буфре для данных
	mov edx, 2000		; макс. размер
	int 0x80

	cmp eax, 0
	jl .error_read

	; Сохраняем размер прочитанных данных
	mov [file_buffer_len], eax

	; Закрытие файла
	mov eax, 6		; sys_close
	mov ebx, edx		; file descriptor
	int 0x80

	clc
	jmp .exit

.error_open:
	mov esi, msg_error_file
	call print_string
	stc
	jmp .exit

.error_read:
	mov esi, msg_error_read
	call print_string
	stc

.exit:
	pop edx
	pop ecx
	pop ebx
	pop eax
	ret

;-----------------------------------------------------------
; Функция для ввода C и D
; Выход: AX = число (-32768..32767)
input_signed_number:

	push esi
	push edi
	push ebx
	push ecx
	push edx

	; Читаем строку с stdin
	mov eax, 3		; sys_read
	mov ebx, 0		; stdin
	mov ecx, input_buffer
	mov edx, 15
	int 0x80

	; Преобразуем строку в число
	mov esi, input_buffer
	xor edx, edx		; EDX будет накапливать число
	xor ecx, ecx		; ECX = счетчик позиции
	xor ebx, ebx		; EBX = для текущего символа
	xor edi, edi		; EDI = флаг знака (0 = +, 1 = -)

	mov bl, byte [esi]
	cmp bl, '-'		; если первый символ минус
	jne .check_plus		; если BL не '-' то переходит
	mov edi, 1		; устанавливаем флаг отрицательности
	inc ecx			; пропускаем символ минуса
	jmp .convert_loop

.check_plus:
	cmp bl, '+'		; если первый символ плюс
	jne .convert_loop
	inc ecx			; пропускаем символ плюса

.convert_loop:
	mov bl, byte [esi + ecx]	; текущий символ

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

	mov eax, edx
	cmp eax, 3276
	ja .error

	mov edx, 10
	imul edx
	jo .error		; если переполнен

	mov edx, eax

	movsx eax, bl
	add edx, eax
	jo .error

	inc ecx
	cmp ecx, 7
	jae .error		; если exc больше чем 6, то переход
	jmp .convert_loop

.done:
	; Проверяем что ввели хотя бы одну цифру
	cmp ecx, edi		; если только знак без цифр (ECX == EDI)
	je .error

	test edi, edi		; проверка флага отрицательности
	jz .check_positive	; если флаг 0 установлен, то переход

	; Проверяем диапазон для 16-битного знакового числа
	cmp edx, 32768
	ja .error
	neg edx
	cmp edx, -32768
	jl .error
	jmp .get_result

.check_positive:

	cmp edx, 32767
	jg .error

.get_result:

	mov ax, dx
	clc

	pop edx
	pop ecx
	pop ebx
	pop edi
	pop esi
	ret

.error:
	stc
        pop edx
        pop ecx
        pop ebx
        pop edi
        pop esi
        ret


;-----------------------------------------------------------
; Функция для преобразования строки в знаковое число из буфера
; Вход - ESI
; Выход - AX (число), ESI - указатель на следущий символ, CF = 1 (если ошибка)
parse_signed_number:
	push ebx
	push ecx
	push edx
	push edi

	xor edx, edx
	xor ecx, ecx
	xor edi, edi

.skip_spaces:
	mov bl, byte [esi]
	cmp bl, ' '
	je .next_char
	cmp bl, 9		; tab
	je .next_char
	cmp bl, ','
	je .next_char
	cmp bl, 0x0A
	je .next_char
	cmp bl, 0x0D
	je .next_char
	jmp .check_sign

.next_char:
	inc esi
	jmp .skip_spaces

.check_sign:
	mov bl, byte [esi]
	cmp bl, '-'
	jne .check_plus
	mov edi, 1		; отрицательное
	inc esi
	jmp .convert_loop

.check_plus:
	cmp bl, '+'
	jne .convert_loop
	inc esi

.convert_loop:
	mov bl, byte [esi]
	cmp bl, ' '
	je .done
	cmp bl, ','
	je .done
	cmp bl, 0x0A
	je .done
	cmp bl, 0x0D
	je .done
	cmp bl, 0
	je .done

	cmp bl, '0'
	jb .error
	cmp bl, '9'
	ja .error

	sub bl, '0'		; преобразуем в цифру
	mov eax, edx
	mov edx, 10
	imul edx		; EAX = число * 10
	jo .error

	mov edx, eax
	movsx eax, bl
	add edx, eax
	jo .error

	inc esi
	inc ecx
	cmp ecx, 6
	jae .error
	jmp .convert_loop

.done:
	cmp ecx, 0		; проверка что есть хотя бы 1 цифра
	je .error

	test edi, edi 		; проверка знака
	jz .positive

	; Отрицательное число
	cmp edx, 32768
	ja .error
	neg edx
	jmp .store_result

.positive:
	cmp edx, 32767
	ja .error

.store_result:
	mov ax, dx
	clc
	jmp .exit

.error:
	stc

.exit:
	pop edi
	pop edx
	pop ecx
	pop ebx
	ret

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
; Вывод числа (без знака, для result_count)
; Вход: EAX = число для вывода
print_number:
	push eax
	push ebx
	push ecx
	push edx
	push esi

	mov esi, input_buffer + 15
	mov byte [esi], 0
	mov ebx, 10

.convert_loop:
	dec esi
	xor edx, edx
	div ebx			; EAX = частное, EDX = остаток
	add dl, '0'		; преобразуем цифру в символ
	mov [esi], dl		; сохраняем символ


	test eax, eax		; проверяем, осталось ли число
	jnz .convert_loop

	; Выводим строку
	mov ecx, esi		; указатель на начало числа
	mov edx, input_buffer + 16	; конец буфера
	sub edx, esi		; длина

	mov eax, 4		; sys_write
	mov ebx, 1		; stdout
	int 0x80		; syscall

	pop esi
	pop edx
	pop ecx
	pop ebx
	pop eax
	ret

;-----------------------------------------------------------
; Проверка аргументов командной строки
; Выход: EBX = указатель на имя файла, CF=1 если ошибка
check_arguments:
	mov ecx, [esp + 4]
	mov eax, [esp + 8]

	cmp ecx, 2
	jl .error		; если argc < 2

	mov ebx, [esp + 12]
	clc
	ret

.error:
	mov esi, msg_usage
	call print_string
	stc
	ret


;-----------------------------------------------------------
; Обработка массива (вариант 21)
; Найти сколько положительных элементов массива A удовлетворяет условию c <= a[i] <= d
process_array:
	push eax
	push ebx
	push ecx
	push edx
	push esi

	mov dword [result_count], 0 	; обнуление счетчика
	mov ecx, [array_size]		; количество элементов
	mov esi, 0			; индекс

	cmp ecx, 0
	je .done			; если массив пустой

.loop:
	mov ax, [array + esi*2]		; загружаем элемент (2 байта)

	; Проверка что число положительное (AX > 0)
	cmp ax, 0
	jle .next_element

	; Проверяем условие c <= a[i] <= d
	cmp ax, [c_value]
	jl .next_element		; если a[i] < c

	cmp ax, [d_value]
	jg .next_element		; если a[i] > d

	inc dword [result_count]	; если оба выполнены - увеличение счетчика

.next_element:
	inc esi
	loop .loop			; уменьшаем значение в rcx на 1, переходим к метке .loop

.done:
	pop esi
	pop edx
	pop ecx
	pop ebx
	pop eax
	ret
