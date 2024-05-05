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

// REMOVER FINAL
No *remover_final(No *lista)
{
  if (lista == NULL)
  {
    return lista;
  }

  No *no_a_deletar = lista->anterior;

  if (no_a_deletar->proximo == no_a_deletar)
  {
    lista = NULL;
  }
  else
  {
    no_a_deletar->anterior->proximo = lista;
    lista->anterior = no_a_deletar->anterior;
  }
  free(no_a_deletar);
  return lista;
}

// REMOVER INICIO
No *remover_inicio(No *lista)
{
  if (lista == NULL)
  {
    return lista;
  }

  No *no_a_deletar = lista;

  if (no_a_deletar->anterior == no_a_deletar)
  {
    lista = NULL;
  }
  else
  {
    no_a_deletar->proximo->anterior = no_a_deletar->anterior;
    no_a_deletar->anterior->proximo = no_a_deletar->proximo;
    lista = no_a_deletar->proximo;
  }
  free(no_a_deletar);
  return lista;
}

// REMOVE POSICAO
No *remover_posicao(No *lista, int posicao)
{
  if (lista == NULL)
  {
    return lista;
  }

  No *aux = lista;

  // remocao no inicio
  if (posicao == 1)
  {
    lista = remover_inicio(lista);
  }
  else
  {
    int cont = 1;
    do
    {
      aux = aux->proximo;
      cont++;
    } while (aux != lista && cont < posicao);
    // remocao no ultimo
    if (aux == lista)
    {
      remover_final(lista);
    }
    else
    {
      aux->proximo->anterior = aux->anterior;
      aux->anterior->proximo = aux->proximo;
      free(aux);
    }
  }
  return lista;
}

// IMPRIMIR LISTA

void percorrer_lista(No *lista)
{
  if (lista != NULL)
  {
    No *ptr = lista;
    do
    {
      printf("(%d)", ptr->idade);
      ptr = ptr->proximo;
    } while (ptr != lista);
  }
  else
  {
    printf("Lista vazia!");
  }
  printf("\n\n");
}

void percorrer_lista_inversa(No *lista)
{
  if (lista != NULL)
  {
    No *ptr = lista->anterior;
    do
    {
      printf("(%d)", ptr->idade);
      ptr = ptr->anterior;
    } while (ptr != lista->anterior);
  }
  else
  {
    printf("Lista vazia!");
  }
  printf("\n\n");
}

int main()
{

  // DEMONSTRAÇÃO DA LISTA CIRCULAR

  // CRIANDO ELEMENTOS
  No *lista = NULL;
  No *n = criar_elemento(31);
  No *n2 = criar_elemento(40);
  No *n3 = criar_elemento(12);
  No *n4 = criar_elemento(7);
  No *n5 = criar_elemento(72);

  // INSERÇÕES

  printf("*******************\nINICIO DA DEMONSTRACAO\n*******************\n");

  printf("\nApresentando lista vazia:\n");
  percorrer_lista(lista);

  printf("Inserindo 31 no inicio:\n");
  lista = inserir_inicio(lista, n);
  percorrer_lista(lista);

  printf("Inserindo 40 no final:\n");
  lista = inserir_final(lista, n2);
  percorrer_lista(lista);

  printf("Inserindo 12 no inicio:\n");
  lista = inserir_inicio(lista, n3);
  percorrer_lista(lista);

  printf("Inserindo 7 na posicao 2:\n");
  lista = inserir_posicao(lista, n4, 2);
  percorrer_lista(lista);

  printf("Inserindo 72 em uma posicao maior do que o tamanho da lista (insere no final):\n");
  lista = inserir_posicao(lista, n5, 10);
  percorrer_lista(lista);

  printf("Apresentando lista inversa:\n");
  percorrer_lista_inversa(lista);

  printf("Apresentando novamente o estado da lista antes das delecoes:\n");
  percorrer_lista(lista);

  // REMOÇÕES

  // lista = remover_posicao(lista, 2);
  // lista = remover_inicio(lista);
  // lista = remover_final(lista);

  // percorrer_lista(lista);
  // percorrer_lista_inversa(lista);
}
