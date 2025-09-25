#include <stdio.h>
#include <math.h>

// Structure pour représenter un vecteur 3D
typedef struct {
    double x;
    double y;
    double z;
} Vecteur3D;

// Calcul du produit vectoriel de deux vecteurs 3D
// u × v = (uy*vz - uz*vy, uz*vx - ux*vz, ux*vy - uy*vx)
Vecteur3D produit_vectoriel(Vecteur3D u, Vecteur3D v) {
    Vecteur3D resultat;
    
    resultat.x = u.y * v.z - u.z * v.y;
    resultat.y = u.z * v.x - u.x * v.z;
    resultat.z = u.x * v.y - u.y * v.x;
    
    return resultat;
}

// Calcul du produit vectoriel avec tableaux
void produit_vectoriel_tableau(double u[3], double v[3], double resultat[3]) {
    resultat[0] = u[1] * v[2] - u[2] * v[1];
    resultat[1] = u[2] * v[0] - u[0] * v[2];
    resultat[2] = u[0] * v[1] - u[1] * v[0];
}

// Calcul de la norme d'un vecteur
double norme_vecteur(Vecteur3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Calcul du produit scalaire (pour vérification)
double produit_scalaire(Vecteur3D u, Vecteur3D v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

// Affichage d'un vecteur
void afficher_vecteur(Vecteur3D v, const char* nom) {
    printf("%s = (%.2f, %.2f, %.2f)\n", nom, v.x, v.y, v.z);
}

// Affichage d'un vecteur sous forme de tableau
void afficher_vecteur_tableau(double v[3], const char* nom) {
    printf("%s = [%.2f, %.2f, %.2f]\n", nom, v[0], v[1], v[2]);
}

// Vérification que le produit vectoriel est perpendiculaire aux deux vecteurs
void verifier_perpendicularite(Vecteur3D u, Vecteur3D v, Vecteur3D w) {
    double scalaire_u_w = produit_scalaire(u, w);
    double scalaire_v_w = produit_scalaire(v, w);
    
    printf("\nVérification de perpendicularité:\n");
    printf("u · (u×v) = %.6f %s\n", scalaire_u_w, 
           (fabs(scalaire_u_w) < 1e-10) ? "(≈ 0, perpendiculaire ✓)" : "(non perpendiculaire ✗)");
    printf("v · (u×v) = %.6f %s\n", scalaire_v_w,
           (fabs(scalaire_v_w) < 1e-10) ? "(≈ 0, perpendiculaire ✓)" : "(non perpendiculaire ✗)");
}

// Calcul de l'aire du parallélogramme formé par deux vecteurs
double aire_parallelogramme(Vecteur3D u, Vecteur3D v) {
    Vecteur3D cross = produit_vectoriel(u, v);
    return norme_vecteur(cross);
}

// Application: Calcul du vecteur normal à un plan
Vecteur3D vecteur_normal_plan(Vecteur3D p1, Vecteur3D p2, Vecteur3D p3) {
    // Deux vecteurs du plan
    Vecteur3D v1 = {p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
    Vecteur3D v2 = {p3.x - p1.x, p3.y - p1.y, p3.z - p1.z};
    
    // Le vecteur normal est le produit vectoriel
    return produit_vectoriel(v1, v2);
}

int main() {
    printf("Produit Vectoriel en 3D\n");
    printf("=======================\n\n");
    
    // Test 1: Vecteurs de base
    printf("Test 1: Vecteurs de base\n");
    printf("------------------------\n");
    Vecteur3D i = {1, 0, 0};
    Vecteur3D j = {0, 1, 0};
    Vecteur3D k = {0, 0, 1};
    
    Vecteur3D resultat = produit_vectoriel(i, j);
    afficher_vecteur(i, "i");
    afficher_vecteur(j, "j");
    afficher_vecteur(resultat, "i × j");
    printf("Résultat attendu: k = (0, 0, 1)\n");
    
    // Test 2: Vecteurs quelconques
    printf("\nTest 2: Vecteurs quelconques\n");
    printf("-----------------------------\n");
    Vecteur3D u = {2, 3, 4};
    Vecteur3D v = {5, 6, 7};
    
    resultat = produit_vectoriel(u, v);
    afficher_vecteur(u, "u");
    afficher_vecteur(v, "v");
    afficher_vecteur(resultat, "u × v");
    printf("Norme de u × v: %.2f\n", norme_vecteur(resultat));
    
    verifier_perpendicularite(u, v, resultat);
    
    // Test 3: Propriété anticommutative (u × v = -(v × u))
    printf("\nTest 3: Propriété anticommutative\n");
    printf("----------------------------------\n");
    Vecteur3D vu = produit_vectoriel(v, u);
    afficher_vecteur(resultat, "u × v");
    afficher_vecteur(vu, "v × u");
    printf("v × u devrait être égal à -(u × v)\n");
    
    // Test 4: Vecteurs colinéaires (résultat = vecteur nul)
    printf("\nTest 4: Vecteurs colinéaires\n");
    printf("-----------------------------\n");
    Vecteur3D a = {2, 4, 6};
    Vecteur3D b = {1, 2, 3};  // b = a/2
    resultat = produit_vectoriel(a, b);
    afficher_vecteur(a, "a");
    afficher_vecteur(b, "b = a/2");
    afficher_vecteur(resultat, "a × b");
    printf("(Vecteurs colinéaires → produit vectoriel nul)\n");
    
    // Test 5: Calcul avec tableaux
    printf("\nTest 5: Calcul avec tableaux\n");
    printf("-----------------------------\n");
    double vec1[3] = {1, 2, 3};
    double vec2[3] = {4, 5, 6};
    double res[3];
    
    produit_vectoriel_tableau(vec1, vec2, res);
    afficher_vecteur_tableau(vec1, "vec1");
    afficher_vecteur_tableau(vec2, "vec2");
    afficher_vecteur_tableau(res, "vec1 × vec2");
    
    // Application: Aire d'un parallélogramme
    printf("\nApplication 1: Aire d'un parallélogramme\n");
    printf("-----------------------------------------\n");
    Vecteur3D p = {3, 0, 0};
    Vecteur3D q = {0, 4, 0};
    double aire = aire_parallelogramme(p, q);
    afficher_vecteur(p, "p");
    afficher_vecteur(q, "q");
    printf("Aire du parallélogramme: %.2f\n", aire);
    
    // Application: Vecteur normal à un plan
    printf("\nApplication 2: Vecteur normal à un plan\n");
    printf("----------------------------------------\n");
    Vecteur3D point1 = {1, 0, 0};
    Vecteur3D point2 = {0, 1, 0};
    Vecteur3D point3 = {0, 0, 1};
    
    Vecteur3D normal = vecteur_normal_plan(point1, point2, point3);
    printf("Points du plan:\n");
    afficher_vecteur(point1, "P1");
    afficher_vecteur(point2, "P2");
    afficher_vecteur(point3, "P3");
    afficher_vecteur(normal, "Vecteur normal");
    printf("Norme du vecteur normal: %.2f\n", norme_vecteur(normal));
    
    
    return 0;
}