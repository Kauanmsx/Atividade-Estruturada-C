/*
 * Exercicio 2 - Fila de chars + Pilha
 * Enfileira chars, desenfileira para pilha (letras viram minusculas),
 * desempilha e exibe.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

/* fila */
char fila[MAX];
int fInicio = 0, fFim = 0;

/* pilha */
char pilha[MAX];
int topo = -1;

int main() {
    char entrada[MAX];
    int i, len;
    char c;

    printf("Digite uma sequencia de caracteres: ");
    fgets(entrada, MAX, stdin);

    len = strlen(entrada);
    if (entrada[len - 1] == '\n')
        entrada[--len] = '\0';

    /* enfileira tudo */
    for (i = 0; i < len; i++) {
        fila[fFim] = entrada[i];
        fFim++;
    }

    /* desenfileira e empilha */
    while (fInicio < fFim) {
        c = fila[fInicio];
        fInicio++;
        if (isalpha(c))
            c = tolower(c);
        topo++;
        pilha[topo] = c;
    }

    /* desempilha e exibe */
    printf("Resultado: ");
    while (topo >= 0) {
        putchar(pilha[topo]);
        topo--;
    }
    printf("\n");

    return 0;
}
