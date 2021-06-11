#include <iostream>
#include <string>
#include <algorithm>
#include <fstream> 
#include<io.h>
#include <madcapcl.h>

// if u want test your program,just keep it else anotation it
// #define DEBUG break;


using namespace std;

void resolve(string fileName,string ansFileName){
    cout << fileName <<endl;
    ifstream ifs(fileName,ios::in);
    if (!ifs.is_open())
    {
        cout << "open file fail!" <<endl;
        return;
    }
    // todo something here !
    int n = 0,k = 0;
    ifs >> n>>k;
    int S[k + 1];
    int oil = n;
    int add_oil_num = 0;
    for (int i = 0; i< k + 1;i++)
    {
        ifs >> S[i]; 
    }
    // Go through all the gas stations
    for (int val : S)
    {
        // The distance is longer than N, not reachable
        if (val > n)
        {
            add_oil_num = -1;
            break;
        }
        // There isn't enough oil left to reach the next station
        if (val > oil) 
        {
            add_oil_num++;
            oil = n - val;
            continue;
        }
        // pass one station ,reduce the oil
        oil -= val;
    }

    cout << "i ans:";
    // print your anwser here !
    if (oil == -1)
    {
        cout << "No Solution" <<endl;
    }else{
        cout << add_oil_num <<endl;
    }
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
        // break;
    }while(_findnext(Handle,&FileInfo) == 0);
    _findclose(Handle);
    return 0;
}
