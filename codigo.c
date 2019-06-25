#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int reps, tiempo;
}series;

typedef struct{
	char nombre[20];
	series sets[20];
}ejercicio;

typedef struct{
	char nombre[20];
	ejercicio ej[20];
}rutina;

int main(){
	int i=0, j=0, k=0, l=0, op, op2, op3, op4, num_ej, num_sets, num_reps, rest;
	float peso, IMC, altura;
	rutina rut[2];
	
	printf("\n ~ Bienvenido a SmartProgress ~\n ________________________________");
	printf("\n\n\n Escoge una opcion:");
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
					printf("\n Introduce tu peso en kg (por ejemplo 83.5 kg): \n\t");
						scanf("%f", &peso);
					printf("\n Introduce tu altura en metros (por ejemplo 1.76 m): \n\t");
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
						printf("\n\n\n Ejercicio numero %i: ", i+1);
						printf("\n\n Introduce el nombre del ejercicio: \n\t");
							scanf("%s", &rut[0].ej[i].nombre);
						printf("\n\n Introduce el numero de series: \n\t");
							scanf("%i", &num_sets);
						printf("\n\n Numero de repeticiones por serie: \n\t");
							scanf("%i", &num_reps);
						printf("\n\n Tiempo de descanso (en segundos): \n\t"); //hacer sistema de conversion de tiempo
							scanf("%i", &rest);
							
						for (l = 0; l < num_sets; l++){
							rut[0].ej[i].sets[l].reps = num_reps;
							rut[0].ej[i].sets[l].tiempo = rest;
						}
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
							printf("\n\n\n Pulsa cualquier tecla cuando termines la serie...");
							getch();
							system("cls");
							printf("\n Descansa durante %i''", rut[0].ej[i].sets[k].tiempo);
							printf("\n\n Cuantas repeticiones has podido hacer?\n\t");
								scanf("%i", &rut[1].ej[i].sets[k].reps);
							printf("\n\n\n Toca cualquier tecla cuando estes listo para continuar...");
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
