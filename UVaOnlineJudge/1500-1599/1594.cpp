#include <iostream>
#include <cmath>

using namespace std;

int a_nums[20];
int b_nums[20];
int temp_nums[20];
int n;

bool is_all_zero(int nums[]){
    bool is_all_zero = true;
    for(int i = 0; i < n;++i){
        if(nums[i] != 0){
            is_all_zero = false;
        }
    }

    return is_all_zero;
}
void next(int nums[]){
    for(int i = 0; i < n;++i){
        if(i == n - 1){
            temp_nums[i] = abs(nums[0] - nums[i]);
        }else{
            temp_nums[i] = abs(nums[i] - nums[i + 1]);
        }
    }

    for(int i = 0 ; i < n;++i){
        nums[i] = temp_nums[i];
    }
}

bool equals(int a[], int b[])
{
    for(int i = 0 ;i <n;++i){
        if(a[i] != b[i])
            return false;
    }

    return true;
}
int main()
{
    int cases;

    cin >> cases;
    while(cases--){
        cin >> n;
        for(int i = 0 ; i < n;++i)
        {
            cin >> a_nums[i];
            b_nums[i] = a_nums[i];
        }

        for(int i = 0 ; i < 1000;++i){
            next(a_nums);
            next(b_nums);
            next(b_nums);
            if(is_all_zero(b_nums)){
                cout << "ZERO" << endl;
                break;
            }
            if(equals(a_nums, b_nums)){
                cout << "LOOP" << endl;
                break;
            }
        }
    }
    return 0;
}
