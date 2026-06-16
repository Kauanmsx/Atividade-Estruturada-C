/*
 * Exercicio 3 - Fila Circular
 * Menu: enfileirar nao nulo, dobro de um, exibir tudo, terminar.
 */

#include <stdio.h>

#define MAX 10

int fila[MAX];
int inicio = 0, fim = 0, tamanho = 0;

void enfileirar(int valor) {
    if (tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    fila[fim] = valor;
    fim = (fim + 1) % MAX;
    tamanho++;
    printf("Valor %d enfileirado.\n", valor);
}

int desenfileirar(int *valor) {
    if (tamanho == 0) return 0;
    *valor = fila[inicio];
    inicio = (inicio + 1) % MAX;
    tamanho--;
    return 1;
}

int main() {
    int opcao, valor;

    do {
        printf("\n=== MENU - FILA CIRCULAR ===\n");
        printf("1. Enfileirar um valor inteiro nao nulo\n");
        printf("2. Desenfileirar um valor e exibir seu dobro\n");
        printf("3. Desenfileirar tudo e exibir os valores\n");
        printf("4. Terminar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite um inteiro nao nulo: ");
            scanf("%d", &valor);
            if (valor == 0)
                printf("Valor nulo nao permitido.\n");
            else
                enfileirar(valor);

        } else if (opcao == 2) {
            if (tamanho == 0)
                printf("Fila vazia!\n");
            else {
                desenfileirar(&valor);
                printf("Valor: %d | Dobro: %d\n", valor, valor * 2);
            }

        } else if (opcao == 3) {
            if (tamanho == 0)
                printf("Fila vazia!\n");
            else {
                printf("Valores: ");
                while (desenfileirar(&valor))
                    printf("%d ", valor);
                printf("\n");
            }

        } else if (opcao == 4) {
            printf("Encerrando.\n");

        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}
