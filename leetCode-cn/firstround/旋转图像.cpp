/*
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        LeadingDiagonalMirror(matrix);
        LeftRightMirror(matrix);
    }
    void LeadingDiagonalMirror(vector<vector<int>>& matrix)
    {
        for(int i = 0; i < matrix.size() - 1; ++i)
        {
            for(int j = i + 1; j < matrix[0].size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void LeftRightMirror(vector<vector<int>>& matrix)
    {
        auto vecLRMirror = [](vector<int>& vec)
        {
            for(int i = 0, j = vec.size() - 1; i < j; ++i, --j)
                swap(vec[i], vec[j]);
        };
        for(int i = 0; i < matrix.size(); ++i)
        {
            vecLRMirror(matrix[i]);
        }
    }
};