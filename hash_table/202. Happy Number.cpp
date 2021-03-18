#include<iostream>
#include<unordered_map>

using namespace std;

bool isHappy(int n) {
        unordered_map<int, int> umap;
        int num, key;
        int sum = 0;
        while(umap[n]!= 1 && sum != 1)
        {
            sum = 0;
            key = n;
            while(n>0)
            {
                num = n%10;
                n = n/10;
                sum = sum + num*num;

            }
            //cout << sum << endl;
            umap[key] = 1;
            n = sum;
        }
        if (sum == 1)
            return true;
        else
            return false;
    }

int main()
{
    int n = 2;
    bool ans;
    ans = isHappy(n);

    cout << ans << endl;

    return 0;
}
