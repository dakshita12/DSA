// Every ugly number can be written as: 2^a * 3^b * 5^c         where a,b,c ≥ 0
// So if we remove all 2s, 3s, and 5s completely, nothing should remain except 1.


class Solution {
public:
    bool isUgly(int n) {

        if(n<=0) return false;

        while(n%2==0){
            n = n/2;
        }

        while(n%3==0){
            n = n/3;
        }

        while(n%5==0){
            n = n/5;
        }

        return n == 1;

    }
};