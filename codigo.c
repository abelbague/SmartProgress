#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int reps, tiempo;
}series;

typedef struct{
	char nombre[20];
	series sets[10];
}ejercicio;

typedef struct{
	char nombre[20];
	ejercicio ej[10];
}rutina;

int main(){
	int i, j, op, op2, op3, op4, num_ej, num_sets, num_reps;
	rutina rut;
	
	printf("\n ~ Bienvenido a SmartProgress ~\n ________________________________");
	printf("\n\n\n Escoge una opcion:");
	printf("\n\n\n [1] Consultar mi estado fisico\n\n [2] Entrenamiento y rutinas ");
		scanf("%i", &op);
	
	switch(op){
		case 1:
			system("cls");
			printf("\n Escoge una opcion:");
			printf("\n\n\n [1] Peso ideal\n\n [2] Test de salud");
			scanf("%i", &op2);
			
			switch(op2){
				
			}
		break;
		
		case 2:
			printf("\n Escoge una opcion:");
			printf("\n\n\n [1] Nuevo entrenamiento\n\n [2] Records personales ");
				scanf("%i", &op3);
				
			switch(op3){
				case 1:
					printf("\n Nombre de la rutina: ");
						scanf("%s", &rut.nombre);
					printf("\n\n Numero de ejercicios que componen la rutina: ");
						scanf("%i", &num_ej);
				
					for (i = 0; i < num_ej - 1; i++){
						printf("\n\n\n Ejercicio numero %i: ", i+1);
						printf("\n\n Nombre del ejercicio: ");
							scanf("%i", rut.ej[i].nombre);
						printf("\n\n Numero de series del ejercicio: ");
							scanf("%i", &num_sets);
						printf("\n\n Numero de repeticiones del ejercicio: ");
							scanf("%i", &num_reps);
					}
					system("cls");
					printf("\n\n Pulse cualquier tecla para comenzar el entrenamiento ");
					getch();
					
					printf("\n\t Rutina: %s", rut.nombre);
					for (i = 0; i < num_ej - 1; i++){
						printf("\n\n\n Ejercicio nº %i", i+1);
						for (j = 0; j < num_sets - 1; j++){
							printf("\n\nSerie: %i", j+1);
							printf("\n\n\n\t Tienes que hacer %i %s", num_reps, rut.ej[i].nombre);
							printf("\n\n\n Pulsa cualquier tecla cuando termines la serie...");
							getch();
							system("cls");
							printf("Cuantas repeticiones has podido hacer?");
								scanf("%i", &rut.ej[i].sets[j].reps);
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
