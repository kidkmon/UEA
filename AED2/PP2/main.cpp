#include <iostream>
#include <iomanip>

using namespace std;

class Grafo{
private:
    float **matriz;
    float ordem, tamanho;
    void inicializador();
public:
    Grafo(int);
    void inserirAresta(int,int,float);
    void print();
};

int main() {

    Grafo g(5);

    g.inserirAresta(1,2,2);
    g.inserirAresta(2,3,2);
    g.inserirAresta(3,4,3);
    g.inserirAresta(4,5,4);
    g.inserirAresta(5,1,5);

    g.print();

    return 0;
}

//Início do Grafo
Grafo::Grafo(int ordem){
    this->ordem = ordem;
    matriz = new float*[ordem+1];
    for(int i = 1; i <= ordem; i++){ matriz[i] = new float[ordem+1]; }
    inicializador();
}

void Grafo::inicializador(){
    for(int i = 1;i <= ordem; i++){
        for(int j = 1; j <= ordem; j++){
            matriz[i][j] = 0;
        }
    }
}

void Grafo::inserirAresta(int u, int v, float peso){
    matriz[u][v] = peso;
    matriz[v][u] = peso;
    tamanho++;
}

void Grafo::print(){
    int k = 3;
    cout << " ";
    for(int j = 1; j <= ordem; j++){ cout << setw(k) << j; }
    cout << endl;
    for(int j = 1; j <= ordem*k + 3; j++){ cout << "-"; }
    cout << endl;
    for(int i = 1; i <= ordem; i++){
        cout << setw(1) << i; cout << " |";
        for(int j = 1; j <= ordem; j++){
            cout << setw(k) << matriz[i][j];
        }
        cout << endl;
    }
}