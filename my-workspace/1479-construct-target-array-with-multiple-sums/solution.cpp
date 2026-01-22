class Solution {
public:
    bool isPossible(vector<int>& target) {
        //Max heap
        priority_queue<long long >p;
        long long  sum=0;
        for(int i=0;i<target.size();i++){
            p.push(target[i]);
            sum+=target[i];
        }
        long long  MaxEle,Remsum,Element;
        //jya sudhii badha element 1 na thay jay tya sudhii
        while(p.top()!=1){
            MaxEle=p.top();
            p.pop();
            Remsum=sum-MaxEle;
            //Edge case
            //Maxelment=Remsum+Element
            if(Remsum<=0 || Remsum>=MaxEle){
                return 0;
            }
            //changes will happen here

         Element=MaxEle% Remsum;
        if(Element==0){
            if(Remsum!=1){
                return 0;
            }
            else{
                return 1;
            }
        }
        sum=Remsum+Element;
        p.push(Element);
        }
        return 1;
    }
};
