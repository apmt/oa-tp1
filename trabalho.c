// Copyright 2018 <Ana Paula Martins / Bruno Murta>
#include<stdio.h>
void cria_ind_prim(FILE *lista, FILE *indice) {
    int tam_chave_prim = 30;
    int i;  
    char c;
    int registro = 0;   // 0 ou 1?
    while (!feof(lista)) {
        for (i = 0; i < tam_chave_prim && !feof(lista); i++) {
            fscanf(lista, "%c", &c);
            if (c == ' ') {
                fscanf(lista, "%c", &c);
            }
            fprintf(indice, "%c", c);
        }
        fprintf(indice, "\t%d\n", registro++);
        while (c != '\n' && !feof(lista)) {
            fscanf(lista, "%c", &c);
        }
    }
}

void cria_ind_sec(FILE *lista, FILE *indPrim, FILE *indSec, FILE *invertida) {
    int i;
    char c;
    fseek(lista, 0, SEEK_SET);
    while (!feof(lista)) {
        fseek(lista, 52, SEEK_CUR);
        fscanf(lista, "%c", &c);

    }
}

int main() {
    // Índices primários
    FILE *lista1 = fopen("lista1.txt", "r");
    FILE *lista2 = fopen("lista2.txt", "r");
    FILE *indicelista1 = fopen("indicelista1.ind", "w");
    FILE *indicelista2 = fopen("indicelista2.ind", "w");
    if (lista1 != NULL && lista2 != NULL) {
        if (indicelista1 != NULL && indicelista2 != NULL) {
            cria_ind_prim(lista1, indicelista1);
            cria_ind_prim(lista2, indicelista2);
        }
    }

    // Índices secundários
    FILE *indSeclista1 = fopen("indSeclista1.ind", "w");
    FILE *indSeclista2 = fopen("indSeclista2.ind", "w");
    FILE *listaInvert1 = fopen("listaInvert1.ind", "w");
    FILE *listaInvert2 = fopen("listaInvert2.ind", "w");
    if (indSeclista1 != NULL && indSeclista2 != NULL) {
        if (listaInvert1 != NULL && listaInvert2 != NULL) {
            cria_ind_sec(lista1, indicelista1, indSeclista1, listaInvert1);
            cria_ind_sec(lista2, indicelista2, indSeclista2, listaInvert2);
        }
    }
    // Operações


    // Fim
    fclose(lista1);
    fclose(lista2);
    fclose(indicelista1);
    fclose(indicelista2);
    fclose(indSecundariolista1);
    fclose(indSecundariolista2);
    fclose(listaInvertida1);
    fclose(listaInvertida2);
}
