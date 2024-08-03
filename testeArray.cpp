#include <iostream> 
#include "array.hpp"

using namespace std;

int main() {
    array_list a1;
    cout <<"tamanho inicial do array é:" << a1.tamanho_() <<endl;

    for(int i = 0; i < 10; i++) {
        a1.push_back(i + 1); 
    }

    for(int i = 0; i < 10; i++) {
        cout << a1.pegar_em(i) << " "; << endl;
    }

    cout << "o tamanho atual do array é:" << a1.tamanho() << endl;
    cout << "a capacidade atual do array é:" << a1.capacidade() << endl;
    cout << "a porcentagem ocupada do array é:" << a1.percentual_ocupado() << endl;

    array a2;
    for(int l = 10; l < 20; l++) {
        a2.push_back(l+1);
    }
    for(int m = 10; m > 0; m--) {
        a2.push_front(m);
    }
    for(int i = 0; i < 12.tamanho()i++) {
        cout << a2.pegar_em(i) << " " << endl;
        a2.inserir_em(4, 84123);
    }

}