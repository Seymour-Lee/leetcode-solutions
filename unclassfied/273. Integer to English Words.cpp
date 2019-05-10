class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        int billion = num / 1000000000;
        int million = (num - billion * 1000000000) / 1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int rest = num - billion * 1000000000 - million * 1000000 - thousand * 1000;
        string ans = "";
        if(billion) ans += three(billion) + " Billion";
        if(million){
            if(ans.empty() == false) ans += " ";
            ans += three(million) + " Million";
        }
        if(thousand){
            if(ans.empty() == false) ans += " ";
            ans += three(thousand) + " Thousand";
        }
        if(rest){
            if(ans.empty() == false) ans += " ";
            ans += three(rest);
        }
        return ans;
    }
    
private:
    string one(int num){
        switch(num) {
          case 1: return "One";
          case 2: return "Two";
          case 3: return "Three";
          case 4: return "Four";
          case 5: return "Five";
          case 6: return "Six";
          case 7: return "Seven";
          case 8: return "Eight";
          case 9: return "Nine";
        }
        return "";
    }
    
    string twoLessThan20(int num) {
        switch(num) {
          case 10: return "Ten";
          case 11: return "Eleven";
          case 12: return "Twelve";
          case 13: return "Thirteen";
          case 14: return "Fourteen";
          case 15: return "Fifteen";
          case 16: return "Sixteen";
          case 17: return "Seventeen";
          case 18: return "Eighteen";
          case 19: return "Nineteen";
        }
        return "";
      }
    
    string ten(int num) {
        switch(num) {
          case 2: return "Twenty";
          case 3: return "Thirty";
          case 4: return "Forty";
          case 5: return "Fifty";
          case 6: return "Sixty";
          case 7: return "Seventy";
          case 8: return "Eighty";
          case 9: return "Ninety";
        }
        return "";
    }
    
    string two(int num) {
        if (num == 0) return "";
        else if (num < 10) return one(num);
        else if (num < 20) return twoLessThan20(num);
        else {
            int tenner = num / 10;
            int rest = num - tenner * 10;
            if (rest != 0) return ten(tenner) + " " + one(rest);
            else return ten(tenner);
        }
    }
    
    string three(int num) {
        int hundred = num / 100;
        int rest = num - hundred * 100;
        string res = "";
        if (hundred*rest != 0) res = one(hundred) + " Hundred " + two(rest);
        else if ((hundred == 0) && (rest != 0)) res = two(rest);
        else if ((hundred != 0) && (rest == 0)) res = one(hundred) + " Hundred";
        return res;
    }
};