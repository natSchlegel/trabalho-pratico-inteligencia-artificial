#include <iostream>
#include <string>
#include <stack>
#include <list>

using namespace std;

struct Tabuleiro{
list<Tabuleiro> sucessores;
int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
int posx = 2;
int posy = 1;
bool explorado = false;

};

stack<Tabuleiro> stackTabuleiro;

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

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

void movimentarTabuleiro(Tabuleiro tabuleiro){

int posicaox[4] = {1,-1,0,0};
int posicaoy[4] = {0,0,1,-1};

stackTabuleiro.push(tabuleiro);

for (int i = 0; i < 4; i++){
int pox = tabuleiro.posx + posicaox[i];
int poy = tabuleiro.posy + posicaoy[i];
if (validar(pox,poy)){
        Tabuleiro sucessor = tabuleiro;
        swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
        sucessor.posx = pox;
        sucessor.posy = poy;
        (tabuleiro.sucessores).push_front(sucessor);
        }
    }
}


void buscar(Tabuleiro tabuleiro){
    tabuleiro.explorado = true;
    movimentarTabuleiro(tabuleiro);
    for(auto prox : tabuleiro.sucessores){
        if(prox.explorado = false){
            stackTabuleiro.push(prox);
            }
    }
    stackTabuleiro.pop();
    Tabuleiro aux = stackTabuleiro.top();
    buscar(aux);
    return;
}

int main(){
Tabuleiro tabuleiro;

buscar(tabuleiro);

}
