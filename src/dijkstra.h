template <class T>
class Dijkstra {
public:

  Dijkstra (Grafo<T> g);

  Grafo<T>  resultado;
  map<T,float> distancia;
  map <T, vector<tuple<T,T,float> > >caminho;
  map<T,float> gera_caminho(T elemento);

  vector< Grafo<T> >cria_grafo();
private:
  priority_queue<tuple<T,T,float>, vector<tuple<T,T,float> >,CompareDist< T > > p;
  Grafo<T> g;
};
