#include <stdio.h>

int main(void) {
    int a, b;
    printf("Entrez deux entiers positifs a et b (>0), séparés par un espace : ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Erreur de lecture.\n");
        return 1;
    }

    if (a <= 0 || b <= 0) {
        printf("Les deux nombres doivent être > 0.\n");
        return 1;
    }

    int result = 0;

    // On n'utilise QUE l'incrémentation de 1 (result++) pour construire la multiplication
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            result++; // ajoute 1, répété a*b fois au total
        }
    }

    printf("%d * %d = %d\n", a, b, result);
    return 0;
}