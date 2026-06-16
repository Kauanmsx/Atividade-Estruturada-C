/*
 * Exercicio 1 - Fila Sequencial Simples
 * Menu: enfileirar inteiro positivo, desenfileirar multiplos de 2, terminar.
 */

#include <stdio.h>

#define MAX 100

int fila[MAX];
int inicio = 0;
int fim = 0;

int main() {
    int opcao, valor;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Enfileirar um numero inteiro positivo\n");
        printf("2. Desenfileirar tudo e imprimir multiplos de 2\n");
        printf("3. Terminar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite um inteiro positivo: ");
            scanf("%d", &valor);
            if (valor <= 0) {
                printf("Valor invalido!\n");
            } else if (fim >= MAX) {
                printf("Fila cheia!\n");
            } else {
                fila[fim] = valor;
                fim++;
                printf("Valor %d enfileirado.\n", valor);
            }

        } else if (opcao == 2) {
            if (inicio == fim) {
                printf("Fila vazia!\n");
            } else {
                printf("Multiplos de 2: ");
                while (inicio < fim) {
                    valor = fila[inicio];
                    inicio++;
                    if (valor % 2 == 0)
                        printf("%d ", valor);
                }
                printf("\n");
            }

        } else if (opcao == 3) {
            printf("Encerrando.\n");

        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}
