#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ===============================
    // 1. DECLARAÇÃO DO TABULEIRO
    // ===============================

    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // ===============================
    // 2. DEFINIÇÃO DOS NAVIOS
    // ===============================

    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO]   = {3, 3, 3};

    // Coordenadas iniciais escolhidas no código
    int linhaH = 2;   // linha do navio horizontal
    int colunaH = 4;  // coluna inicial do navio horizontal

    int linhaV = 5;   // linha inicial do navio vertical
    int colunaV = 7;  // coluna do navio vertical

    // ===============================
    // 3. VALIDAÇÃO E POSICIONAMENTO
    // ===============================

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM) {

        // Verifica sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Se não houver sobreposição, posiciona
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // ===============================
    // 4. EXIBIÇÃO DO TABULEIRO
    // ===============================

    printf("===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}