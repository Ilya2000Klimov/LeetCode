class Solution {
public:
    vector<int> prefixSum(const vector<int>& A)
    {
	    int N = A.size();
    	vector<int> B(N+1, 0);
    	for (int i=0; i<N; ++i)
        {
    		B[i+1] = B[i] + A[i];
    	}
    	return B;
    }


    vector<vector<int>> findPrefixSums2D(vector<vector<int>> A)
    {
    	int N = A.size(); // num rows
    	int M = A[0].size(); // num cols
    	vector<vector<int>> prefixSum1D(N); // 2D array to store prefix sums for each row

    	for (int row=0; row<N; ++row)
        {
    		prefixSum1D[row] = prefixSum(A[row]); //see slide 19 for code
    	}
    	vector<vector<int>>prefixSum2D(N+1, vector<int>(M+1, 0));
    	for (int col=1; col<=M; ++col)
        {
    		for(int row=0; row<N; ++row)
            {
		    	prefixSum2D[row+1][col] = prefixSum2D[row][col]+prefixSum1D[row][col];
            }
        }
    	return prefixSum2D;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int sizeR = mat.size();
        int sizeC = mat[0].size();
        vector<vector<int>> prefixSum = findPrefixSums2D(mat);
        vector<vector<int>> ans(sizeR, vector<int>(sizeC, 0));
        
        
    for (int row = 0; row != sizeR; row++)
    {
        for (int col = 0; col != sizeC; col++)
        {
            ans[row][col] = prefixSum[std::min(row + k + 1, sizeR)][std::min(col + k + 1, sizeC)]
                + prefixSum[std::max(row - k, 0)][std::max(col - k, 0)]
                - prefixSum[std::min(row + k + 1, sizeR)][std::max(col - k, 0)]
                - prefixSum[std::max(row - k, 0)][std::min(col + k + 1, sizeC)];
            //ans[row][col] = prefixSum[row][col];
        }
    }
        
        return ans;
        
        
    }
};

