//https://www.interviewbit.com/problems/majority-element/
class Solution {
    public:
        int majorityElement(vector<int> &num) {
            int majorityIndex = 0;
            for (int count = 1, i = 1; i < num.size(); i++) {
                num[majorityIndex] == num[i] ? count++ : count--;
                if (count == 0) {
                    majorityIndex = i;
                    count = 1;
                }
            }

            return num[majorityIndex];
        }
};