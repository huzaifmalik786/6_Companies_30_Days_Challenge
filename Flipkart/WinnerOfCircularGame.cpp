//link to solution: https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/872551770/


class Solution {
public:

    int helper(int n, int k){
        if(n==1){
            return 0;
        }
        return (helper(n-1,k)+k)%n;
    }

    int findTheWinner(int n, int k) {
        return helper(n,k)+1;
    }
};
