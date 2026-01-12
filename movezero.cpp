#include<iostream>
#include<vector>
using namespace std;

void movezeroes(std::vector<int>& nums){
    int lastnonzero =0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
           // printf("lastnonzero index is %d and i value%d \n", lastnonzero, nums[i]);
            nums[lastnonzero++]=nums[i];
        }
    }
    while(lastnonzero<nums.size()){
        nums[lastnonzero++] = 0;
    }


}
int main(){
    std::vector<int> vec = {1,0,2,0,3,0,4,0};
    int n = vec.size();
    movezeroes(vec);
    for(int x:vec){
        std::cout<<x<<" ";
    }
    return 0;    

}