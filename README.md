# Names-DataBase
Implementation of a binary search tree for storing names of people.

## Target
Develop a C language application to maintain a people name record
stored in RAM using a binary search tree.
## Description
The program, when started, should load an initial name database from a text file.
Each name, no longer than 30 characters, must be entered in a binary search tree maintained by
in RAM via a call to the insert operation, using its name as a key.
The program screen should provide a menu to allow the following operations:
1. Reload the name listing from the file. To do so, all the contents of the previous tree
should be removed and a new charge should be made as described above.
2. List all names in alphabetical order.
3. List all names that contain a provided substring.
4. Enter a new name in memory.
5. Remove a name from memory.
6. List and remove from memory all names that are larger, in alphabetical order, than a name
provided.
7. List and remove from memory all names that are shorter, in alphabetical order, than a name
provided.
8. Save the contents of memory to a text file.
For ease of implementation, store all names in lowercase, and consider the entries
provided in operations as being lowercase.


###### Tradução para a língua portuguesa:

# Banco de Dados de Nomes
Implementação de uma árvore de busca binária para armazenamento de nomes de pessoas.

## Objetivo
Desenvolver uma aplicação em linguagem C para dar manutenção em um cadastro de nomes de pessoas
armazenado em memória RAM usando uma árvore de pesquisa binária.
## Descrição
O programa, ao ser iniciado, deverá carregar uma base de dados de nomes inicial a partir de um arquivo texto.
Cada nome, com não mais que 30 caracteres, deverá ser inserido em uma árvore de pesquisa binária mantida
em memória RAM através de uma chamada à operação inserir, usando como chave o próprio nome.
A tela do programa deverá fornecer um menu para permitir as seguintes operações:
1. Recarregar a listagem de nomes a partir do arquivo. Para tanto, todo o conteúdo da árvore anterior
deverá ser removido e uma nova carga deverá ser feita, como descrito acima.
2. Listar todos os nomes em ordem alfabética.
3. Listar todos os nomes que contém uma substring fornecida.
4. Inserir um novo nome na memória.
5. Remover um nome da memória.
6. Listar e remover da memória todos os nomes que são maiores, em ordem alfabética, que um nome
fornecido.
7. Listar e remover da memória todos os nomes que são menores, em ordem alfabética, que um nome
fornecido.
8. Salvar o conteúdo da memória em um arquivo texto.
Para facilitar a implementação, armazene todas os nomes em letras minúsculas, e considere as entradas
fornecidas nas operações como sendo minúsculas. 

###### Commands to run on docker:
```powershell
docker build -t names-database . 
docker run -it --rm --name names-database names-database
```