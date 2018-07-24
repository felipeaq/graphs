
#include "graphs.h"

template <class T>
void graph_vetor_saida(vector<Grafo<T> >vg,string base_output){
  for (int i=0;i<vg.size();i++){
    stringstream ss;
    ss<<base_output<<i<<".dat";
    vg[i].gera_saida(ss.str(),"D" );
  }


}

void menu(){
  cout<<"o que você deseja executar"<<endl<<endl;

  cout<<"1. Primm"<<endl;
  cout<<"2. Kruskal"<<endl;
  cout<<"3. Kahn"<<endl;
  cout<<"4. Dijkstra"<<endl;

  cout<<endl<<"Digite ctrl+D para sair"<<endl<<endl;
}

void mostra_prim(string input, string output, string elemento){
  Grafo<string> g=Grafo<string>::grafo_reader(input);
  Prim<string> p(g);

  stringstream ss,ss2;
  ss<<output<<"_original"<<".dat";
  ss2<<output<<"_resultado"<<".dat";
  g.gera_saida(ss.str(), "Prim_original");
  p.gera_caminho(elemento).gera_saida(ss2.str(), "Prim_resultado");

}
void mostra_kruskal(string input, string output){
  Grafo<string> g=Grafo<string>::grafo_reader(input);
  Kruskal<string> k(g);

  stringstream ss,ss2;
  ss<<output<<"_original"<<".dat";
  ss2<<output<<"_resultado"<<".dat";
  g.gera_saida(ss.str(), "Kruskal_original");
  k.gera_caminho().gera_saida(ss2.str(), "Kruskal_resultado");

}
void mostra_kahn(string input){
  Grafo<string> d =Grafo<string>::grafo_reader(input,true);
  Kahn <string> ka(d);
  vector <string> resultado=ka.ordenacao();
  if(resultado.empty()){
    cout<<"Não é um DAG"<<endl;
    return;
  }
  for (auto it = resultado.begin();it!=resultado.end();it++){
    cout<< *it<<" ";
  }
  cout<<endl;


}
void mostra_dijkstra(string input, string output,string inicio){
  Grafo<string> d =Grafo<string>::grafo_reader(input,true);
  Dijkstra <string> di(d);
  stringstream ss,ss2;
  ss<<output<<"_original"<<".dat";

  d.gera_saida(ss.str(),"dijkistra_original");
  map<string,float> resultado_dijkstra=di.gera_caminho(inicio);
  vector<Grafo<string> >vg=di.cria_grafo();
  graph_vetor_saida(vg,output);


}




int main(){

  string entrada;
  string saida;
  string nodo;

  //Para fazer testes, podem ser usados os arquivos abaixo:
  //mostra_prim("exemplo.dat", "zz_prim", "5");
  //mostra_kahn("exemplo.dat");
  //mostra_kahn("exemplo_sem_ciclo.dat");
  //mostra_kruskal("exemplo.dat", "zz_kruslal");
  //mostra_dijkstra("exemplo_dijkstra.dat", "zz_dijkstra", "s");

  menu();
  int op;
  while(cin>>op){
    switch (op){
      case 1:

      cout<<"escolha a entrada ";

      cin>>entrada;
      cout<<"escolha a saida ";
      cin>>saida;
      cout<<"escolha o nodo de inicio ";
      cin>>nodo;

      mostra_prim(entrada,saida,nodo);
      break;

      case 2:


      cout<<"escolha a entrada ";

      cin>>entrada;
      cout<<"escolha a saida ";
      cin>>saida;


      mostra_kruskal(entrada,saida);
      break;

      case 3:



      cout<<"escolha a entrada ";

      cin>>entrada;



      mostra_kahn(entrada);
      break;

      case 4:

      cout<<"escolha a entrada ";

      cin>>entrada;
      cout<<"escolha a saida ";
      cin>>saida;
      cout<<"escolha o nodo de inicio ";
      cin>>nodo;

      mostra_dijkstra(entrada,saida,nodo);
      break;

    }

    menu();
  }





  return 0;
}
