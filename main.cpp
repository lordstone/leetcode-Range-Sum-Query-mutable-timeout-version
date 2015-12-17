class NumArray {
    
    
    vector<int> arr;
    unordered_map<pair<int, int>> mylog;
    
    
public:
    NumArray(vector<int> &nums) {
        if(nums.size() == 0) return;
        int sum = 0;
        arr.push_back(0);
        for(int i = 0; i <= nums.size(); i ++){
            sum += nums[i];
            arr.push_back(sum);
        }
    }

    void update(int i, int val) {
        if(arr.size() == 0) return;
        pair<int, int> tmppair;
        int delta = val - (arr[i+1] - arr[i]);
        tmppair.first = i;
        tmppair.second = delta;
        mylog.push_back(tmppair);
    }

    int sumRange(int i, int j) {
        if(arr.size() == 0) return -1;
        int initSum = arr[j+1] - arr[i];
        for(int k = 0; k < mylog.size(); k++){
            if(mylog[k].first >= i && mylog[k].first <= j){
                initSum += mylog[k].second;
            }
        }
        return initSum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
