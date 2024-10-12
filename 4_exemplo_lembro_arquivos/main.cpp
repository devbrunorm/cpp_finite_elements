#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// O arquivo texto vai ter a seguinte estrutura:
// Uma linha com o texto Nodes
// Uma sequência de linhas com os valores de x e y dos nós separados por vírgula (x,y)
// Depois uma linha com o texto Areas, indicando o fim dos nós e começos dos valores das áreas
// Para cada linhas de área, deve haver 2 de nós
// Qualquer dúvida, observar o arquivo exemplo.txt

// As classes se mantêm as mesmas. Só vamos alterar o código na função main
class Node {
    public:
        float x;
        float y;
        Node(float x, float y) {
            this->x = x;
            this->y = y;
        }
};

class Element {
    public:
        Node node_i;
        Node node_f;
        float area;

        Element(Node node1, Node node2, float area):
            node_i(node1), node_f(node2), area(area) {};

        float lenght() {
            return sqrt(pow(node_f.x - node_i.x, 2) + pow(node_f.y - node_i.y, 2));
        }

        float volume() {
            return this->lenght() * this->area;
        }
};

// Vou criar uma função para ajudar a converter as linhas de texto com vírgula para um array de floats
std::vector<float> splitStringToFloats(const std::string& str) {
    std::vector<float> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, ',')) {
        result.push_back(std::stof(item));
    }

    return result;
}

int main()
{
    // Tenta ler o arquivo e se não conseguiir, devolve um erro
    std::ifstream file("exemplo.txt");
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 0;
    }

    std::vector<std::vector<float>> nodes; // Array/vetor de nós (cada nó será um vetor de 2 floats)
    std::vector<float> areas; // Array/vetor de áreas
    std::string line; // Linha atual do arquivo texto

    bool inNodesSection = false;
    bool inAreasSection = false;

    while (std::getline(file, line)) {
        if (line == "Nodes") {
            inNodesSection = true;
            inAreasSection = false;
            continue;
        }
        if (line == "Areas") {
            inNodesSection = false;
            inAreasSection = true;
            continue;
        }
        if (inNodesSection) {
            vector<float> node = splitStringToFloats(line);
            nodes.push_back(node);
        }
        if (inAreasSection) {
            areas.push_back(std::stof(line));
        }
    }

    file.close();

    int counter = 0;
    for (const auto& area : areas) {
        Node node1(nodes[2*counter][0], nodes[2*counter][1]); // Pega o nó 1. Como começamos a contar do 0, multiplicamos por 2 o número da linha
        Node node2(nodes[2*counter+1][0], nodes[2*counter+1][1]); // Pega o nó 2. Como começamos a contar do 0, multiplicamos por 2 o número da linha e somamos 1
        Element element(node1, node2, area);
        counter++;
        printf("Elemento %d: Volume = %.2f, Comprimento = %.2f\n", counter, element.volume(), element.lenght());
    }   
};