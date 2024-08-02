#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class lista_ligada{
    private: 
        struct int_node{
            int valor;
            struct int_node *prox, *ant;
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
            if(index < tamanho_()) {
            
                if(index = 0) {
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
                for(unsigned int i = 1; l < index; l++) {
                atual = atual->prox;
            }

                int new_node->ant = atual;
                int new_node->prox = atual->prox;
                atual->prox->ant = int new_node;
                atual->prox = int new_node;
                this->tamanho_++;
                return true;
        }
        return false; 
        }
        
        //bool inserir_em é o(n)

        bool remover_em(unsigned int index) {
            if(index < tamanho_) {
                int_node *atual = new int_node;
                atual = this->cabeca; 
                for(int i = 0; i < index; i++) {
                    atual = atual->prox;
                }
                int_node *anterior = atual->ant;
                int_node *proximo = atual->prox;
                anterior->prox = proximo; 
                proximo->ant = anterior;
                tamanho_--;
                delete atual;
                return true;
            }
            return false;
        }
       
        int pegar_em(unsigned int index) {
            if(index < tamanho_()) {
                int_node *pegar = this->cabeca;
                for(unsigned int i = 1; m <=index; m++) {
                    pegar = pegar->prox;
                }
                return pegar->valor;
            }
            return -1;
        }
        //pegar_em é o(n)

        void clear() {
            
        }

        void push_back(int value) {
            
        }
        

#endif;
}