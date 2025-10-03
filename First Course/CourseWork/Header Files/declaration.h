#ifndef DECLARATION_H
#define DECLARATION_H

#include <stdio.h>
#include <math.h>


#define U 8.0
#define T 0.00001
#define a 5.0
#define b 0.05
#define Uvx1 10.0

void calculate_Uvx(double *t, double *Uvx, int n);
void calculate_Uvix(double *Uvx, double *Uvix, int n);
void write_files(double *t, double *Uvx, double *Uvix, int n);
void control_calculation(int n_points);
void precision_calculation(double eps);
void show_title_screen();
double calculate_parameter(double *Uvix, int n, double dt);

//Если не работает, то удали это (не забудь про другие файлы, там тоже пометки)
void find_min_max(double  *Uvx, int n, double *Umin, double *Umax);
double calculate_trailing_edge(double *Uvx, int n, double dt);
double find_time_at_80V(double* Uvx, double* t, int n);
double find_time_at_max(double* Uvx, double* t, int n);

#endif