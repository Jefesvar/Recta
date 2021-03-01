/* Primera Punto */
/* Se incluye la libreria de funciones matematicas para el ejercicio */

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
float prom();

void main()
{
	mosmenu();
}

void mosmenu()
{
	short int Selc = 0;
	short int Control = 0 ;

	int Max=0; 
	int Min=0;

	int VALORES[macro];

	short int  END = 1;

	char DATA[macro];

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
		printf(" 5. Mostrar Toda La Informacion\n" );
		printf(" 6. Salir de la aplicacion\n ");
		printf(" Seleccion: \n");
		scanf("%hd", &Selc); 
        
		switch( Selc ){

			case 1:
				{
					printf(" HA SELECCIONADO LA OPCION 1.\n ");
	
					printf("Usuario; porfavor escriba su numero entero entre punto y coma sin dejar espacios en blanco\n");
					printf("Escriba sus valores: ");
					scanf(" %s",DATA);

	                                Control = 1;
	
					convt(DATA,VALORES);

		
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
		}

	}while(END!=0);
}

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


