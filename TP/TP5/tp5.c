#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

int nombres_positifs(int *tab, int taille){
    int compteur = 0;
    for(int i =0 ; i < taille ; i++){
        if(tab[i] >= 0){
            compteur ++;
        }
    }
    return compteur;
}

double somme(double *tab, int taille){
    double res = 0;
    for(int i = 0; i<taille; i++){
        res+= tab[i];
    }
    return res;
}

bool trouve(int val, int *tab, int taille){
    for(int i = 0; i<taille; i++){
        if(tab[i] == val) return true;
    }
    return false;
}

int *copie(int *tab, int taille){
    int *cp = (int*) malloc(taille * sizeof(int));
    for(int i = 0; i <taille; i++){
        cp[i] = tab[i];
    }
    return cp;
}

bool *miroir(bool *tab, int taille){
    bool *mir = (bool*) malloc(taille * sizeof(bool));
    for(int i = 0; i<taille; i++){
        mir[taille-1-i] = tab[i];
    }
    return mir;
}

double plus_petite_distance(double *tab, int taille){
    double min = INFINITY;
    for(int i = 0; i<taille-1; i++){
        if(tab[i+1]-tab[i]<min) min = tab[i+1]-tab[i];
    }
    return min;
}

bool maximum_local(int *tab, int taille, int i){
    if (i==0) return tab[i]>tab[i+1];
    if (i == taille -1) return tab[i-1]<tab[i];
    else return tab[i-1]<tab[i] && tab[i]>tab[i+1] ;
}

