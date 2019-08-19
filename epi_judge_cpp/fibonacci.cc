#include "test_framework/generic_test.h"
#include <vector>
int Fibonacci(int n) {
  // TODO - you fill in here.
  // base cases
  // when n is negative
  // when n is 0
  if(n<=0)
    return 0;
  // when n is 1
  if(n==1)
	return 1;
  // create a vector of size n
  // start filling the vector in bottom up manner
  std::vector<int> nums;
  nums.reserve (n+1);
  nums[0]=0;
  nums[1]=1;
  
  for (int i = 2; i <= n ; ++i) {
	// lookup prev two for this result
	nums[i] = nums[i-1]+nums[i-2];
  }
  return nums[n];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "fibonacci.cc", "fibonacci.tsv", &Fibonacci,
                         DefaultComparator{}, param_names);
}
