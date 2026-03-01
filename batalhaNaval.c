#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ===============================
    // 1. DECLARAÇÃO DO TABULEIRO
    // ===============================

    int tabuleiro[TAM][TAM];

    // Inicializa com água (0)
    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // ===============================
    // 2. POSICIONAMENTO DOS NAVIOS
    // ===============================

    // Navio 1 - Horizontal
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }

    // Navio 2 - Vertical
    int linhaV = 4, colunaV = 6;
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // Navio 3 - Diagonal principal (↘)
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // Navio 4 - Diagonal secundária (↙)
    int linhaD2 = 0, colunaD2 = 9;
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // ===============================
    // 3. EXIBIÇÃO DO TABULEIRO
    // ===============================

    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}