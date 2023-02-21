#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Ligne de compilation: gcc tp3.c -lm -o tp3
// Faire plutot des asset pour les tests (voir utilisation epislon pour le retour des double)

double aire_rectangle(double longueur, double largeur){
    return longueur * largeur;
}

double hypothenuse(int ab, int bc){
    return sqrt(ab*ab + bc*bc);
}

bool cotes_triangle(double c1, double c2, double c3){
    if(c1 <= c2 + c3 && c2 <= c1 + c3 && c3 <= c1 + c2) return true;
    else return false;
}

int suivant_syracuse(int d){
    if(d%2 == 0) return d / 2;
    else return 3*d + 1;
}

int main(void){
    // Tests pour aire_rectangle
    printf("Tests pour la fonction aire_rectangle: \n");
    double a = 30.14;
    double b = 1.5;
    double c = 0.25;
    double d = 0;
    double a1 = aire_rectangle(a,b);
    double a2 = aire_rectangle(c,d);
    double a3 = aire_rectangle(b,c);    
    printf("%f \n%f\n%f \n\n", a1,a2,a3);

    // Tests pour hypothenuse

    printf("Tests pour la fonction hypothenuse: \n");
    int e = 1;
    int f = 5;
    int g = 0;
    int h = 7;
    double h1 = hypothenuse(e,f);
    double h2 = hypothenuse(g,h);
    double h3 = hypothenuse(h,f);
    printf("%f \n%f\n%f \n\n", h1,h2,h3);

    // Tests cotes_triangle
    printf("Tests pour la fonction cotes_triangle: \n");
    double i = 15;
    double j = 6.2;
    double k = 12.2;
    double l = 24.26;
    double m = 1.2;
    bool v1 = cotes_triangle(i,j,k);
    bool v2 = cotes_triangle(l,m,k);
    bool v3 = cotes_triangle(i,j,l);
    printf("%d \n%d\n%d \n\n", v1,v2,v3);

    // Tests suivant_syracuse
    printf("Tests pour la fonction suivant_syracuse: \n");
    int n = 0;
    int o = 17;
    int p = 135;
    int q = 42;
    int res1 = suivant_syracuse(n);
    int res2 = suivant_syracuse(o);
    int res3 = suivant_syracuse(p);
    int res4 = suivant_syracuse(q);
    printf("%d \n%d\n%d\n%d \n\n", res1,res2,res3,res4);


}
