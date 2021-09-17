#include <stdio.h>
#define ERRO -1
#define true 1
#define false 0
#define MAX 100
#include <conio.h>

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int inicio;
  int nroElem;
} FILA;


void inicializarFila(FILA* f){
  f->inicio=0;
  f->nroElem=0;
} 


int tamanhoFila(FILA* f) {
  return f->nroElem;
}



int buscaFila(FILA* f){
  if (f->nroElem > 0) {
    return f->inicio;
  }  
  return ERRO;
} 

int buscaSequencial(FILA* f, TIPOCHAVE ch){
   int i = f->inicio;
   int temp;
   for (temp = 0; temp < f->nroElem; temp++){
      if (f->A[i].chave == ch) {
        return i;
      }  
      i = (i + 1) % MAX;
    }
  return ERRO;
} 


void reinicializarFila(FILA* f) {
     inicializarFila(f);
} 


bool inserirElementoFila(FILA* f,REGISTRO reg){
     if (f->nroElem >= MAX) {
       return false;
     }  
     f->A[(f->inicio + f->nroElem)%MAX] = reg;
     f->nroElem++;
     return true;
} 

bool excluirElementoFila(FILA* f,REGISTRO* reg){
   if (f->nroElem==0) {
     return false;
   }
   *reg = f->A[f->inicio];
   f->inicio = (f->inicio+1)%MAX;
   f->nroElem--;
   return true;
} 

void inserir(FILA* f){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoFila(f,reg)) {
    printf("Peso %i inserido com sucesso!\n",ch);
  }
  else {
    printf("Nao foi possivel inserir o peso %i.\n",ch);
  }  
}



void exibirFila(FILA* f){
   printf("Pesos: ");
   int i = f->inicio;
   int temp;
   for (temp = 0; temp < f->nroElem; temp++){
      printf("%i ", f->A[i].chave); 
      i = (i + 1) % MAX;
    }
   printf("\"\n");
} 


void excluir(FILA* f){
  REGISTRO reg;
  if (excluirElementoFila(f,&reg)) {
    printf("Peso %i excluido com sucesso!\n",reg.chave);
  }  
  else {
    printf("Nao foi possivel excluir o peso.\n");
  }  
}

void imprimir_elementos(FILA* f){
  exibirFila(f);
}



void destruir(FILA* f){
     reinicializarFila(f);
     printf("Pesos zerados!\n");
}

void busca(FILA* f) {
     TIPOCHAVE ch;
     scanf("%i",&ch);
     int pos = buscaSequencial(f, ch);
     if (pos == ERRO) {
       printf("Peso nao encontrado! \n");
     }
     else {
       printf("Peso encontrado na posicao %d \n",pos);          
     }
}     

int main(){
  FILA fila;
  inicializarFila(&fila);
  int opcao ;   
  while (opcao != 6) {
  printf("1 : Inserir Peso \n");
  printf("2 : Excluir Peso \n");
  printf("3 : Mostrar Pesos registrados\n");
  printf("4 : Zerar todos os Pesos registrados\n");  
  printf("5 : Buscar Peso\n");  
  printf("6 : Sair \n");    
  printf("Digite a opcao desejada: ");
  scanf("%d",&opcao);
  switch (opcao) {
      case 1 : inserir(&fila); break;
      case 2 : excluir(&fila); break;
      case 3 : imprimir_elementos(&fila); break;
      case 4 : destruir(&fila); break;
      case 5 : busca(&fila); break;
    }  
  printf("Pressione qualquer tecla para continuar...\n");
  getch();  
  } 

  return 0;
}
