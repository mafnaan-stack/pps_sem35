int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    // Set return metadata for the transposed matrix
    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    int** result = (int**)malloc(cols * sizeof(int*));
    
    // Initialize each row of the new matrix
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    
    // Place elements at swapped indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}