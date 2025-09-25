#include <stdio.h>
#include <stdbool.h>


// Recherche séquentielle simple - retourne l'indice ou -1
int recherche_sequentielle(int tableau[], int taille, int valeur) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == valeur) {
            return i;  // Retourne l'indice de la première occurrence
        }
    }
    return -1;  // Valeur non trouvée
}

// Recherche séquentielle avec sentinelle (optimisée)
int recherche_avec_sentinelle(int tableau[], int taille, int valeur) {
    int dernier = tableau[taille - 1];
    tableau[taille - 1] = valeur;  // Place la sentinelle
    
    int i = 0;
    while (tableau[i] != valeur) {
        i++;
    }
    
    tableau[taille - 1] = dernier;  // Restaure la valeur originale
    
    if (i < taille - 1 || dernier == valeur) {
        return i;
    }
    return -1;
}

// Recherche toutes les occurrences
void recherche_toutes_occurrences(int tableau[], int taille, int valeur) {
    bool trouve = false;
    printf("Occurrences de %d trouvées aux indices: ", valeur);
    
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == valeur) {
            printf("%d ", i);
            trouve = true;
        }
    }
    
    if (!trouve) {
        printf("aucune");
    }
    printf("\n");
}

void afficher_tableau(int tableau[], int taille) {
    printf("Tableau: [");
    for (int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int tableau[] = {5, 3, 8, 3, 9, 1, 3, 7, 2, 6};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    
    afficher_tableau(tableau, taille);
    
    // Test 1: Recherche simple
    int valeur = 9;
    int indice = recherche_sequentielle(tableau, taille, valeur);
    if (indice != -1) {
        printf("\nValeur %d trouvée à l'indice %d\n", valeur, indice);
    } else {
        printf("\nValeur %d non trouvée\n", valeur);
    }
    
    // Test 2: Recherche avec sentinelle
    valeur = 7;
    indice = recherche_avec_sentinelle(tableau, taille, valeur);
    if (indice != -1) {
        printf("Valeur %d trouvée à l'indice %d (avec sentinelle)\n", valeur, indice);
    } else {
        printf("Valeur %d non trouvée (avec sentinelle)\n", valeur);
    }
    
    // Test 3: Recherche de toutes les occurrences
    valeur = 3;
    recherche_toutes_occurrences(tableau, taille, valeur);
    
    // Test 4: Recherche d'une valeur inexistante
    valeur = 15;
    indice = recherche_sequentielle(tableau, taille, valeur);
    if (indice != -1) {
        printf("\nValeur %d trouvée à l'indice %d\n", valeur, indice);
    } else {
        printf("\nValeur %d non trouvée\n", valeur);
    }
    
    return 0;
}