#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_EJ 5
#define NUM_SETS 3
#define REST_TIME 60

typedef struct{
	int reps;
}series;

typedef struct{
	char nombre[20];
	series sets[NUM_SETS];
}ejercicio;

typedef struct{
	char nombre[20];
	ejercicio ej[NUM_EJ];
}rutina;

int main(){
	int i=0, j=0, k=0, l=0, nuevo = 1, guia, op, op2, op3, op4, num_ej, num_sets, num_reps, rest;
	char nombre[20], file_name[20];
	float peso, IMC, altura;
	FILE *r, *ej, *rep, *us;
	rutina rut[2];
	
	r = fopen("Files/Rutinas.txt", "r");
	ej = fopen("Files/Ejercicios", "r");
	rep = fopen("Files/Repeticiones", "r");
	us = fopen("Files/Usuarios", "r");
	
	printf("\n\t\t\t\t\t  ~  Bienvenido a SmartProgress  ~ \n\t\t\t\t\t __________________________________");
	printf("\n\n\n > Dinos tu nombre para personalizar la experiencia: ");
		scanf("%s", nombre[20]);
		_strupr(nombre);
	while(!feof(us)){
		fscanf(us, "%[^\n]\n", &file_name);
		if(strcmp(file_name,nombre)==0){
			//system("cls");
			printf("\n Hola %s, ya has usado este programa anteriormente asi que suponemos que sabes como se usa.", nombre);
			nuevo = 0;
			break;
		}
	}
	if(nuevo == 1){
		system("cls");
		printf("\nEs la primera vez que utilizas este programa. Quieres leer una guia rapida de uso?" );
		printf("\n\n [1] Si\n [2] No ");
			scanf("%i", &guia);
		while(guia != 1 && guia != 2){
			system("cls");
			printf("\n Opcion incorrecta.\n Quieres leer una guia rapida de uso?");
			printf("\n\n [1] Si\n [2] No ");
				scanf("%i", &guia);
		}
		fclose(us);
		
		if(nuevo==0){
        	fopen("Ficheros/Usuarios.txt", "a");
        	fprintf(us,"\n%s",nombre);
    	}
    	
		if(guia == 1){
			printf("El objetivo de SmartProgress es ayudarte a que logres tus retos fisicos de manera rapida usando el registro de progresiones implementado en las rutinas.");
		}
	}
	printf("\n\n\n > En que podemos ayudarte?: ");
	printf("\n\n\n\t [1] Consultar mi estado fisico\n\n\t [2] Entrenamientos y rutinas ");
		scanf("%i", &op);
	
	switch(op){
		case 1:
			system("cls");
			printf("\n Escoge una opcion:");
			printf("\n\n\n\t [1] Calcular IMC (Indice de Masa Corporal)\n\n\t [2] Test de salud \n\t");
			scanf("%i", &op2);
			
			switch(op2){
				case 1:
					printf("\n Introduce tu peso en kg (por ejemplo 83.5): \n\t");
						scanf("%f", &peso);
					printf("\n Introduce tu altura en metros (por ejemplo 1.76): \n\t");
						scanf("%f", &altura);
					IMC = peso / (altura*altura);
					printf("\n\t Su IMC es de %g \n\n", IMC);
				break;
				
				case 2:
				
				break;
			}
		break;
		
		case 2:
			system("cls");
			printf("\n Escoge una opcion:");
			printf("\n\n\n\t [1] Nuevo entrenamiento\n\n\t [2] Records personales ");
				scanf("%i", &op3);
			system("cls");
				
			switch(op3){
				case 1:
					printf("\n Grupo muscular o capacidad fisica a entrenar: \n\t");
						scanf("%s", rut[0].nombre);
					printf("\n\n Introduce el numero de ejercicios que componen la rutina: \n\t");
						scanf("%i", &num_ej);
					
				
					for (i = 0; i < num_ej; i++){
						system("cls");
						printf("\n\n Ejercicio numero %i: ", i+1);
						printf("\n\n Introduce el nombre del ejercicio: \n\t");
							scanf("%s", &rut[0].ej[i].nombre);
						printf("\n\n Introduce el numero de series: \n\t");
							scanf("%i", &num_sets);
						printf("\n\n Numero de repeticiones por serie: \n\t");
							scanf("%i", &num_reps);
				
							
						for (l = 0; l < num_sets; l++)
							rut[0].ej[i].sets[l].reps = num_reps;
					}
					system("cls");
					printf("\n\n Pulse cualquier tecla para comenzar el entrenamiento...");
					getch();
					
					printf("\n\t Rutina de %s", rut[0].nombre);
					for (i = 0; i < num_ej; i++){
						system("cls");
						printf("\n Ejercicio %i\t%s", i+1, rut[0].ej[k].nombre);
						for (k = 0; k < num_sets; k++){
							system("cls");
							printf("\n\nSerie %i", k+1);
							printf("\n\n\n\t Tienes que hacer %i %s", rut[0].ej[i].sets[k].reps, rut[0].ej[i].nombre);
							printf("\n\n\n\n Pulsa cualquier tecla cuando termines la serie...");
							getch();
							system("cls");
							printf("\n Descansa durante %i''", REST_TIME);
							printf("\n\n Cuantas repeticiones has podido hacer?\n\t");
								scanf("%i", &rut[1].ej[i].sets[k].reps);
							printf("\n\n\n\n Toca cualquier tecla cuando estes listo para continuar...");
							getch();
						}
					}
					
					
					
				break;
			}
		break;
		
		default:
			printf("\n No existe tal opcion.");
	}
	
	system("PAUSE");
}
