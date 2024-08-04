#include <iostream> 
#include "arraylist.hpp"
using namespace std;

int main() {
    array_list a1;

    // Exemplo de uso dos métodos
    a1.push_back(10);
    a1.push_back(20);
    a1.push_back(30);

    cout << "Tamanho atual: " << a1.tamanho() << endl;
    cout << "Capacidade atual: " << a1.capacidade() << endl;
    cout << "Percentual ocupado: " << a1.percentual_ocupado() << endl;

    a1.push_front(5);

    cout << "Primeiro elemento: " << a1.front() << endl;

    a1.pop_back();

    cout << "Último elemento: " << a1.back() << endl;

    int valor = 20;
    if (a1.remover(valor)) {
        cout << "Valor " << valor << " removido com sucesso." << endl;
    } else {
        cout << "Valor " << valor << " não encontrado." << endl;
    }

    cout << "Índice do valor 10: " << a1.find(10) << endl;
    cout << "Quantidade de vezes que o valor 20 aparece: " << a1.count(20) << endl;
    cout << "Soma de todos os elementos: " << a1.sum() << endl;

    return 0;
}
