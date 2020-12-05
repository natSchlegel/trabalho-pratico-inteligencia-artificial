#include <queue>
#include <iostream>
using namespace std;
int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
struct Tabuleiro
{
    int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
    int posx = 2;
    int posy = 1;
    bool explorado = false;
};
bool validar(int x, int y)
{
    return !(x < 0 || x > 2 || y < 0 || y > 2);
}
bool Ehobjetivo(Tabuleiro tabuleiro)
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tabuleiro.mat[i][j] != obj[i][j])
                return false;
        }
    }
    return true;
}
void imprimeTabuleiro(Tabuleiro tabuleiro)
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << tabuleiro.mat[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
int main()
{
    Tabuleiro tabuleiro;
    queue<Tabuleiro> fazer;
    queue<Tabuleiro> feito;
    int posicaox[4] = {1,-1,0,0};
    int posicaoy[4] = {0,0,1,-1};
    cout << "Estado Inicial:";
    cout << endl;
    imprimeTabuleiro(tabuleiro);
    fazer.push(tabuleiro);
    while(fazer.size()>0){
        Tabuleiro tabuleiro = fazer.front();
        fazer.pop();
        cout << "Estado Atual: " << endl;
        imprimeTabuleiro(tabuleiro);
        if(Ehobjetivo(tabuleiro))
            return 0;
        cout << "Sucessores: " << endl;
        for (int i = 0; i < 4; i++)
        {
            int pox = tabuleiro.posx + posicaox[i];
            int poy = tabuleiro.posy + posicaoy[i];
            if (validar(pox,poy))
            {
                Tabuleiro sucessor = tabuleiro; //referencia ou valor
                swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
                sucessor.posx = pox;
                sucessor.posy = poy;
                fazer.push(sucessor);
                imprimeTabuleiro(sucessor);
            }
        }
    }
    return 0;
}