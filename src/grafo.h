
using namespace std;
template <class T>
 class CompareDist
{
public:
    bool operator()(tuple<T,T,float> n1,tuple<T,T,float> n2);
};
template <class T>
bool sortbythird(tuple<T,T,float> n1,tuple<T,T,float> n2);
template <class T> class Grafo{
 //já que o objtivo do trabalho é executar todas heuristicas
// tudo vira publico, pois é possível acessar todoas as classes.
//caso tudo fosse herança do grafo, seria necessário ler o arquivo
// cada vez que fosse executar outra heuristica

//std::vector<vector <pair<int,float> > > get_grafo();
public:
  int tam;
  Grafo(bool digraph=false);
  void insere_nodo(T val);
  bool add_cam(T va,T vb,float peso);
  static Grafo<T> grafo_reader(string dir,bool digraph=false);
  bool acha_ciclo(T elemento, T elemento2); //usado para acha ciclos

  std::map<T,vector <pair<T,float> > > info;
  map<T,int> grau;//util somento no kahn

  void mostra_chaves();

  void gera_saida(string output,string nome);
  vector <tuple<T,T,float> >graphviz; //reduz complexidade na hora
// de gerar o arquivo de texto e ajuda no kruskal
private:
  bool digraph;



};
