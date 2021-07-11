#include <iostream>
#include <vector>

using namespace std;

void kmp(string texto, string padrao, vector<int> aux){
	int idx_texto = 0, idx_padrao = 0;

	while((unsigned)idx_texto < texto.size()){
		if(padrao[idx_padrao] == texto[idx_texto]){
			idx_padrao++;
			idx_texto++;
		}

		if((unsigned)idx_padrao == padrao.size()){
			cout << "Padrao encontrado na posicao: " << (idx_texto - idx_padrao) << endl;
			cout << "Indice texto: " << idx_texto << endl;
			idx_padrao = aux[idx_padrao - 1];
		}
		
		if((unsigned)idx_texto < texto.size() && padrao[idx_padrao] != texto[idx_texto]){
			if(idx_padrao){
				idx_padrao = aux[idx_padrao - 1];
			} else{
				idx_texto++;
			}	
		}
	}
}

/**Pré-processa a palavra padrão buscada e constroi um 
 * array aux de mesmo tamanho da palavra. Busca pelo 
 * maior sufixo que também seja um prefixo, evitando 
 * comparações inúteis (caractere seja examinado 
 * novamente) dando continuidade no casamento de padrões.
 **/
void prefix(string padrao, vector<int> & aux){
	aux[0] = 0;
	int j = 0, i = 1;

	while((unsigned)i < padrao.size()){
		if(padrao[i] == padrao[j]){
			j++;
			aux[i] = j;
			i++;
		} else{
			if(j){
				j = aux[j - 1];
			} else {
				aux[i] = 0;
				i++;
			}
		}
	}
}

int main(int argc, char *argv[]){
	string texto = "ATGGACGACACCGTCAGTGATTGGCGTCCGTCGCGCAGGCTCTCGATGAGCTGATGCTTTGGGCCGAGGACTGCCCCGAAGTCCGGCACCTCGTGCACGCGGATTTCGGCTCCAACAATGTCCTGACGGACAATGGCCGCATAACAGCGGTCATTGACTGGAGCGAGGCGATGTTCGGGGATTCCCAATACGAGGTCGCCAACATCTTCTTCTGGAGGCCGTGGTTGGCTTGTATGGAGCAGGAGACGCGCTACTTCGAGCGGAGGCATCCGGAGCTTGCAGGATCGCCGCGGCTCCGGGCGTATATGCTCCGCATTGGTC";
	string padrao = "ATTGG";

	vector<int> aux(padrao.size());

	prefix(padrao, aux);
	kmp(texto, padrao, aux);

	return 0;
}