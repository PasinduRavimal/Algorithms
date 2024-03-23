#include <stdio.h>

void sort(int Array[], int length){
    printf("------------------------");
    printf("\nSorting...\n");
    printf("------------------------\n");

    int limit = length;
    int index = 1;

    do
    {
        printf("\nOuter loop Iteration #%d \n", index);
        printf("------------------------\n");
        int i = 0;

        for (int j = 0; j < limit - 1; j++)
        {
            printf("Inner loop Iteration #%d \n", j + 1);
            if (Array[j] > Array[j + 1])
            {
                int tmp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = tmp;

                i = j;
            }

            printf("Array after inner loop iteration: "); 

            for (int i = 0; i < length; i++)
            {
                printf("%d ", Array[i]);
            }

            printf("\n");
            
        }

        limit = i + 1;
        index++;

        printf("\nArray after outer loop iteration: "); 

            for (int i = 0; i < length; i++)
            {
                printf("%d ", Array[i]);
            }

            printf("\n");
        
    } while (limit > 1);

    printf("\n------------------------\n");
    
}

int main(){
    printf("How many numbers are there in your array: ");
    int length = 0;
    scanf("%d", &length);

    printf("Enter your array: ");
    int Array[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &Array[i]);
    }

    sort(Array, length);
    
    printf("Sorted array: ");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", Array[i]);
    }
    
    return 0;
    
}