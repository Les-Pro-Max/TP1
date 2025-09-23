// multiplication_addition.c
#include <stdio.h>

// Multiplication utilisant uniquement l'addition (+1)
int multiplier_par_addition(int a, int b) {
    // Gestion des cas où a ou b est 0
    if (a == 0 || b == 0) {
        return 0;
    }
    
    int resultat = 0;
    
    // On utilise le plus petit nombre comme compteur pour optimiser
    int multiplicande, multiplicateur;
    if (a <= b) {
        multiplicateur = a;
        multiplicande = b;
    } else {
        multiplicateur = b;
        multiplicande = a;
    }
    
    // Addition répétée
    for (int i = 0; i < multiplicateur; i++) {
        resultat = resultat + multiplicande;
    }
    
    return resultat;
}

// Version récursive (utilise aussi uniquement l'addition)
int multiplier_recursif(int a, int b) {
    // Cas de base
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    
    // Récursion: a × b = b + (a-1) × b
    return b + multiplier_recursif(a - 1, b);
}

// Version optimisée avec décalages (multiplication russe)
int multiplier_russe(int a, int b) {
    int resultat = 0;
    
    while (a > 0) {
        // Si a est impair, ajouter b au résultat
        if (a % 2 == 1) {
            resultat = resultat + b;
        }
        // Diviser a par 2 (décalage à droite)
        a = a / 2;
        // Multiplier b par 2 (décalage à gauche)
        b = b + b;  // Utilise uniquement l'addition
    }
    
    return resultat;
}

int main() {
    printf("Multiplication utilisant uniquement l'addition\n");
    printf("===============================================\n\n");
    
    // Tests avec différentes valeurs
    int tests[][2] = {
        {5, 3},
        {7, 8},
        {12, 4},
        {1, 100},
        {0, 5},
        {15, 15}
    };
    
    int nb_tests = sizeof(tests) / sizeof(tests[0]);
    
    for (int i = 0; i < nb_tests; i++) {
        int a = tests[i][0];
        int b = tests[i][1];
        
        printf("Test %d: %d × %d\n", i + 1, a, b);
        printf("  Méthode itérative:     %d × %d = %d\n", 
               a, b, multiplier_par_addition(a, b));
        
        // Pour éviter stack overflow, on limite la récursion
        if (a <= 100 && b <= 100) {
            printf("  Méthode récursive:     %d × %d = %d\n", 
                   a, b, multiplier_recursif(a, b));
        }
        
        printf("  Méthode russe:         %d × %d = %d\n", 
               a, b, multiplier_russe(a, b));
        printf("  Vérification normale:  %d × %d = %d\n\n", 
               a, b, a * b);
    }
    
    // Démonstration détaillée
    printf("Démonstration détaillée pour 5 × 3:\n");
    printf("-----------------------------------\n");
    int a = 5, b = 3;
    int resultat = 0;
    
    for (int i = 1; i <= a; i++) {
        resultat = resultat + b;
        printf("Étape %d: resultat = %d + %d = %d\n", 
               i, resultat - b, b, resultat);
    }
    printf("Résultat final: %d × %d = %d\n", a, b, resultat);
    
    return 0;
}