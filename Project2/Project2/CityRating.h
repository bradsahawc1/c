/*
This is the header file which shows all of my declarations and includes.
I used stdio.h for my inputs and I used string.h in my function called update.
the defines I used were for constants in the computations in my Computations file.
Everything else is the prototypes for the functions throughout Main, InputOutput, and Computations.
*/

//include statements
#pragma once
#include <stdio.h>
#include <string.h>

//define statements
#define _CRT_SECURE_NO_WARNINGS
#define PollutionCon 1112.2
#define TrafficCon 2.13
#define CrimeCon 924.6
#define ExpenseCon 1217.1
#define LivabilityCon 13.81

//prototypes for the functions
void main();
int input(FILE*, char *, int *, int *, int *, int *, int *, int *);
double ComputePopulationDensity(int, int);
void Compute(double, double *, double *, double *, double *, int, int, int, int);
double LivabilityFunc(double, double, double, double);
void output(char, double, double);
void update(char, char *, int *, double, double *, double *);
void summary(int, double, double *, double, char);