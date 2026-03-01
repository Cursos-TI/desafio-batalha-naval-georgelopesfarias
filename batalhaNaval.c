#include <stdio.h>

#define TAM 10
#define H 5   // tamanho das matrizes de habilidade (5x5)

int main() {

    int tabuleiro[TAM][TAM];

    // ===============================
    // 1. INICIALIZA TABULEIRO
    // ===============================
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // água
        }
    }

    // ===============================
    // 2. POSICIONA NAVIOS FIXOS
    // ===============================
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][3 + i] = 3; // horizontal
        tabuleiro[5 + i][7] = 3; // vertical
    }

    // ===============================
    // 3. MATRIZES DE HABILIDADES
    // ===============================

    int cone[H][H];
    int cruz[H][H];
    int octaedro[H][H];

    int centro = H / 2;

    // ----- CONE (expandindo para baixo) -----
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ----- CRUZ -----
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ----- OCTAEDRO (LOSANGO) -----
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ===============================
    // 4. SOBREPOSIÇÃO DAS HABILIDADES
    // ===============================

    int origemLinha = 6;
    int origemColuna = 4;

    // Função de sobreposição simplificada (aplicando cone)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int linhaTab = origemLinha - centro + i;
            int colunaTab = origemColuna - centro + j;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM) {

                if (cone[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    // ===============================
    // 5. EXIBIÇÃO DO TABULEIRO
    // ===============================

    printf("\n===== BATALHA NAVAL - HABILIDADES =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }

    return 0;
}