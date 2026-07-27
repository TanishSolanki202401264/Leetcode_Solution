class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+salary[i];
        }
        sort(salary.begin(),salary.end());
        return (double)(sum-salary[0]-salary[n-1])/(n-2);
    }
};
