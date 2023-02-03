#include <iostream>
#include <fstream>

std::string spinWords(const std::string &str)
{
	int x=0, s=str.size(), y;
	std::string str2, strpartial;
	while(x!=s || x==500){
		y=0;
		// separar a palavra do texto
		if(str[x]==' ' || (x)==s){
			y=1;
		}
		else{
			strpartial.push_back(str[x]);
		}
		if(strpartial.size()>=5 && y){
			for (int i = int(strpartial.size() - 1); i >= 0; i--) {
  				str2.push_back(strpartial[i]);
			}
			strpartial.clear();
			if((x+1)!=s){
				str2.push_back(' ');
			}
		}
		else if(y){
			for (int i = 0; i < int(strpartial.size()); i++) {
  				str2.push_back(strpartial[i]);
			}
			strpartial.clear();
			if((x+1)!=s){
				str2.push_back(' ');
			}
		}
		x++;
	}
	return str2;
}// spinWords


int main(){
	std::ifstream infile;
	// Criação da variavel para abrir o arquivo
	infile.open("input.txt", std::ifstream::in);
	// Abertura do aquivo dados na forma in -> entrada
	std::string str, parcial;
	while(!infile.eof()){
		infile >> parcial;
		str.append(parcial);
		str.append(" ");
	}
	std::string resposta = spinWords(str);
	std::cout << resposta << std::endl;
	return 0;
}