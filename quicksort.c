#include <stdio.h>

int cLength = 0;

int partition(int Array[], int first, int last) {

    static int mIndex = 0;
    mIndex++;

    printf("Call #%d to partition function:\n", mIndex);
    printf("Partitioning %d to %d\n", first + 1, last);

    int x = Array[last];
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (Array[j] <= x) {
            i = i + 1;

            int temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
        }
    }

    int temp = Array[i + 1];
    Array[i + 1] = Array[last];
    Array[last] = temp;

    printf("Array after partitioning: ");

    for (int i = 0; i < cLength; i++)
    {
        printf("%d ", Array[i]);
    }

    printf("\n\n");

    return i + 1;
}

void quicksort(int Array[], int first, int last){
    static int index = 0;
    index++;
    printf("Call #%d to sort function:\n", index);
    printf("Sorting subarray between %d and %d\n", first + 1, last);

    if (first < last){
        printf("\n");
        int part = partition(Array, first, last);
        quicksort(Array, first, part - 1);
        quicksort(Array, part + 1, last);
    } else {
        printf("This call is an anchor point\n\n");
    }
}

void sort(int Array[], int length){
    printf("------------------------");
    printf("\nSorting...\n");
    printf("------------------------\n");

    quicksort(Array, 0, length - 1);

    printf("------------------------\n");
}

int main(){
    printf("How many numbers are there in your array: ");
    int length = 0;
    scanf("%d", &length);
    cLength = length;

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