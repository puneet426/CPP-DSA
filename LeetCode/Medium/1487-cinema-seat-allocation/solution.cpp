class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=n*2;
        sort(reservedSeats.begin(),reservedSeats.end());
        for(int i=0;i<reservedSeats.size();i++){
            int curr=reservedSeats[i][0];
            int flag25=1;
            int flag47=1;
            int flag69=1;

            while(i<reservedSeats.size()&&reservedSeats[i][0]==curr){
                if(reservedSeats[i][1]>=2&&reservedSeats[i][1]<=5){
                    flag25=0;
                    if(reservedSeats[i][1]>=4&&reservedSeats[i][1]<=5){
                        flag47=0;
                    }
                }else if(reservedSeats[i][1]>=6&&reservedSeats[i][1]<=9){
                    flag69=0;
                    if(reservedSeats[i][1]>=6&&reservedSeats[i][1]<=7){
                        flag47=0;
                    }
                }
                i++;

            }
           if(flag69==0&&flag25==0&&flag47==0){
            ans--;
            ans--;
           }else if(flag69==0||flag47==0||flag25==0){
            ans--;
           }
           i--;
           
        }
        return ans;
    }
};