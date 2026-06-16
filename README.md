**# Atividade Estruturada 4 — Filas Sequenciais em C

Implementação dos quatro exercícios propostos na Atividade Estruturada 4, abordando filas sequenciais simples e filas sequenciais circulares na linguagem C.

---

## Estrutura dos arquivos

```
.
├── ex1_fila_multiplos2.c        # Fila simples — menu com múltiplos de 2
├── ex2_fila_pilha_chars.c       # Fila simples + pilha de caracteres
├── ex3_fila_circular_menu.c     # Fila circular — menu completo
└── ex4_fila_simples_e_circular.c # Duas filas: letras e dígitos
```

---

## Como compilar e executar

Todos os programas compilam com `gcc` padrão (C99 ou superior):

```bash
gcc -Wall -o ex1 ex1_fila_multiplos2.c
gcc -Wall -o ex2 ex2_fila_pilha_chars.c
gcc -Wall -o ex3 ex3_fila_circular_menu.c
gcc -Wall -o ex4 ex4_fila_simples_e_circular.c
```

Execute com:

```bash
./ex1
./ex2
./ex3
./ex4
```

---

## Descrição dos exercícios

### Exercício 1 — Fila Simples com Menu (`ex1_fila_multiplos2.c`)

Menu interativo com três opções:

| Opção | Ação |
|-------|------|
| 1 | Enfileira um número inteiro positivo |
| 2 | Desenfileira tudo e imprime apenas os múltiplos de 2 |
| 3 | Encerra o programa |

**Estrutura:** fila sequencial simples com array de inteiros, ponteiros `inicio`/`fim` e campo `tamanho`.

**Exemplo de uso:**
```
Opcao: 1 → Digite: 4   (enfileirado)
Opcao: 1 → Digite: 7   (enfileirado)
Opcao: 2 → Multiplos de 2: 4
```

---

### Exercício 2 — Fila de chars + Pilha (`ex2_fila_pilha_chars.c`)

Lê uma sequência de caracteres via `fgets`, então:

1. Enfileira todos os caracteres na fila.
2. Desenfileira um a um e empilha na pilha `P`:
   - Letras são convertidas para **minúsculas** antes de empilhar.
   - Qualquer outro caractere é empilhado sem alteração.
3. Desempilha tudo e exibe na saída padrão.

> O resultado é a sequência invertida com letras em minúsculo, pois a pilha inverte a ordem.

**Exemplo:**
```
Entrada:  aBc 3!
Saída:    !3 cba
```

---

### Exercício 3 — Fila Circular com Menu (`ex3_fila_circular_menu.c`)

Menu interativo com quatro opções, implementado com funções dedicadas de enfileirar e desenfileirar:

| Opção | Ação |
|-------|------|
| 1 | Enfileira um inteiro não nulo |
| 2 | Desenfileira um valor e exibe seu dobro |
| 3 | Desenfileira tudo e exibe os valores sem alteração |
| 4 | Encerra o programa |

**Estrutura:** fila circular com array de tamanho `MAX`, avanços feitos com `% MAX` para garantir a circularidade. O campo `tamanho` (contador) evita ambiguidade entre fila cheia e fila vazia.

**Exemplo:**
```
Opcao: 1 → 5   (enfileirado)
Opcao: 1 → -3  (enfileirado)
Opcao: 2 → Valor: 5 | Dobro: 10
Opcao: 3 → Valores: -3
```

---

### Exercício 4 — Duas Filas: Simples e Circular (`ex4_fila_simples_e_circular.c`)

Lê um vetor de caracteres e distribui em duas filas com regras distintas:

| Caractere | Destino | Transformação |
|-----------|---------|---------------|
| Dígito (`0`–`9`) | Fila B (circular de `int`) | Converte para inteiro real: `num = c - '0'` |
| Letra (`a`–`z`, `A`–`Z`) | Fila A (simples de `char`) | Sem alteração |
| Qualquer outro | — | Ignorado |

Ao final, desenfileira **B** e depois **A**, exibindo os dados.

**Estruturas:**
- `FilaA` — fila sequencial simples de `char`.
- `FilaB` — fila circular de `int` com campo `contador`.

**Exemplo:**
```
Entrada:  a3B!7z
Fila B:   3 7
Fila A:   a B z
```

---

## Conceitos aplicados

- **Fila sequencial simples:** inserção no fim, remoção no início, ponteiros avançam em uma única direção.
- **Fila sequencial circular:** ponteiros avançam com aritmética modular (`% MAX`), reaproveitando posições liberadas no início do array.
- **Pilha (LIFO):** usada no exercício 2 para inverter a ordem dos caracteres.
- **Funções auxiliares:** `inicializar`, `estaVazia`, `estaCheia`, `enfileirar`, `desenfileirar`, `empilhar`, `desempilhar` — cada estrutura encapsulada em seu próprio conjunto de funções.
- **Manipulação de caracteres:** uso das funções `isdigit`, `isalpha` e `tolower` da biblioteca `<ctype.h>`.

---

## Disciplina

Estruturas de Dados — Atividade Estruturada 4
**
