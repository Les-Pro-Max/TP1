// tableau_trie.c
#include <stdio.h>
#include <stdbool.h>

// Vérifie si le tableau est trié en ordre croissant
bool est_trie_croissant(int tableau[], int taille) {
    if (taille <= 1) {
        return true;
    }
    
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] > tableau[i + 1]) {
            return false;
        }
    }
    return true;
}

// Vérifie si le tableau est trié en ordre décroissant
bool est_trie_decroissant(int tableau[], int taille) {
    if (taille <= 1) {
        return true;
    }
    
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] < tableau[i + 1]) {
            return false;
        }
    }
    return true;
}

// Vérifie si le tableau est trié (croissant ou décroissant)
bool est_trie(int tableau[], int taille) {
    return est_trie_croissant(tableau, taille) || 
           est_trie_decroissant(tableau, taille);
}

// Vérifie si le tableau est strictement trié (sans doublons)
bool est_strictement_trie_croissant(int tableau[], int taille) {
    if (taille <= 1) {
        return true;
    }
    
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] >= tableau[i + 1]) {
            return false;
        }
    }
    return true;
}

// Retourne le type de tri du tableau
const char* type_de_tri(int tableau[], int taille) {
    if (taille <= 1) {
        return "Tableau vide ou à un seul élément";
    }
    
    bool croissant = true;
    bool decroissant = true;
    bool strictement_croissant = true;
    bool strictement_decroissant = true;
    
    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] > tableau[i + 1]) {
            croissant = false;
            strictement_croissant = false;
        }
        if (tableau[i] < tableau[i + 1]) {
            decroissant = false;
            strictement_decroissant = false;
        }
        if (tableau[i] == tableau[i + 1]) {
            strictement_croissant = false;
            strictement_decroissant = false;
        }
    }
    
    if (strictement_croissant) {
        return "Strictement croissant";
    } else if (strictement_decroissant) {
        return "Strictement décroissant";
    } else if (croissant) {
        return "Croissant (avec doublons possibles)";
    } else if (decroissant) {
        return "Décroissant (avec doublons possibles)";
    } else {
        return "Non trié";
    }
}

void afficher_tableau(int tableau[], int taille) {
    printf("[");
    for (int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) printf(", ");
    }
    printf("]");
}

void tester_tableau(int tableau[], int taille, const char* description) {
    printf("\n%s:\n", description);
    printf("Tableau: ");
    afficher_tableau(tableau, taille);
    printf("\n");
    
    printf("  Est trié croissant: %s\n", 
           est_trie_croissant(tableau, taille) ? "OUI" : "NON");
    printf("  Est trié décroissant: %s\n", 
           est_trie_decroissant(tableau, taille) ? "OUI" : "NON");
    printf("  Est strictement trié croissant: %s\n", 
           est_strictement_trie_croissant(tableau, taille) ? "OUI" : "NON");
    printf("  Type de tri: %s\n", type_de_tri(tableau, taille));
}

int main() {
    printf("Test de tableaux triés\n");
    printf("======================\n");
    
    // Différents cas de test
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[] = {5, 4, 3, 2, 1};
    int tab3[] = {1, 3, 2, 5, 4};
    int tab4[] = {1, 2, 2, 3, 4};
    int tab5[] = {5, 5, 5, 5, 5};
    int tab6[] = {42};
    int tab7[] = {};
    int tab8[] = {1, 2, 3, 3, 2, 1};
    
    tester_tableau(tab1, 5, "Tableau strictement croissant");
    tester_tableau(tab2, 5, "Tableau strictement décroissant");
    tester_tableau(tab3, 5, "Tableau non trié");
    tester_tableau(tab4, 5, "Tableau croissant avec doublons");
    tester_tableau(tab5, 5, "Tableau constant");
    tester_tableau(tab6, 1, "Tableau à un élément");
    tester_tableau(tab7, 0, "Tableau vide");
    tester_tableau(tab8, 6, "Tableau avec pic");
    
    return 0;
}