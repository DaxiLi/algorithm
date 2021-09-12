#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <io.h>
#include <madcapcl.h>
#include <stack>


using namespace std;


int check(int *res,int k,int n){
    int ck_min[n] = {INT_MAX};
    int ck_max[n] = {0};
    int num[n] = {0};
    for (int i = 0;i < n;i++)
    {
        ck_min[i] = k;
    }
    cout <<"start max:";
    for (int val : ck_max)cout << val<<" ";
    cout <<endl << "min:";
    for (int val : ck_min)cout << val<<" ";
    cout <<endl;
    for (int i = 0;i < k;i++)
    {
        num[res[i]]++;
        if (ck_max[res[i]] < i)ck_max[res[i]] = i;
        if (ck_min[res[i]] > i)ck_min[res[i]] = i;
    }
    cout <<"max:";
    for (int val : ck_max)cout << val<<" ";
    cout <<endl << "min:";
    for (int val : ck_min)cout << val<<" ";
    for(int i = 0; i< n;i++)
    {
        if (ck_max[i] + ck_min[i] <= k - 2)
        {
            return 0;
        }
    }
    for (int val : num){
        if (val <= 1)
        {
            return 0;
        }
    }
    return 1;
}

void resolve(string fileName,string ansFileName){
    cout << fileName <<endl;
    ifstream ifs(fileName,ios::in);
    if (!ifs.is_open())
    {
        cout << "open file fail!" <<endl;
        return;
    }
    // todo something here !
    /**
     * NOTE：
     * 对于n分无和集问题
     * 目前，就。。。遍历，将元素分到n个集合，然后
     * 再依次检测是否满足条件辽，不过好在条件检测并不复杂，只需要
     * 将最小值加上最大值，看是否大于K即可
     * 因为，k是正整数集中某一个不确定数，所以将N作为树枝数，从1开始增加k即可
     * 由于k大小未知，此次不再使用数组作为栈使用，使用cpp 里面的stack
     *      如过使用整型数组，在遍历检测时，
     */
    int n,k;
    ifs >>n;
    
    int deep = 2;
    while(deep < INT_MAX)
    {
        k = deep;
        int res[k] = {0};
        int index = 0;
        while (index >= 0)
        {
            if (index >= k)
            {
                if (check(res,k,n))
                {
                    cout << "success"<<endl;
                    deep = INT_MAX;
                    break;
                    // cout << k;
                    // cout << res[index - 1];
                }
                index--;
                
            res[index]++;
                continue;
            }
            if (res[index] >= n)
            {
                index--;
                
            res[index]++;
                continue;
            }
            index++;
            res[index] = 0;
            // cout <<n<<endl;
            cout <<endl;
            for (int val : res)cout << val << " ";
            cout <<endl;
        }
        deep++;
    }

    // cout << "i ans:";
    // // print your anwser here !
    // cout << deep<<endl;
    // for (int i = 0;i < n;i++)
    // {
    //     for (int j = 0;j < deep;j++)
    //     {
    //         if (res[j] == i)
    //         {
    //             cout << deep + 1;
    //         }
    //     }
    //     cout << endl;
    // }
    cout << "t ans:" << ifstream(ansFileName).rdbuf() << endl <<endl;
}

int main(int argv,char** argc){
    string baseDir,testDir,answerDir,testFile;
    int index = 0;
    baseDir = argc[0];
    index = baseDir.rfind('\\');
    baseDir = baseDir.substr(0,index + 1);
    testDir = baseDir + "test\\";
    testFile = testDir + "*.in";
    answerDir = baseDir + "answer\\";
    _finddata_t FileInfo;
    long Handle = _findfirst(testFile.c_str(),&FileInfo);
    if(Handle == -1l){
        printf("has no found files\n");
        _findclose(Handle);
        return 0;
    }
    do{
        string fname = FileInfo.name;
        string ans_name =  fname.substr(0,fname.rfind('.') + 1) + "out";
        resolve(testDir + fname,answerDir + ans_name);

        // if u want test your program,just keep it else anotation it
        break;
    }while(_findnext(Handle,&FileInfo) == 0);
    _findclose(Handle);
    return 0;
}
