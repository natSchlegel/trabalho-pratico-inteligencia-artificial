#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int obj[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

struct Tabuleiro
{
    int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
    int posx = 2;
    int posy = 1;
    int pai;
    bool explorado = false;
};
bool validar(int x, int y)
{
    return !(x < 0 || x > 2 || y < 0 || y > 2);
}
bool Ehobjetivo(Tabuleiro tabuleiro)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(tabuleiro.mat[i][j] != obj[i][j])
                return false;
        }
    }
    return true;
}
void imprimeTabuleiro(Tabuleiro tabuleiro)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
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
    vector<Tabuleiro> feito;
    //Utilizado na função de gerar sucessor
    int posicaox[4] = {1,-1,0,0};
    int posicaoy[4] = {0,0,1,-1};
    cout << "Estado Inicial:";
    cout << endl;
    imprimeTabuleiro(tabuleiro);
    //Inserindo estado inicial na fila
    fazer.push(tabuleiro);
    while(fazer.size()>0)
    {
        //Retira estado/nó/tabuleiro da fila
        Tabuleiro tabuleiro = fazer.front();
        feito.push_back(tabuleiro);
        fazer.pop();
        int pos = feito.size()-1;
        cout << "Estado Atual: " << endl;
        imprimeTabuleiro(tabuleiro);
        //Testando se é objetivo
        if(Ehobjetivo(tabuleiro))
            cout << "Caminho percorrido:" << endl;
            Tabuleiro c = feito.back();
            imprimeTabuleiro(c);
            return 0; //depois fazer ajustes p retornar caminho
        //Gerando e incluindo sucessores na fila
        cout << "Sucessores: " << endl;
        for (int i = 0; i < 4; i++)
        {
            int pox = tabuleiro.posx + posicaox[i];
            int poy = tabuleiro.posy + posicaoy[i];
            if (validar(pox,poy))
            {
                Tabuleiro sucessor = tabuleiro; //referencia ou valor
                swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
                //atualizando a posição vazia do novo estado gerado após swap
                sucessor.posx = pox;
                sucessor.posy = poy;
                sucessor.pai = pos;
                //inserindo sucessor (novo estado, novo tabuleiro) na fila
                fazer.push(sucessor);
                imprimeTabuleiro(sucessor);
            }
        }
    }
    return 0;
}
