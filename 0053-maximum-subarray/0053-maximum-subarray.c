int max(int a, int b){
    return a > b ? a : b;
}

int findCSS(int* nums, int l, int mid, int r){
    int A=0,B=0, sumA=INT_MIN,sumB=INT_MIN;
    for(int i = mid; i >= l; i--){
        A+=nums[i];
        if (A > sumA)
            sumA = A; 
    }
    for(int i = mid+1; i <= r; i++){
        B+=nums[i];
        if (B > sumB)
            sumB = B; 
    }

    return max(sumA, max(sumB, sumA+sumB));
}

int sumSubArr(int* nums, int l, int r){
 
    if (l == r){
        return nums[l];
    }
    int mid = l + (r-l)/2;
    int LSS = sumSubArr(nums, l, mid);
    int RSS = sumSubArr(nums,mid+1, r);
    int CSS = findCSS(nums, l, mid, r);

    return max(CSS, max(LSS,RSS));
}

int maxSubArray(int* nums, int numsSize) {
    return sumSubArr(nums, 0, numsSize-1);
}