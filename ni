1-

 for ( i = 0 ; i < [MAX] ; i++ ){
media = (nota1 + nota2 + nota3 + nota4) /4;
printf("Nome: %s\n"alunos[i].nome_aluno);
printf("R.A: %d\n",alunos[i].ra);
printf("Nota: 1 %f\n",alunos[i].nota1);
printf("Nota: 1 %f\n",alunos[i].nota2);
printf("Nota: 1 %f\n",alunos[i].nota3);
printf("Nota: 1 %f\n",alunos[i].nota4);
}



2 - int main()
{
    int i = 1;
    int *ponteiroint = &i;
    
    float f = 0.6;
    float *ponteirofloat = &f;
    
    char c ='a';
    char  *ponteirochar = &c;
    
   *ponteiroint = 2;
   *ponteirofloat = 0.2;
   *ponteirochar = 'b';

    printf("Inteiro %i ", *ponteiroint);
    printf("\n Real %f",  *ponteirofloat);
    printf("\nChar %c", *ponteirochar);

}




3a - void inicializarPilhaDupla(PILHADUPLA *l){
  l->topo1 = -1;
  l->topo2 = MAX;
} 




3b -int tamanhoPilhaDupla(PILHADUPLA *p) {
  int tamanho = p->topo1+1 + MAX-p->topo2;
  return tamanho;
} 




4 - typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  int inicio; 
  int fim;  
  REGISTRO A[MAX];
} FILA;





5a - void exibirLista(LISTA *l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%d ", l->A[i].chave); 
  printf("\"\n");
} 


5b - bool inserirElemLista(REGISTRO reg, int i, LISTA *l){
  int j;
  if ((l->nroElem >= MAX) || (i < 1) || (i > (l->nroElem+1))) {
    return(false); // lista cheia ou índice inválido
  }
  if((l->nroElem > 0) && (i < l->nroElem+1)){
    for (j = l->nroElem; j >= i; j--) {
       l->A[j] = l->A[j-1];
       }
  }   
  l->A[i-1] = reg;
  l->nroElem++;
  return(true);