bool vrai_maximum_local(int *tab, int taille, int i){
    
}
int main(){

    printf("Les tests de nombres_positifs sont des asserts.\n");
    int t[] = {39, -1, -7, -24, 30, -8, 15, 27, 18, -24, -30, -43, -17, 37, -26, -2, 15, 19, 38, 33, 12, 18, 29, -18, -50, 48, -13, -13, 43, -44, -44, 32, 5, -1, -42, 37, -6, -25, 14, -38, -47, -13, 22, -13, 26, -2, -13, 43, -33, -24, 26, 29, -4, -43, 14, 48, -45, -49, -15, 0, 9, -9, -18, 16, -7, 42, 3, 37, -33, 20, 1, 23, -43, 25, -40, 33, -26, 49, -22, 43, -25, -46, 23, 21, -39, 39, 19, 18, -8, 6, 20, -48, 48, -48, 18, 43, -4, -28, -18, -35, 42, -15, 38, 1, 13, 0, 36, -11, 0, -36, -18, -23, 20, 7, 1, 31, -4, 22, -49, 39, -21, 21, 41, -23, -25, -39, 22, -27, -17, 6, -12, 27, -7, -23, -22, -44, -21, 16, -5, 29, 30, -20, -43, 0, 37, 8, 33, -16, -20, 34, -27, 9, -43, 16, -12, -18, 27, 12, -43, 13, -32, -4, 42, 12, -25, -29, 18, 4, -11, 16, -16, -30, 46, -9, -28, 33, 1, -44, 19, 31, -8, -6, -9, -48, 12, -19, 36, 42, 44, 44, 5, -38, -10, -3, 24, -33, -30, 45, 21, 10, -37, -45, -18, -41, 48, 4, -6, -1, -38, 16, 33, -43, -40, 26, -41, -25, -43, 45, -33, -49, -9, -26, -36, 31, 21, -10, 48, -6, 37, -28, 6, -50, 29, 38, 11, 28, 44, 8, 29, 9, -26, -36, 16, 36, 40, -23, -39, 48, 24, -22};
    assert(nombres_positifs(t, 250) == 124);

    printf("Les tests de somme sont des asserts.\n");
    double tab[] = {15.091159, 17.018564, 2.303721, 10.299249, 2.287905, 18.939696, 16.623742, 19.695700, 3.364164, 3.737904, 14.405662, 15.179672, 11.332850, 2.557379, 2.805298, 19.833425, 0.348194, 4.880141, 19.848426, 3.562896, 11.594663, 7.337706, 11.706009, 15.299541, 14.497066};
    assert(fabs(somme(tab, 25) - 264.55073) < 0.0001 );

    printf("Les tests de trouve sont des asserts.\n");
    int t1[] = {4594, 7358, 6959, 7710, 2090, 1442, 2712, 6598, 4694, 9727, 3040, 7515, 4478, 4427, 5218, 6053, 8873, 4516, 2904, 2743, 9017, 4148, 6223, 6408, 9466, 8821, 711, 5124, 6691, 3892, 8749, 1285, 7602, 2060, 5347, 9693, 3502, 8060, 6291, 4548, 7787, 9331, 8415, 8618, 110, 3634, 4671, 5335, 4502, 3927, 8078, 3519, 8076, 653, 6279, 3894, 5826, 6990, 5371, 2517, 883, 4120, 154, 8485, 2532, 5501, 4530, 2386, 3561, 821, 6934, 7701, 6504, 1701, 6319, 6614, 5335, 7342, 8301, 9837, 1270, 2731, 9708, 9346, 3384, 5987, 3240, 9210, 9330, 8611, 8079, 6565, 9083, 8233, 1402, 1615, 3735, 5933, 4001, 7296, 3106, 7287, 1349, 9611, 8989, 7668, 2577, 676, 5011, 879, 514, 2633, 3610, 222, 1979, 6995, 2562, 1571, 2557, 8244, 6535, 637, 4809, 5618, 8870, 6211, 3586, 2605, 8496, 3939, 6254, 1603, 1227, 7603, 7566, 6568, 1624, 143, 7244, 2987, 1022, 4110, 5620, 985, 685, 3951, 4332, 9599, 1874, 6889, 7843, 8409, 3878, 2652, 380, 2749, 5215, 3966, 1706, 64, 7905, 4312, 1667, 5484, 8268, 9233, 8404, 9892, 5728, 2001, 9231, 3103, 2463, 1203, 4088, 3148, 5154, 8420, 9099, 3380, 1661, 6942, 1790, 5540, 5946, 2170, 8289, 1162, 2488, 6347, 7578, 6745, 660, 9245, 8582, 8928, 4830, 6986, 5172, 558, 5339, 4403, 13, 7803, 1958, 4101, 7303, 3464, 8873, 6403, 6844, 535, 9697, 8634, 6075, 5644, 804, 716, 3158, 9644, 3415, 736, 6390, 4075, 9981, 4972, 3003, 1163, 1958, 4527, 8073, 3650, 8930, 8087, 1453, 7240, 8540, 5108, 704, 7414, 7863, 7549, 7949, 7561, 6183, 376, 3205, 3340, 7444, 6363, 2984, 859, 7099, 5726, 1287, 3432, 698, 4290, 947, 9009, 5170, 9020, 2659, 4100, 3459, 464, 1341, 2000, 5572, 8397, 9414, 9788, 5946, 3715, 7349, 8482, 443, 554, 8174, 7887, 6917, 1158, 5098, 368, 6885, 6385, 152, 3935, 7028, 1099, 2944, 2198, 6471, 5603, 2650, 9931, 2419, 343, 8283, 4344, 8741, 4049, 4132, 4687, 7764, 1481, 9521, 4559, 2035, 7695, 8798, 5304, 5206, 3896, 2024, 2091, 6634, 2176, 2378, 3662, 3275, 5323, 5860, 6098, 7278, 8510, 6029, 9698, 5206, 664, 4042, 3947, 4713, 8174, 4986, 8829, 6007, 4508, 3388, 8042, 2203, 2186, 9698, 7409, 2435, 1722, 5852, 9069, 250, 8231, 2731, 9877, 3554, 4943, 5975, 7184, 9805, 8357, 6882, 5011, 9021, 7276, 8958, 3735, 5450, 297, 2564, 1457, 4805, 2305, 5851, 3360, 843, 1901, 770, 3278, 9975, 2974, 8699, 225, 1205, 7782, 6454, 1111, 2725, 2430, 8296, 8883, 7139, 1530, 3894, 6160, 8807, 9205, 6247, 609, 9502, 5164, 8419, 659, 7469, 622, 4019, 4664, 2524, 1141, 7943, 2499, 4116, 2994, 9077, 1673, 777, 5531, 9137, 9854, 4313, 3785, 8737, 1452, 5315, 2632, 7613, 474, 8189, 212, 1084, 4043, 5376, 5855, 4702, 2845, 6477, 5073, 3862, 9001, 6215, 8157, 7853, 6683, 1151, 3282, 8356, 1928, 5165, 3845, 1783, 9479, 7630, 520, 931, 9298, 9504, 4896, 9772, 7693, 5109, 7208, 8088, 6837, 3063, 2790, 6035, 5893, 7864, 9897, 1246, 431, 8054, 9099, 7114, 9205, 8733, 1822, 7486, 3899, 5668, 5621, 3378, 9650, 2493, 661, 8948, 1998, 1910, 8721, 6043, 3371, 5929, 4132, 208, 5345, 3274, 6243, 1238, 7490, 2492, 2484, 7921, 546};
    assert(! trouve(532, t1, 500));
    assert(trouve(212, t1, 500));

    printf("Les tests de copie sont des asserts.\n");
    int a[] = {9};
    int *a2 = copie(a, 1);
    int b[] = {6, 10, -3, 4, 5};
    int *b2 = copie(b, 5);
    assert(a[0] == a2[0]);
    assert(b[0] == b2[0]);
    assert(b[4] == b2[4]);

    printf("Les tests de miroir sont des asserts.\n");
    bool xxx[] = {true, false, false, true, false, true, true, true, false, false, false, false, false, false, false, true, true, true, true, true, false, false, true, true, true, true, false, true, true, false, true, false, false, true, true, false, false, false, true, true, false, true, true, false, true, false, true, true, true, false, false, true, false, true, false, true, true, false, false, false, false, true, false, true, true, true, true, true, true, true, false, true, false, false, false, false, false, true, true, true, false, true, false, false, false, false, false, true, false, false, true, false, false, true, true, true, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, false, false, false, true, true, false, true, false, false, true, false, false, true, true, false, false};
    bool *yyy = miroir(xxx, 127);
    assert(! yyy[0]);
    assert(yyy[32]);
    assert(! yyy[86]);
    assert(! yyy[117]);

    printf("Les tests de plus_petite_distance sont des asserts.\n");
    double tab1[] = {-4.3, -3.1, 0, 1.2, 5.6, 6.3};
    assert(fabs(plus_petite_distance(tab1, 6) - .7) < 0.00001);

    printf("Les tests de maximum_local sont des asserts.\n");
    int t2[] = {1, 2, 3, 2, 1, -1, -2, -1, -3, 5, 5, 2};
    int t3[] = {1, 2, 3, 2, 1, -1, -2, -1, -3, 5, 5, 2, 3, 3, 3, 3, 1, 4, 4, 4};
    assert(! maximum_local(t2, 12, 0));
    assert(maximum_local(t2, 12, 2));
    assert(maximum_local(t2, 12, 7));
    assert(! maximum_local(t2, 12, 9));
    assert(! maximum_local(t2, 12, 12));


}