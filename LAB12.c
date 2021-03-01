/* Segundo Punto */
/* Se incluye la libreria de funciones matematicas para el ejercicio.NOTA: no termino funcionando para la aplicacion, no reconoce las funciones matematicas */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define macro 30
#define tam 5


void ingrdata();
void hamaxmin();
double desestand();
void mosmenu();
void convt();
void convt2();
float prom();

void main()
{
	mosmenu();
}

/*Funcion encargada de mostrar el menu y organizar cada funcion operativa de la aplicacion hasta la culminacion del programa*/
void mosmenu()
{

/*Se inicializan las variables locales de la aplicacion, en el alcance de la funcion mosmenu,*/
	short int Selc = 0;
	short int Control = 0;

	int SUMA = 0;
	int SUMA2 = 0; 

	int Max=0; 
	int Min=0;

	int VALORES[tam];
	int VALORES2[tam];

	short int  END = 1;

	char DATA[macro];
	char DATA2[macro];

	for (int i = 0; i<macro ; i++)
        {
	        DATA[i]=0;
	}

        do{
		
		Selc = 0;
		printf(" Acontinuacion se le enseñara el Menu de la aplicacion\n ");
		printf(" -----------------------------------------------------------------------------------------\n ");
       	        printf(" 1. Ingresar Datos\n ");
		printf(" 2. Mostrar Promedio\n ");
		printf(" 3. Mostrar Varianza\n ");
		printf(" 4. Mostrar Valores Maximos y Minimos\n ");
		printf(" 5. Mostrar Toda La Informacion hasta el numeral 4\n" );
		printf(" 6. Salir de la aplicacion\n ");
		printf(" 7. Mostrar la desigualtad/igualdad digito a digito\n ");
		printf(" 8. Mostrar la desigualdad/igualdad de la suma de los valores\n ");
		printf(" Seleccion: \n");
		scanf("%hd", &Selc); 

/*En esta etapa se imprime el menu del programa junto con las selecciones del usuario para las diversas acciones*/
		switch( Selc ){

			case 1:
				{
					printf(" HA SELECCIONADO LA OPCION 1.\n ");
	
					printf("Usuario; porfavor escriba su numero entero entre punto y coma sin dejar espacios en blanco\n");
					printf("Escriba sus primeros valores: ");
					scanf(" %s",DATA);
					
					printf("Escriba sus siguientes valores: ");
					scanf(" %s",DATA2);

	                                Control = 1;
	
					convt(DATA,VALORES);

					convt2(DATA2,VALORES2);

		
					break;
				}
			case 2:
				printf(" HA SELECCIONADO LA OPCION 2.\n ");
			        if ( Control == 1  )
				{
					printf("El promedio de los valores ingresados es: %f",prom(VALORES));
	
				}	
				else
				{
					printf("Aun no ha ingresado valores\n");
				}
	
				break;
			case 3:
				printf(" HA SELECCIONADO LA OPCION 3.\n ");
			  	if ( Control == 1 )
	                        {
	                                printf("La varianza de los valores ingresados es: %lf",desestand(VALORES));
	
	                        }
	                        else
	                        {
        	                        printf("Aun no ha ingresado valores\n");
                	        }
	
				break;
			case 4:
				printf(" HA SELECCIONADO LA OPCION 4.\n ");
				if ( Control == 1 )
	       	                {
					hamaxmin(VALORES,&Max,&Min);
	                                printf("Los valores Max y Min son.... Min: %d y Max: %d ",Min,Max);
	
	                        }
	                        else
	                        {
	                                printf("Aun no ha ingresado valores\n");
	                        }

				break;
			case 5:
				printf(" HA SELECCIONADO LA OPCION 5.\n ");
				if ( Control == 1 )
       		                {
	                                printf("Los valores Max y Min son.... Min: %d y Max: %d\n ",Min,Max);
					printf("La varianza de los valores ingresados es: %f\n",desestand(VALORES));
	       	                        printf("El promedio de los valores ingresados es: %f\n",prom(VALORES));
	                        }
	                        else
	                        {
	                                printf("Aun no ha ingresado valores\n");
	                        }
	
				break;
			case 6:
				printf(" HA SELECCIONADO LA OPCION 6.\n ");
				printf("SALIENDO DEL PROGRAMA\n");
				printf(".\n");
				printf(".\n");
				printf(".\n");

				END = 0;
	
				break;
			case 7:
				printf(" HA SELECCIONADO LA OPCION 7.\n ");
				if( Control == 1 )
				{
					
					for (int i = 0; i < tam ; i++)
					{
						if(VALORES[i] > VALORES2[i])
						{
							printf("Posicion %d: Primera entrada de valores es mayor a la segunda entrada\n",i+1);
						}
						else if(VALORES[i] < VALORES2[i])
						{
							printf("Posicion %d: Segunda entrada de valores es mayor a la primera entrada\n",i+1);
						}
						else
						{
							printf("Posicion %d: Ambas entradas son iguales\n",i+1);
						}
					}
				}
				else
				{
					printf("Aun no ha escrito todos los valores");
				}
				break;
			case 8:
				printf(" HA SELECCIONADO LA OPCION 8.\n");
				if( Control == 1 )
				{
					
					for (int i = 0; i < tam ; i++)
					{
						SUMA += VALORES[i];
					}
					for (int i = 0; i < tam ; i++)
					{
						SUMA2 += VALORES2[i];
					}
	
					if ( SUMA > SUMA2 )
					{
						printf("La Suma de la primera entrada es mayor a la segunda\n");
					}
			                else if ( SUMA < SUMA2 )
					{
						printf("La suma de la segunda entrada es mayor a la primera\n");
					}
					else 
					{
						printf("Las sumas son identicas\n");
					}
				}
				else
				{
					printf(" Aun no ha escrito todos los valores\n ");
				}
				break;

			default:
				printf("Numeral incorrecto, porfavor escoger los numeros adecuados...");
				break;

			}

	}while(END!=0);
}

