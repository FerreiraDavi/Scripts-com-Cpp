#include <iostream>
#include <fstream>

#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
	std::string str;
	int x = args[0];
	bool flag = true;
	for(int i = 0; i < int(args.size()); i++){
		x = args [i];
		//std::cout<<x <<"   " << (args[i]) <<std::endl;
		if((x == (args[i+1]-1 )) && flag){
			str += std::to_string(x);
			if(x == (args[i+2]-2 )){
				str.push_back('-');
			}
			else{
				str.push_back(',');
			}
			
			flag=false;
		}
		else if(x != (args[i+1]-1 )){
			str+= std::to_string(x);
			str.push_back(',');
			flag=true;
		}
	}
	str.pop_back();
  	return str;
}

int main(){
	std::ifstream infile;
	// Criação da variavel para abrir o arquivo
	infile.open("input.txt", std::ifstream::in);
	// Abertura do aquivo dados na forma in -> entrada
	std::string resposta;
	std::vector<int> numbers;
	numbers = {-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
 	resposta = range_extraction(numbers);
	std::cout << resposta << std::endl;
	return 0;
}