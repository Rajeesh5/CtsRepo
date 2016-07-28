#include<iostream>
#include<malloc.h>
#define N 4

using namespace std;


void display(int **matrix ,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;

    }
}


int ** multiply(int A[][N], int B[][N])
{
    int **C;
    C=(int**)calloc(4,sizeof(int*));
        for(int k=0;k<4;k++)
            C[k]= (int*)calloc(4,sizeof(int));


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return C;
}


int main()
{

    int mat1[4][4]={{2,3,2,4},{4,2,4,1},{4,1,1,4},{4,1,4,3}};
    int mat2[4][4]={{2,3,2,4},{4,2,4,1},{4,1,1,4},{4,1,4,3}};
    int **ans=multiply(mat1,mat2);
    display(ans,4,4);



    return 0;

}



















/*
class Matrix
{
    int **matrix,row,col;
public:
    Matrix(int i,int j)
    {
        row=i;col=j;
        matrix=(int**)calloc(row,sizeof(int*));
        for(int k=0;k<row;k++)
            matrix[k]= (int*)calloc(col,sizeof(int));
    }

    void inputMatrixA();
    void inputMatrixB();

    void display()
    {
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cout<<matrix[i][j]<<"  ";
            cout<<endl;
    }

    ~Matrix(){
        for(int k=0;k<row;k++)
            free(matrix[k]);
        free(matrix);
    }

};
*/
