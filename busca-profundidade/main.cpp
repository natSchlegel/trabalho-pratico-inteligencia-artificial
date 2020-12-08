#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>

using namespace std;


struct Tabuleiro{
list<Tabuleiro> sucessores;
int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
int posx = 2;
int posy = 1;
int pai = 0;
bool explorado = false;
};

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

stack<Tabuleiro> stackTabuleiro;
vector<Tabuleiro> caminho;

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
        cout << "Teste" << endl;
    }
    cout << endl;
    return;
}

void movimentarTabuleiro(Tabuleiro tabuleiro){

stackTabuleiro.push(tabuleiro);

int posicaox[4] = {1,-1,0,0};
int posicaoy[4] = {0,0,1,-1};

    for(int i = 0; i < 4; i++){
        int pox = tabuleiro.posx + posicaox[i];
        int poy = tabuleiro.posy + posicaoy[i];

    if (validar(pox,poy)){

        Tabuleiro sucessor;
        sucessor = tabuleiro;
        swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
        sucessor.posx = pox;
        sucessor.posy = poy;
        (tabuleiro.sucessores).push_front(sucessor);
        }
    }
}


void buscar(struct Tabuleiro, Tabuleiro tabuleiro , stack<Tabuleiro> &stackTabuleiro){

    caminho.push_back(tabuleiro);
    tabuleiro.explorado = true;
    movimentarTabuleiro(tabuleiro);

    for(auto prox : tabuleiro.sucessores){
        if(prox.explorado == false){
            stackTabuleiro.push(prox);
            }
    }
    stackTabuleiro.pop();

    Tabuleiro aux;
    aux = stackTabuleiro.top();
    buscar (aux , &stackTabuleiro);
    return;
}

void imprimir(vector<Tabuleiro> &vector){
    int aux = caminho.size();
    cout << "Teste 1" << endl;
    for (int i = 0; i < aux ; i++){
            Tabuleiro novoAux;
            novoAux = caminho[i];
            cout << "Teste 2" << endl;
            imprimeTabuleiro(novoAux);
    }
}

int main(){

    Tabuleiro tabuleiro;
    buscar(tabuleiro,stackTabuleiro);
    imprimir(caminho);

    //algum problema de conversão nas linhas 90 e 108
}
