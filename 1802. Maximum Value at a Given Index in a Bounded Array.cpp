int64_t calculateTrapezoidalArea(int64_t h, int64_t l) {
  return (2 * h - l + 1) * l / 2;
}

int findMaxItems(int start, int increment, int max_sum) {
  int64_t b = start * 2 / increment - 1;
  int64_t c = 2 * max_sum / increment;
  int64_t d = std::sqrt(b * b + 4 * c);
  int n = (d - b) / 2;
  return n;
}

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int left = index + 1;
    int right = n - index;
    int small = std::min(left, right);
    int large = std::max(left, right);

    const int64_t trapezoidalArea = calculateTrapezoidalArea(large, large) + calculateTrapezoidalArea(large, small) - large;
    if (maxSum >= trapezoidalArea) {
      return large + (maxSum - trapezoidalArea) / n + 1;
    }
    const int64_t triangleArea = calculateTrapezoidalArea(small, small) * 2 - small;
    if (maxSum >= triangleArea) {
      return small + findMaxItems(small * 2, 1, maxSum - triangleArea) + 1;
    }
    return findMaxItems(1, 2, maxSum) + 1;
  }
};
