// median_tableau.c
#include <stdio.h>
#include <stdlib.h>

// Fonction pour échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Tri par sélection pour trier le tableau
void trier_tableau(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            echanger(&tableau[i], &tableau[min_idx]);
        }
    }
}

// Calcul du médian après tri
double calculer_median_tri(int tableau[], int taille) {
    if (taille == 0) {
        printf("Erreur: tableau vide\n");
        return 0;
    }
    
    // Créer une copie pour ne pas modifier le tableau original
    int *copie = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++) {
        copie[i] = tableau[i];
    }
    
    // Trier la copie
    trier_tableau(copie, taille);
    
    double median;
    if (taille % 2 == 1) {
        // Nombre impair d'éléments: médian est l'élément du milieu
        median = copie[taille / 2];
    } else {
        // Nombre pair d'éléments: médian est la moyenne des deux éléments du milieu
        median = (copie[taille / 2 - 1] + copie[taille / 2]) / 2.0;
    }
    
    free(copie);
    return median;
}

// Partition pour QuickSelect
int partition(int tableau[], int gauche, int droite) {
    int pivot = tableau[droite];
    int i = gauche - 1;
    
    for (int j = gauche; j < droite; j++) {
        if (tableau[j] <= pivot) {
            i++;
            echanger(&tableau[i], &tableau[j]);
        }
    }
    echanger(&tableau[i + 1], &tableau[droite]);
    return i + 1;
}

// QuickSelect pour trouver le k-ième plus petit élément
int quickselect(int tableau[], int gauche, int droite, int k) {
    if (gauche == droite) {
        return tableau[gauche];
    }
    
    int pivot_index = partition(tableau, gauche, droite);
    
    if (k == pivot_index) {
        return tableau[k];
    } else if (k < pivot_index) {
        return quickselect(tableau, gauche, pivot_index - 1, k);
    } else {
        return quickselect(tableau, pivot_index + 1, droite, k);
    }
}

// Calcul du médian avec QuickSelect (plus efficace O(n) en moyenne)
double calculer_median_quickselect(int tableau[], int taille) {
    if (taille == 0) {
        printf("Erreur: tableau vide\n");
        return 0;
    }
    
    // Créer une copie pour ne pas modifier le tableau original
    int *copie = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++) {
        copie[i] = tableau[i];
    }
    
    double median;
    if (taille % 2 == 1) {
        // Nombre impair: trouver l'élément du milieu
        median = quickselect(copie, 0, taille - 1, taille / 2);
    } else {
        // Nombre pair: trouver les deux éléments du milieu
        int val1 = quickselect(copie, 0, taille - 1, taille / 2 - 1);
        int val2 = quickselect(copie, 0, taille - 1, taille / 2);
        median = (val1 + val2) / 2.0;
    }
    
    free(copie);
    return median;
}

void afficher_tableau(int tableau[], int taille) {
    printf("[");
    for (int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) printf(", ");
    }
    printf("]");
}

void afficher_tableau_trie(int tableau[], int taille) {
    int *copie = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++) {
        copie[i] = tableau[i];
    }
    trier_tableau(copie, taille);
    
    printf("Tableau trié: ");
    afficher_tableau(copie, taille);
    printf("\n");
    
    free(copie);
}

void tester_median(int tableau[], int taille, const char* description) {
    printf("\n%s\n", description);
    printf("Tableau original: ");
    afficher_tableau(tableau, taille);
    printf("\n");
    
    afficher_tableau_trie(tableau, taille);
    
    double median1 = calculer_median_tri(tableau, taille);
    double median2 = calculer_median_quickselect(tableau, taille);
    
    printf("Médian (méthode tri): %.1f\n", median1);
    printf("Médian (QuickSelect): %.1f\n", median2);
    
    if (taille % 2 == 1) {
        printf("(Nombre impair d'éléments: médian = élément du milieu)\n");
    } else {
        printf("(Nombre pair d'éléments: médian = moyenne des 2 éléments du milieu)\n");
    }
}

int main() {
    printf("Calcul du médian dans un tableau\n");
    printf("=================================\n");
    
    // Cas de test
    int tab1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};  // 9 éléments
    int tab2[] = {7, 3, 1, 4, 6, 2, 8, 5};      // 8 éléments
    int tab3[] = {5};                            // 1 élément
    int tab4[] = {3, 7};                         // 2 éléments
    int tab5[] = {10, 20, 30, 40, 50};          // Déjà trié
    int tab6[] = {5, 5, 5, 5, 5};               // Tous identiques
    
    tester_median(tab1, 9, "Test 1: Tableau avec 9 éléments (impair)");
    tester_median(tab2, 8, "Test 2: Tableau avec 8 éléments (pair)");
    tester_median(tab3, 1, "Test 3: Tableau avec 1 élément");
    tester_median(tab4, 2, "Test 4: Tableau avec 2 éléments");
    tester_median(tab5, 5, "Test 5: Tableau déjà trié");
    tester_median(tab6, 5, "Test 6: Tableau avec valeurs identiques");
    
    return 0;
}