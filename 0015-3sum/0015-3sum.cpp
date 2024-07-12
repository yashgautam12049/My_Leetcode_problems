class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int k = 0; k < n; k++) {
            int i = k + 1;
            int j = n - 1;
            while (i < j) {
                if (nums[i] + nums[j] == (-1) * nums[k]) {
                    vector<int> temp;
                    temp.push_back(nums[k]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    ans.push_back(temp);
                    if (i < n-1 && nums[i] == nums[i + 1]) {
                        while (i < n-1 && nums[i] == nums[i + 1]) {
                             i++;
                        }
                        i++;
                    } else {
                        i++;
                    }
                    if (j > 0 && nums[j] == nums[j - 1]) {
                        while (j > 0 && nums[j] == nums[j - 1]) {
                             j--;
                        }
                        j--;
                    } else {
                        j--;
                    }
                } else if(nums[i] + nums[j] > (-1) * nums[k]){
                    if (j > 0 && nums[j] == nums[j - 1]) {
                        while (j > 0 && nums[j] == nums[j - 1]) {
                             j--;
                        }
                        j--;
                    } else {
                        j--;
                    }
                }
                else{
                    if (i < n-1 && nums[i] == nums[i + 1]) {
                        while (i < n-1 && nums[i] == nums[i + 1]) {
                             i++;
                        }
                        i++;
                    } else {
                        i++;
                    }
                }
            }
            while(k<n-1 && nums[k]==nums[k+1]){
                 k++;
            }
        }
        return ans;
    }
};