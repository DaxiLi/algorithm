#include <iostream>
#include <iomanip>
/**
 * 石子合并问题：
 * 
 */
using namespace std;
#define MAX_SIZE 100

void solve(int res[MAX_SIZE][MAX_SIZE],int *stones,int N);


void solve(int res[MAX_SIZE][MAX_SIZE],int *stones,int N){
    for (int i = 0; i < N;i++)
    {
        res[i][i] = stones[i];
    }
    for (int sdept = 1;sdept <= N;sdept++)
    {
        for (int i = 1;i < N + 1 - sdept;i++)
        {
            res[i % N][(i + sdept)%N] = res[(i + 1)%N][(i + sdept)%N] + res[i%N][(i - 1 + sdept)%N];
        }
    }


    for (int i = 0;i < N;i++){
        for (int j = 0;j < N;j++)
        {
            cout << setw(4) <<res[i][j];
        }
        cout <<endl;
    }
}

int main(){
    int N = 5;
    int stones[] = {0,4,4,5,6};

    int res[MAX_SIZE][MAX_SIZE] = {0};
    solve(res,stones,N);

    return 0;
}