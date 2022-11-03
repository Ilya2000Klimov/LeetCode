class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int nSize = nums1.size();
        vector <int> N(nSize, 0);
        
        if (m == 0)
        nums1 = nums2;
        else if (n == 0);
        else
        {
            for(int i = 0, n1 = 0, n2 = 0; i < nSize; i++)
            {
                N[i] = n1 >= m ?  N[i] = nums2[n2++] : n2 >= n ? N[i] = nums1[n1++] : nums1[n1] < nums2[n2] ? nums1[n1++] : nums2[n2++];
                
                /*if (n1 >= m)
                    N[i] = nums2[n2++];
                else if(n2 >= n)
                    N[i] = nums1[n1++];
                else
                    N[i] = nums1[n1] < nums2[n2] ? nums1[n1++] : nums2[n2++];*/
                
            }
        
            nums1 = N;
        }
    }
};