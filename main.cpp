#include "distance.cpp"
#include "stuff.cpp"
#include <iostream>
#include <fstream>

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

book1 = book1.substr(0,1200);
book2 = book2.substr(0,1);

// cout<<"Tamaño del libro 1:  "<<book1.length()<<" --> "<<sizeof(string) + book1.length()<<" bytes en memoria."<<endl;
// cout<<"Tamaño del libro 2:  "<<book2.length()<<" --> "<<sizeof(string) + book2.length()<<" bytes en memoria."<<endl;

Solution2 solClasica;       // instancia del tipo de solucion clasica
Solution3 solAdaptativa;    // instancia del tipo de solucion adaptativa

auto time1 = execTimeForKAttempts(solClasica,book1,book2,20);
auto time2 = execTimeForKAttempts(solAdaptativa,book1,book2,20);

// imprime solClasica - solAdaptativa 
cout<<time1<<","<<time2<<","<<solClasica.minDistance(book1,book2)<<","<<solAdaptativa.minDistance(book1,book2)<<endl;

return 0;
}