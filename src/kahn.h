template <class T>
class Kahn {
public:

  Kahn (Grafo<T> g);



  vector<T> ordenacao();
private:
  queue<tuple<T,T,float> > p;
  Grafo<T> g;
};
