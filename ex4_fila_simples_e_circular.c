/*
 * Exercicio 4 - Fila simples (letras) + Fila circular (digitos)
 * Digitos -> converte para int -> fila B (circular)
 * Letras  -> fila A (simples)
 * Outros  -> ignora
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

/* Fila A - simples de char */
char filaA[MAX];
int aInicio = 0, aFim = 0;

/* Fila B - circular de int */
int filaB[MAX];
int bInicio = 0, bFim = 0, bTamanho = 0;

int main() {
    char entrada[MAX];
    int i, len;
    char c;


    printf("Digite uma sequencia de caracteres: ");
    fgets(entrada, MAX, stdin);

    len = strlen(entrada);
    if (entrada[len - 1] == '\n')
        entrada[--len] = '\0';

    /* distribui nas filas */
    for (i = 0; i < len; i++) {
        c = entrada[i];
        if (isdigit(c)) {
            filaB[bFim] = c - '0';
            bFim = (bFim + 1) % MAX;
            bTamanho++;
        } else if (isalpha(c)) {
            filaA[aFim] = c;
            aFim++;
        }
        /* outros: ignora */
    }

    /* exibe fila B */
    printf("\nFila B (digitos): ");
    while (bTamanho > 0) {
        printf("%d ", filaB[bInicio]);
        bInicio = (bInicio + 1) % MAX;
        bTamanho--;
    }
    printf("\n");

    /* exibe fila A */
    printf("Fila A (letras): ");
    while (aInicio < aFim) {
        printf("%c ", filaA[aInicio]);
        aInicio++;
    }
    printf("\n");

    return 0;
}
