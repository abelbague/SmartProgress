#include "libreria.h"

int main(){
	int i, j, k, l=0, m, n, o, p, q, r, nuevo = 1, guia, op, op2;
	int aux, aux2 = 0, aux3 = 0, aux4 = 0, out = 0, num_reps, rest, repes[50];
	char name[20], file_name[20], rutina[20], nameFile[50], rutaFile[50] = "Files/Progreso_usuarios/";
	float peso, altura, imc;
	FILE *ru, *ej, *rep, *us, *pu;
	
	rutinas rut[NUM_RUT+1];
	
	ru = fopen("Files/Rutinas.txt", "r");
	ej = fopen("Files/Ejercicios.txt", "r");
	rep = fopen("Files/Repeticiones.txt", "r");
	us = fopen("Files/Usuarios.txt", "a+"); // leer y añadir (append)
	
	rellenarStruct (rut, ru, ej, rep, NUM_RUT, NUM_EJ, NUM_SETS);
	
	do
	{
		printf("\n\t\t\t\t\t  ~  Bienvenido a SmartProgress  ~ \n\t\t\t\t\t __________________________________");
		printf("\n\n\n\n\t > Teclea tu nombre para personalizar la experiencia: ");
			gets(name);
			_strupr(name);
			
		nuevo = verificarUsuario (name, us);
		
		system("cls");
		if(nuevo != 0){
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
Ademas, disponemos de una opcion que te permite calcular tu Indice de Masa Corporal para conocer\n \
de manera aproximada cual es tu estado fisico actual.");
				printf("\n\n\n Pulsa una tecla para continuar...");
				getch();
			}
		}
		system("cls");
		printf("\n\n > En que podemos ayudarte %s?: ", name);
		printf("\n\n\n\t [1] Entrenamientos y rutinas\n\n\t [2] Calcular mi IMC (Indice de Masa Corporal)\n\n\t [3] Salir ");
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
								strcpy(rut[NUM_RUT].nombre, rut[aux].nombre); // PARA LUEGO RELLENAR EL FICHERO DE TEXTO CON LOS RESULTADOS
								printf("\n Has seleccionado la rutina de %s", rut[aux].nombre);
								printf("\n\n > Tiempo de descanso entre series? \n\t");
									fflush(stdin);
									scanf("%i", &rest);
								printf("\n\n\n Pulsa cualquier tecla para empezar el entrenamiento... ");
									getch();
								system("cls");
								
								for (m = 0; m < NUM_EJ; m++){	
									strcpy(rut[NUM_RUT].ej[m].nombre, rut[aux].ej[m].nombre); // PARA LUEGO RELLENAR EL FICHERO DE TEXTO CON LOS RESULTADOS
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
											scanf("%i", &rut[NUM_RUT].ej[m].sets[n].reps);
										printf("\n\n\n\n Toca cualquier tecla cuando estes listo para continuar...");
											getch();
										system("cls");
									}
								if(aux3==1) 
									break;
								}
								
								if(aux3!=1)
								{
									printf("\n\t > Bien hecho! Rutina de %s terminada", rut[aux].nombre);
									printf("\n > Estos son tus resultados:\n\n");	
									printf("\t\t%-20s", rut[aux].ej[0].nombre);
									
									for( o=1; o<NUM_EJ; o++)
										printf("%-20s", rut[aux].ej[o].nombre);
									
									for(r=0; r<NUM_SETS; r++){
										printf("\nSerie%-20i", r+1);
										
										for(p=0;p<NUM_EJ;p++)
											printf("%-20i", rut[NUM_RUT].ej[p].sets[r].reps);
									}	
									
								archivoUsuario (name, rut[NUM_RUT], rutaFile, pu, NUM_SETS, NUM_EJ); // SE ALMACENA EN UN .TXT
							
								if(archivoUsuario (name, rut[NUM_RUT], rutaFile, pu, NUM_SETS, NUM_EJ) == 0)
									printf("\n\n > Tus resultados han sido correctamente guardados.");

								printf("\n\n\nPulse cualquier tecla para ir al menu de inicio...");
								getch();
								}
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
				Sleep(1000);
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
	fclose(pu);
	
	return 0;
}
