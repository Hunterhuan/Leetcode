// 本来想用求和的方法的，但挺麻烦的。可以看一下别人的代码逻辑
// https://blog.csdn.net/u012501459/article/details/46553139

// solution1:
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height=matrix.size();
        if(height==0)
            return 0;
        int width=matrix[0].size();
        vector<vector<int>>  vec(height,vector<int>(width,0));
        int result=0;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(matrix[i][j]=='1')
                {
                    vec[i][j]=1;
                    if(i-1>=0&&j-1>=0)
                    {
                        int size=vec[i-1][j-1];
                        for(int k=1;k<=size;k++)
                        {
                            if(matrix[i-k][j]=='0'||matrix[i][j-k]=='0')
                            {
                                size=k-1;
                                break;
                            }
                        }
                        vec[i][j]+=size;
                    }
                }
                result=max(result,vec[i][j]);
            }
        }
        return result*result;
    }
};


// solution2 : 优化最里面的那个for循环
// 如果matrix[i][j]为1，那么A[i][j]=min(A[i-1][j-1],A[i-1][j],A[i][j-1])+1；如果matrix[i][j]为0，那么A[i][j]为0。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height=matrix.size();
        if(height==0)
            return 0;
        int width=matrix[0].size();
        vector<vector<int>>  vec(height,vector<int>(width,0));
        int result=0;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(matrix[i][j]=='1')
                {
                    vec[i][j]=1;
                    if(i>0&&j>0)
                        vec[i][j]+=min(min(vec[i-1][j],vec[i][j-1]),vec[i-1][j-1]);
                }
                result=max(result,vec[i][j]);
            }
        }
        return result*result;
    }
};


// solution3: 优化空间
// 但时间上似乎变慢了。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height=matrix.size();
        if(height==0)
            return 0;
        int width=matrix[0].size();
        vector<vector<int>>  vec(2,vector<int>(width,0));
        int result=0;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                vec[i%2][j]=0;//注意这里需要对其进行清空
                if(matrix[i][j]=='1')
                {
                    vec[i%2][j]=1;
                    if(i>0&&j>0)
                        vec[i%2][j]+=min(min(vec[(i-1)%2][j],vec[i%2][j-1]),vec[(i-1)%2][j-1]);
                }
                result=max(result,vec[i%2][j]);
            }
        }
        return result*result;
    }
};

