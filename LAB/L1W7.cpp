#include <iostream>
#include <limits.h>
using namespace std;

void getMaxMinRow(int** matrix,int row,int col,int** maxRowPtrPtr,int** minRowPtrPtr);
void displayMatrix(int** matrix,int row,int col);
void swapRow(int *a,int *b,int col);


int main()
{
    int** matrix;
    int row,col;
    cin>>row>>col;
    //TODO-행렬에 메모리 할당
    matrix=new int*[row];

    //TODO-행렬 채우기
    for(int a = 0;a<row;a++){
        matrix[a]=new int[col];
    }
    for(int b = 0;b<row;b++){
        for(int c = 0;c<col;c++){
            cin>>matrix[b][c];
        }
    }
    
    ////////////////////////////////////////
    int *maxRowPtr,*minRowPtr;
    cout<<"---Before Swap Max Min---"<<endl;
    displayMatrix(matrix,row,col);
    getMaxMinRow(matrix,row,col,&maxRowPtr, &minRowPtr);
    swapRow(maxRowPtr,minRowPtr,col);
    cout<<"---After Swap Max Min---"<<endl;
    displayMatrix(matrix,row,col);

    return 0;
}

void getMaxMinRow(int** matrix,int row,int col,int** maxRowPtrPtr,int** minRowPtrPtr){
    int* sumrowarray;
    sumrowarray = new int[row];
    for(int b = 0;b<row;b++){
        int sumrow = 0;
        for(int c = 0;c<col;c++){
            sumrow= sumrow + matrix[b][c];
        }
        sumrowarray[b] = sumrow;
    }
    int min = 2147483647;
    for (int i = 0;i<row;i++){
        if(sumrowarray[i] < min){
            min = sumrowarray[i];
            *minRowPtrPtr=matrix[i];
        }
    }
    int max = -2147483648;
    for (int i = 0;i<row;i++){
        if(sumrowarray[i]>=max){
            max = sumrowarray[i];
            *maxRowPtrPtr=matrix[i];
        }
    }
  //  cout<<*minRowPtrPtr<<endl;
    //    cout<<*maxRowPtrPtr<<endl;
}
void displayMatrix(int** matrix,int row,int col){
    for(int b = 0;b<row;b++){
        for(int c = 0;c<col;c++){
            cout<<matrix[b][c];
        }
        cout<<endl;
    }
}
void swapRow(int *a,int *b,int col){
    for (int i = 0;i<col;i++){
    int temp=a[i];
    a[i]=b[i];
    b[i] = temp;
    }
}