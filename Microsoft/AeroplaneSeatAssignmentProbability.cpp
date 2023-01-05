//link to solution: https://leetcode.com/problems/airplane-seat-assignment-probability/submissions/872028345/


class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){
            return 1;
        }
        return 0.5;
    }
};
