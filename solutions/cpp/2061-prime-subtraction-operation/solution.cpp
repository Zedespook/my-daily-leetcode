class Solution {
public:
  vector<int> getPrimes(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++) {
      if (sieve[i]) {
        for (int j = i * i; j <= n; j += i) {
          sieve[j] = false;
        }
      }
    }

    vector<int> primes;
    for (int i = 0; i <= n; i++) {
      if (sieve[i]) {
        primes.push_back(i);
      }
    }
    return primes;
  }

  bool primeSubOperation(vector<int> &nums) {
    vector<int> primes = getPrimes(1000);
    int n = nums.size();

    bool isIncreasing = true;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] >= nums[i + 1]) {
        isIncreasing = false;
        break;
      }
    }
    if (isIncreasing)
      return true;

    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1])
        continue;

      int target = nums[i] - nums[i + 1] + 1;
      int left = 0, right = primes.size() - 1;
      int foundPrime = -1;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (primes[mid] >= target) {
          foundPrime = primes[mid];
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }

      if (foundPrime != -1 && foundPrime < nums[i]) {
        nums[i] -= foundPrime;
      } else {
        return false;
      }

      if (i > 0 && nums[i - 1] >= nums[i])
        continue;
    }

    return true;
  }
};