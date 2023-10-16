// Problem Statement: 
// Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is 
// the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn’t exist, return -1 for this element.
//_________________________________________________________________________________________________________________________________________________________
//problem links:
//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
//https://leetcode.com/problems/next-greater-element-i/
//_________________________________________________________________________________________________________________________________________________________
//For more discussion on time and space complexity refer to:
//https://www.geeksforgeeks.org/next-greater-element/
//https://takeuforward.org/data-structure/next-greater-element-using-stack/
//_________________________________________________________________________________________________________________________________________________________

//CODE:
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
