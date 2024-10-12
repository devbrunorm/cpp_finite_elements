#include <iostream>
#include <cstdio> // Biblioteca para simplificar a impressão de resultados na tela

using namespace std;

float lenght(float x1, float x2, float y1, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Estou considerando os elementos como sendo uma extrusão de uma área
// Apenas para exemplificação
float volume(float lenght, float area) {
    return lenght * area;
}

// Esse é um exemplo de como ficaria o código sem a utilização de POO
// Note que o código vai ser extramente repetivo e confuso
int main()
{
    //Criando um elemento 1 com os nós 1 e 2
    float node1_x = 1.0;
    float node1_y = 2.0;

    float node2_x = 3.0;
    float node2_y = 4.0;

    float element1_lenght = lenght(node1_x, node2_x, node1_y, node2_y);
    float element1_area = 4.0;
    float element1_volume = volume(element1_lenght, element1_area);

    printf("O elemento 1 possui volume de %.2f\n", element1_volume);
    // A notação %.2f é para imprimir apenas 2 casas decimais
    // O caracter \n é para pular uma linha
    printf("O elemento 1 possui comprimento de %.2f\n", element1_lenght);

    //Criando um elemento 2 com os nós 3 e 4
    float node3_x = 5.0;
    float node3_y = 6.0;

    float node4_x = 7.0;
    float node4_y = 8.0;

    float element2_lenght = lenght(node3_x, node4_x, node3_y, node4_y);
    float element2_area = 5.0;
    float element2_volume = volume(element2_lenght, element2_area);

    printf("O elemento 2 possui volume de %.2f\n", element2_volume);
    printf("O elemento 2 possui comprimento de %.2f\n", element2_lenght);

    //Criando um elemento 3 com os nós 5 e 6
    float node5_x = 9.0;
    float node5_y = 10.0;

    float node6_x = 11.0;
    float node6_y = 12.0;

    float element3_lenght = lenght(node5_x, node5_x, node6_y, node6_y);
    float element3_area = 12.0;
    float element3_volume = volume(element3_lenght, element3_area);

    printf("O elemento 3 possui volume de %.2f\n", element3_volume);
    printf("O elemento 3 possui comprimento de %.2f\n", element3_lenght);

};