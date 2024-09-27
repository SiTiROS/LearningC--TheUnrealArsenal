// Online C++ compiler to run C++ program online
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10; //2 //3
            
            reversed = reversed * 10 + digit; //2 //23
            temp /= 10; //3 //0
        }

        return (reversed == x);
    }
};


int main()
{
    //int digit = 3 % 10;
    // int digit = 3;
    // digit /= 10;
    // std::cout << digit << std::endl;
   
   
    Solution sol;
    
    std::cout << sol.isPalindrome(32);
    
    
    return 1;
}
