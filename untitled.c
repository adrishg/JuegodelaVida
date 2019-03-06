#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int x,y,i,j,k,l,a=0,w=0,tot,r,r1,r2;
time_t t;



int main()
{
	printf("Ingresa las dimensiones de tu tablero: \n");
	printf("Columnas :  ");;
	scanf("%d",&y);
	printf("Filas:  ");;
	scanf("%d",&x);

	int tablero[x][y];
	for (i=0;i<x;i++)
	{
		for (j=0;j<y;j++)
		{
		tablero[i][j]=1;

		//printf("\t %d", tablero[i][j]);
		}
	}	

	srand((unsigned) time(&t));
	//srand(time(NULL));
	tot=(x*y);	
	r=rand() % tot*tot + 1;
	//printf("%d",r);
	

	for (k=0;k<r;k++)
	{
		r1=rand() % x + 1;
		r2=rand() % y + 1;
		
		tablero[r1][r2]=0; //Aquí se puede repetir la posición pero entre más grande sea la matriz dismunuye la posibilidad :(
			
	}


while(w<10000000)
{
	w++;
	//printf("\n\n\n");
	system("clear");
	system("sleep .1");

	
	for (i=0;i<x;i++)
	{	
		a=0; //Para que en cada ciclo, o sea al evaluar cada coordenada empiece en 0
		for (j=0;j<y;j++)
		{
			a=0;
			if(i==0) //Primera fila se evita comparar fuera de matriz
			{
				if(j!=0)
				{
					if(j!=y-1) //Esquina superior derecha
						if(tablero[0][j-1]==1)
							a++;
						if(tablero[1][j]==1)
							a++;
					else
						if(tablero[0][j+1]==1)
							a++;
				}
				else //Esquina superior izquierda
					if(tablero[1][1]==1)
						a++;
					if(tablero[0][1]==1)
						a++;
			}
		
			else
			{

				if(i==x-1) //Última fila no debe compararse lo que este más allá de la matriz
				{
					if(j!=0) 
					{
						if(j!=y-1) 
							if(tablero[x-1][j+1]==1)
							a++;
						else //Esquina inferior izquierda
							if(tablero[x-2][y-1]==1)
								a++;
							if(tablero[x-1][y-2])
								a++;
					}
					else //Posicion esquina inferior derecha
						if(tablero[x-1][1]==1)
							a++;
						if(tablero[x-2][0]==1)
							a++;
				}
				else
				{
					if(j==0) //Primera columna
					{
						if(i!=0)
						{
							if(i!=x-1)
							{
								if(tablero[i][j-1]==1)
									a++;
								if(tablero[i+1][j]==1)
									a++;
							}	
							if(tablero[i][j+1]==1)
								a++;
						}
				}
				else
				{
					if(j==y-1) //Última columna
					{
						if(i!=0)
						{
							if(i!=x-1)
							{
								if(tablero[x-1][y+1]==1)
								a++;
							}	
							if(tablero[x-2][y]==1)
								a++;
						}
						if(tablero[i-1][y-1]==1)
						a++;
					}
					else
					{
						if(tablero[i-1][j]==1)
							a++;
						if(tablero[i+1][j]==1)
							a++;
						if(tablero[i][j-1]==1)
							a++;
						if(tablero[i][j+1]==1)
							a++;
					}
				}
				}
				}
				if(tablero[i][j]==1)
				{
					if(a<=1)
					{
						
						tablero[i][j]=0; //Muere de soledad
					}
					else
					{
						if(a>=4)
						{
							tablero[i][j]=0; //Muere de sobrepoblación
						}
					}
					//tablero[i][j]=1; //Seguirá viva

				}
				else //Entonces es 0
				{
					if(a>=3)
						tablero[i][j]=1; //Revive
				}
		if(tablero[i][j]==1)
			printf("\t ■");
		if(tablero[i][j]==0)
			printf("\t .");
		}
		printf("\n\n\n");
	}	
	
	

printf("\n\n\n");


}
}