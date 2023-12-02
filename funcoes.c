#include "funções.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscarProducaoCultivar(Node *head, const char *cultivar) {
  char tiposDeFeno[] = {'A', 'B', 'C'};
  int somaFardos[sizeof(tiposDeFeno) / sizeof(tiposDeFeno[0])] = {0};
  int encontrou = 0;

  Node *atual = head;
  while (atual != NULL) {
    if (strcmp(atual->colheita.tipoDeFardo.cultivar, cultivar) == 0) {
      encontrou = 1;
      for (int i = 0; i < sizeof(tiposDeFeno) / sizeof(tiposDeFeno[0]); ++i) {
        if (atual->colheita.tipoDeFardo.tipoDeFeno == tiposDeFeno[i]) {
          somaFardos[i] += atual->colheita.qtDeFardos;
          break;
        }
      }
    }
    atual = atual->next;
  }

  if (!encontrou) {
    printf("\nNao ha registros para o cultivar %s.\n", cultivar);
  } else {
    printf("\n%s:\n", cultivar);
    for (int i = 0; i < sizeof(tiposDeFeno) / sizeof(tiposDeFeno[0]); ++i) {
      if (somaFardos[i] > 0) {
        printf("%c - %d\n", tiposDeFeno[i], somaFardos[i]);
      }
    }
  }
}

void buscarProducaoData(Node *head, Data data) {
  int qtdFardos = 0, qtdTipoA = 0, qtdTipoB = 0, qtdTipoC = 0, qtdTifton = 0,
      qtdFlora = 0, qtdJiggs = 0, qtdCoast = 0;
  Node *aux = head;
  while (aux != NULL) {
    if (aux->colheita.dataProducao.dia == data.dia &&
        aux->colheita.dataProducao.mes == data.mes &&
        aux->colheita.dataProducao.ano == data.ano) {
      qtdFardos += aux->colheita.qtDeFardos;
      if (aux->colheita.tipoDeFardo.tipoDeFeno == 'A') {
        qtdTipoA += aux->colheita.qtDeFardos;
      } else if (aux->colheita.tipoDeFardo.tipoDeFeno == 'B') {
        qtdTipoB += aux->colheita.qtDeFardos;
      } else if (aux->colheita.tipoDeFardo.tipoDeFeno == 'C') {
        qtdTipoC += aux->colheita.qtDeFardos;
      }

      if (strcmp(aux->colheita.tipoDeFardo.cultivar, "Tifton 85") == 0) {
        qtdTifton += aux->colheita.qtDeFardos;
      } else if (strcmp(aux->colheita.tipoDeFardo.cultivar, "Flora") == 0) {
        qtdFlora += aux->colheita.qtDeFardos;
      } else if (strcmp(aux->colheita.tipoDeFardo.cultivar, "Jiggs") == 0) {
        qtdJiggs += aux->colheita.qtDeFardos;
      } else if (strcmp(aux->colheita.tipoDeFardo.cultivar, "Coast") == 0) {
        qtdCoast += aux->colheita.qtDeFardos;
      }
    }
    aux = aux->next;
  }
  printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
  printf("Data: %d/%d/%d\n", data.dia, data.mes, data.ano);
  printf("Quantidade de Fardos totais: %d\n", qtdFardos);
  printf("Fardos do tipo A: %d\n", qtdTipoA);
  printf("Fardos do tipo B: %d\n", qtdTipoB);
  printf("Fardos do tipo C: %d\n", qtdTipoC);
  printf("Tifton 85: %d\n", qtdTifton);
  printf("Florakirk: %d\n", qtdFlora);
  printf("Jiggs: %d\n", qtdJiggs);
  printf("Coastcross: %d\n", qtdCoast);
}

Producao *buscarProducao(Node *head, int codigo) {
  Node *aux = head;
  while (aux != NULL) {
    if (aux->colheita.codigo == codigo) {
      return &aux->colheita;
    }
    aux = aux->next;
  }
  return NULL;
}

