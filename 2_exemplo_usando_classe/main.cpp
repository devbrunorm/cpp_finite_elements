#include <iostream>
#include <cstdio> // Biblioteca para simplificar a impressão de resultados na tela

using namespace std;

// Agora vamos usar classes para deixar ele um pouco mais simples
// Para fins didáticos, vou começar criando elas sem um método construtor

// Criando uma classe para os Nós
// Cada nó terá apenas cordenadas decimais (float) x e y
// Como não faremos operações com os nós, iremos utilizar apenas os atributos

class Node { //Declaração da Classe Node
    // Começamos sempre definindoos atributos (propriedades) da classe
    public:
        //Public apenas indica que os atributos podem ser editados por outras classes. Por agora não é relevante entender isso
        float x; //Cada atributo é definido com o tipo e o nome
        float y;
};

// Criando uma classe para os Elementos
// Cada elemento terá dois nós (Node) e uma área (float)
// Nesse caso, já teremos métodos (funções) para calcular o comprimento e o volume do elemento

class Element {
    public:
        Node node1; // Atribuição de um objeto da classe Node que definimos anteriormente
        Node node2;
        float area;

        // Com os atributos definidos, agora temos os métodos da classe, que serão os cálculos que precisaremos fazer
        // Toda função (ou nesse caso, método) em C++ começa com o tipo de retorno (void, int, float, etc)
        // Nesse caso, os métodos são do tipo float, pois retornam um valor decimal

        // Note que os métodos estão dentro da classe e não vão precisar de parâmetros, pois eles já tem acesso aos atributos da classe
        float lenght() {
            // Para acessar um atributo de um objeto, podemos adicionar um ponto (.) e o nome do atributo após o nome da variável
            // Ou seja, "node1.x" nos retornará o valor de x do node1
            return sqrt(pow(node2.x - node1.x, 2) + pow(node2.y - node1.y, 2));
        }

        float volume() {
            // Nesse caso, como a área é um atributo da classe, podemos acessá-la diretamente usando a palavra reservada "this" e o operador de seta (->)
            return this->lenght() * this->area;
        }
};

int main()
{
    //Agora vamos criar os elementos e nós de forma mais simples
    //Criando um elemento 1 com os nós 1 e 2
    Node node1;
    node1.x = 1.0; //Podemos usar o ponto (.) para editar os atributos de um objeto conforme o código ao lado
    node1.y = 2.0;

    Node node2;
    node2.x = 3.0;
    node2.y = 4.0;

    Element element1;
    element1.node1 = node1;
    element1.node2 = node2;
    element1.area = 4.0;

    printf("O elemento 1 possui volume de %.2f\n", element1.volume()); //Podemos utilizar o método invés da variável diretamente
    printf("O elemento 1 possui comprimento de %.2f\n", element1.lenght());

    //Criando um elemento 2 com os nós 3 e 4
    Node node3;
    node3.x = 5.0;
    node3.y = 6.0;

    Node node4;
    node4.x = 7.0;
    node4.y = 8.0;

    Element element2;
    element2.node1 = node3;
    element2.node2 = node4;
    element2.area = 5.0;

    printf("O elemento 2 possui volume de %.2f\n", element2.volume());
    printf("O elemento 2 possui comprimento de %.2f\n", element2.lenght());

    //Criando um elemento 3 com os nós 5 e 6
    Node node5;
    node5.x = 9.0;
    node5.y = 10.0;

    Node node6;
    node6.x = 11.0;
    node6.y = 12.0;

    Element element3;
    element3.node1 = node5;
    element3.node2 = node6;
    element3.area = 12.0;

    printf("O elemento 3 possui volume de %.2f\n", element3.volume());
    printf("O elemento 3 possui comprimento de %.2f\n", element3.lenght());

    //Note, porém, que ainda temos muita repetição no código, já que estamos criando os nós e elementos de forma manual, 
    // atribuindo os valores um a um. No próximo exemplo, vamos ver como podemos melhorar isso utilizando métodos construtores
};