// 1358. Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int size = s.size();
        int left = 0, right = 0;
        int countA = 0, countB= 0, countC = 0;
       
            while(right < size)
            {
                if(s[right] == 'a')
                    countA+=1;
                else if(s[right] == 'b')    
                    countB+=1;
                else    
                    countC+=1;
                while(countA > 0 && countB > 0 && countC > 0)
                {
                    cout << "IN the loop " << endl;
                    res += s.size()-right;
                    if(s[left] == 'a')
                        countA--;
                    else if(s[left] == 'b')
                        countB--;
                    else
                        countC--;
                    left++;
                }
                right++;
            }


        return res;
    }
};