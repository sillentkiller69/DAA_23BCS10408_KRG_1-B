class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        vector<vector<int>>res;
        for(auto i: mp){
            vector<int>temp;
            temp.push_back(i.first);
            temp.push_back(i.second);
            res.push_back(temp);
        }
        return res;
    }
};
