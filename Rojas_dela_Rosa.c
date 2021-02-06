//Autor: Rojas de la Rosa Carlos Armando
//Titulo: Algoritmo para multiplicar un numero muy grande por otro numero muy grande

#include<stdlib.h>
#include<stdio.h>

int *resultado;
int bandera1 = 0;
int bandera2 = 0;

int *reservar_memoria(int n);
int *reservar_memoria_resultado(int n);
void multiplicacion(int *numero1, int numero2,int N, int *resultado,int indice);
void llenarArreglo(int *numero, int N);
void limpiarResultado(int *resultado,int N);
void imprimirResultado(int *resultado, int N);
void llenarArregloChico(int *numero1,int NChico,int NGrande);

int main(){
    
    int N1,N2;
    int *numero1;
    int *numero2;
//longitud del arreglo 1
    printf("N1:");
    scanf("%d",&N1);
//longitud del arreglo 2
    printf("N2:");
    scanf("%d",&N2);

    if(N1 < N2){

    numero1 = reservar_memoria(N2);
    printf("Valores N1 \n");
    llenarArregloChico(numero1,N1,N2);
    //comprobar si hay negativo
    if(numero1[N1-1]<0){
      numero1[N1-1]*=-1;
      bandera1 = 1;
    }
    numero2 = reservar_memoria(N2);
    printf("Valores N2 \n");
    llenarArreglo(numero2,N2);
    //comprobar si hay negativo
    if(numero2[N2-1]<0){
      numero2[N2-1]*=-1;
      bandera2 = 1;
    }
    }

    if(N1 > N2){
      numero1 = reservar_memoria(N1);
      numero2 = reservar_memoria(N1);
      printf("Valores N1:");
      llenarArreglo(numero1,N1);
      //comprobar si hay negativo
      if(numero1[N1-1]<0){
        numero1[N1-1]*=-1;
        bandera1 = 1;
      }
      
      printf("Valores N2:");
      llenarArregloChico(numero2,N2,N1);
      //comprobar si hay negativo
      if(numero2[N2-1]<0){
        numero2[N2-1]*=-1;
        bandera2 = 1;
      }
    }

    if(N1 == N2){
      numero1 = reservar_memoria(N1);
      numero2 = reservar_memoria(N2);
      printf("Valores N1");
      llenarArreglo(numero1,N1);
      //comprobar si hay negativo
    if(numero1[N1-1]<0){
      numero1[N1-1]*=-1;
      bandera1 = 1;
    }
      printf("Valores N2");
      llenarArreglo(numero2,N2);
      //comprobar si hay negativo
    if(numero2[N2-1]<0){
      numero2[N2-1]*=-1;
      bandera2 = 1;
    }
    }

  
    
    
   /* int N1 = 4;
    int N2 = 4;
    //El numero se pone de menor a mayor
    int numero1[4] = {1,5,4,4};
    int numero2[4] = {7,2,6,9};*/

    int indice = 0;
    int valor;

    if(N1 > N2){
        
        resultado = reservar_memoria_resultado(N1);
        limpiarResultado(resultado,2*N1);
        
        while(indice < N2){
          valor = numero2[indice];
          multiplicacion(numero1,valor,N1,resultado,indice);
          indice++;
        }
        
        imprimirResultado(resultado,N1);
    }
    else{
       
        resultado = reservar_memoria_resultado(N2);
        limpiarResultado(resultado,2*N2);

        while(indice < N1)
        {
          valor = numero1[indice];
          multiplicacion(numero2,valor,N2,resultado,indice);
          indice++;
        }
        if(bandera1 == 0 && bandera2 == 1){
            printf("-");
          }
          if(bandera1 == 1 && bandera2 == 0){
            printf("-");
          }
        imprimirResultado(resultado,N2);
        
    }

    
    
    
    free(numero1);
    free(numero2);
    
    free(resultado);
}


int *reservar_memoria(int n){
  int *mem;
  mem = (int *)malloc (sizeof(int)*(n));

  if(mem == NULL){
    perror("Error de asignacion de memoria");
    exit(EXIT_FAILURE);
  }
  return mem;
}

int *reservar_memoria_resultado(int n){
  int *mem;
  mem = (int *)malloc (sizeof(int)*(2*n));

  if(mem == NULL){
    perror("Error de asignacion de memoria");
    exit(EXIT_FAILURE);
  }
  return mem;
}

void llenarArreglo(int *numero, int N){
    for(int i = 0; i < N; i++){
        printf("Digito:");
        scanf("%d",&numero[i]);
    }
}

void limpiarResultado(int *resultado,int N){
    for(int i = 0; i < N; i++){
      resultado[i] = 0;
    }
}

void imprimirResultado(int *resultado, int N){
    printf("Resultado: ");
    if(bandera1 == 0 && bandera2 == 1){
            printf("-");
          }
          if(bandera1 == 1 && bandera2 == 0){
            printf("-");
          }
    for(int i = 2*N-1; i >= 0; i--){
      printf("%d",resultado[i]);
    }
    printf("\n");
}

void multiplicacion(int *numero1, int numero2,int N1, int *resultado,int indice){
   
    int temporal = 0;
    int acarreo = 0;
    int aux[N1+1];
//para la multiplicacion
      for(int i = 0 ; i <N1; i++){
        
           temporal = numero1[i] * numero2 + acarreo;
           acarreo = temporal / 10;
           temporal = temporal%10;    
           aux[i] = temporal;              
          }
          aux[N1] = acarreo;
          acarreo = 0;
//para la suma 
        
          for(int j =0;j < N1+1; j++){
            
            temporal = aux[j] + resultado[j+indice] + acarreo;
            acarreo = temporal /10;
            temporal = temporal%10;
            resultado[j+indice] = temporal;
            
          }
          
          printf("\n");
          printf("resultado:");

          

          for(int i = 2*N1-1; i>=0 ;i--){
          printf(" %d",resultado[i]);
          }

        printf("\n");

      
       
}

void llenarArregloChico(int *numero1,int NChico,int NGrande){
  int numero;
    for(int i = 0; i < NChico; i++){
      printf("Dato:");
      scanf("%d",&numero1[i]);
    }
    for(int i = NChico; i < NGrande; i++){
      numero1[i] = 0;
    }
}
