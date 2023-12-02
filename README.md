# Sistema de Acompanhamento de Produção Agrícola - GEX605 - Estruturas de dados - 2023/2

Este sistema foi desenvolvido como parte da avaliação proposta pelo Professor Claunir Pavan para a disciplina de Estruturas de Dados. Ele tem como objetivo fornecer um sistema eficiente para o acompanhamento da produção agrícola. O programa permite realizar operações como inclusão, consulta, alteração e exclusão de registros de produção.

## Estruturas de Dados

### Producao
A estrutura `Producao` é o bloco fundamental de dados, representando um período específico de produção de feno. Contém as seguintes informações:
- `codigo`: Identificador único da produção.
- `dataProducao`: Estrutura contendo informações sobre a data da produção.
- `tipoDeFardo`: Estrutura representando o fardo produzido.
- `qtDeFardos`: Quantidade de fardos produzidos.
- `duracao`: Duração do processo de produção.

### Fardo
A estrutura `Fardo` contém informações detalhadas sobre cada fardo produzido, incluindo:
- `cultivar`: Nome da cultivar do feno.
- `tipoDeFeno`: Tipo do feno (A, B ou C).
- `diametro`: Diâmetro do fardo.

### Data
A estrutura `Data` representa a data exata de uma produção e inclui:
- `dia`: Dia da data.
- `mes`: Mês da data.
- `ano`: Ano da data.

## Funções Principais

### `adicionarProducao(Node **head, Producao *producao)`
Responsável por incluir um novo período de produção no sistema, garantindo a unicidade dos códigos.

### `buscarProducao(Node *head, int codigo)`
Realiza a busca por um registro de produção com base no código. Retorna um ponteiro para a produção encontrada ou `NULL` se não existir.

### `buscarProducaoData(Node *head, Data data)`
Consulta e exibe detalhes das produções em uma data específica, incluindo a quantidade de fardos de cada tipo e por cultivar.

### `buscarProducaoCultivar(Node *head, const char *cultivar)`
Consulta e exibe a soma da quantidade de fardos para uma cultivar específica, discriminando por tipo de feno.

### `alteraProducao(Producao *prodalt)`
Permite a modificação de qualquer campo do registro de produção por meio do código.

### `excluiProducao(Node **head, int codigo)`
Exclui um registro de produção com base no código.

### `listarTodos(Node *head)`
Lista todos os registros de produção armazenados no programa, exibindo detalhes relevantes.

## Organização do Projeto

O código está organizado em três principais arquivos:
- `funcoes.c`: Contém a implementação das funções principais do programa.
- `funcoes.h`: Declaração das funções utilizadas no projeto.
- `main.c`: Contém a função principal do programa.

## Conclusões e Aprendizado

Durante o desenvolvimento deste projeto, diversos aspectos fundamentais foram abordados, proporcionando uma experiência enriquecedora no campo da programação e estrutura de dados.

1. **Estruturação Modular com Funções:**
   - A utilização de funções foi essencial para modularizar o código, tornando-o mais legível, organizado e facilitando a manutenção.

2. **Manipulação de Listas Encadeadas:**
   - A implementação de listas encadeadas permitiu armazenar e gerenciar eficientemente as informações relacionadas à produção de feno, contribuindo para uma estrutura dinâmica e adaptável.

3. **Validações e Integridade de Dados:**
   - Foram implementadas validações robustas e verificações criteriosas para garantir a integridade dos dados, assegurando que apenas informações válidas sejam processadas.

4. **Interatividade com o Usuário:**
   - O programa foi projetado para interagir de forma eficaz com o usuário, solicitando e apresentando informações de maneira clara e intuitiva.

Este projeto não apenas reforçou conceitos fundamentais de estrutura de dados, mas também destacou a importância de uma abordagem sistemática na resolução de problemas do mundo real.

## Como Executar

Para executar o programa, compile o código-fonte e execute o executável resultante.
```bash
gcc main.c funcoes.c -o seu_programa
./seu_programa
