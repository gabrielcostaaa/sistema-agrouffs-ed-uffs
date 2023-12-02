#include "funções.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Node *head = NULL;

  while (1) {
    int escolhaMenu = 0;
    printf("\n-------------------------\n");
    printf("|   Sistema Agro UFFS   |\n");
    printf("-------------------------\n");
    printf("[ 1 ] - Incluir Produção|\n");
    printf("[ 2 ] - Consultar       |\n");
    printf("[ 3 ] - Alterar         |\n");
    printf("[ 4 ] - Excluir         |\n");
    printf("[ 5 ] - Listar todos    |\n");
    printf("[ 6 ] - Sair            |\n");
    printf("-------------------------\n\n");

    scanf("%d", &escolhaMenu);

    switch (escolhaMenu) {
    case 1:
      printf("\nIncluir Produção\n\n");
      int codigo, qtDeFardos;
      Data dataProducao;
      Fardo tipoDeFardo;
      float duracao;

      printf("Digite o código: ");
      scanf("%d", &codigo);

      if (buscarProducao(head, codigo) != NULL) {
        printf("\nJá existe uma produção com esse código.\n");
        break;
      }

      printf("\nDigite a data de produção (dd/mm/aaaa): ");
      scanf("%d/%d/%d", &dataProducao.dia, &dataProducao.mes,
            &dataProducao.ano);

      printf("\nDigite o cultivar (Tifton 85, Florakirk, Jiggs, Coastcross): ");
      while (getchar() != '\n')
        ;
      fgets(tipoDeFardo.cultivar, sizeof(tipoDeFardo.cultivar), stdin);
      tipoDeFardo.cultivar[strcspn(tipoDeFardo.cultivar, "\n")] = '\0';

      printf("\nDigite o tipo de feno (A, B, C): ");
      scanf(" %c", &tipoDeFardo.tipoDeFeno);

      printf("\nDigite o diâmetro (80 cm até 160 cm): ");
      scanf(" %d", &tipoDeFardo.diametro);

      printf("\nDigite a quantidade de fardos (unidades): ");
      scanf(" %d", &qtDeFardos);

      printf("\nDigite a duração (em horas): ");
      scanf(" %f", &duracao);

      Producao *prod =
          criarProducao(codigo, dataProducao, tipoDeFardo, qtDeFardos, duracao);
      adicionarProducao(&head, prod);
      break;

    case 2:
      printf("\nConsultar\n\n");
      printf("Deseja consultar por [1- Data] ou [2- Cultivar]");
      int escolhaConsulta;
      scanf("%d", &escolhaConsulta);
      if (escolhaConsulta == 1) {
        printf("\nDigite a data de produção (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dataProducao.dia, &dataProducao.mes,
              &dataProducao.ano);
        buscarProducaoData(head, dataProducao);
      } else if (escolhaConsulta == 2) {
        printf(
            "\nDigite o cultivar (Tifton 85, Florakirk, Jiggs, Coastcross): ");
        while (getchar() != '\n')
          ;
        char cultivar[20];
        fgets(cultivar, sizeof(cultivar), stdin);
        cultivar[strcspn(cultivar, "\n")] = '\0';
        buscarProducaoCultivar(head, cultivar);
      }
      break;
    case 3:
      printf("\nAlterar\n\n");
      printf("Digite o código da produção a ser alterado: ");
      scanf(" %d", &codigo);
      Producao *prodalt = buscarProducao(head, codigo);
      if (prodalt == NULL) {
        printf("\nProdução não encontrada.\n");
        break;
      } else {
        alteraProducao(prodalt);
        break;
      }

    case 4:
      printf("\nExcluir\n\n");
      printf("Digite o código da produção a ser excluído: ");
      scanf(" %d", &codigo);
      excluiProducao(&head, codigo);
      break;

    case 5:
      printf("\nListar todas produções\n\n");
      listarTodos(head);
      break;

    case 6:
      printf("\nSair\n\n");
      exit(0);
      break;

    default:
      printf("\nOpção inválida\n\n");
    }
  }
  return 0;
}