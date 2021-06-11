#include <iostream>
#include <iomanip>

#define MX 400

using namespace std;

void alg3(int* res,int A[],int B[],int N,int ALL_TIME);
int sum(int* A,int N);


int main(){
    int N = 31;
    int A[100] = {0,6 ,7 ,7 ,4 ,4 ,2 ,9 ,5 ,3 ,8 ,9 ,1 ,5 ,10 ,10 ,5 ,8, 7 ,6 ,1 ,6 ,7 ,3 ,10, 6, 3 ,1 ,3 ,10 ,5 ,4 ,10 ,10 ,9 ,9 ,5 ,9 ,3 ,10 ,8 };
    int B[100] = {0,2 ,7 ,9 ,7 ,10, 5, 3, 2, 8, 4, 8, 10, 8, 6, 9 ,2 ,2, 7, 4, 2, 7, 5, 2, 3, 3, 1 ,2 ,6 ,5 ,10 ,1 ,9 ,7 ,5 ,4 ,3 ,1 ,2 ,10 ,1  };
    int ALL_TIME = sum(A,N);
    int res = 0xFFFF;
    // cout <<res;
    alg3(&res,A,B,N - 1,ALL_TIME);
    return 0;
}
/**
 * 每一次只增加一个任务，先全部让B机器去做，然后逐步增加A的时间，在A的最大容纳限度内，将任务逐渐转移给A。
 * 到最后任务数为N时，当前A用的时间和B用的时间最长的就是该任务序列的最长时间。只需要找到A和B最小的排列即该任务的最优解。
 */


void alg3(int* res,int A[],int B[],int N,int ALL_TIME){
    // 二维数组 (m[完成任务数][所耗时间]) => 在该条件下，B所耗时间 
    int m[N + 1][MX] = {0};
    if (A[1] > B[1]){
        m[1][0] = B[1];
    }
    for (int i = 1; i <= N;i++){
        // 遍历 A 机器可能用的所有时间 **模拟时间流逝**
        for (int j = 0;j < MX;j++){
            if (j > A[i])// 如果 A有足够时间了，那就让它做，可不能让它闲着
            {
                // 虽然你能做这个工作，但是我要看看，你做的好不好
                if (m[i - 1][j - A[i]] < m[i - 1][j] + B[i]) 
                {
                     m[i][j] = m[i - 1][j - A[i]];
                }else{
                    m[i][j] = m[i - 1][j] + B[i];
                }
            }else // 不然，就只能让机器B背锅了，能者多劳
            {
                m[i][j] = B[i] + m[i - 1][j];
            }
        }
    }



    // for (int i = 0;i <= N ;i++){
    //     for (int j = 0;j < MX;j++){
    //         cout << setw(3) <<  m[i][j] <<"  ";
    //     }
    //     cout << endl;
    // }

    int tmp = 0xFFFFFF;
    for(int i = 0;i <= ALL_TIME;i++)
    {
        if (m[N][i] < tmp && i < tmp)
        {
            tmp = m[N][i] > i ? m[N][i] : i;
        }
    }
    cout << tmp;
}


int sum(int *A,int N){
    int sum = 0;
    for (int i = 0;i < N;i++){
        sum += A[i];
    }
    return sum;
}