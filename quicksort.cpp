#include "inc.h"


int partition(vector<int> &nums, int l , int r ){
    int pivot = nums[r];
    int lop = l;
    for(int i = l; i <= r - 1; i++){
        if(nums[i] < pivot){
            swap(nums[lop], nums[i]);
            lop++;
        }
    }
    swap(nums[lop], nums[r]);
    //print(nums);
    return lop;
}

void quicksort(vector<int> &nums, int l , int r ){
    if(l >= r) return;
    int mid = partition(nums, l, r);
    quicksort(nums, l, mid - 1);
    quicksort(nums, mid + 1, r);
}

int main(){
    vector<int> nums = {5, 6, 8, 1, 2, 9, 5, 4 , 6, 10, 3};
    quicksort(nums, 0, 10);
    print(nums);
    return 0;
}