/*
 * @Description: 
 * @Author: Yuan Jie
 * @Data: 
 * @LastEdit: moogila@outlook.com
 * @LastEditTime: 2021-09-06 12:49:49
 * @FileName: 
 */
#include <iostream>

using namespace std;

//贪心

int findMinIndex(string &num,int index,int k)
{
    int min = index;
    while (k--)
    {
        if(num[index + k] < num[index])
        {
            min = index + k;
        }
    }
    
}

int main() {
    int k,n,index = 0 ;
    string num;
    string res = "";
    cin >> k >> n;
    cin.getline(num);
    while (k && k < num.length)
    {
        index = findMinIndex(num,index,k)
        res.append(num[index]);
        k - index;
        /* code */
    }
    



    return 0;
}