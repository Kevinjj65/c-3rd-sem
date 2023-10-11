#include <stdio.h>
void polyadd(int A[], int B[], int C[], int m, int n)
{
    int p = 1, q = 1, r = 1;
    while (p <= 2 * m && q <= 2 * n)
    {
        if (A[p] == B[q])
        {
            C[r + 1] = A[p + 1] + B[q + 1];
            if (C[r + 1] != 0)
            {
                C[r] = A[p];
                r = r + 2;
            }
            p = p + 2;
            q = q + 2;
        }
        else if (A[p] < B[q])
        {
            C[r + 1] = B[q + 1];
            C[r] = B[q];
            q = q + 2;
            r = r + 2;
        }
        else
        {
            C[r + 1] = A[p + 1];
            C[r] = A[p];
            p = p + 2;
            r = r + 2;
        }
    }
    while (q <= 2 * n)
    {
        C[r] = B[q];
        C[r + 1] = B[q + 1];
        q = q + 2;
        r = r + 2;
    }
    C[0] = r / 2;
}
int main()
{
    int A[50], B[50], C[50], l = 0;
    int m, n, c, k;
    printf("choice 1: to take values of polynomial\n choice 2: to sum and display\n");
    while (l == 0)
    {
        printf("eneter the choice:");
        scanf("%d", &k);
        if (k == 1)
        {
            printf("enter the no. of terms in polynomail 1:");
            scanf("%d", &m);
            printf("enter the values of polynomial 1 in array form:");
            for (int i = 1; i <= 2 * m; i += 2)
            {
                scanf("%d%d", &A[i], &A[i + 1]);
            }
            printf("enetr the no. of terms polynomial 2;");
            scanf("%d", &n);
            printf("eneter th values of polynomial 2 in array form:");
            for (int i = 1; i <= 2 * n; i += 2)
            {
                scanf("%d%d", &B[i], &B[i + 1]);
            }
        }
        else if (k == 2)
        {
            polyadd(A, B, C, m, n);
            {
                for (int i = 1; i <= C[0] * 2; i += 2)
                {
                    printf("%dx^%d", C[i + 1], C[i]);
                    if (i < C[0] * 2 - 1)
                    {
                        printf("+");
                    }
                }
                printf("\n");
                return 0;
            }
        }
        else
        {
            l += 1;
        }
    }
}

#include <stdio.h>
void main()
{
    int ch, mat[50][50], row, a[50][3], b[50][3], c[3][3], p, q, r, m, n, t, i, j, col;
    printf("choices:-\n");
    printf("1. Sparse matrix addition\n");
    printf("2. Sparse matrix transpose\n");
    printf("Enter choice:\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter no. of rows of matrix 1:\n");
        scanf("%d", &row);
        printf("Enter no. of columns of matrix 1:\n");
        scanf("%d", &col);
        a[0][0] = row;
        a[0][1] = col;
        r = 1, p = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                printf("Enter value in row %d column %d:\n", i, j);
                scanf("%d", &mat[i][j]);
                if (mat[i][j] != 0)
                {
                    p++;
                    a[r][0] = i;
                    a[r][1] = j;
                    a[r][2] = mat[i][j];
                    r++;
                }
            }
        }
        a[0][2] = p;
        printf("\nMatrix 1:\n\n");
        for (i = 0; i <= a[0][2]; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%d\t", a[i][j]);
            printf("\n");
        }
        printf("\nEnter no. of rows of matrix 2:\n");
        scanf("%d", &row);
        printf("Enter no. of columns of matrix 2:\n");
        scanf("%d", &col);
        b[0][0] = row;
        b[0][1] = col;
        r = 1, p = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                printf("Enter value in row %d column %d:\n", i, j);
                scanf("%d", &mat[i][j]);
                if (mat[i][j] != 0)
                {
                    p++;
                    b[r][0] = i;
                    b[r][1] = j;
                    b[r][2] = mat[i][j];
                    r++;
                }
            }
        }
        b[0][2] = p;
        printf("\nMatrix 2:\n\n");

        for (i = 0; i <= b[0][2]; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%d\t", b[i][j]);
            printf("\n");
        }
        p = q = r = 1;
        c[0][0] = a[0][0];
        c[0][1] = b[0][1];
        while (p <= a[0][2] && q <= b[0][2])
        {
            if (a[p][0] < b[q][0])
            {
                c[r][0] = a[p][0];
                c[r][1] = a[p][1];
                c[r][2] = a[p][2];
                p++;
                r++;
            }
            else if (a[p][0] > b[q][0])
            {
                c[r][0] = b[q][0];
                c[r][1] = b[q][1];
                c[r][2] = b[q][2];
                q++;
                r++;
            }
            else if (a[p][1] < b[q][1])
            {
                c[r][0] = a[p][0];
                c[r][1] = a[p][1];
                c[r][2] = a[p][2];
                p++;
                r++;
            }
            else if (a[p][1] > b[q][1])
            {
                c[r][0] = b[q][0];
                c[r][1] = b[q][1];
                c[r][2] = b[q][2];
                q++;
                r++;
            }
            else
            {
                c[r][0] = a[p][0];
                c[r][1] = a[p][1];
                c[r][2] = a[p][2] + b[q][2];
                p++;
                q++;
                r++;
            }
        }
        while (p <= a[0][2])
        {
            c[r][0] = a[p][0];
            c[r][1] = a[p][1];
            c[r][2] = a[p][2];
            p++;
            r++;
        }
        while (q <= b[0][2])
        {
            c[r][0] = b[q][0];
            c[r][1] = b[q][1];
            c[r][2] = b[q][2];
            q++;
            r++;
        }
        c[0][2] = r - 1;
        printf("\nSum:\n\n");
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%d\t", c[i][j]);
            printf("\n");
        }
    }
    else if (ch == 2)
    {
        printf("Enter no. of rows of matrix:\n");
        scanf("%d", &row);
        printf("Enter no. of columns of matrix:\n");
        scanf("%d", &col);
        a[0][0] = row;
        a[0][1] = col;
        r = 1;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                printf("Enter value in row %d column %d:\n", i, j);
                scanf("%d", &mat[i][j]);
                if (mat[i][j] != 0)
                {
                    p++;
                    a[r][0] = i;
                    a[r][1] = j;
                    a[r][2] = mat[i][j];
                    r++;
                }
            }
        }
        a[0][2] = p;
        printf("\nOriginal sparse matrix:\n\n");
        for (i = 0; i <= a[0][2]; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%d\t", a[i][j]);
            printf("\n");
        }
        m = a[0][0];
        n = a[0][1];
        t = a[0][2];
        b[0][0] = n;
        b[0][1] = m;
        b[0][2] = t;
        q = 1;
        if (t <= 0)
            return;
        for (col = 0; col <= n - 1; col++)
        {
            for (p = 1; p <= t; p++)
            {
                if (a[p][1] == col)
                {
                    b[q][0] = a[p][1];
                    b[q][1] = a[p][0];
                    b[q][2] = a[p][2];
                    q++;
                }
            }
        }
        printf("\nTransposed sparse matrix:\n\n");
        for (i = 0; i <= b[0][2]; i++)
        {
            for (int j = 0; j < 3; j++)
                printf("%d\t", b[i][j]);
            printf("\n");
        }
    }
    else
        printf("\nWrong choice\n");
}