#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

struct Tabuleiro{
    int mat[3][3] = {{1,2,3},{4,8,5},{7,0,6}};
    int posx = 2; // linha
    int posy = 1; // coluna
    int pai = 0;
    bool explorado = false;
};

bool validar(int x, int y){
    return !(x < 0 || x > 2 || y < 0 || y > 2);
}

bool finalizar(Tabuleiro tabuleiro){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tabuleiro.mat[i][j] != obj[i][j])
                return false;
        }
    }
    return true;
}

void imprimeTabuleiro(Tabuleiro tabuleiro){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << tabuleiro.mat[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void buscar(Tabuleiro tabuleiro){

queue<Tabuleiro> lista;
vector<Tabuleiro> caminho;

int posicaox[4] = {1,-1,0,0};
int posicaoy[4] = {0,0,1,-1};

lista.push(tabuleiro);

while(lista.size()>0){

    Tabuleiro tabuleiro = lista.front();

    caminho.push_back(tabuleiro);
    int pos = caminho.size()-1;

    lista.pop();

    if(finalizar(tabuleiro)){

        cout << "Caminho:" << endl;
        cout << " " << endl;
        Tabuleiro novoTabuleiro;
        imprimeTabuleiro(tabuleiro);
        int aux = tabuleiro.pai;

        for(int i = 3; i > 0; i--) { /*o for eh finito e preciso pois ainda nao consegui descobrir como escrever de forma recursiva*/
        novoTabuleiro = caminho[aux];
        aux = novoTabuleiro.pai;
        imprimeTabuleiro(novoTabuleiro);
        }

        return;
    }

    for (int i = 0; i < 4; i++){

        int pox = tabuleiro.posx + posicaox[i];
        int poy = tabuleiro.posy + posicaoy[i];

        if (validar(pox,poy)){

        Tabuleiro sucessor = tabuleiro;
        swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);

                sucessor.posx = pox;
                sucessor.posy = poy;
                sucessor.pai = pos;

                lista.push(sucessor);
            }
        }
    }
}

int main(){
    Tabuleiro tabuleiro;
    buscar(tabuleiro);
    return 0;
}
