class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>>arr;
        arr.push_back(nums);
        vector<int>p(15);
        for(int i=0;i<15;i++){
            int bit=14-i;
            long long count=0;
            int x=-1;
            for(size_t k=0;k<arr.size();k++){
                vector<int>&g=arr[k];
                int c=0;
                for(int y:g)
                    if((y>>bit)&1)
                        c++;

                int s=(int)g.size();
                if(c==s){
                    count=count+s;
                    continue;
                }
                x=(int)count+c;
         if(c>0 && c<s){
             vector<int>a;
             vector<int>b;
             a.reserve(c);
             b.reserve(s-c);
             for(int y:g){
                 if((y>>bit)&1){
                     a.push_back(y);
                 }
                 else{
                     b.push_back(y);
                 }
             }
             arr[k]=a;
             arr.insert(arr.begin()+k+1,b);
         }
break;     
            }   
            if(x==-1){
                x=(int)count;
            }
            p[i]=x;
        }
        return p;
    }
};
