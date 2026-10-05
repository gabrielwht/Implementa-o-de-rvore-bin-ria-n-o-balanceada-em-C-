# Árvore Binária de Busca (BST) Não Balanceada em C++

Uma implementação robusta de uma **Árvore Binária de Busca (Binary Search Tree)** em C++. Este projeto armazena dados no formato Chave-Valor (`int Key`, `string Dado`) e foca no uso avançado de manipulação de memória através de ponteiros duplos (`Node **`) para otimizar as operações recursivas na árvore.

## Funcionalidades

A classe `Btree` abstrai a complexidade dos nós e expõe os seguintes métodos públicos:

- **Inserção (`setBtree`)**: Insere um novo par chave-valor na árvore. Ignora chaves duplicadas.
- **Busca (`find`)**: Retorna o ponteiro para o nó correspondente à chave buscada, ou `nullptr` se não existir.
- **Remoção (`remover`)**: Remove um nó específico pelo valor da chave, tratando automaticamente os cenários de nós folhas, nós com um filho e nós com dois filhos (substituindo pelo menor nó da subárvore direita).
- **Impressão (`printTree`)**: Realiza a travessia *In-Order* (Esquerda, Raiz, Direita), imprimindo as chaves em ordem crescente.
- **Inversão da Árvore (`inverter`)**: Espelha a árvore (Mirror Tree), invertendo as subárvores esquerda e direita de todos os nós.
- **Gerenciamento de Memória**: O destrutor da classe (`~Btree`) desaloca automaticamente todos os nós da memória via travessia em pós-ordem (`limpaArvore`).

## Estrutura do Código

- `Node`: Classe que representa cada vértice da árvore. Contém a chave de busca (`Key`), o dado armazenado (`Dado`) e os ponteiros para os filhos (`Left`, `Right`).
- `Btree`: Classe gerenciadora. Mantém o ponteiro para a raiz (`Root`) e variáveis de controle (como o número de elementos `N`). Os métodos principais são empacotadores públicos que chamam funções recursivas estáticas privadas.
