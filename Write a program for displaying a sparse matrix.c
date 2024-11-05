#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

void displaySparseMatrix(SparseMatrix arr[], int nonZeroCount) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", arr[i].row, arr[i].col, arr[i].value);
    }
}

int main() {
    int nonZeroCount;
    printf("Enter number of non-zero elements in the sparse matrix: ");
    scanf("%d", &nonZeroCount);
    
    SparseMatrix sparse[nonZeroCount];
    
    for (int i = 0; i < nonZeroCount; i++) {
        printf("Enter row, column, and value for element %d: ", i + 1);
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
    
    displaySparseMatrix(sparse, nonZeroCount);
    
    return 0;
}
