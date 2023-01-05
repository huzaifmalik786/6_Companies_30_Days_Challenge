//link to solution: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/871731176/


class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int left=0,right=0, end= s.size()-1;
        int ans = 0;
        while(right!= s.size()){
            mp[s[right]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                ans+= 1+ (end-right);
                mp[s[left++]]--;
            }
            right++;
        }
        return ans;
    }
};
