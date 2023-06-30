#include <iostream>
#include <fstream>
#include <string>

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

