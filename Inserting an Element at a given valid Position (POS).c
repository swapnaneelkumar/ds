#include <stdio.h>

int main() {
    int arr[100], n, pos, element, i;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to be inserted
    printf("Enter the element to insert: ");
    scanf("%d", &element);


    printf("Enter the position (1 to %d) to insert the element: ", n + 1);
    scanf("%d", &pos);


    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please enter a position between 1 and %d\n", n + 1);
    } else {
    
        for (i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

      
        arr[pos - 1] = element;

 
        n++;

        printf("Array after insertion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
