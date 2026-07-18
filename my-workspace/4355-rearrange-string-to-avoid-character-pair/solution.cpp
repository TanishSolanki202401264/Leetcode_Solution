class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string count;
        for(char ch:s){
            if(ch==y){
                count=count+ch;
            }
        }


          for(char ch:s){
              if(ch!=x && ch!=y){
                  count=count+ch;
              }
          }

        for(char ch:s){
            if(ch==x){
                count=count+ch;
            }
        }
        return count;
    }
};
