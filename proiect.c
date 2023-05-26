#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define INF 1000000000

int **alocare_matrice(int n, int m)
{
    int **a = calloc(n, sizeof(int *));
    DIE(!a, "alocarea a esuat");
    for (int i = 0; i <= n; i++)
    {
        a[i] = calloc(m, sizeof(int));
        DIE(!a[i], "alocarea a esuat");
    }
    return a;
}

void eliberare_memorie(int **a, int n)
{
	for (int i = 0; i <= n; i++) {
		free(a[i]);
	}
	free(a);
}

void citire(int ***a, int *n, int *m)
{
    int i, j;
    system("clear");
    printf("Introduceti matricea\n");

    scanf("%d %d", n, m);
    (*a) = alocare_matrice(*n, *m);
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            scanf("%d", &((*a)[i][j]));
        }
    }
    
    printf("\nApasa Enter pentru a vedea matricea citita :\n");
    fflush(stdin);
    getchar();
}

void suma_2_matrici()
{
    printf("Pentru suma matricilor, se aduna elementele de pe aceleasi pozitii\n");
    system("clear");
    int i, j;
    printf("Introduceti marimile matricilor: ");
    int n1, m1, n2, m2;
    scanf("%d %d", &n1, &m1);
    int **x = alocare_matrice(n1, m1);

    printf("Introduceti prima matrice: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    printf("Introduceti a doua matrice: \n");
    int **y = alocare_matrice(n1, m1);
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }

    printf("Suma celod doua matrici este: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            printf("%d ", x[i][j] + y[i][j]);
        }
        printf("\n");
    }
    eliberare_memorie(x, n1);
    eliberare_memorie(y, n1);
    printf("\nApasa Enter pentru a vedea matricea citita :\n");
    fflush(stdin);
    getchar();
}

void dif_2_matrici()
{
    system("clear");
    printf("Pentru diferenta matricilor, se scad elementele de pe aceleasi pozitii\n");
    int i, j;
    printf("Introduceti marimile matricilor: ");
    int n1, m1, n2, m2;
    scanf("%d %d", &n1, &m1);
    int **x = alocare_matrice(n1, m1);

    printf("Introduceti prima matrice: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    printf("Introduceti a doua matrice: \n");
    int **y = alocare_matrice(n1, m1);
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }

    printf("Diferenta celor doua matrici este: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            printf("%d ", x[i][j] - y[i][j]);
        }
        printf("\n");
    }
    eliberare_memorie(x, n1);
    eliberare_memorie(y, n1);
    printf("\nApasa Enter pentru a vedea matricea citita :\n");
    fflush(stdin);
    getchar();
}

void prod_2_matrici()
{
    system("clear");
    printf("Pentru produsul matricilor, algoritmul este un pic mai complicat\n");
    printf("Elementul de pe pozitia [i][j] din matricea rezultat este obtinut prin adunarea\n");
    printf("elementelor a[i][k] * b[k][j], k mergand de la 0 la nr de coloane - 1\n");
    printf("Observati astfel de ce trebuie ca matricea a sa aiba nr de coloane egal cu nr de linii a lui b\n");
    int i, j;
    printf("Introduceti marimile matricilor: ");
    int n1, m1, n2, m2;
    scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
    if (m1 != n2) {
        printf("Matricile nu pot fi inmultite\n");
    }
    int **x = alocare_matrice(n1, m1);

    printf("Introduceti prima matrice: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    printf("Introduceti a doua matrice: \n");
    int **y = alocare_matrice(n2, m2);
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }

    printf("Produsul celor doua matrici este: \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            int elem = 0;
            for (int k = 0; k < n2; k++) {
                elem = elem + x[i][k] * y[k][j];
            }
            printf("%d ", elem);
        }
        printf("\n");
    }
    eliberare_memorie(x, n1);
    eliberare_memorie(y, n1);
    printf("\nApasa Enter pentru a vedea matricea citita :\n");
    fflush(stdin);
    getchar();
}

void afisare(int **a, int n, int m)
{
    system("clear");
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%ls ", *(a + i + j));
        printf("\n");
    }

    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void diag_princ(int **a, int n, int m)
{
    system("clear");

    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%ls ", *(a + i + j));
        }
        printf("\n");
    }

    printf("\nElementele de pe diagonala principala sunt:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i][i]);
    }

    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}


