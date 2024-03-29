#include <iostream>

using namespace std;

typedef struct No{
    int chave;
    struct No *prox;
    struct No *ant;
}No;

typedef struct Lista{
    int n;
    No *cabeca;
}Lista;

No* criarNo(int chave){
    No *novo_no = new No;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
    novo_no->chave = chave;
    return novo_no;
}

Lista* criarListaVazia(){
    Lista *nova_lista = new Lista;
    nova_lista->cabeca = NULL;
    nova_lista->n = 0;
    return nova_lista;
}

void adicionaListaCauda(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        lista->cabeca->prox = lista->cabeca;
        lista->cabeca->ant = lista->cabeca;
    }else{
        No *cauda = lista->cabeca;
        for (int i = 0 ; i < ((lista->n)-1); i++) {
            cauda = cauda->prox;
        }
        no_adc->ant = cauda;
        cauda->prox = no_adc;
        no_adc->prox = lista->cabeca;
        lista->cabeca->ant = no_adc;
    }
    lista->n += 1;
}

No* copiaNo(No *no){
    No *copia = criarNo(no->chave);
    return copia;
}

void adicionaListaCabeca(Lista *lista, No *no_adc){
    if (lista->cabeca == NULL){
        lista->cabeca = no_adc;
        no_adc->prox = lista->cabeca;
        no_adc->ant = lista->cabeca;
    }else{
        No *aux;
        aux = lista->cabeca;
        for (int cont = 0; cont < lista->n-1; cont++) {
            aux = aux->prox;
        }
        aux->prox = no_adc;
        lista->cabeca->ant = no_adc;
        no_adc->prox = lista->cabeca;
        no_adc->ant = aux;
        lista->cabeca = no_adc;

    }
    lista->n += 1;
}

void removerNoN(Lista *lista, int no_remover){
        if(no_remover == 0){
            cout<<"Nao pode remover a cabeca da lista" <<endl;
        }else{
            No *aux = lista->cabeca;
            for (int cont = 0; cont < no_remover; cont++) {
                aux = aux->prox;
            }
            No *no_ant = aux->ant;
            No *no_prox = aux->prox;
            no_ant->prox = no_prox;
            no_prox->ant = no_ant;
            lista->n -= 1;
        }
}

No* criancaVencedora(Lista* lista){
    lista->n -= 1;//para nao contar com a cabeca
    int n_remover = -1;
    while(lista->n > 1){
        cout << "Qual crianca quer remover?" <<endl;
        cin >> n_remover;
        while(n_remover < 0){
            cout << "Qual crianca quer remover?" <<endl;
            cin >> n_remover;
        }
        if(n_remover > lista->n){
            cout <<"Nó nao pode ser removido.Tente novamente"<<endl;
        }else{
            removerNoN(lista,n_remover);
        }

    }
    return lista->cabeca->prox;
}


int main()
{
        No* vencedor = NULL;

        No *no1 = criarNo(-1);
        No *no2 = criarNo(1);
        No *no3 = criarNo(2);
        No *no4 = criarNo(3);
        No *no5 = criarNo(4);
        No *no6 = criarNo(5);
        No *no7 = criarNo(6);

        Lista *lista1 = criarListaVazia();

        adicionaListaCauda(lista1,no1);
        adicionaListaCauda(lista1,no2);
        adicionaListaCauda(lista1,no3);
        adicionaListaCauda(lista1,no4);
        adicionaListaCauda(lista1,no5);
        adicionaListaCauda(lista1,no6);
        adicionaListaCauda(lista1,no7);

        vencedor = criancaVencedora(lista1);

        cout <<"Crianca vencedora:" <<vencedor->chave << endl;

    return 0;
}
