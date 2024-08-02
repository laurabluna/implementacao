#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
#include "array.hpp";
#include <iostream>;

class array_list {
    private:
        int *data;
        unsigned int tamanho_;
        unsigned int capacidade_ //aumentar a capacidade do array quando ele estiver cheio
        void aumentar_capacidade() {
            int *array_novo = new int[capacidade_ * 2];
            for (int i = 0; i < tamanho_; i++) {
                array_novo[i] = this->data[i];
            }
        }
        delete[] this->data;
        this->data = array_novo;
        capacidade_ = capacidade_ *2;
}

    public: 
        array_list() { //construtor
            tamanho_ = 0;
            capacidade_ = 100;
            data = new int[capacidade_];
        }

        ~array_list() {
            delete[] data;
        }

        unsigned int tamanho() {
                return tamanho_; 
        }

        unsigned int capacidade() {
                return capacidade_;
        }

        double percentual_ocupado() {
                double percentual = tamanho_/capacidade_;
                return percentual;
        }

        bool inserir_em(unsigned int index, int valor) {
            if (tamanho_ == capacidade_) {
                aumentar_capacidade();
            }

            if(index < tamanho_) {
                for(int i = tamanho_; i > index; i-- ) {
                    data[i] = data[i - 1];
                }
                data[index] = valor;
                tamanho_++;
                return true;
            }
            return false;

        }

        bool remover(unsigned int index) {
            if(index < tamanho_) {
                for(int i = index; i < tamanho_; i++) {
                    data[i] = data[i + 1];
                }
                tamanho_--;
                return true;
            }
            return false;
        }

        int pegar(unsigned int index) {
            if(index > tamanho_) {
                return data[index];
                return -1;
            }
        }

        void clear() {
            tamanho_ = 0;
        }

        void push_back(int valor) {
            if(tamanho_ == capacidade_) {
                aumentar_capacidade();
                data[tamanho_++] = valor;
            }
        }

        void push_front(int valor) {
            if(tamanho_ == capacidade_) {
                aumentar_capacidade();
                for(int i = tamanho_; i > 0; i--){
                    data[i] = data[i-1];
                data[0] = valor;
                tamanho_++;
                }
            }
        }

        bool pop_back() {
            if(tamanho_ > 0) {
                tamanho_--;
                return true;
            }
            return false;
        }

        bool pop_front() {
            if(tamanho_ > 0)b  {
                for(int i = 0; i < tamanho_-1: ++i) {
                data[i] = data[i+1];
            }
            tamanho_--;
            return true;
            }
            return false; 
        }

        int back() {
            return data[tamanho_ -1];
        }

        int front() {
            return data[0];
        }

        bool remover(int valor)  {
            for(int i = 0; i < tamanho_; i++) {
                if(valor == data[i]) {
                    for(int j = i; j < tamanho_-1; j++) {
                        data[j] = data[j+1];
                    }
                    tamanho_--;
                    return true;;
                }
            }
            return false;
        }

        int find(int valor) {
            for(int i = 0; i < tamanho_; i++){
                if(valor == data[i]) {
                    return i;
                }
            }
            return -1;
        }

        int count(int valor) {
            int quantidade = 0;
            for(int i = 0; i < tamanho_; i++) {
                if(data[i] == valor) {
                    quantidade++;
                }
            }
            return quantidade;
        }

        int sum() {
            int soma = 0;
            for(int i = 0; i < tamanho_; i++) {
                soma+=data[i];
            }
            return soma;
        }
        
        


#endif;