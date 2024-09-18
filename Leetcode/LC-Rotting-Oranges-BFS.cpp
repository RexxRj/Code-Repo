class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;

        int cntFresh = 0;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                //cout<<i<<" "<<j<<endl;
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1)
                cntFresh++;
            }
        }

        int tm = 0;
        int cnt = 0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,-1,0,+1};

        while(!q.empty())
        {
            int nr = q.front().first.first;
            int nc = q.front().first.second;
            int t = q.front().second;
            tm = max(t,tm);
            q.pop();

            for(int i = 0; i<4; i++){

                int r = nr + drow[i];
                int c = nc + dcol[i];
                //cout<<r<<" "<<c<<endl;

                if(r<m && r>=0 && c<n && c>=0 && grid[r][c] == 1)
                {
                    q.push({{r,c},t+1});
                    grid[r][c] = 2;
                    cnt++;
                }
            }
            
        }

        if(cnt != cntFresh) return -1;
        return tm;
        
    }
};