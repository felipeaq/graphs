template <class T>
class Kruskal {
public:

  Kruskal (Grafo<T> g);

  Grafo<T>  resultado;

  Grafo<T> gera_caminho();
private:
  priority_queue<tuple<T,T,float>, vector<tuple<T,T,float> >,CompareDist< T > > p;

  Grafo<T> g;
};
