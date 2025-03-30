typedef struct {
    int value;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* counts) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Element* L = (Element*)malloc(n1 * sizeof(Element));
    Element* R = (Element*)malloc(n2 * sizeof(Element));
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    int rightCount = 0;
    
    while (i < n1 && j < n2) {
        if (L[i].value > R[j].value) {
            arr[k] = R[j];
            rightCount++;
            j++;
        } else {
            counts[L[i].index] += rightCount;
            arr[k] = L[i];
            i++;
        }
        k++;
    }
    
    while (i < n1) {
        counts[L[i].index] += rightCount;
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(Element* arr, int left, int right, int* counts) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) {
        return NULL;
    }
    
    int* counts = (int*)calloc(numsSize, sizeof(int));
    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    
    for (int i = 0; i < numsSize; i++) {
        elements[i].value = nums[i];
        elements[i].index = i;
    }
    
    mergeSort(elements, 0, numsSize - 1, counts);
    
    free(elements);
    return counts;
}