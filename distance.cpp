#include<vector>
#include<string>

/*
Basado en el código entregado por Vicente en laboratorio, se modificaron líneas tal que solo considere las operaciones
INSERT - DELETE, dejando fuera el SWAP
*/

using namespace std;

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