void diag_sec(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }

    printf("'Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nElementele de pe diagonala secundara sunt:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i][n - i - 1]);
    }

    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void diag_princ_sub(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    printf("'Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nElementele de sub diagonala principala sunt:\n\n");
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void diag_princ_deas(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    printf("'Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
                printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nElementele deasupra diagonalei principale sunt:\n\n");
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void diag_sec_sub(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    printf("'Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nElementele de sub diagonala secundara sunt:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = n - i; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void diag_sec_deas(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    printf("'Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
                printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nElementele deasupra diagonalei secundare sunt:\n\n");
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void spirala(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    if (n != m) {
        printf("Matricea trebuie sa fie diagonala\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    printf("Pentru matricea:\n\n");
    for (i = 0; i < n; i++) {
        for (j= 0; j < n; j++)
                printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nElementele matricei parcursa sub forma de spirala:\n\n");
    int l1, l2;
    l1 = 0; l2 = n - 1;
    while (l1 <= l2)
    {
        for (j= l1; j <= l2; j++)
            printf("%d ", a[l1][j]);
        for (i= l1 + 1; i <= l2; i++)
            printf("%d ", a[i][l2]);
        for (j = l2 - 1; j >= l1; j--)
            printf("%d ", a[l2][j]);
        for (i= l2 - 1; i >= l1 + 1; i--)
            printf("%d ", a[i][l1]);
        l1++;
        l2--;
    }

    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();

}


void triunghiuri(int **a, int n , int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    printf("Pentru matricea:\n\n");
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    int l1, l2, s1, s2, s3, s4;
    l1 = 1; l2 = n - 2;
    j = 1;
    s1 = 0;
    s2 = 0;
    while (l1 < l2)
    {
        for (i = l1; i < l2; i++)
            s1 += a[i][j]; s2= s2 + a[i][n - j + 1];
        j++;
        l1++;
        l2--;
    }

    l1 = 1; l2 = n - 2;
    i = 1;
    s3 = 0;
    s4 = 0;
    while (l1 <= l2)
    {
        for (j = l1; j < l2; j++)
            s3 += a[i][j]; s4 = s4 + a[n - i + 1][j];
        i++;
        l1++;
        l2--;
    }

    printf("\nsuma triunghi 1:%d\n\n", s1);
    printf("\nsuma triunghi 2:%d\n\n", s4);
    printf("\nsuma triunghi 3:%d\n\n", s2);
    printf("\nsuma triunghi 4:%d\n\n", s3);

    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();

}


void transpusa(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nTranspusa matricei este:\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void minimul(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j;
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nMinimul pentru fiecare linie:\n\n");

    int min;
    for (i = 0; i < n; i++)
    {
        min = INF;
        for (j = 0; j < m; j++)
        {
            if (min > a[i][j])
                min = a[i][j];
        }
        printf("linia %d: %d", i, min);
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();

}

void maximul(int **a, int n, int m)
{
    system("clear");
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j, max;
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nMaximul pentru fiecare linie:\n\n");


    for (i = 0; i < n; i++)
    {
        max = -INF;
        for (j = 0; j < m; j++)
        {
            if (max < a[i][j])
                max = a[i][j];
        }
        printf("linia %d: %d", i, max);
        printf("\n");
    }
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();

}

void rotire90(int **a, int n, int m)
{
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i,j;
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nRotire cu 90 de grade in sensul acelor de ceasornic\n");
    int **d = alocare_matrice(m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            d[i][j] = a[j][m - i - 1];

    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
    eliberare_memorie(d, m);
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void flipv(int **a, int n, int m)
{
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j, aux;

    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nFlip vertical\n");

    int **d = alocare_matrice(n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            d[i][j] = a[i][j];

    for (i = 0; i < n / 2; i++) {   
        for (j = 0; j < m; j++)
        {
            aux = d[i][j];
            d[i][j] = d[n - i - 1][j];
            d[n - i - 1][j] = aux;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
    eliberare_memorie(d, m);
    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

void flipo(int **a, int n, int m)
{
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int i, j, aux;
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
                printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nFlip orizontal\n");

    int **d = alocare_matrice(n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            d[i][j] = a[i][j];
    for (j = 0; j < m / 2; j++) {
        for (i = 0; i < n; i++)
        {
            aux = d[i][j];
            d[i][j] = d[i][n - j - 1];
            d[i][n - j - 1] = aux;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }

    printf("\nApasa Enter pentru revenire la meniul principal ");
    fflush(stdin);
    getchar();
}

int cmm(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void cmmdc(int **a, int n, int m)
{
    if (!a) {
        printf("Trebuie introdusa o matrice\n");
        printf("\nApasa Enter pentru revenire la meniul principal ");
        fflush(stdin);
        getchar();
        return;
    }
    int c = a[0][0], i, j;
    printf("Pentru matricea: \n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nCMMDC=\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            c = cmm(c, a[i][j]);


    printf("\ncmmdc=%d", c);
    fflush(stdin);
    getchar();
}

int main()
{
    int **a = NULL, n, m;
    int x;
    do {
        system("clear");
        printf("0 - Iesire\n");
        printf("1 - Citirea si afisarea matricelor\n");
        printf("2 - Diagonala principala\n");
        printf("3 - Diagonala secundara\n");
        printf("4 - Sub diagonala principala\n");
        printf("5 - Deasupra diagonalei principale\n");
        printf("6 - Sub diagonala secundara\n");
        printf("7 - Deasupra diagonalei secundare\n");
        printf("8 - Transpusa unei matrici\n");
        printf("9 - Suma a doua matrici\n");
        printf("10 - Diferenta a doua matrici\n");
        printf("11 - Produsul a doua matrici\n");
        printf("12 - Printarea matricei sub forma de spirala\n\n");
        printf("Optiunea dumneavoastra este : ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            citire(&a, &n, &m);
            afisare(a, n, m);
            break;
        case 2:
            diag_princ(a, n, m);
            break;
        case 3:
            diag_sec(a, n, m);
            break;
        case 4:
            diag_princ_sub(a, n, m);
            break;
        case 5:
            diag_princ_deas(a, n, m);
            break;
        case 6:
            diag_sec_sub(a, n, m);
            break;
        case 7:
            diag_sec_deas(a, n, m);
            break;
        case 8:
            transpusa(a, n, m);
            break;
        case 9:
            suma_2_matrici();
            break;
        case 10:
            dif_2_matrici();
            break;
        case 11:
            prod_2_matrici();
            break;
        case 12:
            spirala(a, n, m);
            break;
        }
    } while (x != 0);
    if (a)
        eliberare_memorie(a, n);
    return 0;
}