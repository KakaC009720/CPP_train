class RecentCounter {

public:
    RecentCounter() {

    }
    queue<int> q;
    int ping(int t) {
        while(!q.empty() && q.front() < t-3000)
        {
            q.pop();
        }
        q.push(t);
        return q.size();
    }

};

