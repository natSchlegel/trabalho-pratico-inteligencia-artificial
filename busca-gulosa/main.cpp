#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <queue>

using namespace std;

struct Tabuleiro{
list<Tabuleiro> sucessores;
list<Tabuleiro> posSuc;
int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
int posx = 2;
int posy = 1;
int contagem = 0;
};

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

Tabuleiro tabuleiro;

queue<Tabuleiro> queueTabuleiro;

bool validar(int x, int y){
    return !(x < 0 || x > 2 || y < 0 || y > 2);
}

bool conferir(Tabuleiro tabuleiro){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tabuleiro.mat[i][j] != obj[i][j])
                return false;
        }
    }
    return true;
}

void compararPecas(Tabuleiro tabuleiro){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tabuleiro.mat[i][j] != obj[i][j]){
                tabuleiro.contagem++;
            }
        }
    }
}

void compSuc(Tabuleiro sucessor, Tabuleiro tabuleiro){

    /*comparar os números de tabuleiro.contagem e retornar o menor*/

}

void movimentarTabuleiro(Tabuleiro tabuleiro){

int posicaox[4] = {1,-1,0,0};
int posicaoy[4] = {0,0,1,-1};

queueTabuleiro.push(tabuleiro);

for (int i = 0; i < 4; i++){
int pox = tabuleiro.posx + posicaox[i];
int poy = tabuleiro.posy + posicaoy[i];
if (validar(pox,poy)){
        Tabuleiro sucessor = tabuleiro;
        swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
        sucessor.posx = pox;
        sucessor.posy = poy;
        compararPecas(sucessor);
        (tabuleiro.posSuc).push_front(sucessor);
        }
    }
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
    queueTabuleiro.push(tabuleiro);
    while(queueTabuleiro.size()>0){
        movimentarTabuleiro(tabuleiro);
    }
    return;
}

int main(){

buscar(tabuleiro);

/*erro: não é criado a fila queueTabuleiro */

}
