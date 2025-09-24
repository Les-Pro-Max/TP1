#include <stdio.h>
#include <stdlib.h>

void produit_vecteur_ligne_matrice(double* vecteur, double** matrice, 
                                   double* resultat, int m, int n) {
    // vecteur est de dimension m
    // matrice est m×n
    // resultat est de dimension n
    
    for (int j = 0; j < n; j++) {
        resultat[j] = 0;
        for (int i = 0; i < m; i++) {
            resultat[j] += vecteur[i] * matrice[i][j];
        }
    }
}

// Produit matrice × vecteur colonne
// Résultat: vecteur colonne de dimension m
void produit_matrice_vecteur_colonne(double** matrice, double* vecteur, 
                                     double* resultat, int m, int n) {
    // matrice est m×n
    // vecteur est de dimension n
    // resultat est de dimension m
    
    for (int i = 0; i < m; i++) {
        resultat[i] = 0;
        for (int j = 0; j < n; j++) {
            resultat[i] += matrice[i][j] * vecteur[j];
        }
    }
}

// Création d'une matrice dynamique
double** creer_matrice(int lignes, int colonnes) {
    double** mat = (double**)malloc(lignes * sizeof(double*));
    for (int i = 0; i < lignes; i++) {
        mat[i] = (double*)malloc(colonnes * sizeof(double));
    }
    return mat;
}

