#include <iostream>
#include <vector>
using namespace std;

void setRow(vector<vector<int>> &matrix,int row,int i){
    for(int j =0;j<row;j++){
        if(matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}

void setCol(vector<vector<int>> &matrix,int col,int j){
    for(int i =0;j<col;i++){
        if(matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}
void setMatrixZero(vector<vector<int>> &matrix,int col, int row){
    for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            if(matrix[i][j] ==0){
                setRow(matrix,row,i);
                setCol(matrix,col,j);
            }
        }
    }
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j] =0;
                }
            }
        }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    setMatrixZero(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}