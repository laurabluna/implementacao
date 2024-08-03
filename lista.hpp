#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class lista_ligada{
    private: 
        struct int_node{
            int valor;
            int_node *prox, *ant;
        };

        int_node *cabeca, *calda;
        unsigned int tamanho_;

    public: 
        //aqui irei fazer o construtor
        lista_dup() {
            this->cabeca = nullptr;
            this->calda = nullptr;
            this->tamanho_ = 0;
  
      } //lista_dup é o(1)

        lista_dup() {
            clear();
        }
        //clear é o(n)
        
        unsigned int tamanho_() {
            return tamanho_;
        }
        // tamanho é o(1)

        unsigned int capacidade_(){
            return tamanho_;
        }

        double percentual_ocupado() {
            return 1.0;
        }

        bool inserir_em(unsigned int index, int valor) {
            if(index > tamanho_()) {
                return false;
            }
                if(index == 0) {
                push_front(valor);
                return true;    
            }

                if(index == (tamanho_() - 1)){
                push_back(valor);
                return true;
            }

                int_node *new_node = new int_node;
                new_node->valor = valor;
                int_node *atual = this->cabeca;
                for(unsigned int i = 1; i < index; i++) {
                atual = atual->prox;
            }

                new_node->ant = atual;
                new_node->prox = atual->prox;
                if(atual > prox) {
                   atual->prox->ant = new_node;
                }
                atual->prox = new_node;
                this->tamanho_++;
                return true;
        }
        return false; 
        }
        
        //bool inserir_em é o(n)

        bool remover_em(unsigned int index) {
        if (index >= tamanho_) {
            return false;
        }

        int_node *atual = this->cabeca;
        for (unsigned int i = 0; i < index; i++) {
            atual = atual->prox;
        }

        int_node *anterior = atual->ant;
        int_node *proximo = atual->prox;
        if (anterior) {
            anterior->prox = proximo;
        } else {
            this->cabeca = proximo;
        }
        if (proximo) {
            proximo->ant = anterior;
        } else {
            this->calda = anterior;
        }

        delete atual;
        this->tamanho_--;
        return true;
    }
       
        int pegar_em(unsigned int index) {
            if(index >= tamanho_()) {
                 return -1;
        }
            int_node *pegar = this->cabeca;
            for(int i = 0; i < index; i++) {
                pegar = pegar->prox;
            }
            return pegar->valor;
            }
            
        
        //pegar_em é o(n)

        void clear() {
            int_node *atual   = this->cabeca;
            while(atual!= nullptr) {
                int_node *remover = atual;
                atual = atual->prox;
                delete remover;
            }
            cabeca = nullptr;
            calda = nullptr;
            tamanho_ = 0;

        }

        void push_back(int valor) {
            int_node *new_valor = new int_node;
            new_node->value = valor;
            new_node->prox = nullptr;
            new_node->ant = this->calda;
            if(this-> cabeca == nullptr) {
                this->cabeca == new_valor;
            }
            else {
                this->calda->prox = new_valor;
            }
            this->calda = new_valor;
            this->tamanho++;
        }
        //push_back é o(1)
        void push_front(int valor) {
            int_node* = new_node = new int_node;
            new_node->valor = valor;
            ñew_node->prox = this->cabeca;
            new_node->ant = nullptr;
            if(this->cabeca == nullptr) {
                this->calda = new_node;
            }
            else{
                this->cabeca->ant = new_node;
            }
            this->cabeca = new_node;
            this->tamanho_++;
    
        }
        //push front é o(1)
        
        bool pop_back{
            if(this->cabeca) {
                if(tamanho_() == 1) {
                    delete cabeca;
                    cabeca = nullptr;
                    calda = nullptr;
                    this->tamanho_--;
                    return true;
                }
                int_node *remover = this->calda;
                this->calda = this->calda->ant;
                this->calda->prox = nullptr;
                delete remover;
                this->tamanho_--;
                return true;
            }
            return false;
            //pop_back é o(1)
        }

        bool pop_front() {
            if(tamanho_ > 1) {
                int_node *apagar;
                apagar = this->cabeca;
                this->cabeca = this->cabeca->prox;
                delete apagar;
                this->cabeca->ant = nullptr;
                tamanho_--;
                return true; 
            }
            if(cabeca == calda) {
                delete cabeca;
                cabeca = nullptr;
                calda = nullptr;
                tamanho_ = 0;
                return true;
            }
            return false;
        }
        //pop_front é o(1)

        int back(){
            return this->calda->valor;
        }
        //back é o(1)
        
        int front() {
            return this->cabeca->valor;
        }
        //front é o(1)

        bool remove(int valor) {
            int_node *node;
            node = this->cabeca;
            for(int i = 0; i<tamanho_; i++) {
                if(node->valor == valor) {
                    int_node *anterior = no->ant;
                    int_node *proximo = no->prox;
                    anterior->prox = proximo;
                    proximo->ant = anterior;
                    tamanho_--;
                    delete node;
                    return true;
                }
                node = node->prox;
            }
            return false;
        }
        //bool_remove é o(n)

        int find(int valor) {
            int_node *node = this->cabeca;
            for(int i = 0; i < tamanho_; i++) {
                if(node->valor == valor) {
                    return i;
                }
                else{
                    node = node->prox;
                }
                return -1
            }
        }
        //int find é o(n)

        int count(int valor) {
            int quantidade = 0;
            int_node *node = this->cabeca;
            for(int i = 0; i < tamanho_; i++) {
                if(node->valor == valor) {
                    quantidade++
                    node = node->prox;
                }

            }
            return quantidade;
        }
        //int count é o(n)

        int soma() {
            int soma = 0;
            int_node *node = this->cabeca;
            for(int i = 0; i < tamanho_(); i++) {
                soma += node->valor;
                node = node->prox;
            }
            return soma;
        }
        //int soma é o(n)
#endif;
}