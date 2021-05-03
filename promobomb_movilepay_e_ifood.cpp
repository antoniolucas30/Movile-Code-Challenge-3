#include <iostream>
#include <algorithm>

int N, tamStr;
long X;
std::string toCin;
std::pair <long long, long> result[1001];

bool Compare(std::pair <long long, long> p1, std::pair <long long, long> p2){

  if(p1.first > p2.first)
    return true;

  else if(p1.first == p2.first && p1.second < p2.second)
    return true;

  return false;

}

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for(int i = 0; i < N; i++){

    std::cin.ignore();
    std::getline(std::cin, toCin);

    tamStr = toCin.length();

    for(int j = tamStr - 1; j >= 0; j--){

      if(toCin[j] == ' '){

        X = std::stoi(toCin.substr(j + 1, tamStr - j));
        break;

      }

    }

    result[i].first = (4 * X * X) - (100 * X);
    result[i].second = i + 1;

  }

  std::sort(result, result + N, Compare);

  for(int i = 0; i < 3; i++)
    std::cout << result[i].second << '\n';

  return 0;
}
