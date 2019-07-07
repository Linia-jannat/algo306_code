#include <iostream>
#include <fstream>
using namespace std;

int main()
{ int ro,co;
    ifstream fileinput;
    fileinput.open("input.txt");
    fileinput>>ro>>co;

    int **array;
    array=new int*[ro];
    for(int i=0;i<ro;i++)
    {
        array[i]=new int[co];
    }

    for (int i=0;i<ro;i++){
    for (int j=0;j<co;j++)
    {
        fileinput>>array[i][j];

        cout<<array[i][j]<<" ";

    }
        cout<<endl;
    }
}