void excluiProducao(Node **head, int codigo) {
  Node *aux = *head;

  while (aux != NULL) {
    if (aux->colheita.codigo == codigo) {
      if (aux->prev == NULL) {
        *head = aux->next;
        if (*head != NULL) {
          (*head)->prev = NULL;
        }
        free(aux);
        printf("\nProdução excluída com sucesso!\n");
        return;
      } else if (aux->next == NULL) {
        aux->prev->next = NULL;
        free(aux);
        printf("\nProdução excluída com sucesso!\n");
        return;
      } else {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        free(aux);
        printf("\nProdução excluída com sucesso!\n");
        return;
      }
    }
    aux = aux->next;
  }
  printf("\nProdução não encontrada!\n");
}

void alteraProducao(Producao *prodalt) {
  int opcao;
  while (1) {
    printf("\nO que você deseja alterar \n\n(0 para sair) \n\n[1 - Data, 2 - "
           "Cultivar, 3 - Qualidade, 4 - Diâmetro, 5 - Quantidade de fardos, 6 "
           "- Duração]:\n\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 0:
      return;
    case 1:
      printf("\nDigite o novo dia:\n");
      scanf("%d", &prodalt->dataProducao.dia);
      printf("\nDigite o novo mês:\n");
      scanf("%d", &prodalt->dataProducao.mes);
      printf("\nDigite o novo ano:\n");
      scanf("%d", &prodalt->dataProducao.ano);
      break;
    case 2:
      printf("\nDigite o novo cultivar:\n");
      scanf("%s", prodalt->tipoDeFardo.cultivar);
      break;
    case 3:
      printf("\nDigite o novo tipo de feno:\n");
      scanf(" %c", &prodalt->tipoDeFardo.tipoDeFeno);
      break;
    case 4:
      printf("\nDigite o novo diâmetro:\n");
      scanf("%d", &prodalt->tipoDeFardo.diametro);
      break;
    case 5:
      printf("\nDigite a nova quantidade de fardos:\n");
      scanf("%d", &prodalt->qtDeFardos);
      break;
    case 6:
      printf("\nDigite a nova duração:\n");
      scanf("%f", &prodalt->duracao);
      break;
    default:
      printf("\nOpção inválida.\n");
      break;
    }
    printf("\nProdução alterada com sucesso.\n");
  }
}

Producao *criarProducao(int codigo, Data dataProducao, Fardo tipoDeFardo,
                        int qtDeFardos, float duracao) {
  Producao *producao = (Producao *)malloc(sizeof(Producao));
  producao->codigo = codigo;
  producao->dataProducao = dataProducao;
  producao->tipoDeFardo = tipoDeFardo;
  producao->qtDeFardos = qtDeFardos;
  producao->duracao = duracao;
  return producao;
}

void adicionarProducao(Node **head, Producao *producao) {

  Node *novo = (Node *)malloc(sizeof(Node));

  novo->colheita = *producao;
  novo->next = NULL;
  novo->prev = NULL;

  if (*head == NULL) {
    *head = novo;
  } else {

    Node *ultimo = *head;
    while (ultimo->next != NULL) {
      ultimo = ultimo->next;
    }

    ultimo->next = novo;
    novo->prev = ultimo;
  }
}

void listarTodos(Node *head) {
  Node *aux = head;
  if (aux == NULL) {
    printf("\nNão há produções cadastradas.\n");
  }
  while (aux != NULL) {
    printf("#########################\n\n");
    printf("Código: %d\n", aux->colheita.codigo);
    printf("------------------------\n");
    printf("Data: %d/%d/%d\n", aux->colheita.dataProducao.dia,
           aux->colheita.dataProducao.mes, aux->colheita.dataProducao.ano);
    printf("------------------------\n");
    printf("Cultivar: %s\nQualidade: %c\nDiâmetro: %d cm\n",
           aux->colheita.tipoDeFardo.cultivar,
           aux->colheita.tipoDeFardo.tipoDeFeno,
           aux->colheita.tipoDeFardo.diametro);
    printf("------------------------\n");
    printf("Fardos: %d unidades\n", aux->colheita.qtDeFardos);
    printf("------------------------\n");
    printf("Duração: %.2f horas\n\n", aux->colheita.duracao);
    aux = aux->next;
    printf("#########################\n\n\n");
  }
}