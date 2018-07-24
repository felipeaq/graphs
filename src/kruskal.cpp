
template <class T>
void imprime_tudo(Grafo<T> g, vector <tuple<T,T,float> >lista_adj){
  for (int i=0;i<g.graphviz.size();i++){
    cout<< get<0>(g.graphviz[i])<<" "<<get<1>(g.graphviz[i])<<endl;
  }
}

template <class T>

Kruskal<T>::Kruskal(Grafo<T> g){
  this->g=g;
}

template <class T>
Grafo<T> Kruskal<T>::gera_caminho(){
  vector <tuple<T,T,float> >lista_adj=g.graphviz;
  unsigned int adj_size=lista_adj.size();

  for(auto iter = this->g.info.begin(); iter != this->g.info.end(); ++iter)//incia grafo apenas com nodos
  {

    this->resultado.insere_nodo (iter->first);
  }

  sort(lista_adj.begin(),lista_adj.end(),sortbythird<T>);//ordena as copias pelo menor pesoz

  for (int i=0;i<adj_size;i++){
    
    //pecorre todos os valores e caso tenha cilo não adiciona ao grafo resultante
    if(!this->resultado.acha_ciclo(get<0>(lista_adj[i]),get<1>(lista_adj[i])) ){

      this->resultado.add_cam(get<0>(lista_adj[i]),get<1>(lista_adj[i]),get<2>(lista_adj[i]));
    }
  }

  return this->resultado;
}
