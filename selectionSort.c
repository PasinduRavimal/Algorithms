#include <stdio.h>

void sort(int Array[], int length){
    printf("------------------------");
    printf("\nSorting...\n");
    printf("------------------------");

    int index = 1;

    for (int i = 0; i < length; i++)
    {
        printf("\nIteration #%d \n", index);
        printf("------------------------\n");

        int min = i;
        int innerIndex = 1;

        for (int j = i + 1; j < length; j++)
        {
            if (Array[j] < Array[min])
            {
                min = j;
            }
            
        }

        int temp = Array[i];
        Array[i] = Array[min];
        Array[min] = temp;

        printf("Array after iteration: "); 

        for (int i = 0; i < length; i++)
        {
            printf("%d ", Array[i]);
        }

        printf("\n");

        index++;
        
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