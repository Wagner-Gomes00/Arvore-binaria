#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

int buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    
    if (raiz->valor == valor) {
        return 1;
    }
    
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

void exibirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

void imprimirArvore(No* raiz, int espaco) {
    if (raiz == NULL) {
        return;
    }
    
    espaco += 5;
    imprimirArvore(raiz->direita, espaco);
    printf("\n");
    for (int i = 5; i < espaco; i++) {
        printf(" ");
    }
    printf("%d", raiz->valor);
    imprimirArvore(raiz->esquerda, espaco);
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    No* raiz = NULL;
    int opcao;
    int valor;
    
    do {
        printf("\n==== MENU ====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Exibir em Ordem\n");
        printf("4 - Exibir Arvore\n");
        printf("5 - Reiniciar Arvore\n");
        printf("0 - Sair\n");
        
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                printf("Valor inserido!\n");
                break;
            
            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor)) {
                    printf("Valor encontrado\n");
                } else {
                    printf("Valor não encontrado\n");
                }
                break;
            
            case 3:
                printf("Impressao em ordem\n");
                exibirEmOrdem(raiz);
                printf("\n");
                break;
            
            case 4:
                printf("Impressao em Arvore\n");
                imprimirArvore(raiz, 0);
                printf("\n");
                break;
            
            case 5:
                liberarArvore(raiz);
                raiz = NULL;
                printf("Arvore reiniciada!\n");
                break;
            
            case 0:
                printf("Fim do programa!\n");
                break;
            
            default:
                printf("Opção inválida!\n");
                break;
            
        }
    } while (opcao != 0);
    liberarArvore(raiz);
}