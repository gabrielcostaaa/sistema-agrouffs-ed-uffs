#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct fardo {
  char cultivar[20];
  char tipoDeFeno;
  int diametro;
} Fardo;

typedef struct producao {
  int codigo;
  Data dataProducao;
  Fardo tipoDeFardo;
  int qtDeFardos;
  float duracao;
} Producao;

typedef struct Node {
  Producao colheita;
  struct Node *next;
  struct Node *prev;
} Node;

void buscarProducaoCultivar(Node *head, const char *cultivar);
void adicionarProducao(Node **head, Producao *producao);
void alteraProducao(Producao *prodalt);
void buscarProducaoData(Node *head, Data data);
Producao *buscarProducao(Node *head, int codigo);
Producao *criarProducao(int codigo, Data dataProducao, Fardo tipoDeFardo,
                        int qtDeFardos, float duracao);
void excluiProducao(Node **head, int codigo);
void listarTodos(Node *head);

#endif