/*Funciones que permiten la organizacion/conversion de los datos del usuario*/
void convt(char data[macro],int *valores)
{

	short int i = 0; 

	char *secc = strtok(data,";");

	while(secc != NULL )
	{
		valores[i] = atoi(secc);
		secc = strtok(NULL,";");
		i++;
	}

}

void convt2(char data2[macro],int *valores2)
{

        short int i = 0;

        char *secc = strtok(data2,";");

        while(secc != NULL )
        {
                valores2[i] = atoi(secc);
                secc = strtok(NULL,";");
                i++;
        }

}

/*Funcion encargada de obtener el promedio de los valores del usuario*/
float prom(int valores[tam])
{
	float Promedio = 0.0;

	for(int i=0; i < tam ; i++)
	{
		Promedio += valores[i];	
	}
	Promedio = Promedio / tam ;

	return Promedio;
}

/*Funcion encargada de obtener la varianza de los valores*/
/*NOTA: el programa no reconoce el archivero math.h, no se pudo calcular la desviacion estandar con sus funciones*/
double desestand (int valores[tam])
{
	double Radicando = 0.0;
	float Promedio = prom(valores);

	for ( int i = 0; i < tam ; i++ )
	{
		Radicando += (valores[i]-Promedio)*(valores[i]-Promedio);
	}

	Radicando = Radicando/(tam-1);
        double Raiz = sqrt(Radicando);

	return Raiz;

}

/*Funcion encargada de obtener organizar el vector y extraer los valores min y max del mismo*/
void hamaxmin(int valores[tam],int *max,int *min)
{
	int Reserva = 0;

	for(int i = 0; i < tam-1 ; i++ )
	{
		for(int j = 1+i; j < tam; j++)
		{
			if(valores[i]>valores[j])
			{
				Reserva = valores[i];
				valores[i] = valores[j];
				valores[j] = Reserva;
			}
		}
	}
        
	*min = valores[0];
	*max = valores[4];

}


