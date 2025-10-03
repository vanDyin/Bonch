#!/bin/bash

choice=1

while [ $choice -ne 3 ]; do
    clear

    echo "Введите вариант калькулятора:"
    echo "1. Через switch-case"
    echo "2. Через указатели на функцию"
    echo "3. Выход"

    read -p "Ваш выбор: " choice

    if [ $choice -eq 1 ]; then    
        ./pr1
    elif [ $choice -eq 2 ]; then 
        ./pr2
    elif [ $choice -eq 3 ]; then
        exit 0
    fi
done