#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

string readFileContent(const string& filePath) {
    ifstream file(filePath);
    string content;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo: " << filePath << endl;
    }

    return content;
}

template<typename T>
double execTimeForKAttempts(T& distance_func, string word1, string word2,int K){

    double totalTime = 0;
    for(int i = 0; i < K; i++){
        auto startTime = std::chrono::high_resolution_clock::now();
        
        // Llamar a la función a medir
        auto distance = distance_func.minDistance(word1,word2);
        
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds> (endTime - startTime).count();

        totalTime += duration/K;
    }
    return totalTime/K;
}
