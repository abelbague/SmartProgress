#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_RUT 4
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
}rutinas;

int main(){
	int i, j, k, l=0, m, n, nuevo = 1, guia, op, op2, op3, op4, aux, aux2 = 0, out = 0, num_reps, num_ej, rest, repes[50], rutina_len;
	char name[20], file_name[20], rutina[20];
	float peso, IMC, altura;
	FILE *ru, *ej, *rep, *us;
	rutinas rut[NUM_RUT];
	
	ru = fopen("Files/Rutinas.txt", "a+");
	ej = fopen("Files/Ejercicios.txt", "r");
	rep = fopen("Files/Repeticiones.txt", "r");
	us = fopen("Files/Usuarios.txt", "a+");
	
	for(i=0;i<NUM_RUT;i++) // Se almacenan las rutinas en estructuras para luego ser comparadas
	{
		fscanf(ru, "%s\n", rut[i].nombre);
		for(j=0;j<NUM_EJ;j++)
		{
			fscanf(ej, "%s\n", rut[i].ej[j].nombre);
			fscanf(rep, "%i\n", &num_reps);
			
			for(k=0;k<NUM_SETS;k++)
				rut[i].ej[j].sets[k].reps = num_reps; // mismo numero de repticiones para todas las series de un mismo ejercicio
		}
	}
	printf("Nombre de la rutina %s", rut[3].nombre);
	// printf("sets %i", rut[3].ej[2].sets[2].reps); para ver si almacena correctamente los datos
	
	printf("\n\t\t\t\t\t  ~  Bienvenido a SmartProgress  ~ \n\t\t\t\t\t __________________________________");
	printf("\n\n\n > Teclea tu nombre para personalizar la experiencia: ");
		gets(name);
		_strupr(name);
		
	while(!feof(us)){
		fscanf(us, "%s\n", &file_name);
		if(strcmp(file_name,name)==0){
			system("cls");
			printf("\n Hola %s, ya has usado este programa anteriormente asi que suponemos que sabes como se usa.", name);
			nuevo = 0;
			break;
		}
	}
	system("cls");
	if(nuevo == 1){
        fprintf(us,"\n%s", name);
        
		printf("\nEs la primera vez que utilizas este programa. Quieres leer una guia rapida de uso?" );
		printf("\n\n\n [1] Si\n\n [2] No ");
			scanf("%i", &guia);
			
		while(guia != 1 && guia != 2){
			system("cls");
			printf("\n Opcion incorrecta.\n Quieres leer una guia rapida de uso?");
			printf("\n\n\n [1] Si\n\n [2] No ");
				scanf("%i", &guia);
		}
    	
		if(guia == 1){
			printf("El objetivo de SmartProgress es ayudarte a que logres tus retos fisicos de manera rapida usando nuestro registro de progresiones implementado en las rutinas.");
		}
	}
	printf("\n\n\n > En que podemos ayudarte %s?: ", name);
	printf("\n\n\n\t [1] Consultar mi estado fisico\n\n\t [2] Entrenamientos y rutinas \n\n\t [3] Salir");
		scanf("%i", &op);
	
	switch(op){
		case 1:
			system("cls");
			printf("\n Escoge una opcion:");
			printf("\n\n\n\t [1] Calcular IMC (Indice de Masa Corporal)\n\n\t [2] Test de salud \n\t [3] Volver atras");
			scanf("%i", &op2);
			
			switch(op2){
				case 1:
					printf("\n Introduce tu peso en kg (por ejemplo 83.5): \n\t");
						scanf("%f", &peso);
					printf("\n Introduce tu altura en metros (por ejemplo 1.76): \n\t");
						scanf("%f", &altura);
					IMC = (peso / (altura*altura))*100;
					printf("\n\t Su IMC es de %g \n\n", IMC);
				break;
				
				case 2:
				
				break;
				case 3:
				break;
				default:
					printf("\n Esta opcion no existe");
			}
		break;
		
		case 2:
			system("cls");
			printf("\n Escoge una opcion:");
			printf("\n\n\n\t [1] Entrenar \n\n\t [2] Nueva rutina \n\n\t [3] Volver atras ");
				scanf("%i", &op3);
			system("cls");
				
			switch(op3){
				case 1:
					printf("\n\tQue grupo muscular quieres entrenar? ");
					scanf("%s", rutina);
					rutina_len = strlen(rutina);
					//system("cls");
						
					for(l=0; l<NUM_RUT; l++){
						if(strncmp(rut[l].nombre, rutina, rutina_len)==0){ // compara con tantos caracteres como se introduzcan
							aux = l; // referencia de la rutina seleccionada
							out = 1;
							system("cls");
							printf("\n\tCuanto tiempo de descanso quieres tener entre series?");
								fflush(stdin);
								scanf("%i", &rest);
							printf("\n\n Pulsa cualquier tecla para empezar el entrenamiento ");
								fflush(stdin);
								getch();
							printf("\n\t Rutina de %s", rut[aux].nombre);
							
							for (m = 0; m < NUM_EJ; m++){
								printf("\n\n > Ejercicio %i\t%s", i+1, rut[aux].ej[m].nombre);
								
								for (n = 0; n < NUM_SETS; n++){
									
									printf("\n\n Serie %i/%i", n+1, NUM_SETS);
									printf("\tTienes que hacer %i %s", rut[aux].ej[m].sets[n].reps, rut[aux].ej[m].nombre);
									printf("\n\n\n\n\n > Pulsa cualquier tecla cuando termines la serie ");
										getch();
									system("cls");
									
									printf("\n Descansa durante %i''", rest);
									printf("\n\n Cuantas repeticiones has podido hacer?\n\t");
										scanf("%i", &repes[aux2]);
											aux2++;
									printf("\n\n\n\n Toca cualquier tecla cuando estes listo para continuar...");
										getch();
									system("cls");
								}
							}
							printf("\n\t > Bien hecho! Rutina de %s terminada", rut[aux].nombre);
							printf("\n Estos son tus resultados:");	
							break;	
						}	
					}
					if(out == 0)
						printf("No hay ninguna rutina con ese nombre. Quieres crearla?");
					break;
					
				case 2:
					printf("\n Grupo muscular o capacidad fisica a entrenar: \n\t");
						scanf("%s", rut[0].nombre);
					printf("\n\n Introduce el numero de ejercicios que componen la rutina: \n\t");
						scanf("%i", &num_ej);
					
				
					for (i = 0; i < num_ej; i++){
						system("cls");
						printf("\n\n Ejercicio numero %i: ", i+1);
						printf("\n\n Introduce el nombre del ejercicio: \n\t");
							scanf("%s", &rut[0].ej[i].nombre);
						//printf("\n\n Introduce el numero de series: \n\t");
							//scanf("%i", &num_sets);
						//printf("\n\n Numero de repeticiones por serie: \n\t");
							//scanf("%i", &num_reps);
				
							
						for (l = 0; l < NUM_SETS; l++)
							rut[0].ej[i].sets[l].reps = num_reps;
					}
					system("cls");
					printf("\n\n Pulse cualquier tecla para comenzar el entrenamiento...");
					getch();
					
					printf("\n\t Rutina de %s", rut[0].nombre);
					for (i = 0; i < NUM_EJ; i++){
						system("cls");
						printf("\n Ejercicio %i\t%s", i+1, rut[0].ej[k].nombre);
						for (k = 0; k < NUM_SETS; k++){
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
				
				case 3:
					break;
				default:
					printf("\n Esta opcion no existe");
			}
		break;
		
		case 3:
			printf("\n Hasta la proxima %s", name);
			break;
			
		default:
			printf("\n No existe tal opcion\n");
	}
	fclose(us);
	
	system("PAUSE");
	return 0;
}
