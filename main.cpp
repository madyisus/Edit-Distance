#include "distance.cpp"
#include "getBook.cpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

if (argc != 3) {
    cout << "Se requieren dos paths como argumentos." << endl;
    return 1;
}

string path1 = argv[1];     // path al primer input
string path2 = argv[2];     // path al segundo input

string book1 = readFileContent(path1);      // libro 1 completo como string
string book2 = readFileContent(path2);      // libro 2 completo como string

cout<<"Tamaño del libro 1:  "<<book1.size()<<endl;
cout<<"Tamaño del libro 2:  "<<book2.size()<<endl;

Solution2 solClasica;       // instancia del tipo de solucion clasica
Solution3 solAdaptativa;    // instancia del tipo de solucion adaptativa

int d_classic = solClasica.minDistance(book1,book2);        // calculo de la distancia usando metodo clasico
int d_adaptive = solAdaptativa.minDistance(book1,book2);        // calculo de la distnacia usando metodo adaptativo

cout<<"Distancia calculada con metodo clásico:      "<<d_classic<<endl;
cout<<"Distancia calculada con metodo adaptativo:   "<<d_adaptive<<endl;

return 0;
}