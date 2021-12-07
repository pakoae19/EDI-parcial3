/*
    Escriba un programa en C que dada la siguiente declaración de estructuras:

    typedef struct {
        char nombre[40];
        char pais[25];
    }DatosPersonales;

    typedef struct{
        DatosPersonales datos;
        char deporte[30];
        int numMedallas;
    }Deportista;

    1. Realice una función que lea de un archivo de TEXTO la información de los deportistas.
    2. Realice una función que reciba los deportistas leídos y calcule e imprima el número de medallas por
    deporte.

    Nota: Dentro del código existe un arreglo que contiene los nombres de todos los deportes que existen en el archivo.

        char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};
*/

#include <stdio.h>
#include <string.h>

typedef struct {

    char nombre[40];
    char pais[25];

}DatosPersonales;

typedef struct{
    DatosPersonales datos;
    char deporte[30];
    int numMedallas;

}Deportista;

int lecturaDatos(Deportista dep[100]);
void medallas(Deportista dep[100], char deporte[6][30], int N);

int main()
{
    Deportista deportistas[100];
    // Puede cambiar la declaración de este arreglo a donde lo considere necesario
    char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitación", "Esgrima"};
    int N;
    
    N = lecturaDatos(deportistas);
    medallas(deportistas, deporte, N);
    
    return 0;
}

void medallas(Deportista dep[100], char deporte[6][30], int N)
{
    int i, l;
    int medallas[6];
    
    for(i = 0; i < 6; i++)
    {
        medallas[i] = 0;
        for(l = 0; l < N; l++)
        {
            if(strcmp(deporte[i], dep[l].deporte) == 0)// Si devuelve 0 son iguales
            {
                medallas[i] += dep[l].numMedallas;
            }
        }
    }
    printf("El número de medallas por deporte es:\n\tNatación: %d\n\tAtletismo: %d\n\tCiclismo: %d\n\tGimnasia: %d\n\tEquitación: %d\n\tEsgrima: %d\n", medallas[0], medallas[1], medallas[2], medallas[3], medallas[4], medallas[5]);
}

int lecturaDatos(Deportista dep[100])
{
    FILE *archivo;
    int i = 0, fin, cerrado;
    
    archivo = fopen("deportistas.txt", "r");
    
    do
    {
        fscanf(archivo, "%s", dep[i].datos.nombre);
        fscanf(archivo, "%s", dep[i].datos.pais);
        fscanf(archivo, "%s", dep[i].deporte);
        fin = fscanf(archivo, "%d", &dep[i].numMedallas);
        i++;
    }while(fin != EOF);
    
    cerrado = fclose(archivo);
    
    if(cerrado == EOF)
        printf("El archivo no se cerró bien\n");
    
    return i;
}
