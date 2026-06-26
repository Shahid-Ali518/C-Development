#include"iostream"

using namespace std;

int add(int a, int b){
    return a + b;
}

int main(){

    int nums[] = {2, 7, 11, 15};
    int target = 9;

    // what actually does sizeof()

    cout << "Array size: " << sizeof(nums) << endl;
    cout << "Number of elements: " << sizeof(nums)/sizeof(nums[0]) << endl;

    for(int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        for(int j = i + 1; j < sizeof(nums)/sizeof(nums[0]); j++){
            if(nums[i] + nums[j] == target){
                cout << "Indices: " << i << ", " << j << endl;
                break;
            }
        }
    }

    cout << "Sum: " << add(5, 10) << endl;

    return 0;
}

