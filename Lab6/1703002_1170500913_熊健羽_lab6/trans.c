/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int block_i;
    int block_j;
    int mini_i;
    int mini_j;
    int t0, t1, t2, t3, t4, t5, t6, t7;
    if (M == 32 && N == 32)
        for (block_i = 0; block_i < M / 8; block_i++)
            for (block_j = 0; block_j < N / 8; block_j++)
            {
                for (mini_i = 0; mini_i < 8; mini_i++)
                {
                    t0 = A[block_i * 8 + mini_i][block_j * 8 + 0];
                    t1 = A[block_i * 8 + mini_i][block_j * 8 + 1];
                    t2 = A[block_i * 8 + mini_i][block_j * 8 + 2];
                    t3 = A[block_i * 8 + mini_i][block_j * 8 + 3];
                    t4 = A[block_i * 8 + mini_i][block_j * 8 + 4];
                    t5 = A[block_i * 8 + mini_i][block_j * 8 + 5];
                    t6 = A[block_i * 8 + mini_i][block_j * 8 + 6];
                    t7 = A[block_i * 8 + mini_i][block_j * 8 + 7];

                    B[block_j * 8 + 0][block_i * 8 + mini_i] = t0;
                    B[block_j * 8 + 1][block_i * 8 + mini_i] = t1;
                    B[block_j * 8 + 2][block_i * 8 + mini_i] = t2;
                    B[block_j * 8 + 3][block_i * 8 + mini_i] = t3;
                    B[block_j * 8 + 4][block_i * 8 + mini_i] = t4;
                    B[block_j * 8 + 5][block_i * 8 + mini_i] = t5;
                    B[block_j * 8 + 6][block_i * 8 + mini_i] = t6;
                    B[block_j * 8 + 7][block_i * 8 + mini_i] = t7;
                }
            }

    if (M == 64 && N == 64)
    {
        for (block_i = 0; block_i < 64; block_i += 8)
            for (block_j = 0; block_j < 64; block_j += 8)
            {
                for (mini_i = 0; mini_i < 4; mini_i++)
                {
                    t0 = A[block_i + mini_i][block_j + 0];
                    t1 = A[block_i + mini_i][block_j + 1];
                    t2 = A[block_i + mini_i][block_j + 2];
                    t3 = A[block_i + mini_i][block_j + 3];
                    t4 = A[block_i + mini_i][block_j + 4];
                    t5 = A[block_i + mini_i][block_j + 5];
                    t6 = A[block_i + mini_i][block_j + 6];
                    t7 = A[block_i + mini_i][block_j + 7];

                    B[block_j + 0][block_i + mini_i] = t0;
                    B[block_j + 1][block_i + mini_i] = t1;
                    B[block_j + 2][block_i + mini_i] = t2;
                    B[block_j + 3][block_i + mini_i] = t3;
                    B[block_j + 0][block_i + mini_i + 4] = t4;
                    B[block_j + 1][block_i + mini_i + 4] = t5;
                    B[block_j + 2][block_i + mini_i + 4] = t6;
                    B[block_j + 3][block_i + mini_i + 4] = t7;
                }
                for (mini_j = 0; mini_j < 4; mini_j++)
                {

                    t4 = B[block_j + mini_j][block_i + 4];
                    t5 = B[block_j + mini_j][block_i + 5];
                    t6 = B[block_j + mini_j][block_i + 6];
                    t7 = B[block_j + mini_j][block_i + 7];

                    t0 = A[block_i + 4][block_j + mini_j];
                    t1 = A[block_i + 5][block_j + mini_j];
                    t2 = A[block_i + 6][block_j + mini_j];
                    t3 = A[block_i + 7][block_j + mini_j];

                    B[block_j + mini_j][block_i + 4] = t0;
                    B[block_j + mini_j][block_i + 5] = t1;
                    B[block_j + mini_j][block_i + 6] = t2;
                    B[block_j + mini_j][block_i + 7] = t3;

                    B[block_j + mini_j + 4][block_i + 0] = t4;
                    B[block_j + mini_j + 4][block_i + 1] = t5;
                    B[block_j + mini_j + 4][block_i + 2] = t6;
                    B[block_j + mini_j + 4][block_i + 3] = t7;
                }
                for (mini_i = 4; mini_i < 8; mini_i++)
                {
                    t1 = -1;

                    t4 = A[block_i + mini_i][block_j + 4];
                    t5 = A[block_i + mini_i][block_j + 5];
                    t6 = A[block_i + mini_i][block_j + 6];
                    t7 = A[block_i + mini_i][block_j + 7];

                    B[block_j + 4][block_i + mini_i] = t4;
                    B[block_j + 5][block_i + mini_i] = t5;
                    B[block_j + 6][block_i + mini_i] = t6;
                    B[block_j + 7][block_i + mini_i] = t7;
                }
            }
    }

    if (M == 61 && N == 67)
    {
        for (block_i = 0; block_i + 16 < N; block_i += 16)
        {
            for (block_j = 0; block_j + 16 < M; block_j += 16)
            {
                for (mini_i = 0; mini_i < 16; mini_i++)
                {
                    for (mini_j = 0; mini_j < 16; mini_j++)
                    {
                        B[block_j + mini_j][block_i + mini_i] = A[block_i + mini_i][block_j + mini_j];
                    }
                }
            }
            t0 = block_j;
            // block_j -= 16;

            for (mini_i = 0; mini_i < 16; mini_i++)
                for (block_j = t0; block_j < M; block_j++)
                    B[block_j][block_i + mini_i] = A[block_i + mini_i][block_j];
        }
        // block_i -= 16;
        t0 = block_i;

        for (block_j = 0; block_j < M; block_j++)
            for (block_i = t0; block_i < N; block_i++)
                B[block_j][block_i] = A[block_i][block_j];
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);
}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; ++j)
        {
            if (A[i][j] != B[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
