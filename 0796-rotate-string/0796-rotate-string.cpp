class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {
            return false;
        }
        int n = s.length();
        string r = s;
        for(int i=0; i<n; i++)
        {
            if(r==goal)
            {
                return true;
            }
            rotate(r.begin(),r.begin()+1,r.end());
        }
        return false;
    }
};