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

queue<Tabuleiro> queueTabuleiro;

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

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

struct compararEssaBagaca()//com todo respeito
{
    bool operator()(Tarefas const& aux, Tarefas const& auxi)
    {
        return aux.prioridade < auxi.prioridade;
    }
};

void compararSucessores(Tabuleiro sucessor, Tabuleiro tabuleiro){
for (int i = 0; i < (sucessor.sucessores).size(); i++){
aux[i] = tabuleiro.contagem;
}
for (int i = 0; i < (sucessor.sucessores).size(); i++){
    cout << aux ;
}
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

/*
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
}*/

int main(){
Tabuleiro tabuleiro;
/*
buscar(tabuleiro);
*/
}
