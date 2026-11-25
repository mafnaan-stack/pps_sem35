#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int rows = matSize;
    int cols = matColSize[0];
    
    // 1. Validate if reshape is possible
    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = (int*)malloc(rows * sizeof(int));
        for (int i = 0; i < rows; i++) {
            (*returnColumnSizes)[i] = cols;
        }
        return mat;
    }
    
    // 2. Allocate memory for the new r x c matrix
    int** res = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    
    for (int i = 0; i < r; i++) {
        res[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }
    
    // 3. Map elements from original to new matrix using flat index arithmetic
    int idx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = mat[idx / cols][idx % cols];
            idx++;
        }
    }
    
    *returnSize = r;
    return res;
}