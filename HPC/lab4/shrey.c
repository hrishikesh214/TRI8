#include <omp.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define size 2000000

int main()
{

    int *m1 = malloc((size) * sizeof(int));
    int *m2 = malloc((size) * sizeof(int));
    int *m3 = malloc((size) * sizeof(int));

    int i, j, k;

    for (i = 0; i < size; i++)
        m1[i] = 111 + size;

    for (i = 0; i < size; i++)
        m2[i] = size - 1;

    double start, end;

    start = omp_get_wtime();

    printf("Number of processors : %d ", omp_get_num_procs());

    // omp_set_num_threads(omp_get_num_procs());
    // #pragma omp parallel for
    for (i = 0; i < size; i++)
    {
        m3[i] = m1[i] + m2[i];
        // printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
    }
    end = omp_get_wtime();

    //   for (i = 0; i < ROW; i++) {
    //     for (j = 0; j < COLOUMNS; j++) {
    //       printf("%d\t", mul[i][j]);
    //     }
    //     printf("\n");
    //   }

    printf("\nTime Parallel= %f", (end - start));
    free(m1);
    free(m2);
    free(m3);
    return 0;
}