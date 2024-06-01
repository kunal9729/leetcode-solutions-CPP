class Solution {
public:
    int scoreOfString(string str) {
        int total = 0;
        for(int i = 0; i < str.size() - 1; i++) {
            total += abs(str[i] - str[i + 1]);
        }
        return total;
    }
};
