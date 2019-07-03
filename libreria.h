#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_RUT 4 // Nº DE RUTINAS
#define NUM_EJ 5 // Nº DE EJERCICIOS POR RUTINA
#define NUM_SETS 3  // Nº DE SERIES POR EJERCICIO

typedef struct{
	int reps;
}series;

typedef struct{
	char nombre[20];
	series sets[NUM_SETS];
}ejercicio;

typedef struct{ // STRUCT PRINCIPAL
	char nombre[20];
	ejercicio ej[NUM_EJ];
}rutinas;

void pedirDatos (float *p, float *a);
void tablaIMC (float *imc);
void rellenarStruct (rutinas rutina[], FILE *pf1, FILE *pf2, FILE *pf3, int nRut, int nEj, int nSets);
float calculoIMC (float *p, float *a);
int archivoUsuario (char usuario[], rutinas rutina, char ruta[], FILE *pf, int nSets, int nEj, int aux);
int verificarUsuario (char nombre[], FILE *pf);

