#include<bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a,const vector<int>&b){
    return a[0]<b[0];
}
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    int n=arr.size();

    sort(arr.begin(),arr.end(),compare);

    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];

        //skip merged intervals
        if(!ans.empty() && end<=ans.back()[1])
            continue;

        //check the rest of intervals
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end)
                end=max(end,arr[j][1]);
            else   
                break;
        }
        ans.push_back({start,end});
    }
    return ans;
}


int main() {
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);

    cout << "The merged intervals are:" << endl;
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "]" << endl;
    }

    return 0;
}