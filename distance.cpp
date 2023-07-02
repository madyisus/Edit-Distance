#include<vector>
#include<string>
#include <iostream>

/*
Basado en el código entregado por Vicente en laboratorio, se modificaron líneas tal que solo considere las operaciones
INSERT - DELETE, dejando fuera el REPLACE
*/

using namespace std;

/*
----------Solución clásica usando recursividad------------
*/
class Solution1{
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return solve(0, 0, word1, word2);
    }
    int solve(int i, int j, const string &word1, const string &word2) {
        if (i >= word1.size() || j >= word2.size())
            return (word2.size() - j) + (word1.size() - i);
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(i+1, j+1, word1, word2);

        int insert = 1 + solve(i, j+1, word1, word2);
        int dlete = 1 + solve(i+1, j, word1, word2);

        return dp[i][j] = min(insert, dlete);
    }
};

/*
------------Solución clásica usando iteraciones--------------
*/
class Solution2{
public:
  int minDistance(string word1, string word2) {
      int m = word1.size();                     // tamaño palabra source
      int n = word2.size();                     // tamaño palabra target
      int dp[m+1][n+1];                         // matrix de tamaño (m+1)(n+1)
      for(int i = 0; i <= m; i++) dp[i][0] = i; // llena la primera columna con el rango (0,m-1)
      for(int j=0; j <= n; j++) dp[0][j] = j;   // llena la primera fila con el rango (0,n-1)
      
      for(int i = 1; i <= m; i++)               // itera sobre cada elemento de la matriz
        for(int j = 1; j <= n; j++){            // de izquierda a derecha, arriba-abajo
          if(word1[i-1] == word2[j-1])          // si los simbolos coinciden, se toma el mismo de la diagonal
            dp[i][j] = dp[i-1][j-1];            // de arriba-izquierda
          else{
            dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]); // si los simbolos no coinciden, se toma el minimo entre las casillas contiguas a la izquierda y arriba
          }
        }
    return dp[m][n];                            // devuelve la solución al problema de mayor tamaño (m x n)
  }

};

/*
---------------------------Solución adaptativa----------------------------
Este algoritmo fue pensado y trabajado junto a mi compañero Mario Aguilera 

*/
class Solution3{
public:
    int verifica(string word1, string word2, int D){

        int m = word1.length();     // tamaño de del string source (m) y target (n)
        int n = word2.length();
  
        // Incluso en el mejor caso, la distancia d entre 2 palabras será no menor a |m-n|
        if (abs(m - n) > D) {
            return m + n + 1;
        }

        // Ajuste conveniente, para trabajar siempre con una matriz de proporcion similar
        // cuando no es cuadrada
        if (m > n) {
            swap(word1, word2);
            swap(m, n);
            }
        
        // Inicializamos la matriz de tamaño (m+1)(n+1)
        int dp[m+1][n+1];

        // Se inicializan los valores de las "paredes" del corredor de ancho 2D, y
        // las primeras D celdas de la primera fila y columna
        for(int i = 0; i <= m; i++){    // O(m)
            dp[i][max(0,i-D-1)] = i;
        } 
  
        for(int i=0; i <= n; i++){      // O(n)
            dp[max(0,i-D-1)][i] = i;    
        } 

        // Se calculan solo los valores dentro del corredor, con el mismo algoritmo
        // utilizado en el método clásico (para INSERT-DELETE)
        for (int i = 1; i <= m; i++) {
            for (int j = max(1,i-D); j <=min(n,i+D); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; 
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);

                }
            }
        }

        if(dp[m][n] <= D){      // devolvemos el d obtenido si es menor o igual a D
            return dp[m][n];
        }
        return (m + n + 1);     // devolvemos (m+n+1) si es mayor a D
                return 0;
            };

    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();

        int iter=1;
        int result;

        while(iter<=m+n){   // llamamos a verifica para D = 2^i, i in [0,1,2,3,...,log2(d)]

            result = verifica(word1,word2,iter);
  
            if(result < m+n+1){     // si obtenemos un valor menor a D, devuelve ese valor
            // cout<<"Distancia encontrada para D = "<<iter<<endl;
            return result;
            }
            if(iter*2>m+n){     // si la siguiente iteración escapa del límite m+n, fija iter = m+n
            iter = m+n;
            }else{
            iter=iter*2;    // doblamos iter para la siguiente llamada
            }
        }
        return n+m;
    }
};