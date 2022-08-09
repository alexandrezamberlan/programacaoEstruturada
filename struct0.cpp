Dentro das linguagens C e C++, é muito comum o uso de conjuntos heterogêneos, que nada mais é que o princípio de classe da teoria da Orientação a Objetos.
Um conjunto heterogêneo, é STRUCT,  que contém variáveis de diferentes tipos.

Um struct nada mais é que a criação de um tipo definido pelo programador.

struct NomeStruct1 {
  tipo variavel1;
  tipo2 variavel2;
  //...
} ;


typedef struct {
  tipo variavel1;
  tipo2 variavel2;
  //...
} NomeStruct2;


struct NomeStruct1 minhaVariavel;
NomeStruct2 minhaOutraVariavel;
