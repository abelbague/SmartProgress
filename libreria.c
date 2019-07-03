#include "libreria.h"

void pedirDatos (float *p, float *a)
{
	system("cls");
	printf("\n Introduce tu peso en kg (por ejemplo 83.5): \n\t");
	scanf("%f", p);
	printf("\n Introduce tu altura en metros (por ejemplo 1.76): \n\t");
	scanf("%f", a);
}

float calculoIMC (float *p, float *a)
{
	float IMC;
	IMC = (*p /(*a * *a));
	return IMC;
}

void tablaIMC (float *imc)
{
	if (*imc < 18.5)
		printf("\n\n\t Su peso esta por debajo de lo normal. Le recomendamos que consulte a un especialista.");
	else if (*imc >= 18.5 && *imc < 25)
		printf("\n\n\t Su peso esta dentro valores ideales. No hay de que preocuparse.");
	else if (*imc >= 25 && *imc < 30)
		printf("\n\n\t Su peso esta un poco por encima de lo ideal. Deberia cuidar mas la alimentacion y hacer deporte a menudo.");
	else if (*imc >= 30)
		printf("\n\n\t Su peso esta muy por encima de lo normal. Le recomendamos que consulte a un especialista.");
}

int archivoUsuario (char usuario[], rutinas rutina, char ruta[], FILE *pf, int nSets, int nEj, int aux)
{
	int i, j, k;
	
	if(aux == 0)
	{
		strcat(ruta, usuario);
		strcat(ruta, rutina.nombre);
		strcat(ruta, ".txt");
	}
	pf = fopen(ruta, "w+"); // CREA UN FILE PERSONAL DE CADA USUARIO Y DE CADA RUTINA
	if(pf == NULL)
	{
		printf("\nError al abrir el archivo\n");
		return -1;
	}
	else
	{
		fprintf(pf, "\t\t%-20s", rutina.ej[0].nombre);
		
		for(i = 1; i < nEj; i++)
			fprintf(pf, "%-20s", rutina.ej[i].nombre);
		
		for(j = 0; j < nSets; j++){
			fprintf(pf, "\nSerie%-20i", j+1);
			
			for(k = 0; k < nEj; k++)
				fprintf(pf, "%-20i", rutina.ej[k].sets[j].reps);
		}
	return 0;
	}
}

int verificarUsuario (char nombre[], FILE *pf)
{
	char filename[20];
	int nuevousuario = 1;
	
	while(!feof(pf)){
		fscanf(pf, "%s\n", &filename);
		if(strcmp(filename,nombre)==0){
			system("cls");
			nuevousuario = 0;
			break;
		}
	}
	return nuevousuario;
}

void rellenarStruct (rutinas rutina[], FILE *pf1, FILE *pf2, FILE *pf3, int nRut, int nEj, int nSets)
{
	int i, j, k, numReps;
	
	for(i = 0; i < nRut; i++)
	{
		fscanf(pf1, "%s\n", rutina[i].nombre);
		for(j = 0; j < nEj; j++)
		{
			fscanf(pf2, "%s\n", rutina[i].ej[j].nombre);
			fscanf(pf3, "%i\n", &numReps);
			
			for(k = 0; k < NUM_SETS; k++)
				rutina[i].ej[j].sets[k].reps = numReps;
		}
	}
}
