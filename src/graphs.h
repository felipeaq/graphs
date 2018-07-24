#include <vector> //para acessar valores em tempo constante
#include <queue>  //para a fila de prioridades e filas em algoritmos
// que precisam usar a fila
#include <map>   //acessar valores em tempo constante
//a partir de um template T ou em um grafo
// onde os valores não vão de zero
#include <tuple> //solução bonita para guardar valores de n tipos em uma mesma
//estrutra
#include <iostream> //entrada e saida
#include <fstream> //entrada e saida de arquivos
#include <set> // importante para buscar valores que não precisam se repetir
#include <algorithm> //ordenação de valores
//#include <limits>
#include <string> //para ajudar a criar arquivos
#include <sstream>
#ifndef INF
//poupa uma biblioteca a ser importada
  #define INF 3.40282e+38
#endif



#include "grafo.h"
#include "prim.h"
#include "kruskal.h"
#include "kahn.h"
#include "dijkstra.h"

//solução para problema com templates que davam problema ao
// tentar compilar multiplos arquivos


#include "grafo.cpp"
#include "kruskal.cpp"
#include "kahn.cpp"
#include "prim.cpp"
#include "dijkstra.cpp"
