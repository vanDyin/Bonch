#include "../Header Files/declaration.h"

int main() {
    show_title_screen();
    
    char choice;
    do {
        printf("\nМеню:\n");
        printf("1 - Контрольный расчет\n");
        printf("2 - Расчет с точностью\n");
        printf("3 - Запись в файл\n");
        printf("Выберите: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1': {
                int n;
                printf("Количество точек: ");
                scanf("%d", &n);
                control_calculation(n);
                break;
            }
            case '2': {
                double eps;
                printf("Точность (например 0.01): ");
                scanf("%lf", &eps);
                precision_calculation(eps);
                break;
            }
            case '3': {
                int number_of_points;
                printf("Введите количество точек: ");
                scanf("%d", &number_of_points);
                double t[number_of_points], Uvx[number_of_points], Uvix[number_of_points];
                double dt = T/(number_of_points-1);
                for(int i = 0; i<number_of_points; i++) {
                    t[i] = i*dt;
                }
                calculate_Uvx(t, Uvx, number_of_points);
                calculate_Uvix(Uvx, Uvix, number_of_points);
                write_files(t, Uvx, Uvix, number_of_points);
                break;
            }
            default:
                printf("Неверный выбор!\n");
        }
        
        printf("Продолжить? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
    
    return 0;
}