#include <stdio.h>
#include <math.h>

int cLength = 0;

void merge(int Array[], int first, int mid, int last){

    static int mIndex = 0;
    mIndex++;

    printf("Call #%d to merge function:\n", mIndex);
    printf("Merging %d to %d and %d to %d\n", first + 1, mid + 1, mid + 1, last);

    int n1 = mid - first;
	int n2 = last - mid;
	int left[n1 + 1];
	int right[n2 + 1];

	for (int i = 0; i < n1; i++) {
		left[i] = Array[first + i];
	}

	for (int j = 0; j < n2; j++) {
		right[j] = Array[mid + j];
	}

	left[n1] = __INT_MAX__;
	right[n2] = __INT_MAX__;

	int i = 0;
	int j = 0;

	for (int k = first; k < last; k++) {
		if (left[i] <= right[j]) {
			Array[k] = left[i];
			i = i + 1;
		} else {
			Array[k] = right[j];
			j = j + 1;
		}
	}

    printf("Array after merging: ");

    for (int i = 0; i < cLength; i++)
    {
        printf("%d ", Array[i]);
    }

    printf("\n\n");
}

void sortTD(int Array[], int first, int last){

    static int index = 0;
    index++;
    printf("Call #%d to sort function:\n", index);
    printf("Sorting subarray between %d and %d\n", first + 1, last);

    if (first < last){
        printf("\n");
        int mid = floor((first + last)/2);
        sortTD(Array, first, mid);
        sortTD(Array, mid + 1, last);
        merge(Array, first, mid, last);
    } else {
        printf("This call is an anchor point\n\n");
    }
}

int min(int first, int second){
    return (first > second) ? second : first;
}

void sortBU(int Array[], int length){
    int n = length;
    int index = 1;

    for (int sz = 1; sz < n; sz = 2*sz)
    {
        printf("\nIteration #%d \n", index);
        printf("------------------------\n");

        for (int first = 0; first < n - sz; first += 2*sz)
        {
            merge(Array, first, min(first + sz, n), min(first + 2*sz, n));
        }

        printf("Array after iteration: "); 

        for (int i = 0; i < length; i++)
        {
            printf("%d ", Array[i]);
        }

        printf("\n\n");   

        index++;
        
    }
    
}

void sort(int Array[], int length, short flag){

    printf("------------------------");
    printf("\nSorting...\n");
    printf("------------------------\n");

    if (flag == 1){
        sortTD(Array, 0, length);
    } else {
        sortBU(Array, length);
    }
    
    printf("------------------------\n");
}

int main(){

    printf("Select the implementation\n 1. Top-Down\n 2. Bottom-Up\n Choose 1 or 2: ");
    short flag = 0;
    scanf("%d", &flag);

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

    sort(Array, length, flag);
    
    printf("Sorted array: ");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", Array[i]);
    }

    return 0;
    
    
}