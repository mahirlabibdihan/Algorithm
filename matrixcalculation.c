#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 100

void Trim(char[]);
void Input(float[][MAX], int, int);
void Output(float[][MAX], int, int);
float StringToFloat(char[], int, int);
void Add(float[][MAX], float[][MAX], int, int);
void Substract(float[][MAX], float[][MAX], int, int);
void Multiply(float[][MAX], int, int, float);
void MatMultiply(float[][MAX], float[][MAX], int, int, int);
void Divide(float[][MAX], int, int, float);
void MatDivide(float[][MAX], float[][MAX], int, int, int, float);
void Transpose(float[][MAX], int, int);
void Cofactor(float[][MAX], float[][MAX], int, int, int);
float Determinant(float[][MAX], int);
void CofactorMatrix(float[][MAX], float[][MAX], int);
void Adjoint(float[][MAX], int);
void Inverse(float[][MAX], int, float);
void Equation(float[][MAX], float[][MAX],int);
int main()
{
    char s[100];
    float Matrix[26][MAX][MAX];
    int r[26], c[26],i;
    for (i = 0; i < 26; i++)
    {
        r[i] = c[i] = -1;
    }
    while (1)
    {
        scanf("\n");
        gets(s);
        Trim(s);
        switch (s[1])
        {
        case 'X': return 0;

        case 'N':
            if (s[2] == 'V')
            {
                char mat = s[strlen(s) - 1];
                if (mat > 64 && mat < 91)
                {
                    if (r[mat - 65] > -1)
                    {
                        if (r[mat - 65] == c[mat - 65])
                        {
                            float Det = Determinant(Matrix[mat - 65], r[mat - 65]);
                            if (Det != 0)
                            {
                                Inverse(Matrix[mat - 65], r[mat - 65], Det);
                                printf("Matrix %c is Inversed\n\n", mat);
                            }
                            else
                            {
                                puts("Inversion not possible\n");
                            }
                        }
                        else
                        {
                            printf("Matrix %c is not a square matrix\n\n", mat);
                        }
                    }
                    else
                    {
                        printf("No %c matrix found\n\n", mat);
                    }
                }
                else
                {
                    puts("Invalid Input\n");
                }
            }
            else
            {
                char mat = s[strlen(s) - 1];
                if (mat > 64 && mat < 91)
                {
                    printf("Enter Dimension of %c : ", mat);
                    scanf("%d %d", &r[mat - 65], &c[mat - 65]);
                    printf("Enter matrix %c (%d X %d) :\n",mat,r[mat - 65],c[mat - 65]);
                    Input(Matrix[mat - 65], r[mat - 65], c[mat - 65]);
                    printf("Matrix %c is Inserted\n\n", mat);
                }
                else
                {
                    puts("Invalid Input\n");
                }
            }
            break;

        case 'U':
        {
            char mat = s[strlen(s) - 1];
            if (mat > 64 && mat < 91)
            {
                if (r[mat - 65] > -1)
                {
                    printf("Matrix %c (%d X %d) :\n",mat,r[mat - 65],c[mat - 65]);
                    Output(Matrix[mat - 65], r[mat - 65], c[mat - 65]);
                }
                else
                {
                    printf("No %c matrix found\n\n", mat);
                }
            }
            else
            {
                puts("Invalid Input\n");
            }
            break;
        }

        case 'R':
        {
            char mat = s[strlen(s) - 1];
            if (mat > 64 && mat < 91)
            {
                if (r[mat - 65] > -1)
                {
                    Transpose(Matrix[mat - 65], r[mat - 65], c[mat - 65]);
                    r[mat - 65]^=c[mat - 65];
                    c[mat - 65]^=r[mat - 65];
                    r[mat - 65]^=c[mat - 65];
                    printf("Matrix %c is Transposed\n\n", mat);
                }
                else
                {
                    printf("No %c matrix found\n\n", mat);
                }
            }
            else
            {
                puts("Invalid Input\n");
            }
            break;
        }

        case 'E':
        {
            char mat = s[strlen(s) - 1];
            if (mat > 64 && mat < 91)
            {
                if (r[mat - 65] > -1)
                {
                    if (r[mat - 65] == c[mat - 65])
                    {
                        printf("Determinant of %c : %.6g\n\n", mat, Determinant(Matrix[mat - 65], r[mat - 65]));
                    }
                    else
                    {
                        puts("Determinant not possible\n");
                    }
                }
                else
                {
                    printf("No %c matrix found\n\n", mat);
                }
            }
            else
            {
                puts("Invalid Input\n");
            }
            break;
        }
        case 'Q':
        {
            float mat1[MAX][MAX], mat2[MAX][MAX];
            int unknown;
            printf("Enter number of unknowns : ");
            scanf("%d", &unknown);
            printf("Enter %d X %d matrix :\n", unknown, unknown);
            Input(mat1, unknown, unknown);
            printf("Enter %d X 1 matrix :\n", unknown);
            Input(mat2, unknown, 1);
            Equation(mat1, mat2, unknown);
            break;
        }

        case '+':
        {
            char mat1 = s[0], mat2 = s[strlen(s) - 1];
            if (mat1 > 64 && mat1 < 91 && mat2 > 64 && mat2 < 91)
            {
                if (r[mat1 - 65] > -1 && r[mat2 - 65] > -1)
                {
                    if (r[mat1 - 65] == r[mat2 - 65] && c[mat1 - 65] == c[mat2 - 65])
                    {
                        Add(Matrix[mat1 - 65], Matrix[mat2 - 65], r[mat1 - 65], c[mat1 - 65]);
                    }
                    else
                    {
                        puts("Addition not possible\n");
                    }
                }
                else
                {
                    if (r[mat1 - 65] == -1)
                    {
                        printf("No %c matrix found\n\n", mat1);
                    }
                    if (r[mat2 - 65] == -1)
                    {
                        printf("No %c matrix found\n\n", mat2);
                    }
                }
            }
            else
            {
                puts("Invalid Input\n");

            }
            break;
        }

        case '-':
        {
            char mat1 = s[0], mat2 = s[strlen(s) - 1];
            if (mat1 > 64 && mat1 < 91 && mat2 > 64 && mat2 < 91)
            {
                if (r[mat1 - 65] > -1 && r[mat2 - 65] > -1)
                {
                    if (r[mat1 - 65] == r[mat2 - 65] && c[mat1 - 65] == c[mat2 - 65])
                    {
                        Substract(Matrix[mat1 - 65], Matrix[mat2 - 65], r[mat1 - 65], c[mat1 - 65]);
                    }
                    else
                    {
                        puts("Substraction not possible\n");
                    }
                }
                else
                {
                    if (r[mat1 - 65] == -1)
                    {
                        printf("No %c matrix found\n", mat1);
                    }
                    if (r[mat2 - 65] == -1)
                    {
                        printf("No %c matrix found\n", mat2);
                    }
                    puts("");
                }
            }

            else
            {
                puts("Invalid Input\n");

            }
            break;
        }

        case '/':
        {
            char mat1 = s[0], mat2 = s[strlen(s) - 1];

            if (mat1 > 64 && mat1 < 91 )
            {
                if (mat2 > 64 && mat2 < 91)
                {
                    if (r[mat1 - 65] > -1 && r[mat2 - 65] > -1)
                    {
                        if (r[mat2 - 65] == c[mat2 - 65])
                        {
                            if (c[mat1 - 65] == r[mat2 - 65])
                            {
                                float Det = Determinant(Matrix[mat2 - 65], r[mat2 - 65]);

                                if (Det != 0)
                                {
                                    MatDivide(Matrix[mat1 - 65], Matrix[mat2 - 65], r[mat1 - 65], c[mat1 - 65], c[mat2 - 65], Det);
                                }
                                else
                                {
                                    puts("Division not possible\n");
                                }
                            }
                        }
                        else
                        {
                            puts("Division not possible\n");
                        }
                    }

                    else
                    {
                        if (r[mat1 - 65] == -1)
                        {
                            printf("No %c matrix found\n\n", mat1);
                        }
                        if (r[mat2 - 65] == -1)
                        {
                            printf("No %c matrix found\n\n", mat2);
                        }
                    }
                }

                else
                {
                    if (r[mat1 - 65] > -1)
                    {
                        float n = StringToFloat(s, 2, strlen(s));
                        if (n != 0)
                        {
                            Divide(Matrix[mat1 - 65], r[mat1 - 65], c[mat1 - 65], n);
                        }
                    }
                    else
                    {
                        printf("No %c matrix found\n\n", mat1);
                    }
                }
            }
            else
            {
                puts("Invalid Input\n");
            }
            break;
        }

        case '*':
        {
            char mat1 = s[0], mat2 = s[strlen(s) - 1];
            if ( mat1 > 64 && mat1 < 91 )
            {
                if ( mat2 > 64 && mat2 < 91)
                {
                    if (r[mat1 - 65] > -1 && r[mat2 - 65] > -1)
                    {
                        if (c[mat1 - 65] == r[mat2 - 65])
                        {
                            MatMultiply(Matrix[mat1 - 65], Matrix[mat2 - 65], r[mat1 - 65], c[mat1 - 65], c[mat2 - 65]);
                        }
                        else
                        {
                            puts("Multiplication not possible\n");
                        }
                    }

                    else
                    {
                        if (r[mat1 - 65] == -1)
                        {
                            printf("No %c matrix found\n\n", mat1);
                        }
                        if (r[mat2 - 65] == -1)
                        {
                            printf("No %c matrix found\n\n", mat2);
                        }
                    }
                }

                else
                {


                    if (r[mat1 - 65] > -1)
                    {
                        float n = StringToFloat(s, 2, strlen(s));
                        Multiply(Matrix[mat1 - 65], r[mat1 - 65], c[mat1 - 65], n);
                    }
                    else
                    {
                        printf("No %c matrix found\n\n", mat1);
                    }

                }
            }
            else
            {
                puts("No matrix detected\n");
            }
        }

        break;
        default:
            if (s[0] > 57)
            {
                puts("Invalid Command\n");
            }
            break;
        }
    }
}
void Equation(float x[][MAX], float y[][MAX], int n)
{
    float det[n + 1];
    int i, j, k;

    puts("");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j)
            {
                printf("%c %.4g%c ",x[i][j]<0?'-':'+',abs(x[i][j]),j+97);
            }
            else
            {
                printf("%c %.4g%c ",x[i][j]<0?'-':' ',abs(x[i][j]),j+97);
            }
            
        }
        printf("= %0.5g\n",y[i][0]);
    }
    det[0] = Determinant(x, n);
    if(det[0]==0)
    {
        puts("No Solution\n");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        float temp[MAX][MAX];
        for (j = 0; j < n; j++)
        {
            if (j != i - 1)
            {
                for (k = 0; k < n; k++)
                {
                    temp[j][k]=x[j][k];
                }
            }

            else
            {
                for(k=0;k<n;k++)
                {
                    temp[j][k]=y[k][0];
                }
            }

        }
        det[i]=Determinant(temp,n);
    }


    puts("\nWhere ,");

    for(i=1;i<=n;i++)
    {
        printf("%c = %.5g\n",96+i,det[i]/det[0]);
    }
    puts("");
}
float StringToFloat(char s[], int start, int end)
{
    float a = 10, b = 1, n = 0;
    int fl = 0, i;
    for (i = start; i < end; i++)
    {
        if (s[i] == '.')
        {
            fl = 1; a = 1;  continue;
        }
        if (fl)
        {
            b /= 10;
        }
        n *= a;
        s[i] -= '0';
        n += s[i] * b;
    }
    return n;
}
void Trim(char s[])
{
    char t[100];
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            t[j++] = (s[i] > 96) ? s[i] - 32 : s[i];
        }
    }
    for (i = 0; i < j; i++)
    {
        s[i] = t[i];
    }
    s[i] = '\0';
}
void Input(float x[][MAX], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%f", &x[i][j]);
        }
    }
}
void Output(float x[][MAX], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        puts("");
        for (j = 0; j < c; j++)
        {
            printf("%10.4g ", x[i][j]);
        }
        puts("");
    }
    puts("");
}
void Add(float x[][MAX], float y[][MAX], int r, int c)
{
    float mat[MAX][MAX];
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            mat[i][j] = x[i][j] + y[i][j];
        }
    }
    Output(mat, r, c);
}
void Substract(float x[][MAX], float y[][MAX], int r, int c)
{
    float mat[MAX][MAX];
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            mat[i][j] = x[i][j] - y[i][j];
        }
    }
    Output(mat, r, c);
}
void MatMultiply(float x[][MAX], float y[][MAX], int rx, int cx, int cy)
{
    float mat[MAX][MAX];
    int i, j, k;
    for (i = 0; i < rx; i++)
    {
        for (j = 0; j < cy; j++)
        {
            mat[i][j] = 0;
            for (k = 0; k < cx; k++)
            {
                mat[i][j] += (x[i][k] * y[k][j]);
            }
        }
    }
    Output(mat, rx, cy);
}
void Multiply(float x[][MAX], int r, int c, float n)
{
    float mat[MAX][MAX];
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            mat[i][j] = x[i][j] * n;
        }
    }
    Output(mat, r, c);
}
void MatDivide(float x[][MAX], float y[][MAX], int rx, int cx, int cy, float Det)
{
    float mat[MAX][MAX], temp[MAX][MAX];
    int i, j, k;

    for (i = 0; i < cy; i++)
    {
        for (j = 0; j < cy; j++)
        {
            temp[i][j] = y[i][j];
        }
    }

    Inverse(temp, cy, Det);

    for (i = 0; i < rx; i++)
    {
        for (j = 0; j < cy; j++)
        {
            mat[i][j] = 0;
            for (k = 0; k < cx; k++)
            {
                mat[i][j] += (x[i][k] * temp[k][j]);
            }
        }
    }
    Output(mat, rx, cy);
}
void Divide(float x[][MAX], int r, int c, float n)
{
    float mat[MAX][MAX];
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            mat[i][j] = x[i][j] / n;
        }
    }
    Output(mat, r, c);
}
void Transpose(float x[][MAX], int r, int c)
{
    int i, j;
    float temp[MAX][MAX];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            temp[j][i]=x[i][j];
        }
    }
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            x[i][j]=temp[i][j];
        }
    }
}
void Cofactor(float x[][MAX], float temp[][MAX], int r, int c, int n)
{
    int i = 0, j = 0, row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (row != r && col != c)
            {
                temp[i][j++] = x[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
void CofactorMatrix(float x[][MAX], float inv[][MAX], int n)
{
    int i, j, sign = 1;
    float temp[MAX][MAX];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Cofactor(x, temp, i, j, n);
            inv[i][j] = sign * Determinant(temp, n - 1);
            sign *= -1;
        }
    }
}
float Determinant(float x[][MAX], int n)
{
    float Det = 0;
    int i, sign = 1;
    if (n == 1)
    {
        return x[0][0];
    }
    float temp[MAX][MAX];
    for (i = 0; i < n; i++)
    {
        Cofactor(x, temp, 0, i, n);
        Det += (sign * Determinant(temp, n - 1) * x[0][i]);
        sign *= -1;
    }
    return Det;
}
void Adjoint(float x[][MAX], int n)
{
    float inv[MAX][MAX];
    int i, j;
    CofactorMatrix(x, inv, n);
    Transpose(inv, n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            x[i][j] = inv[i][j];
        }
    }
}
void Inverse(float x[][MAX], int n, float Det)
{
    int i, j;
    Adjoint(x, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            x[i][j] /= Det;
        }
    }
}