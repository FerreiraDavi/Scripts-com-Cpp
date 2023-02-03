#include <iostream>
#include <fstream>

#include <vector>

int findOdd(const std::vector<int>& numbers){
	int s = numbers.size();

	int contador [2][100] = {};
	int z = 1;
	contador [1][0] = numbers [0];
	contador [0][0] = 1;
	for (int i=1; i<s; i++){

		for (int j=0; j<z; j++){
			if(contador [1][j] == numbers [i]){
				contador [0][j]++;
				goto semelhante;
			}
		}
		contador [1][z] = numbers [i];
		contador [0][z]++;
		z++;
		semelhante: ;	
	}
	
	for (int i=0; i<z; i++){
		if((contador [0][i])%2){
			return contador [1][i];
		}
	}
}

int main(){
	std::ifstream infile;
	// Criação da variavel para abrir o arquivo
	infile.open("input.txt", std::ifstream::in);
	// Abertura do aquivo dados na forma in -> entrada
	std::vector<int> numbers;
	int parcial, resposta;
	//while(!infile.eof()){
	//	infile >> parcial;
	//	std::cout <<  << std::endl;
	//	numbers.push_back(parcial);
	//}
	numbers = {7};
 	resposta = findOdd(numbers);
	std::cout << resposta << std::endl;
	return 0;
}