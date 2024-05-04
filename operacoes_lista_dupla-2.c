#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
  int idade;
  struct No *proximo;
  struct No *anterior;
} No;

No *criar_elemento(int idade)
{
  No *novo;
  novo = (No *)malloc(sizeof(No));
  novo->idade = idade;
  novo->proximo = NULL;
  novo->anterior = NULL;
  return novo;
}

// INSERIR INICIO
No *inserir_inicio(No *lista, No *novo)
{
  if (lista == NULL)
  {
    lista = novo;
    lista->proximo = lista;
    lista->anterior = lista;
  }
  else
  {
    novo->proximo = lista;
    novo->anterior = lista->anterior;
    lista->anterior->proximo = novo;
    lista->anterior = novo;
    lista = novo;
  }
  return lista;
}

// INSERIR FINAL
No *inserir_final(No *lista, No *novo)
{
  if (lista == NULL)
  {
    lista = novo;
    lista->proximo = lista;
    lista->anterior = lista;
  }
  else
  {
    novo->proximo = lista;
    novo->anterior = lista->anterior;
    lista->anterior->proximo = novo;
    lista->anterior = novo;
  }
  return lista;
}

// INSERIR POSICAO
No *inserir_posicao(No *lista, No *novo, int posicao)
{
  No *aux = lista;
  // Inclusao no inicio
  if (posicao == 1)
  {
    lista = inserir_inicio(lista, novo);
  }
  else
  {
    int cont = 1;
    do
    {
      aux = aux->proximo;
      cont++;
    } while (aux != lista && cont < posicao);
    // Inclusao no ultimo
    if (aux == lista)
    {
      inserir_final(lista, novo);
    }
    else
    {
      novo->proximo = aux;
      novo->anterior = aux->anterior;
      aux->anterior->proximo = novo;
      aux->anterior = novo;
    }
  }
  return lista;
}

No *remover_final(No *lista)
{
  No *no_a_deletar = lista->anterior;
  if (lista != NULL && no_a_deletar->proximo != no_a_deletar)
  {
    no_a_deletar->anterior->proximo = lista;
    lista->anterior = no_a_deletar->anterior;
    free(no_a_deletar);
  }
  else
  {
    lista = NULL;
    free(no_a_deletar);
  }
  return lista;
}

// REMOVE INICIO
// REMOVE POSICAO

void percorrer_lista(No *lista)
{
  if (lista != NULL)
  {
    No *ptr = lista;
    do
    {
      printf("%d\n", ptr->idade);
      ptr = ptr->proximo;
    } while (ptr != lista);
  }
  else
  {
    printf("Lista vazia!");
  }
}

int main()
{
  No *lista = NULL;
  No *n = criar_elemento(35);
  No *n2 = criar_elemento(50);
  No *n3 = criar_elemento(30);
  No *n4 = criar_elemento(55);

  lista = inserir_inicio(lista, n);
  lista = inserir_final(lista, n2);
  lista = inserir_final(lista, n3);
  lista = inserir_posicao(lista, n4, 2);
  lista = remover_final(lista);

  percorrer_lista(lista);
}
