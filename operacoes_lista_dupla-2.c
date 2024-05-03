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

No *inserir_inicio(No *lista, No *novo)
{
  if(lista == NULL)
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
}

int main()
{
  No *lista = NULL;
  No *n = criar_elemento(35);
  No *n2 = criar_elemento(50);
  No *n3 = criar_elemento(30);
  No *n4 = criar_elemento(55);

  lista = inserir_inicio(lista, n);
  lista = inserir_inicio(lista, n2);
  lista = inserir_inicio(lista, n3);
  percorrer_lista(lista);

}
