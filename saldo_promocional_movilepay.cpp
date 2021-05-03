#include <iostream>
#include <algorithm>

struct Deposito{
  
  int valorDeposito;
  int diaExpiracao;
  int indice;

};

int qntDepositos;
Deposito vecDepositosOriginal[5002];
Deposito vecPirata[5002];
int tentativaCompras;
int compraX;
int somaAtual = 0;

bool Compare(Deposito p1, Deposito p2){

  if(p1.diaExpiracao < p2.diaExpiracao)
    return true;

  else if(p1.diaExpiracao == p2.diaExpiracao && p1.valorDeposito < p2.valorDeposito)
    return true;

  return false;

}

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> qntDepositos;

  for(int i = 0; i < qntDepositos; i++){

    std::cin >> vecDepositosOriginal[i].valorDeposito >> vecDepositosOriginal[i].diaExpiracao;

    somaAtual += vecDepositosOriginal[i].valorDeposito;

    vecPirata[i].valorDeposito = vecDepositosOriginal[i].valorDeposito;
    vecPirata[i].diaExpiracao = vecDepositosOriginal[i].diaExpiracao;
    vecPirata[i].indice = i;

  }

  std::sort(vecPirata, vecPirata + qntDepositos, Compare);

  std::cin >> tentativaCompras;

  for(int i = 0; i < tentativaCompras; i++){

    std::cin >> compraX;

    if(compraX <= somaAtual){

      somaAtual -= compraX;

      for(int i = 0; compraX > 0; i++){

        vecPirata[i].valorDeposito = std::max(0, vecPirata[i].valorDeposito - compraX);

        compraX -= vecDepositosOriginal[vecPirata[i].indice].valorDeposito;
        vecDepositosOriginal[vecPirata[i].indice].valorDeposito = vecPirata[i].valorDeposito;

      }

    }

  }

  for(int i = 0; i < qntDepositos; i++)
    std::cout << vecPirata[i].valorDeposito << '\n';

  return 0;
}
