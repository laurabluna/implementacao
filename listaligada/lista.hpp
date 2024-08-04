#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class lista_ligada {
private:
    struct int_node {
        int valor;
        int_node *prox, *ant;
    };

    int_node *cabeca, *calda;
    unsigned int tamanho_;

public:
    lista_ligada() {
        this->cabeca = nullptr;
        this->calda = nullptr;
        this->tamanho_ = 0;
    }
//lista ligada é o(1)
    ~lista_ligada() {
        clear();
    }
//~lista ligada é o(n)
    unsigned int tamanho() {
        return tamanho_;
    }
//tamanho é o(1)
    double percentual_ocupado() {
        return 1.0;
    }
//percentual é o(1)
    bool inserir_em(unsigned int index, int valor) {
        if (index > tamanho_) {
            return false;
        }

        if (index == 0) {
            push_front(valor);
            return true;
        }

        if (index == tamanho_) {
            push_back(valor);
            return true;
        }

        int_node *new_node = new int_node;
        new_node->valor = valor;

        int_node *atual = cabeca;
        for (unsigned int i = 0; i < index - 1; i++) {
            atual = atual->prox;
        }

        new_node->ant = atual;
        new_node->prox = atual->prox;
        if (atual->prox) {
            atual->prox->ant = new_node;
        }
        atual->prox = new_node;

        tamanho_++;
        return true;
    }
//inserir em é o(n)
    bool remover_em(unsigned int index) {
        if (index >= tamanho_) {
            return false;
        }

        int_node *atual = cabeca;
        for (unsigned int i = 0; i < index; i++) {
            atual = atual->prox;
        }

        if (atual->ant) {
            atual->ant->prox = atual->prox;
        } else {
            cabeca = atual->prox;
        }

        if (atual->prox) {
            atual->prox->ant = atual->ant;
        } else {
            calda = atual->ant;
        }

        delete atual;
        tamanho_--;
        return true;
    }
//remover em é o(n)
    int pegar_em(unsigned int index) {
        if (index >= tamanho_) {
            return -1;
        }

        int_node *pegar = cabeca;
        for (unsigned int i = 0; i < index; i++) {
            pegar = pegar->prox;
        }

        return pegar->valor;
    }
//pegar em é o(n)
    void clear() {
        int_node *atual = cabeca;
        while (atual != nullptr) {
            int_node *remover = atual;
            atual = atual->prox;
            delete remover;
        }
        cabeca = nullptr;
        calda = nullptr;
        tamanho_ = 0;
    }
//clear é o(n)
    void push_back(int valor) {
        int_node *new_node = new int_node;
        new_node->valor = valor;
        new_node->prox = nullptr;
        new_node->ant = calda;

        if (cabeca == nullptr) {
            cabeca = new_node;
        } else {
            calda->prox = new_node;
        }

        calda = new_node;
        tamanho_++;
    }
//push_back é o(1)
    void push_front(int valor) {
        int_node *new_node = new int_node;
        new_node->valor = valor;
        new_node->prox = cabeca;
        new_node->ant = nullptr;

        if (cabeca == nullptr) {
            calda = new_node;
        } else {
            cabeca->ant = new_node;
        }

        cabeca = new_node;
        tamanho_++;
    }
//push_front é o(1)
    bool pop_back() {
        if (!cabeca) {
            return false;
        }

        if (tamanho_ == 1) {
            delete cabeca;
            cabeca = nullptr;
            calda = nullptr;
            tamanho_--;
            return true;
        }

        int_node *remover = calda;
        calda = calda->ant;
        calda->prox = nullptr;
        delete remover;
        tamanho_--;
        return true;
    }
//pop back é o(1)
    bool pop_front() {
        if (tamanho_ == 0) {
            return false;
        }

        int_node *apagar = cabeca;
        cabeca = cabeca->prox;
        delete apagar;

        if (cabeca) {
            cabeca->ant = nullptr;
        } else {
            calda = nullptr;
        }

        tamanho_--;
        return true;
    }
//pop_front é o(1)
    int back() {
        return calda->valor;
    }
//back é o(1)
    int front() {
        return cabeca->valor;
    }
//front é o(1)
    bool remove(int valor) {
        int_node *node = cabeca;
        while (node != nullptr) {
            if (node->valor == valor) {
                if (node->ant) {
                    node->ant->prox = node->prox;
                } else {
                    cabeca = node->prox;
                }

                if (node->prox) {
                    node->prox->ant = node->ant;
                } else {
                    calda = node->ant;
                }

                delete node;
                tamanho_--;
                return true;
            }
            node = node->prox;
        }
        return false;
    }
//bool remove é o(n)
    int find(int valor) {
        int_node *node = cabeca;
        for (int i = 0; i < tamanho_; i++) {
            if (node->valor == valor) {
                return i;
            }
            node = node->prox;
        }
        return -1;
    }
//find é o(n)
    int count(int valor) {
        int quantidade = 0;
        int_node *node = cabeca;
        while (node != nullptr) {
            if (node->valor == valor) {
                quantidade++;
            }
            node = node->prox;
        }
        return quantidade;
    }
//count é o(n)
    int soma() {
        int soma = 0;
        int_node *node = cabeca;
        while (node != nullptr) {
            soma += node->valor;
            node = node->prox;
        }
        return soma;
    }
//soma é o(n)
};

#endif // __LINKED_LIST_IFRN__
