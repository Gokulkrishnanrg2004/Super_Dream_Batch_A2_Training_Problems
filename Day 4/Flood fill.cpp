class Solution {
    public:
    void dfs(vector<vector<int>>& image,int r,int c,int oldcolor,int newcolor)
    {
        int row = image.size();
        int col = image[0].size();
        if(r<0 || c<0 || r>=row || c>=col || image[r][c]!=oldcolor || image[r][c]==newcolor)
        {
            return;
        }   
        image[r][c] = newcolor;

        dfs(image,r+1,c,oldcolor,newcolor);
        dfs(image,r-1,c,oldcolor,newcolor);
        dfs(image,r,c+1,oldcolor,newcolor);
        dfs(image,r,c-1,oldcolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int oldcolor = image[sr][sc];
        if(oldcolor != color)
        {
            dfs(image,sr,sc,oldcolor,color);
        }    
        return image;
    }
};
