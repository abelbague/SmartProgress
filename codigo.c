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

void pedirDatos (float *p, float *a);
float calculoIMC (float *p, float *a);
void tablaIMC (float *imc);
int archivoUsuario ();

int main(){
	int i, j, k, l=0, m, n, p, o, q, r, nuevo = 1, guia, op, op2;
	int aux, aux2 = 0, aux3 = 0, aux4 = 0, out = 0, num_reps, rest, repes[50];
	char name[20], file_name[20], rutina[20], nameFile[50], rutaFile[50] = "Files/Progreso_usuarios/";
	float peso, altura, imc;
	FILE *ru, *ej, *rep, *us, *pu;
	
	rutinas rut[NUM_RUT+1];
	
	ru = fopen("Files/Rutinas.txt", "a+"); // leer y escribir
	ej = fopen("Files/Ejercicios.txt", "r");
	rep = fopen("Files/Repeticiones.txt", "r");
	us = fopen("Files/Usuarios.txt", "a+"); // leer y escribir
	
	for(i=0;i<NUM_RUT;i++) // Se almacenan las rutinas en estructuras para luego ser comparadas
	{
		fscanf(ru, "%s\n", rut[i].nombre);
		for(j=0;j<NUM_EJ;j++)
		{
			fscanf(ej, "%s\n", rut[i].ej[j].nombre);
			fscanf(rep, "%i\n", &num_reps);
			
			for(k=0;k<NUM_SETS;k++)
				rut[i].ej[j].sets[k].reps = num_reps; // mismo numero de repeticiones para todas las series de un mismo ejercicio
		}
	}
	
	//rut[NUM_RUT].ej[]
	// printf("sets %i", rut[3].ej[2].sets[2].reps); para ver si almacena correctamente los datos
	do
	{
		printf("\n\t\t\t\t\t  ~  Bienvenido a SmartProgress  ~ \n\t\t\t\t\t __________________________________");
		printf("\n\n\n\n\t > Teclea tu nombre para personalizar la experiencia: ");
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
				system("cls");
				printf("\n El objetivo de SmartProgress es ayudarte a alcanzar tus retos fisicos de manera facil y rapida\n \
mediante nuestro sistema de registro de progresiones implementado en el apartado de rutinas.\n \
Ademas, disponemos de una opcion que te permite calcular tu Indice de Masa Corporal para conocer \
de manera aproximada cual es tu estado fisico actual.");
				printf("\n\n\n Pulsa una tecla para continuar...");
				getch();
			}
		}
		system("cls");
		printf("\n\n > En que podemos ayudarte %s?: ", name);
		printf("\n\n\n\t [1] Entrenamientos y rutinas\n\n\t [2] Calcular mi IMC (Indice de Masa Corporal)\n\n\t [3] Salir");
			scanf("%i", &op);
		
		switch(op){
			case 1:
				system("cls");
				printf("\n > Escoge una opcion:");
				printf("\n\n\n\t [1] Entrenar \n\n\t [2] Volver atras ");
					scanf("%i", &op2);
				system("cls");
					
				switch(op2){
					case 1:
						printf("\n Rutinas disponibles: \n");
						for(q = 0; q < NUM_RUT; q++)
							printf("\n\n - %s", rut[q].nombre);
						printf("\n\n\n > Escoge una rutina de las anteriores (ej. espalda): \n\t");
						scanf("%s", rutina);
							
						for(l=0; l<NUM_RUT; l++){
							if(strncmp(rut[l].nombre, rutina, strlen(rutina))==0){ // compara con el mismo numero caracteres introducidos
								aux = l; // referencia de la rutina seleccionada
								aux4 = 1;
								system("cls");
								printf("\n Has seleccionado la rutina de %s", rut[aux].nombre);
								printf("\n\n > Tiempo de descanso entre series? \n\t");
									fflush(stdin);
									scanf("%i", &rest);
								printf("\n\n\n Pulsa cualquier tecla para empezar el entrenamiento... ");
									getch();
								system("cls");
								
								for (m = 0; m < NUM_EJ; m++){	
								
									for (n = 0; n < NUM_SETS; n++){
										
										printf("\n\t Rutina de %s", rut[aux].nombre);
										printf("\n\n\n > Ejercicio %i\t%s", m+1, rut[aux].ej[m].nombre);
										printf("\n\n Serie %i/%i", n+1, NUM_SETS);
										printf("\tEl objetivo es hacer %i %s", rut[aux].ej[m].sets[n].reps, rut[aux].ej[m].nombre);
										printf("\n\n\n\n\n\n\n\n\n > Pulsa 1 para continuar o 2 para salir: ");
										if(getch() == '2')
										{
											aux3=1;
											system("cls");
											break;
										}
										system("cls");
										printf("\n Descansa durante %i''", rest);
										printf("\n\n Cuantas repeticiones has podido hacer?\n\t");
											fflush(stdin);
											scanf("%i", &rut[NUM_RUT].ej[m].sets[n].reps); // ESTA RECOGIENDO MAL LOS DATOS??
										printf("\n\n\n\n Toca cualquier tecla cuando estes listo para continuar...");
											getch();
										system("cls");
									}
								if(aux3==1) 
									break;
								}
								if(aux3!=1)
									printf("\n\t > Bien hecho! Rutina de %s terminada", rut[aux].nombre);
								printf("\n Estos son tus resultados:\n\n");	
								printf("%40s", rut[aux].ej[0]);
								
								for( o=1; o<NUM_EJ; o++)
									printf("%20s", rut[aux].ej[o]);
								
								for(r=0; r<NUM_SETS; r++){
									printf("\n%20i", r+1);
									
									for(p=0;p<NUM_EJ;p++)
										printf("%20i", rut[NUM_EJ].ej[p].sets[r].reps); // NO SALEN BIEN LOS NUMEROS
								}
							strcat(name, rut[aux].nombre);
							strcat(name, ".txt");
							strcat(rutaFile,name);
							pu = fopen(rutaFile, "w+");
							if(pu == NULL)
							{
								printf("\nError al abrir el archivo\n");
								return -1;
							}
							else
							{
								r=0;
								p=0;
								for(r=0; r<NUM_SETS; r++){
									for(p=0;p<NUM_EJ;p++)
										fprintf(pu, "%i\t", rut[NUM_EJ].ej[p].sets[r].reps); // NO SALEN BIEN LOS NUMEROS
								}
							}
							printf("\n\n\nPulse cualquier tecla para ir al menu de inicio...");
							getch();	
							}
						if(aux3 == 1) break;	
						}
						if(aux4 == 0){
							printf("\nNo hay ninguna rutina con ese nombre. Pulsa cualquier tecla para volver al inicio");
							getch();
						}
						break;
						
					case 2:
						break;
						
					default:
						printf("\n Esta opcion no existe");
					
				}
			break;
			
			case 2:
				pedirDatos (&peso, &altura);
				imc = calculoIMC (&peso, &altura);
				system("cls");
				printf("\n\t > Su IMC es de %g", imc);
				tablaIMC (&imc);
				
				printf("\n\n\n Pulsa cualquier tecla para salir...\n");
				getch();
				break;
			
			case 3:
				printf("\n >> Hasta la proxima %s\n\n", name);
				Sleep(2000);
				out = 1; //	Salir del programa
				break;
				
			default:
				printf("\n No existe tal opcion\n");
		}
	}while(out != 1);
	
	fclose(us);
	fclose(ru);
	fclose(ej);
	fclose(rep);

	return 0;
}

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
