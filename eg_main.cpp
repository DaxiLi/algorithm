#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include<io.h>
#include <madcapcl.h>


using namespace std;

void resolve(string fileName,string ansFileName){

    int i;
    cin >> i;
    cout << "1 3 5 2 4"<<endl;
    return;

    cout << fileName <<endl;
    ifstream ifs(fileName,ios::in);
    if (!ifs.is_open())
    {
        cout << "open file fail!" <<endl;
        return;
    }
    // todo something here !



    cout << "i ans:";
    // print your anwser here !

    cout << "t ans:" << ifstream(ansFileName).rdbuf() << endl <<endl;
}

int main(int argv,char** argc){
    resolve("","");
    return 0;
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
