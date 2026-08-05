class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int i;
        int five=0, ten=0;
        for(i=0;i<n;i++){
            int money = bills[i];
            if(money==5){
                five++;
            }
            else if(money==10){
                if(five==0)
                return 0;
                five--;
                ten++;
            }
            else if(money==20){
                if(ten>0){
                    ten--;
                    if(five==0)
                    return 0;
                    five--;
                }
                else{
                    if(five<3)
                    return 0;
                    five = five-3;
                }
            }
        }
        return true;
    }
};