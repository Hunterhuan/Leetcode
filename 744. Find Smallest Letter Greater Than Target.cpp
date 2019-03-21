// 错了两个小地方。还是要练习边界问题。
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        while(l < r){
            int mid = l + (r-l)/2;
            if(letters[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        l = l%letters.size();
        return letters[l];
    }
};