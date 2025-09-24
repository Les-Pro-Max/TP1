#include <stdio.h>
#include <stdlib.h>

void afficher_matrice(int **mat, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** creer_matrice(int lignes, int colonnes) {
    int **mat = (int**)malloc(lignes * sizeof(int*));
    for (int i = 0; i < lignes; i++) {
        mat[i] = (int*)malloc(colonnes * sizeof(int));
    }
    return mat;
}

void liberer_matrice(int **mat, int lignes) {
    for (int i = 0; i < lignes; i++) {
        free(mat[i]);
    }
    free(mat);
}

void somme_matrices(int **A, int **B, int **C, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int lignes = 3, colonnes = 3;
    
    int **A = creer_matrice(lignes, colonnes);
    int **B = creer_matrice(lignes, colonnes);
    int **C = creer_matrice(lignes, colonnes);
    
    // Initialisation des matrices A et B
    printf("Matrice A:\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            A[i][j] = i + j + 1;
            B[i][j] = (i + 1) * (j + 1);
        }
    }
    afficher_matrice(A, lignes, colonnes);
    
    printf("\nMatrice B:\n");
    afficher_matrice(B, lignes, colonnes);
    
    somme_matrices(A, B, C, lignes, colonnes);
    
    printf("\nMatrice C = A + B:\n");
    afficher_matrice(C, lignes, colonnes);
    
    liberer_matrice(A, lignes);
    liberer_matrice(B, lignes);
    liberer_matrice(C, lignes);
    //branch * feat/somme-matrices
    return 0;
}