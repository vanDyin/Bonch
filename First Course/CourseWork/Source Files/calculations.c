#include "../Header Files/declaration.h"
#include <stdio.h>
#include <math.h>

void calculate_Uvx(double *t, double *Uvx, int n) {
    double half_T = T / 2.0;
    for (int i = 0; i < n; i++) {
        if (0.0 <= t[i] && t[i] < half_T) {
            Uvx[i] = -2.0 * U * t[i] / T;
        } else if (half_T <= t[i] && t[i] < T) {
            Uvx[i] = 2.0 * U * (t[i] - half_T) / T;
        }
    }
}

void calculate_Uvix(double *Uvx, double *Uvix, int n) {
    for (int i = 0; i < n; i++) {
        if (Uvx[i] <= Uvx1) {
            Uvix[i] = a;
        } else if (Uvx[i] > Uvx1) {
            Uvix[i] = b * (Uvx[i] * Uvx[i]);
        }
    }
}

void write_files(double *t, double *Uvx, double *Uvix, int n) {
    FILE *f1 = fopen("t.txt", "w");
    FILE *f2 = fopen("Uvx.txt", "w");
    FILE *f3 = fopen("Uvix.txt", "w");

    for (int i = 0; i < n; i++) {
        fprintf(f1, "%.10f\n", t[i]);
        fprintf(f2, "%.10f\n", Uvx[i]);
        fprintf(f3, "%.10f\n", Uvix[i]);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("Файлы готовы!\n");
}

double calculate_parameter(double *Uvix, int n, double dt) {
    double Umax = Uvix[0], Umin = Uvix[0];
    for (int i = 1; i < n; i++) {
        if (Uvix[i] > Umax) Umax = Uvix[i];
        if (Uvix[i] < Umin) Umin = Uvix[i];
    }

    double temp = Umin + 0.5 * (Umax - Umin);
    double duration = 0.0;

    for (int i = 0; i < n; i++) {
        if (Uvix[i] >= temp)
            duration += dt;
    }

    return duration;
}

void find_min_max(double  *Uvx, int n, double *Umin, double *Umax) {
    *Umin = Uvx[0];
    *Umax = Uvx[0];
    
    for (int i = 1; i < n; i++) {
        if (Uvx[i] < *Umin) *Umin = Uvx[i];
        if (Uvx[i] > *Umax) *Umax = Uvx[i];
    }
}

double calculate_trailing_edge(double* Uvx, int n, double dt) {
    double Umin, Umax;
    find_min_max(Uvx, n, &Umin, &Umax);
    
    double U1 = Umin + 0.9 * (Umax - Umin);
    double U2 = Umin + 0.1 * (Umax - Umin);
    double duration = 0.0;
    
    for (int i = 0; i < n - 1; i++) {
        if (Uvx[i] > U2 && Uvx[i] < U1 && Uvx[i+1] < Uvx[i]) {
            duration += dt;
        }
    }
    
    return duration;
}

double find_time_at_80V(double* Uvx, double* t, int n) {
    for (int i = 0; i < n; i++) {
        if (Uvx[i] > 80.0) {
            return t[i];
        }
    }
    return -1.0;
}

double find_time_at_max(double* Uvx, double* t, int n) {
    double Umax = Uvx[0];
    int max_index = 0;
    
    for (int i = 1; i < n; i++) {
        if (Uvx[i] > Umax) {
            Umax = Uvx[i];
            max_index = i;
        }
    }
    
    return t[max_index];
}

void control_calculation(int n_points) {
    double t[n_points], Uvx[n_points], Uvix[n_points];
    double dt = T / (n_points - 1);
    
    for (int i = 0; i < n_points; i++) {
        t[i] = i * dt;
    }
    
    calculate_Uvx(t, Uvx, n_points);
    calculate_Uvix(Uvx, Uvix, n_points);
    
    printf("\nКонтрольный расчет для %d точек:\n", n_points);
    printf(" t\t\tUvx\t\tUvix\n");
    for (int i = 0; i < n_points; i++) {
        printf("%.10f\t%.10f\t%.10f\n", t[i], Uvx[i], Uvix[i]);
    }

    double trailing_edge = calculate_trailing_edge(Uvix, n_points, dt);
    double time_80V = find_time_at_80V(Uvx, t, n_points);
    double time_max = find_time_at_max(Uvx, t, n_points);
    double param = calculate_parameter(Uvix, n_points, dt);
    
    printf("\nРезультаты анализа:\n");
    printf("Длительность импульса: %.10f\n", param);
    printf("Длительность заднего фронта Uvix: %.10f\n", trailing_edge);
    
    if (time_80V >= 0) {
        printf("Момент достижения 80 В в Uvx: %.10f\n", time_80V);
    } else {
        printf("Сигнал Uvx не достиг 80 В\n");
    }
    
    printf("Момент максимума сигнала Uvx: %.10f\n", time_max);
}

void precision_calculation(double eps) {
    double p = 1.0;
    double par = 1e10;
    int n = 2;
    
    printf("\nРасчет параметра с точностью %.10f:\n", eps);
    printf(" n\tПараметр\tПогрешность\n");
    
    while (p > eps) {
        double t[n], Uvx[n], Uvix[n];
        double dt = T / (n - 1.0);
        
        for (int i = 0; i < n; i++) {
            t[i] = i * dt;
        }
        
        calculate_Uvx(t, Uvx, n);
        calculate_Uvix(Uvx, Uvix, n);
        
        double par1 = calculate_parameter(Uvix, n, dt);
        p = (par == 1e10) ? 1.0 : fabs(par - par1) / par1;
        
        printf("%d\t%.10f\t%.10f\n", n, par1, p);
        
        par = par1;
        n *= 2;
        
        if (n > 1000000) {
            printf("Достигнут предел итераций!\n");
            break;
        }
    }
    
    printf("\nИтоговый параметр: %.10f\n", par);
}

void show_title_screen() {
    FILE *file = fopen("codeOnC/Resource Files/title.txt", "r");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\n");
}