class Solution {
public:
    int climbStairs(int n)
    {
        int n2 = 1;
        int n1 = 1;
        int res = 1;
        for(int i = 1; i < n; i++)
        {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
        }
        
        return (n <= 0) ? 0 : res;
    }
};

/*if (n == 0)
            return 0;
        if (n <= 2)
            return n;
        else
            ()*/