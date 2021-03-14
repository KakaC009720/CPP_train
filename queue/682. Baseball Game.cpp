class Solution {
public:
    vector<int> v;
    int calPoints(vector<string>& ops) {

        for(int i=0; i<ops.size(); i++)
        {
            int s = v.size();
            if(ops[i] == "C")
            {
                v.pop_back();
            }
            else if(ops[i] == "D")
            {
                v.push_back(2 * v[s-1]);
            }
            else if(ops[i] == "+")
            {
                v.push_back(v[s-2] + v[s-1]);
            }
            else
            {
                v.push_back(atoi(ops[i].c_str()));
            }
        }
        int sum = 0;
        for(int j=0; j < v.size(); j++)
        {
            sum += v[j];
        }
        return sum;
    }
};
