# Компилятор и флаги
ASM = nasm
ASM_FLAGS = -f elf32
LD = ld
LD_FLAGS = -m elf_i386

# Исходные файлы
SOURCES = main.asm io.asm asm_sign_calc.asm asm_unsign_calc.asm
OBJECTS = $(SOURCES:.asm=.o)
TARGET = program

# Основная цель
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(LD) $(LD_FLAGS) -o $(TARGET) $(OBJECTS)

# Компиляция .asm в .o
%.o: %.asm
	$(ASM) $(ASM_FLAGS) $< -o $@

# Очистка
clean:
	rm -f $(OBJECTS) $(TARGET)

# Пересборка
rebuild: clean all

# Запуск программы
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
