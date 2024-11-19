#define ll long long
class Solution {
public:
    ll maximumSubarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> um;

        int l=0, r;
        ll last_sum = 0;
        for(r=0;r<k;r++){
            um[arr[r]]++;
            last_sum += arr[r];
        }

        ll sum = 0ll;
        while(r<=arr.size()){
            if(um.size() == k){ // chk if window is distinct ?
                sum = max(last_sum, sum);
            }

            if(l<arr.size()){
                um[arr[l]]--;
                if(um[arr[l]]==0){um.erase(arr[l]);}
                last_sum -= arr[l];
                l++;
            }

            if(r<arr.size()){
                um[arr[r]]++;
                last_sum += arr[r];
            }
            r++;
        }

        return sum;
    }
};