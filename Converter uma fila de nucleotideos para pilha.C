#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NO {
    char dado;
    struct NO* prox;
} NO;

typedef struct FILA {
    NO* inicio;
    NO* fim;
} FILA;

typedef struct PILHA {
    NO* topo;
} PILHA;

FILA f;
PILHA p;

void inserirFila(char nucleotideo) {
    NO* ptr = (NO*)malloc(sizeof(NO));
    ptr->dado = nucleotideo;
    ptr->prox = NULL;
    if (f.inicio == NULL)
        f.inicio = ptr;
    else
        f.fim->prox = ptr;
    f.fim = ptr;
}

int removerFila() {
    NO* ptr = f.inicio;
    char dado;
    if (ptr != NULL) {
        f.inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }

    return 0;
}

void inserirPilha(char nucleotideo) {
    NO* ptr = (NO*)malloc(sizeof(NO));
    ptr->dado = nucleotideo;
    ptr->prox = p.topo;
    p.topo = ptr;
}

char imprimirFila() {
    NO* ptr = f.inicio;
    printf("Fila: ");
    while (ptr != NULL) {
        printf("%c", ptr->dado);
        ptr = ptr->prox;
    }

    printf("\n");
}

void imprimirPilha() {
    NO* ptr = p.topo;
    printf("Pilha: ");
    while (ptr != NULL) {
        printf("%c", ptr->dado);
        ptr = ptr->prox;
    }

    printf("\n");
}

int main() {
    char sequencia[100];
    printf("Insira a sequência de nucleotídeos:\n");
    scanf("%s", sequencia);

    int i;
    for (i = 0; i < strlen(sequencia); i++) {
        inserirFila(sequencia[i]);
    }

    imprimirFila();
    
    while (f.inicio != NULL) {
        char nucleotideo = removerFila();
        if (nucleotideo == 'A')
            inserirPilha('T');
        else if (nucleotideo == 'C')
            inserirPilha('G');
        else if (nucleotideo == 'T')
            inserirPilha('A');
        else if (nucleotideo == 'G')
            inserirPilha('C');
    }

    imprimirPilha();

    return 0;
}
