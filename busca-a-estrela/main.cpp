#include <iostream>
#include <list>
#include <cmath>
#include <queue>

using namespace std;

struct Tabuleiro {
int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
int posx = 2;
int posy = 1;
int distancia = 0;
int heuristica = 0;
int nivel = 0;
};

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

queue<Tabuleiro> percorrer;
queue<Tabuleiro> percorrido;

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


void contarDistancia(Tabuleiro sucessor){
    for(int i = 0; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if(!finalizar(sucessor)){
                for (int x = 0; x < 3; x++){
                    for (int y = 0; y < 3; y++){
                        if(finalizar(sucessor)){
                            sucessor.distancia = abs(i-x) + abs(j-y);
                        }
                    }
                }
            }
        }
    }
}

int contarHeuristica(Tabuleiro sucessor){
   return sucessor.heuristica = sucessor.nivel + sucessor.distancia;
}

void buscar(Tabuleiro tabuleiro){

    int posicaox[4] = {1,-1,0,0};
    int posicaoy[4] = {0,0,1,-1};

    percorrer.push(tabuleiro);

    if(finalizar(tabuleiro)){
            //
    }

    while(percorrer.size() > 0){

        Tabuleiro tabuleiro = percorrer.front();

        for (int i = 0; i < 4; i++){

        int pox = tabuleiro.posx + posicaox[i];
        int poy = tabuleiro.posy + posicaoy[i];

            if (validar(pox,poy)){

                Tabuleiro sucessor = tabuleiro;
                swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);

                sucessor.posx = pox;
                sucessor.posy = poy;
                sucessor.nivel++;
                contarDistancia(sucessor);
                contarHeuristica(sucessor);

                percorrer.push(sucessor);
            }
        }
        percorrido.push(tabuleiro);
        percorrer.pop();
        buscar(sucessor);
    }
    return;
}

int main(){
    Tabuleiro tabuleiro;
    buscar(tabuleiro);



/*



buscar(){
- verificar objetivo (se não){
- movimentar + inserir nivel
- contar distancia
- contar heuristica
- inserir na lista pronto
- retirar do topo }
- verificiar objetivo (se sim){
- imprimir caminho (pai) da lista pronto
}

- buscar (prox)



*/
    return 0;
}
