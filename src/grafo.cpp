
using namespace std;

template <class T>
bool CompareDist<T>::operator()(tuple<T,T,float> n1,tuple<T,T,float> n2){
   return get<2>(n1)>get<2>(n2);
}
template <class T>
bool sortbythird(tuple<T,T,float> n1,tuple<T,T,float> n2){
  return get<2>(n1)<get<2>(n2);
}

template <class T>
Grafo<T>::Grafo(bool digraph ){
  this->digraph=digraph;
  this->tam=0;
}
template <class T>
void Grafo<T>::insere_nodo(T val){
  info[val]=vector<pair<T,float> >();

  this->tam++;

}
template <class T>
void print_set(set<T> v){//função de debug
  cout<<endl<<"{";
  for(auto iter=v.begin(); iter!=v.end();++iter) {
    cout<<*iter<<" ";
  }
  cout<<"}"<<endl;
}

template <class T>
bool Grafo<T>::acha_ciclo(T elemento, T elemento2){
  //metodo que faz busca de ciclos
  queue<T> elementos;
  elementos.push(elemento);
  T temp = elemento2;
  set<T> visitados;
  while(!elementos.empty()){
    elemento=elementos.front();
    elementos.pop();

    visitados.insert(elemento);
    //cout<<elemento<<endl;
    for(auto it=this->info[elemento].begin();it!=this->info[elemento].end();it++){

      if(visitados.find(it->first)==visitados.end()){
        visitados.insert(it->first);
        elementos.push(it->first);


      }

    }

    if (elemento==elemento2){

      return true;
    }

  }
  return false;
}
template <class T>
bool Grafo<T>::add_cam(T va, T vb,float peso){


    if(this->info.find(va)==this->info.end())
      return false;
    if(this->info.find(vb)==this->info.end())
      return false;

  //caso valor não exista ele retorna falso


  this->graphviz.push_back(make_tuple(va,vb,peso));
  this->info[va].push_back(make_pair(vb,peso));

  if(va!=vb && !this->digraph)
    //se não for um digrafo nem um ciclo para ele mesmo, adiciona um nodo pro outro
    //pois assim eu posso tanto acessar a de b quando b de a
    this->info[vb].push_back(make_pair(va,peso));
    grau[vb]++;
  return true;

}
template <class T>
void Grafo<T>::gera_saida(string output,string nome){
  string seta;
  if(!digraph)
    seta="--";
  else
    seta="->";
  ofstream out(output);

  if(digraph)
    out<<"digraph ";
  else
    out<<"graph ";
  out<<nome<<"{"<<endl;

  for (int i=0;i<this->graphviz.size();i++){
    out<< get<0>(this->graphviz[i])<<" "<<seta<<" "<<get<1>(this->graphviz[i])<<" [label=\""<<get<2>(this->graphviz[i]) << "\"];"<<endl;
  }
  out<<"}";
  out.close();

}
template <class T>
void Grafo<T>::mostra_chaves(){
  for(auto iter = this->info.begin(); iter != this->info.end(); ++iter)
  {
    cout<<iter->first<<" ";

  }
  cout<<"\n";
}
template <class T>
Grafo<T> Grafo<T>::grafo_reader(string dir,bool digraph){
  Grafo<T> grafo(digraph);
  T val, valb;
  int tam;
  float peso;
  ifstream in(dir);
  in >> tam;
  for (int i=0;i<tam;i++){
    in>>val;

    grafo.insere_nodo(val);

  }

  while(in>>val){


    in>>valb;
    in>>peso;

    if(!grafo.add_cam(val,valb,peso)){
      //cout<<"Nodo não encontrado"<<endl;
    }

  }

 return grafo;
}
