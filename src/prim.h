

template <class T>
class Prim {
public:

  Prim (Grafo<T> g);

  Grafo<T>  resultado;

  Grafo<T> gera_caminho(T elemento);
private:
  priority_queue<tuple<T,T,float>, vector<tuple<T,T,float> >,CompareDist< T > > p;
  Grafo<T> g;
};
