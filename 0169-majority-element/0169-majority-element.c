int countOccurrences(int* nums, int numsSize, int target) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) count++;
    }
    return count;
}


int majorityElement(int* nums, int numsSize) {
    
    if(numsSize == 1)
        return nums[0];

    int mid = numsSize / 2;

    int leftMajority = majorityElement(nums, mid);
    int rightMajority = majorityElement(nums + mid, numsSize - mid);

    if (leftMajority == rightMajority)
        return leftMajority;
    else{
    int leftCount = countOccurrences(nums, numsSize, leftMajority);
    int rightCount = countOccurrences(nums, numsSize, rightMajority);

    return (leftCount > rightCount) ? leftMajority : rightMajority;
    }

}