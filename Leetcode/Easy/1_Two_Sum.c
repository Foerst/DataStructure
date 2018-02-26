int* twoSum(int* nums, int numsSize, int target) {
    int *p = (int *)malloc(sizeof(int)*2);
    memset(p,0,2);
    for(int i=0;i<numsSize;i++){
        int first = nums[i];
        int another = target-first;
        for(int j=i+1;j<numsSize;j++){
            if(another == nums[j]){
                *p=i;
                *(p+1)=j;
                return p;
            }
        }
    }
    return p;
}