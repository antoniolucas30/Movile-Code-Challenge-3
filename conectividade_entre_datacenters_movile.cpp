#include <iostream>
#include <vector>
#include <algorithm>

struct Vertice{

  int conexaoU;
  int conexaoV;
  int conexaoCusto;

};

int resultado = 0;
int totalNos;
int totalVertices;
int custo;
int noU;
int noV;
int vecPai[10000];
int custoPai[10000];
std::vector <std::vector <std::pair<int, int>>> Grafo;
Vertice arr[25000];

bool Compare(Vertice p1, Vertice p2){

  return p1.conexaoCusto < p2.conexaoCusto;

}

int Achar(int filho){

  if(vecPai[filho] == filho)
    return filho;

  return vecPai[filho] = Achar(vecPai[filho]);

}

void Juntar(int filho1, int filho2){

  int pai1 = Achar(filho1), pai2 = Achar(filho2);

  if(custoPai[pai1] > custoPai[pai2])
    vecPai[pai2] = pai1;

  else if(custoPai[pai2] > custoPai[pai1])
    vecPai[pai1] = pai2;

  else{

    vecPai[pai2] = pai1;
    custoPai[pai1]++;

  }

}

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> totalNos >> totalVertices;

  Grafo.resize(totalNos);

  for(int i = 0; i < totalNos; i++)
    vecPai[i] = i;

  for(int i = 0; i < totalVertices; i++){

    std::cin >> noU >> noV >> custo;

    noU--;
    noV--;

    Grafo[noU].push_back(std::make_pair(noV, custo));
    Grafo[noV].push_back(std::make_pair(noU, custo));

    arr[i] = {noU, noV, custo};

  }

  std::sort(arr, arr + totalVertices, Compare);

  for(int i = 0; i < totalVertices; i++){

    int paiU = Achar(arr[i].conexaoU), paiV = Achar(arr[i].conexaoV);

    if(paiU != paiV){

      resultado += arr[i].conexaoCusto;
      Juntar(paiU, paiV);

    }

  }

  std::cout << resultado << '\n';

  return 0;
}
