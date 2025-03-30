int findKthLargest(int* nums, int numsSize, int k) {

    int *bigger = (int*)malloc(numsSize * sizeof(int));
    int *smaller = (int*)malloc(numsSize * sizeof(int));
    int counterBigger = 0, counterSmaller = 0;
    int pivotIndex = numsSize / 2;
    int pivotElements = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > nums[pivotIndex]) {
            bigger[counterBigger++] = nums[i];
        } 
        else if (nums[i] < nums[pivotIndex]) {
                smaller[counterSmaller++] = nums[i];
        }
        else{
            pivotElements++;
        }
    }
   
   int result;
    if (k <= counterBigger) {  
        result = findKthLargest(bigger, counterBigger, k);
    } else if (k > counterBigger && k <= counterBigger + pivotElements) {
        result = nums[pivotIndex];
    } else {
        result = findKthLargest(smaller, counterSmaller, k - counterBigger - pivotElements);
    }

    free(bigger);
    free(smaller);
    return result;
}