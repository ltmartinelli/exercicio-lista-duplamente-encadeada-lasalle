#include<stdlib.h>
#include<stdio.h>

typedef struct No{
   int idade;
   struct No *proximo;
   struct No *anterior;
} No;


////////////////////////////////////
//////// FUNCAO DO EXERCICIO ///////
///////////////////////////////////

void apresenta_lista_inversa(No * lista){
  //Percorrendo os elementos da lista na ordem inversa
   int cont = 1;
    while (lista -> proximo != NULL){
      cont++;
      lista = lista->proximo;
    }
    while(lista != NULL){
       printf("Idade do elemento %d, %d \n", cont, lista->idade);
       cont--;
       lista = lista -> anterior;
    }

}

No * criar_elemento(int idade){
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->idade = idade;
  novo->proximo  = NULL;
  novo->anterior = NULL;
  return novo;
}

No * insere_primeiro(No * lista, No * novo){
   if (lista != NULL){
     lista->anterior = novo;
     novo->proximo = lista;
   }
   return novo;
}

No * retorna_ultimo_da_lista(No * lista){
  while (lista->proximo != NULL){
    lista = lista->proximo;
  }
  return lista;
}

No * insere_ultimo(No * lista, No * novo){
  if (lista != NULL) {
    No * n = retorna_ultimo_da_lista(lista);
    n->proximo = novo;
    novo->anterior = n;
    return lista;
  }else{
    return novo;
  }
}

void apresenta_lista(No * lista){
  //Percorrendo os elementos da lista
   int cont = 1;
   while (lista != NULL){
      printf("Idade do elemento %d, %d \n", cont, lista->idade);
      cont++;
      lista = lista->proximo;
   }
}


No * remove_elemento(No * lista, int posicao){
  if (lista != NULL){
    No * aux = lista;
    //exclusão lista
    if (posicao == 1){
      lista = lista->proximo;
      lista->anterior = NULL;
    }else{
      int cont = 1;
      while (aux != NULL && cont < posicao) {
        aux = aux->proximo;
        cont++;
      }

      if (aux == NULL){
          printf("A lista nao tem %d elementos \n", posicao);
          return lista;
      }

      aux->anterior->proximo = aux->proximo;

      //exclusao do ultimo nao necessita atualizar a referencia de um elemento posterior
      if (aux->proximo != NULL){
        aux->proximo->anterior = aux->anterior;
      }
    }
    free(aux);
  }else{
     printf("A lista esta vazia! \n");
  }
  return lista;
}

No * insere_na_lista(No * lista, No * novo, int posicao){
  No * aux = lista;
  //Inclusao no inicio
  if (posicao == 1){
     lista = insere_primeiro(lista, novo);
  }else{
    int cont = 1;
    while (aux->proximo != NULL && cont < posicao) {
      aux = aux->proximo;
      cont++;
    }
    //Inclusao no ultimo
    if (aux->proximo == NULL){
       insere_ultimo(lista, novo);
    }else{
       //inclusao em outro ponto
       aux->anterior->proximo = novo;
       novo->proximo  = aux;
       novo->anterior = aux->anterior;
       aux->anterior  = novo;
    }
  }
  return lista;
}


 int main() {
   // Criando referencia para a lista
   No *lista = NULL;
   // criar um lista apontada por n com o primeiro elemento
   No *n = criar_elemento(35);
   No *n2 = criar_elemento(50);
   No *n3 = criar_elemento(30);
   No *n4 = criar_elemento(55);
   No *n5 = criar_elemento(3);
   No *n6 = criar_elemento(1);

   lista = insere_ultimo(lista, n2);
   lista = insere_ultimo(lista, n3);
   lista = insere_ultimo(lista, n4);
   lista = insere_primeiro(lista, n5);
   
   printf("\nApresentando lista inversa\n");

   ////////////////////////////
   ///////DEMONSTRACAO ////////
   ///////////////////////////

   apresenta_lista_inversa(lista);
}

