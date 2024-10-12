#include <iostream>
#include <cstdio> // Biblioteca para simplificar a impressão de resultados na tela

using namespace std;


class Node {
    public:
        float x;
        float y;
        // Em C++, definimos um método construtor com o mesmo nome da classe e sem atribuir um tipo de retorno
        Node(float x, float y) {
            this->x = x;
            this->y = y;
        }
};

class Element {
    public:
        Node node_i; //Decidi trocar o nome dos atributos para que eles tenham um significado mais claro
        Node node_f; //i para início e f para final
        float area;

        // Como boa prática, sempre definimos o método construtor primeiro
        // Já que o método construtor é chamado toda vez que um objeto da classe é criado
        Element(Node node1, Node node2, float area): //Passamos os parâmetros que precisamos para a classe
            node_i(node1), node_f(node2), area(area) {}; //E aqui definimos para qual atributo cada parâmetro será atribuído, sem termos que usar o this como na classe Node

        float lenght() {
            return sqrt(pow(node_f.x - node_i.x, 2) + pow(node_f.y - node_i.y, 2));
        }

        float volume() {
            return this->lenght() * this->area;
        }
};

int main()
{
    //Note como agora conseguimos economizar linhas de código
    //Criando um elemento 1 com os nós 1 e 2

    Node node1(1.0, 2.0); //Agora podemos criar um nó com os valores de x e y diretamente na criação
    Node node2(3.0, 4.0);

    Element element1(node1, node2, 4.0); //E o mesmo para o elemento

    printf("O elemento 1 possui volume de %.2f\n", element1.volume()); //Podemos utilizar o método invés da variável diretamente
    printf("O elemento 1 possui comprimento de %.2f\n", element1.lenght());

    //Criando um elemento 2 com os nós 3 e 4
    Node node3(5.0, 6.0);
    Node node4(7.0, 8.0);


    Element element2(node3, node4, 5.0);

    printf("O elemento 2 possui volume de %.2f\n", element2.volume());
    printf("O elemento 2 possui comprimento de %.2f\n", element2.lenght());

    //Criando um elemento 3 com os nós 5 e 6
    Node node5(9.0, 10.0);
    Node node6(11.0, 12.0);

    Element element3(node5, node6, 12.0);

    printf("O elemento 3 possui volume de %.2f\n", element3.volume());
    printf("O elemento 3 possui comprimento de %.2f\n", element3.lenght());
};