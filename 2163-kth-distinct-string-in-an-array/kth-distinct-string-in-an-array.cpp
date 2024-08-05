#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>

class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> counter;
        std::for_each(arr.begin(), arr.end(), [&counter](const std::string& s) { ++counter[s]; });
        
        auto it = std::find_if(arr.begin(), arr.end(), [&counter, &k](const std::string& s) {
            if (counter[s] == 1 && --k == 0) return true;
            return false;
        });

        return (it != arr.end()) ? *it : "";
    }
};
