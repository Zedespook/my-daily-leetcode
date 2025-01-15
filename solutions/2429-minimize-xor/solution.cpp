class Solution {
public:
  int minimizeXor(int num1, int num2) {
    // Count set bits in num2
    int setBits = __builtin_popcount(num2);

    // Initialize result
    int result = 0;

    // First pass: Set 1s from MSB where num1 has 1s
    for (int i = 31; i >= 0 && setBits > 0; i--) {
      if (num1 & (1 << i)) {
        result |= (1 << i);
        setBits--;
      }
    }

    // Second pass: Set remaining 1s from LSB where num1 has 0s
    for (int i = 0; i < 32 && setBits > 0; i++) {
      if (!(num1 & (1 << i)) && !(result & (1 << i))) {
        result |= (1 << i);
        setBits--;
      }
    }

    return result;
  }
};