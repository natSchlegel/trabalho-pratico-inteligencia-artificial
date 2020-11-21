#include <iostream>
#include <queue>
using namespace std;

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

struct Tabuleiro{
    int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
    int adj[3][3];
    bool visitado = false;
};

struct Vertice {
    int grau;
};


queue<Tabuleiro>visitar;

void criarMatriz(Tabuleiro tabuleiro){
    for (int l = 0; l < 3; l++){
        for (int c = 0; c < 3; c++){
            if (tabuleiro.adj[l][c] != 0){
                tabuleiro.adj[l][c] = 1;
            }
        }
    }
    for (int l = 0; l < 3; l++){
        int grau = 0;
        for (int c = 0; c < 3; c++){
            if (tabuleiro.adj[l][c] > 0){
                grau++;
            }
        }
    }
}

void retornarVertice(Tabuleiro tabuleiro, int aux)
{

    for (int l = aux; l < aux+1; l++){
        for (int c = 0; c < 6; c++){
            if (tabuleiro.adj[l][c] > 0){
            }
        }
    }
}

void imprimirTabuleiro(Tabuleiro tabuleiro){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << tabuleiro.adj[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

void busca(){

    stack<int> pilha;
	bool visitados[6];
	for(int i = 0; i < 6; i++)
		visitados[i] = false;

	while(true)
	{
		if(!visitados[v]){
			visitados[v] = true;
			pilha.push(v);
		}
}

void expandir(){

}

int main()
{
Tabuleiro tabuleiro;
criarMatriz(tabuleiro);
imprimirTabuleiro(tabuleiro);
    return 0;
}
