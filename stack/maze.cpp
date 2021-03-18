#include <iostream>
#include<stack>

using namespace std;

pair<int,int> start{1,1};
pair<int,int> finish{8,10};
void print_stack(stack<pair<int,int>>&);

int MAZE[10][12]={
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,0,0,0,0,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1},
    {1,1,1,0,0,0,0,1,1,0,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1},
    {1,1,1,0,1,1,0,1,1,0,1,1},
    {1,1,1,1,1,1,0,1,1,0,1,1},
    {1,1,0,0,0,0,0,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}
};

int Visited[10][12]={0};
bool finished = 0;

void dfs(stack<pair<int,int>> Route){
    if(finished)
        return ;
    int x = Route.top().first;
    int y = Route.top().second;
    // cout << x << y << endl;
    if(x == finish.first&&y == finish.second){
        // print_stack(Route);
        while(!Route.empty()){
            x = Route.top().first;
            y = Route.top().second;
            // cout << x << y << endl;
            MAZE[x][y] = 2;
            Route.pop();
        }
        finished = true;
        return ;
    }
    if(MAZE[x-1][y]==0&&Visited[x-1][y]==0){
        Route.push(pair<int,int>(x-1,y));
        Visited[x-1][y]=1;
        dfs(Route);
        Route.pop();
    }
    if(MAZE[x+1][y]==0&&Visited[x+1][y]==0){
        Route.push(pair<int,int>(x+1,y));
        Visited[x+1][y]=1;
        dfs(Route);
        Route.pop();
    }
    if(MAZE[x][y+1]==0&&Visited[x][y+1]==0){
        Route.push(pair<int,int>(x,y+1));
        Visited[x][y+1]=1;
        dfs(Route);
        Route.pop();
    }
    if(MAZE[x][y-1]==0&& Visited[x][y-1]==0){
        Route.push(pair<int,int>(x,y-1));
        Visited[x][y-1]=1;
        dfs(Route);
        Route.pop();
    }
}

int main() {

    stack<pair<int,int>> Route;
    Route.push(start);

    dfs(Route);
    for(int i=0;i<10;i++){
        for(int j=0;j<12;j++)
            cout << MAZE[i][j] << " ";
        cout << endl;
    }
    return 0;
}

void print_stack(stack<pair<int,int>>& s){
    if(s.empty())
        return ;
    pair<int,int> p = s.top();
    // cout << p.first << "," << p.second << endl;
    s.pop();
    print_stack(s);
    s.push(p);
}