// Libération de la mémoire d'une matrice
void liberer_matrice(double** mat, int lignes) {
    for (int i = 0; i < lignes; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Affichage d'une matrice
void afficher_matrice(double** mat, int lignes, int colonnes, const char* nom) {
    printf("%s (%d×%d):\n", nom, lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        printf("[ ");
        for (int j = 0; j < colonnes; j++) {
            printf("%6.2f ", mat[i][j]);
        }
        printf("]\n");
    }
}

// Affichage d'un vecteur ligne
void afficher_vecteur_ligne(double* vect, int taille, const char* nom) {
    printf("%s (1×%d): [ ", nom, taille);
    for (int i = 0; i < taille; i++) {
        printf("%6.2f ", vect[i]);
    }
    printf("]\n");
}

// Affichage d'un vecteur colonne
void afficher_vecteur_colonne(double* vect, int taille, const char* nom) {
    printf("%s (%d×1):\n", nom, taille);
    for (int i = 0; i < taille; i++) {
        printf("[ %6.2f ]\n", vect[i]);
    }
}

// Produit scalaire de deux vecteurs
double produit_scalaire(double* v1, double* v2, int taille) {
    double resultat = 0;
    for (int i = 0; i < taille; i++) {
        resultat += v1[i] * v2[i];
    }
    return resultat;
}

// Application: Transformation linéaire
void transformation_lineaire() {
    printf("\n=== Application: Transformation linéaire 2D ===\n");
    
    // Matrice de rotation de 45 degrés
    double** rotation = creer_matrice(2, 2);
    rotation[0][0] = 0.707;  rotation[0][1] = -0.707;
    rotation[1][0] = 0.707;  rotation[1][1] = 0.707;
    
    double point[2] = {1.0, 0.0};
    double point_transforme[2];
    
    printf("Matrice de rotation (45°):\n");
    afficher_matrice(rotation, 2, 2, "R");
    printf("\nPoint original: (%.2f, %.2f)\n", point[0], point[1]);
    
    produit_matrice_vecteur_colonne(rotation, point, point_transforme, 2, 2);
    printf("Point après rotation: (%.2f, %.2f)\n", 
           point_transforme[0], point_transforme[1]);
    
    liberer_matrice(rotation, 2);
}

// Application: Système d'équations linéaires
void systeme_equations() {
    printf("\n=== Application: Système d'équations Ax = b ===\n");
    printf("2x + 3y - z = 1\n");
    printf("x - y + 2z = 4\n");
    printf("3x + 2y + z = 5\n\n");
    
    double** A = creer_matrice(3, 3);
    A[0][0] = 2;  A[0][1] = 3;  A[0][2] = -1;
    A[1][0] = 1;  A[1][1] = -1; A[1][2] = 2;
    A[2][0] = 3;  A[2][1] = 2;  A[2][2] = 1;
    
    // Solution connue: x=1, y=0, z=1
    double x[3] = {1.0, 0.0, 1.0};
    double b[3];
    
    afficher_matrice(A, 3, 3, "Matrice A");
    printf("\nSolution x = [1, 0, 1]ᵀ\n");
    
    produit_matrice_vecteur_colonne(A, x, b, 3, 3);
    printf("\nVérification Ax = b:\n");
    afficher_vecteur_colonne(b, 3, "b calculé");
    printf("b attendu:\n[ 1.00 ]\n[ 4.00 ]\n[ 5.00 ]\n");
    
    liberer_matrice(A, 3);
}

int main() {
    printf("Produit Vecteur × Matrice et Matrice × Vecteur\n");
    printf("===============================================\n\n");
    
    // Test 1: Produit vecteur ligne × matrice
    printf("Test 1: Produit vecteur ligne × matrice\n");
    printf("----------------------------------------\n");
    
    double vecteur_ligne[3] = {1, 2, 3};
    double** matrice1 = creer_matrice(3, 4);
    
    // Initialisation de la matrice
    matrice1[0][0] = 1;  matrice1[0][1] = 2;  matrice1[0][2] = 3;  matrice1[0][3] = 4;
    matrice1[1][0] = 5;  matrice1[1][1] = 6;  matrice1[1][2] = 7;  matrice1[1][3] = 8;
    matrice1[2][0] = 9;  matrice1[2][1] = 10; matrice1[2][2] = 11; matrice1[2][3] = 12;
    
    double resultat_ligne[4];
    
    afficher_vecteur_ligne(vecteur_ligne, 3, "v");
    afficher_matrice(matrice1, 3, 4, "M");
    
    produit_vecteur_ligne_matrice(vecteur_ligne, matrice1, resultat_ligne, 3, 4);
    afficher_vecteur_ligne(resultat_ligne, 4, "v × M");
    
    printf("\nCalcul détaillé:\n");
    for (int j = 0; j < 4; j++) {
        printf("Colonne %d: ", j);
        for (int i = 0; i < 3; i++) {
            printf("%.0f×%.0f", vecteur_ligne[i], matrice1[i][j]);
            if (i < 2) printf(" + ");
        }
        printf(" = %.0f\n", resultat_ligne[j]);
    }
    
    // Test 2: Produit matrice × vecteur colonne
    printf("\nTest 2: Produit matrice × vecteur colonne\n");
    printf("------------------------------------------\n");
    
    double** matrice2 = creer_matrice(2, 3);
    matrice2[0][0] = 1;  matrice2[0][1] = 2;  matrice2[0][2] = 3;
    matrice2[1][0] = 4;  matrice2[1][1] = 5;  matrice2[1][2] = 6;
    
    double vecteur_colonne[3] = {2, 1, 3};
    double resultat_colonne[2];
    
    afficher_matrice(matrice2, 2, 3, "A");
    afficher_vecteur_colonne(vecteur_colonne, 3, "x");
    
    produit_matrice_vecteur_colonne(matrice2, vecteur_colonne, resultat_colonne, 2, 3);
    afficher_vecteur_colonne(resultat_colonne, 2, "A × x");
    
    printf("\nCalcul détaillé:\n");
    for (int i = 0; i < 2; i++) {
        printf("Ligne %d: ", i);
        for (int j = 0; j < 3; j++) {
            printf("%.0f×%.0f", matrice2[i][j], vecteur_colonne[j]);
            if (j < 2) printf(" + ");
        }
        printf(" = %.0f\n", resultat_colonne[i]);
    }
    
    // Test 3: Matrice identité
    printf("\nTest 3: Multiplication par matrice identité\n");
    printf("--------------------------------------------\n");
    
    double** identite = creer_matrice(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            identite[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    
    double vect_test[3] = {5, 7, 9};
    double vect_resultat[3];
    
    afficher_matrice(identite, 3, 3, "I (identité)");
    afficher_vecteur_colonne(vect_test, 3, "v");
    
    produit_matrice_vecteur_colonne(identite, vect_test, vect_resultat, 3, 3);
    afficher_vecteur_colonne(vect_resultat, 3, "I × v");
    printf("(Le vecteur reste inchangé avec la matrice identité)\n");
    
    // Applications pratiques
    transformation_lineaire();
    systeme_equations();
    
    // Libération de la mémoire
    liberer_matrice(matrice1, 3);
    liberer_matrice(matrice2, 2);
    liberer_matrice(identite, 3);
    
    printf("\n=== Résumé ===\n");
    printf("- Vecteur ligne (1×m) × Matrice (m×n) = Vecteur ligne (1×n)\n");
    printf("- Matrice (m×n) × Vecteur colonne (n×1) = Vecteur colonne (m×1)\n");
    printf("- Les dimensions doivent être compatibles pour la multiplication\n");
    
    return 0;
}