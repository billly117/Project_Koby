#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Ligne de compilation: gcc tp3.c -lm -o tp3
// Faire plutot des asset pour les tests (voir utilisation epislon pour le retour des float)

float aire_rectangle(float longueur, float largeur){
    return longueur * largeur;
}

float hypothenuse(int ab, int bc){
    return sqrt(ab*ab + bc*bc);
}

bool cotes_triangle(float c1, float c2, float c3){
    if(c1 <= c2 + c3 && c2 <= c1 + c3 && c3 <= c1 + c2) return true;
    else return false;
}

int suivant_syracuse(int d){
    if(d%2 == 0) return d / 2;
    else return 3*d + 1;
}

double valeur_absolue(double a){
    if(a<=0) return -a;
    else return a;
}

void racine_par_dichotomie(float x, double precision){
    float debut, fin,milieu;
        if(x>1){
           debut = 1;
           fin = x;
        }
        
        else{
            debut = x;
            fin = 1;
        }

        while(fin-debut > precision){
            milieu = (debut + fin)/2;

            if(x > milieu*milieu){
                debut = milieu;
            }
            else{
                fin = milieu;
            }
        }
        printf("racine %f = %f\n", x, milieu);

    }

void racine_Heron(float x, double precision){
    float c1 = x;
    float c2 = 1;
    while(valeur_absolue(c1-c2) > precision){
        c1 = (c1+c2)/2;
        c2 = x/c1;
    }
    printf("racine de %f est %f\n",x,c1);
}

    



int main(void){
    // Tests pour aire_rectangle
    printf("Tests pour la fonction aire_rectangle: \n");
    float a = 30.14;
    float b = 1.5;
    float c = 0.25;
    float d = 0;
    float a1 = aire_rectangle(a,b);
    float a2 = aire_rectangle(c,d);
    float a3 = aire_rectangle(b,c);    
    printf("%f \n%f\n%f \n\n", a1,a2,a3);

    // Tests pour hypothenuse

    printf("Tests pour la fonction hypothenuse: \n");
    int e = 1;
    int f = 5;
    int g = 0;
    int h = 7;
    float h1 = hypothenuse(e,f);
    float h2 = hypothenuse(g,h);
    float h3 = hypothenuse(h,f);
    printf("%f \n%f\n%f \n\n", h1,h2,h3);

    // Tests cotes_triangle
    printf("Tests pour la fonction cotes_triangle: \n");
    float i = 15;
    float j = 6.2;
    float k = 12.2;
    float l = 24.26;
    float m = 1.2;
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

    // Tests valeur_absolue
    printf("Les tests pour valeur_absolue sont des asserts.\n\n");
    double epsilon = 0.0000001;
    assert(fabs(valeur_absolue(0)) < epsilon);
    assert(fabs(valeur_absolue(1.) - 1) < epsilon);
    assert(fabs(valeur_absolue(-1.7) - 1.7) < epsilon);

    // Tests racine_par_dichotomie
    printf("Les tests pour racine_par_dichotomie ne sont pas ceux de la prof.\n\n");
    double eps = 0.001;
    float r = 12;
    float s = 0.54;
    float t = 64;
    racine_par_dichotomie(r,eps);
    racine_par_dichotomie(s,eps);
    racine_par_dichotomie(t,eps);
    printf("\n");

    // Tests racine_Heron
    printf("Les tests pour racine_Heron ne sont pas ceux de la prof.\n\n");
    racine_Heron(r,eps);
    racine_Heron(s,eps);
    racine_Heron(t,eps);
}
