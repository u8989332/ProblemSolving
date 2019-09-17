#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<int> nums;
    stack<char> oprs;
    void calculate(stack<int>& nums, stack<char>& oprs){
        if(nums.size() < 2)
            return;

        int n1 = nums.top();
        nums.pop();
        int n2 = nums.top();
        nums.pop();

        char opr = oprs.top();
        oprs.pop();
        if(opr == '+')
            nums.push(n1 + n2);
        else if(opr == '-')
            nums.push(n2 - n1);


    }
public:
    int calculate(string s) {
        const int BEGIN_STATE = 0;
        const int NUMBER_STATE = 1;
        const int OPERATOR_STATE = 2;

        int currentState = BEGIN_STATE;
        int len = s.length();
        int number = 0;
        int computeMode = 0;
        stack<int>().swap(nums);
        stack<char>().swap(oprs);
        for(int i = 0 ; i < len; ++i)
        {
            if(s[i] == ' ')
            {
                continue;
            }

            switch(currentState)
            {
                case BEGIN_STATE:
                    if(isdigit(s[i]))
                        currentState = NUMBER_STATE;
                    else
                        currentState = OPERATOR_STATE;

                    i--;
                    break;
                case NUMBER_STATE:
                    if(isdigit(s[i]))
                    {
                        number =number * 10 + (s[i] - '0');
                    }
                    else
                    {
                        nums.push(number);
                        currentState = OPERATOR_STATE;
                        if(computeMode)
                        {
                            calculate(nums, oprs);
                            computeMode = 0;
                        }
                        number = 0;
                        i--;
                    }
                    break;
                case OPERATOR_STATE:
                    if(isdigit(s[i]))
                    {
                        currentState = NUMBER_STATE;
                        i--;
                    }
                    else if(s[i] == '(')
                    {
                        computeMode = 0;
                        currentState = NUMBER_STATE;
                    }
                    else if(s[i] == ')')
                    {
                        calculate(nums, oprs);
                    }
                    else if(s[i] == '+' || s[i] == '-')
                    {
                        oprs.push(s[i]);
                        computeMode = 1;
                    }
                    break;
            }
        }

        if(number != 0)
        {
            nums.push(number);
            calculate(nums, oprs);
        }

        if(number == 0 && nums.empty())
        {
            return 0;
        }

        return nums.top();
    }
};
int main()
{
    Solution s;
    cout << s.calculate("1 + 5 - 3") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << s.calculate("(500)") << endl;
    return 0;
}
