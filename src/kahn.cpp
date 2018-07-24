

template <class T>

Kahn<T>::Kahn(Grafo<T> g){
  this->g=g;
}

template <class T>
vector<T> Kahn<T>::ordenacao(){
  queue<T> visitados;
  //se o numero de vertices for maior que v, então não temos um DAG
  //se não temos um DAG, então podemos finalizar o algoritmo

  int n_vertices=0,contagem=0;
  vector<T> resultado;
  T valor;

  for (auto it=this->g.info.begin();it!=this->g.info.end();it++){

    n_vertices++;
    if(this->g.grau[it->first]==0){
      visitados.push(it->first);

      this->g.grau[it->first]--;

    }
  }
  while(!visitados.empty()){
    valor=visitados.front();


    visitados.pop();
    resultado.push_back(valor);
    contagem++;
    vector <pair<T,float> > w=this->g.info[valor];
    int temp_tam= w.size();
    for(int i=0;i<temp_tam;i++){
      g.grau[w[i].first]--;

      if(g.grau[w[i].first]==0){

        visitados.push(w[i].first);


      }
    }
    if(contagem>n_vertices){
      return vector<T>(0);
      //caso haja um ciclo, retorna um vetor vazio
    }
  }

  if(contagem!=n_vertices)
    return vector<T>(0);

  return resultado;
}
