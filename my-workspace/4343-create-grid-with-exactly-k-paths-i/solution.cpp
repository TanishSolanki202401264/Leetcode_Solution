class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {

        vector<string>grd(m,string(n,'#'));

        if(k==1){

            for(int j=0;j<n;j++){
                grd[0][j]='.';
            }
            for(int i=0;i<m;i++){
                grd[i][n-1]='.';
            }

            return grd;
        }

        if(k==2){
            if(m<2 || n<2){
                return {};
            }

            grd[0][0]='.';
             grd[0][1]='.';
             grd[1][0]='.';
             grd[1][1]='.';

            for(int j=1;j<n;j++){
                grd[1][j]='.';
            }
            for(int i=1;i<m;i++){
                grd[i][n-1]='.';
            }
            return grd;
        }

        if(k==3){
            if(n>=3 && m>=2){

            for(int j=0;j<3;j++){
                grd[0][j]='.';
                grd[1][j]='.';
            }
            for(int j=2;j<n;j++){
                grd[1][j]='.';
            }
        for(int i=1;i<m;i++){
            grd[i][n-1]='.';
                }
            }

            else if(m>=3 && n>=2){
                for(int i=0;i<3;i++){
                    grd[i][0]='.';
                    grd[i][1]='.';
                }

                for(int i=2;i<m;i++){
                    grd[i][1]='.';
                }
                for(int j=1;j<n;j++){
                    grd[m-1][j]='.';
                }
            }
            else{
                return {};
            }
            return grd;
        }

        if(k==4){
            if(n>=4 && m>=2){

                for(int j=0;j<4;j++){
                    grd[0][j]='.';
                    grd[1][j]='.';
                }

                for(int j=3;j<n;j++){
                    grd[1][j]='.';
                }
                for(int i=1;i<m;i++){
                    grd[i][n-1]='.';
                }
            }

            else if(m>=4 && n>=2){
                for(int i=0;i<4;i++){
                    grd[i][0]='.';
                    grd[i][1]='.';
                }

                for(int i=3;i<m;i++){
                    grd[i][1]='.';
                }
                for(int j=1;j<n;j++){
                    grd[m-1][j]='.';
                }
            }

            else if(m>=3 && n>=3){
                grd[0][0]='.';
                grd[0][1]='.';
                grd[1][0]='.';
                grd[1][1]='.';
                grd[1][1]='.';
                grd[1][2]='.';
                grd[2][1]='.';
                grd[2][2]='.';

                for(int j=2;j<n;j++){
                    grd[2][j]='.';
                }
                for(int i=2;i<m;i++){
                    grd[i][n-1]='.';
                }
            }
                else{
                return {};
                }
            return grd;
            }
        return {};
        }
    
};
