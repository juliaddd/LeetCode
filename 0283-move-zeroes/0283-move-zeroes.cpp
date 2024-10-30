class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        while (j < nums.size()){
            if (nums[i]  == 0){
                while ( nums [j] == 0 ){
                    if ( j + 1 == nums.size())
                        break;
                    else    
                        j ++;
                }
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
                j++;
            }
            else {
                j++;
                i++;
            }
        }
    }
};