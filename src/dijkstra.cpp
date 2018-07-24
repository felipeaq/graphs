

template <class T>

Dijkstra<T>::Dijkstra(Grafo<T> g){
  this->g=g;
}

template <class T>
map<T,float> Dijkstra<T>::gera_caminho(T elemento){
  set<T> visitados;


  for (auto  it = g.info.begin();it!=g.info.end();it++){
    //if (it->first!=elemento) encher tudo com infinito e
    // depois passar isso pra zero reduz complexidade
    distancia[it->first]=INF;


  }
  distancia[elemento]=0;
  caminho[elemento]=vector<tuple<T,T,float> >();

  this->p.push((make_tuple(elemento,elemento,0)));

  while(!this->p.empty()){
    tuple <T,T,float> topo = p.top();
    p.pop();
    T u=get<1>(topo);
    float distancia_anterior = distancia[u];

    if(visitados.find(u)==visitados.end()){

      visitados.insert(u);
      for(auto it= this->g.info[u].begin();it!=this->g.info[u].end();it++){
        float dist_total=distancia_anterior+it->second;
        if(dist_total<distancia[it->first]){
          this->p.push(make_tuple(elemento,it->first,dist_total));
          distancia[it->first]=dist_total;
          caminho[it->first]=caminho[u];
          caminho[it->first].push_back(make_tuple(u,it->first,it->second));
        }

      }
    }


  }





  return distancia;
}

template<class T>
vector<Grafo<T> > Dijkstra<T>::cria_grafo(){
vector<Grafo<T> > resultado;

  for (auto it =caminho.begin();it!=caminho.end();it++){

    Grafo<T> aux;
    if (!it->second.empty())
      aux.insere_nodo(get<0>(it->second[0]));
    for (int i=0;i<it->second.size();i++){
      aux.insere_nodo(get<1>(it->second[i]));
      aux.add_cam(get<0>(it->second[i]),get<1>(it->second[i]),get<2>(it->second[i]));

    }
    resultado.push_back(aux);

  }

  return resultado;
}
