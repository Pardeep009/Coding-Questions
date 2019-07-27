vector<int> Solution::dNums(vector<int> &arr, int k) {
    unordered_map<int,int> map;              // hash variable to store occurence count of each value
    int i,c=0,size = arr.size();
    vector<int> ans;
    for(i=0;i<k && i<size;i++)
    {
        if(map.find(arr[i]) == map.end())
        {
            c++;
            map[arr[i]] = 1;
        }
        else
        {
            map[arr[i]]++;
        }
    }
    int start = 0;
    ans.push_back(c);
    for(;i<size;i++)
    {
        map[arr[start]]--;
        if(!map[arr[start]])
        {
            c--;
        }
        if(map.find(arr[i]) == map.end())
        {
            c++;
            map[arr[i]] = 1;
        }
        else
        {
            map[arr[i]]++;
            if(map[arr[i]]==1)
            c++;
        }
        ans.push_back(c);
        start++;
    }
    return ans;
}
