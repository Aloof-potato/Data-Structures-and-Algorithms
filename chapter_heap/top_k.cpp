//2026-04-12
#include"../common/common.h"

//Question:给定一个长度为n的无序数组nums,请返回数组中最大的k个元素。

priority_queue<int,vector<int>,greater<int>> topKHeap(vector<int>&nums,int k){
    //初始化小顶堆
    //先将数组的前k个元素依次入堆,,堆大小固定为k
    priority_queue<int,vector<int>,greater<int>>minHeap(nums.begin(),nums.begin()+k);
    
    //从k+1个元素开始依次遍历
    for(int i=k;i<nums.size();i++){
        int top=minHeap.top();
        //若当前元素大于堆顶元素,则堆顶元素出堆,并将当前元素入堆
        //保证堆中永远是最大的k个元素
        if(nums[i]>top){
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap;
}

int main()
{
    vector<int> nums = {1, 7, 6, 3, 2};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> res = topKHeap(nums, k);
    cout << "最大的 " << k << " 个元素为: ";
    printHeap(res);

    return 0;
}