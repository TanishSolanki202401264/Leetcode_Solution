class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(colors[i]!=colors[0])
            {
                ans =max(ans,i);
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(colors[i]!=colors[n-1])
            {
                ans = max(ans, n-1-i);
                break;
            }
        }
        return ans;
        //ama biji approach compare with first and last house valii pan possible chee atle apde first and last house ne levana dhyan ma and tena adhare max distance ne update karvanu
    }
};
