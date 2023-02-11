#include <iostream>
#include <fstream>
#include <vector>

long zeros(long n) {
  int s=0, d=5;
  while(d<n){
    s+=int(n/d);
    d*=5;
  }
  return s;
}
int main(){
  std::ifstream infile;
  // Criação da variavel para abrir o arquivo
  infile.open("input.txt", std::ifstream::in);
  // Abertura do aquivo dados na forma in -> entrada
  long n;
  infile >> n;
  std::cout << zeros(n) << std::endl;
  return 0;
}