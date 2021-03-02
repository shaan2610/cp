#include <stdio.h>
#include <stdlib.h>

int** simplify(int** a, int** b, int sign) // For matrix addition and subtraction
{
    int m = sizeof(a) / sizeof(a[0]);
    int **c = (int **)malloc(m * sizeof(int *)); 
    for (int i = 0; i < m; i++) 
    {
    	c[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            c[i][j] = a[i][j] + (sign * b[i][j]);
        }
    }
    return c;
}
int** split(int** a, int p, int q, int m) // For splitting the given 2-D Array
{
    int **c = (int **)malloc(m * sizeof(int *)); 
    for (int i = 0; i < m; i++) 
    {
    	c[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = p; i < p + m; i++) 
    {
        for (int j = q; j < q + m; j++) 
        {
            c[i - p][j - q] = a[i][j];
        }
    }
    return c;
}
void combine(int p, int q, int** res, int** quad, int m) // For merging the different parts of matrix
{
    for (int i = p; i < p + m; i++) 
    {
        for (int j = q; j < q + m; j++) 
        {
            res[i][j] = quad[i - p][j - q];
        }
    }
}
int** multiply(int** A, int** B, int n) // Strassen’s Matrix Multiplication Algorithm using Divide & combineonquer
{
    int **res = (int **)malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; i++) 
    {
    	res[i] = (int *)malloc(n * sizeof(int));
    }
    // base cases
    if (n == 1) 
    {
        res[0][0] = A[0][0] * B[0][0];
        return res;
    } 
    // four splits of a
    int** a = split(A, 0, 0, n / 2);
    int** b = split(A, 0, n / 2, n / 2);
    int** c = split(A, n / 2, 0, n / 2);
    int** d = split(A, n / 2, n / 2, n / 2);
    // four splits of b
    int** e = split(B, 0, 0, n / 2);
    int** f = split(B, 0, n / 2, n / 2);
    int** g = split(B, n / 2, 0, n / 2);
    int** h = split(B, n / 2, n / 2, n / 2);
    // solving 7 subproblems
    int** p1 = multiply(a, simplify(f, h, -1), n / 2); // a, f - h
    int** p2 = multiply(simplify(a, b, 1), h, n / 2);  // a + b, h
    int** p3 = multiply(simplify(c, d, 1), e, n / 2);  // c + d, e
    int** p4 = multiply(d, simplify(g, e, -1), n / 2); // d, g - e
    int** p5 = multiply(simplify(a, d, 1), simplify(e, h, 1), n / 2); // a + d, e + h         
    int** p6 = multiply(simplify(b, d, -1), simplify(g, h, 1), n / 2); // b - d, g - h
    int** p7 = multiply(simplify(a, c, -1), simplify(e, f, 1), n / 2); // a - c, e + f
    
    int** q1 = simplify(p1, p2, 1); // p1 + p2
    int** q2 = simplify(simplify(simplify(p5, p4, 1), p2, -1), p6, 1); // p5 + p4 - p2 + p6
    int** q3 = simplify(p3, p4, 1); // p3 + p4 
    int** q4 = simplify(simplify(simplify(p1, p5, 1), p3, -1), p7, -1); // p1 + p5 - p3 - p7
    
    combine(0, 0, res, q2, n / 2);
    combine(0, n / 2, res, q1, n / 2);
    combine(n / 2, 0, res, q3, n / 2);
    combine(n / 2, n / 2, res, q4, n / 2);
    return res;
}

signed main() {
    int n; // n will be power of 2 only
    scanf("%d", &n);

    // declaring a and b matrices
    int **a = (int **)malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; i++) 
    {
    	a[i] = (int *)malloc(n * sizeof(int));
    }
	int **b = (int **)malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; i++) 
    {
    	b[i] = (int *)malloc(n * sizeof(int));
    }
    // taking input from user a and b
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }
	for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }
	// function call to generate the product
    int** ab = multiply(a, b, n); 
    // product of the two matrices
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
        	printf("%d ", ab[i][j]);
        } 
        printf("\n");
    }
    return 0;
}
// XD