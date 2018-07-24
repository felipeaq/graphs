

template <class T>

Prim<T>::Prim(Grafo<T> g){
  this->g=g;
}

template <class T>
Grafo<T> Prim<T>::gera_caminho(T elemento){
  set<T> visitados;

  tuple<T,T,float> prox;

  visitados.insert(elemento);
  this->resultado.insere_nodo(elemento);
  for (int i=0;i<this->g.info[elemento].size();i++){

    this->p.push(make_tuple(elemento,this->g.info[elemento][i].first,this->g.info[elemento][i].second));

  }

  while(!this->p.empty()){
    
    prox=this->p.top();

    this->p.pop();

    if(visitados.find(get<1>(prox))==visitados.end()){

      this->resultado.insere_nodo( get<1>(prox));
      // insere o elemento anterior o proximo e a distancia entre eles
      this->resultado.add_cam(get<0>(prox), get<1>(prox),get<2>(prox));
      elemento= get<1>(prox);
      visitados.insert(elemento);
      for (int i=0;i<this->g.info[elemento].size();i++){
        this->p.push(make_tuple(elemento,this->g.info[elemento][i].first,this->g.info[elemento][i].second));

      }

    }
  }


  return this->resultado;
}
