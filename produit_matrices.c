// produit_matrices.c
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

void produit_matrices(int **A, int **B, int **C, int m, int n, int p) {
    // A est m×n, B est n×p, C est m×p
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m = 2, n = 3, p = 2;  // A(2×3) × B(3×2) = C(2×2)
    
    // Création des matrices
    int **A = creer_matrice(m, n);
    int **B = creer_matrice(n, p);
    int **C = creer_matrice(m, p);
    
    // Initialisation de A
    printf("Matrice A (%d×%d):\n", m, n);
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    afficher_matrice(A, m, n);
    
    // Initialisation de B
    printf("\nMatrice B (%d×%d):\n", n, p);
    B[0][0] = 7;  B[0][1] = 8;
    B[1][0] = 9;  B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;
    afficher_matrice(B, n, p);
    
    // Calcul du produit
    produit_matrices(A, B, C, m, n, p);
    
    printf("\nMatrice C = A × B (%d×%d):\n", m, p);
    afficher_matrice(C, m, p);
    
    // Libération de la mémoire
    liberer_matrice(A, m);
    liberer_matrice(B, n);
    liberer_matrice(C, m);
    
    return 0;
}