#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <queue>
#include <vector>

using namespace std;

struct Tabuleiro{
int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
int posx = 2;
int posy = 1;
int contagem = 0;
list<Tabuleiro> sucessores;
};

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

Tabuleiro tabuleiro;

queue<Tabuleiro> queueTabuleiro;
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

struct comparar{
    bool operator()(Tabuleiro const& a, Tabuleiro const& b)
    {
        return a.contagem < b.contagem;
    }
};

void buscar(Tabuleiro tabuleiro){
    cout<<"Teste 1"<<endl;
    if(finalizar(tabuleiro)){
        cout<<"sucesso"<<endl;
    }

    priority_queue <Tabuleiro, vector<Tabuleiro>, comparar> filaPrioridade;
    cout<<"Teste 2"<<endl;
    int posicaox[4] = {1,-1,0,0};
    int posicaoy[4] = {0,0,1,-1};

    for (int i = 0; i < 4; i++){
        int pox = tabuleiro.posx + posicaox[i];
        int poy = tabuleiro.posy + posicaoy[i];
         cout<<"Teste 3"<<endl;
        if (validar(pox,poy)){
                cout<<"Teste 4"<<endl;
            Tabuleiro sucessor = tabuleiro;
            swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
            sucessor.posx = pox;
            sucessor.posy = poy;
            filaPrioridade.push(sucessor);
        }
        cout<<"Teste 5"<<endl;
    }
    cout<<"Teste 6"<<endl;
        Tabuleiro aux;
        aux = filaPrioridade.top();
        caminho.push_back(aux);
        cout<<"Tamanho" << caminho.size()<<endl;
            for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << tabuleiro.mat[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
        buscar(aux);
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

int main(){
    buscar(tabuleiro);
    //falta criar a lista de comparação para não dar loop infinito
}
