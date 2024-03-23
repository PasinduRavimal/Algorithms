#include <stdio.h>

void sort(int Array[], int length){
    printf("------------------------");
    printf("\nSorting...\n");
    printf("------------------------");

    for (int  i = 1; i < length; i++)
    {
        printf("\nIteration #%d \n", i);
        int key = Array[i];
        int j = i - 1;

        while (j >= 0 && Array[j] > key)
        {
            Array[j + 1] = Array[j];
            j = j - 1;
        }

        Array[j + 1] = key;

        printf("Array after iteration: "); 

        for (int i = 0; i < length; i++)
        {
            printf("%d ", Array[i]);
        }       
    }

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