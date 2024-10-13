#include <stdio.h>
#include <stddef.h>

int RC = 0;


void printArray(size_t len, int *arr) {
    for (int i = 0; i < len; i++) {
        // printf("%d: %d\n", i, arr[i]);
        printf("%d, ", arr[i]);
    }
    printf("\n");
}


void bubbleSort(size_t len, int *arr) {
    int maxEl = len-1;
    while (maxEl>0) {
        int largest = 0;
        int container;
        while (largest < maxEl) {
            if (arr[largest]>arr[largest+1]) {
                container = arr[largest];
                arr[largest] = arr[largest+1];
                arr[largest+1] = container;
            }
            largest++;
        }
        maxEl--;
    }
}


void insertionSort(size_t len, int *arr) {
    for (int i = 1; i < len; i++) {
        int container;
        int current = i;
        while (arr[current]<arr[current-1] && current>0) {
            container = arr[current];
            arr[current] = arr[current-1];
            arr[current-1] = container;
            current--;
        }
    }
}


void insertionSortDesc(size_t len, int *arr) {
    for (int i = 1; i < len; i++) {
        int container;
        int current = i;
        while (arr[current]>arr[current-1] && current>0) {
            container = arr[current];
            arr[current] = arr[current-1];
            arr[current-1] = container;
            current--;
        }
    }
}


int linearSearch(size_t len, int *arr, int x) {
    int i = 0;
    while (i <= len-1) {
        if (arr[i] == x) {
            return i;
        }
        i++;
    }
    return 0;
}


void addBinary(size_t len, int* arrA, int* arrB, int* newArr) {
    int carr = 0;
    for(int i = len-1; i >= 0; i--) {
        int res = arrA[i] + arrB[i] + carr;
        if (res==0) {
            newArr[i+1]=0;
        } else if (res==1) {
            newArr[i+1]=1;
            carr=0;
        } else if (res==2) {
            newArr[i+1]=0;
            carr=1;
        } else if (res==3) {
            newArr[i+1]=1;
            carr=1;
        }
    }
    newArr[0]=carr;
}


void selectionSort(size_t len, int* arr) {
    for (int i = 0; i < len-1; i++) {
        int smallest = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j]<arr[smallest]) {
                smallest = j;
            }
        }
        int container = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = container;
    }
}


void mergeSortedArrays(int* arr, int l, int m, int r) {
	int leftLength = m - l + 1;
	int rightLength = r - m;
	int tempLeft[leftLength];	
	int tempRight[rightLength];
	int i, j, k;
	for (int i = 0; i < leftLength; i++) {
		tempLeft[i] = arr[l + i];
	}
	for (int i = 0; i < rightLength; i++) {
		tempRight[i] = arr[m + 1 + i];
	}
	for (i = 0, j = 0, k = l; k <= r; k++) {
		if ((i<leftLength) && (j >= rightLength || tempLeft[i] <= tempRight[j])) {
			arr[k] = tempLeft[i];
			i++;
		} else {
			arr[k] = tempRight[j];
			j++;
		}
	}
}


void mergeSortRecursion(int* arr, int l, int r) {
	if (l < r) {
	    int m = l + (r - l) / 2;	
	    mergeSortRecursion(arr, l, m);
        mergeSortRecursion(arr, m+1, r);
	    mergeSortedArrays(arr, l, m, r);
	}
}


void mergeSort(size_t len, int* arr) {
	mergeSortRecursion(arr, 0, len-1);
}


int binarySearch(size_t len, int* arr, int el) {
	int l = 0;
	int r = len - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
        printf("l: %d, m: %d, r: %d\n", l, m, r);
		if (arr[m] == el) {
			return m;
		} else {
			if (arr[m] < el) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
	}
	return -1;
}





int main() {
	

	// int arr[] = {1, 3, 5, 7, 8, 12, 35, 45, 66, 108, 202, 233, 333, 444, 555, 666};
    int arr[] = {1, 3, 5, 7, 8, 12, 35, 45, 66, 108, 202, 233, 333, 444, 555, 666, 789};
    // int arr[] = {1, 3, 5, 7, 8, 12, 35};
	size_t len = sizeof(arr)/sizeof(arr[0]);
	// mergeSort(len, arr);
	// printArray(len, arr);

    printf("%d", binarySearch(len, arr, 108));

    // int m = l + (r - l) / 2;

    // printf();

	return 0;
}

















