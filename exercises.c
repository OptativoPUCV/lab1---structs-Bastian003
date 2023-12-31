#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size-1-i;j++){
      if(arr[j]<arr[j+1]){
        int aux=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=aux;
      }
    }
  }
  
  return arr[0]; }

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int cont=size-1;
  for(int i=0;i<size/2;i++){
    int aux=arr[i];
    arr[i]=arr[cont];
    arr[cont]=aux;
    cont-=1;
  }
  
  
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize){
  int* nuevo;
  int j=0;
  *newSize=0;
  for(int i=0;i<size;i++){
    if(arr[i]%2==0){
      *newSize+=1;
    }
  }
  nuevo=(int *)malloc(*newSize * sizeof(int));
  for(int i=0;i<size;i++){
    if(arr[i]%2==0){
      nuevo[j]=arr[i];
      j++;
    }
    
  }
  return nuevo; }

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) {

  int size3=size1+size2;
  
  int j=0;
  for(int i=0;i<size1;i++){
    result[j]=arr1[i];
    j++;
    
  }
  for(int i=0;i<size2;i++){
    result[j]=arr2[i];
    j++;
    
  }
  for(int i=0;i<size3-1;i++){
    for(int k=0;k<size3-1-i;k++){
      if(result[k]>result[k+1]){
        int aux=result[k];
        result[k]=result[k+1];
        result[k+1]=aux;
      }
    }
  }
  
  for(int i=0;i<size3;i++){
    printf("%i ",result[i]);
  }
  
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int orden=0;
  int desorden=0;
  
  for(int i=0;i<size-1;i++){
    if(arr[i]>arr[i+1]){
      desorden++;
    }else if(arr[i]<arr[i+1]){
      orden++;
    }
  }
  if(desorden>orden && orden==0){
    return -1;
  }else if(orden>desorden && desorden==0){
    return 1;
  }else{
    return 0;
  }
}
  
  
  

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,int anioNacimiento, int anioPublicacion) {
  strncpy(libro->titulo,titulo,sizeof(libro->titulo)-1);
  strncpy(libro->autor.nombre,nombreAutor,sizeof(libro->autor.nombre)-1);
  libro->autor.anioNacimiento=anioNacimiento;
  libro->anioPublicacion=anioPublicacion;
  
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  if(size<=0){
    return NULL;
  }
  Nodo *Inicio=NULL;
  Nodo *Final=NULL;
  for(int i=0;i<size;i++){
    Nodo *nuevo=(Nodo *)malloc(sizeof(Nodo));
    nuevo->numero=arr[i];
    nuevo->siguiente=NULL;

    if(Inicio==NULL){
      Inicio=nuevo;
      Final=nuevo;
    }else{
      Final->siguiente=nuevo;
      Final=nuevo;
    }
  }
  return Inicio;
}
