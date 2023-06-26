#include "distance.cpp"
#include <iostream>

using namespace std;

int main(){

string source;
string target;

source = "mamifero";
target = "mamal";

Solution2 solClasica;
int distance = solClasica.minDistance(source,target);

cout<<"Distance between "<<source<<" and "<<target<<": "<<distance<<endl;
return 0;
}