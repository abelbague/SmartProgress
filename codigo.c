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
	int i, j, k, l=0, m, n, p, o, q, r, nuevo = 1, guia, op, op2, op3, op4, aux, aux2 = 0, aux3 = 0, aux4 = 0, out = 0, num_reps, rest, repes[50], rutina_len;
	char name[20], file_name[20], rutina[20], nameFile[50];
	float peso, IMC, altura;
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
	// printf("sets %i", rut[3].ej[2].sets[2].reps); para ver si almacena correctamente los datos
	do
	{
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
				system("cls");
				printf("\n El objetivo de SmartProgress es ayudarte a alcanzar tus retos fisicos de manera facil y rapida\n \
	mediante nuestro sistema de registro de progresiones implementado en el apartado de rutinas.\n \
	Ademas, disponemos de una opcion que te permite calcular tu Indice de Masa Corporal.");
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
				printf("\n Escoge una opcion:");
				printf("\n\n\n\t [1] Entrenar \n\n\t [2] Volver atras ");
					scanf("%i", &op3);
				system("cls");
					
				switch(op3){
					case 1:
						printf("\n > Que grupo muscular quieres entrenar? ");
						scanf("%s", rutina);
						rutina_len = strlen(rutina);
						//system("cls");
							
						for(l=0; l<NUM_RUT; l++){
							if(strncmp(rut[l].nombre, rutina, rutina_len)==0){ // compara con el mismo numero caracteres
								aux = l; // referencia de la rutina seleccionada
								aux4 = 1;
								system("cls");
								printf("Has seleccionado la rutina de %s", rut[aux].nombre);
								printf("\n\n > Tiempo de descanso entre series? ");
									fflush(stdin);
									scanf("%i", &rest);
								printf("\n\n\n Pulsa cualquier tecla para empezar el entrenamiento... ");
									fflush(stdin);
									getch();
								system("cls");
								
								for (m = 0; m < 2; m++){
									printf("\n\t Rutina de %s", rut[aux].nombre);
									printf("\n\n\n > Ejercicio %i\t%s", m+1, rut[aux].ej[m].nombre);
									
									for (n = 0; n < NUM_SETS; n++){
										
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
								printf("%20s", rut[aux].ej[0]);
								
								for( o=1; o<NUM_EJ; o++)
									printf("%20s", rut[aux].ej[o]);
								
								for(r=0; r<NUM_SETS; r++){
									printf("\n%20i", r+1);
									
									for(p=0;p<NUM_EJ;p++)
										printf("%20i", rut[NUM_EJ].ej[p].sets[r].reps); // NO SALEN BIEN LOS NUMEROS
								}
							strcat(name,"_");
							strcat(name,rut[aux].nombre);
							strcpy(nameFile, name);
							strcat("Files/Progreso_usuarios/", nameFile);
							strcat(nameFile, ".txt");
							pu = fopen(nameFile, "w+");
							puts(nameFile);
							if(pu == NULL)
							{
								printf("\nError al abrir el archivo\n");
								return -1;
							}
							else
							{
								for(r=0; r<NUM_SETS; r++){
									fprintf(pu, "\n");
									for(p=0;p<NUM_EJ;p++)
										fprintf(pu, "%i\t", rut[NUM_EJ].ej[p].sets[r].reps); // NO SALEN BIEN LOS NUMEROS
								}
							}
							printf("\n\n\nPulse cualquier tecla para ir al menu de inicio...");
							getch();	
							}
						if(aux3==1) break;	
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
				system("cls");
				printf("\n Introduce tu peso en kg (por ejemplo 83.5): \n\t");
					scanf("%f", &peso);
				printf("\n Introduce tu altura en metros (por ejemplo 1.76): \n\t");
					scanf("%f", &altura);
					IMC = (peso / (altura*altura));
				printf("\n\t Su IMC es de %g \n\n", IMC);
				printf("\nPulsa cualquier tecla para salir...\n");
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
	
	system("PAUSE");
	return 0;
}
