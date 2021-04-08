class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int num, type = 1, ans;
        num = candyType.size()/2;
        sort(candyType.begin(), candyType.end());
        for(int i = 0; i < candyType.size()-1; i++)
        {
            if(candyType[i] != candyType[i+1])
            {
                type += 1;
            }
        }
        if(type >= num)
            ans = num;
        else
            ans = type;
        return ans;
    }
};
