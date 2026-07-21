class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int currzero=0;
        int prevzero=0;
        int onecnt=0;
        int zeroseg=0;
        int maxone=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                currzero++;
            }
            else{
                onecnt++;
                maxone=max(maxone,currzero+prevzero);
              if(currzero!=0){
                prevzero=currzero;
                zeroseg++;
              }  
              currzero=0;
            }
        }
        if(currzero!=0)
            zeroseg++;
        maxone=max(maxone,currzero+prevzero);
        return onecnt+((zeroseg>1)?maxone:0);

    }
};
