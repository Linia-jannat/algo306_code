

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void bubblesort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int flag=A[j];
                A[j]=A[j+1];
                A[j+1]=flag;
            }
        }
    }
}
int main()
{


    ofstream fileinput;
    srand(89345);
    fileinput.open("b1m.txt");
    int n=100000;
    //fileinput>>n;
    int*A=new int[n];

    for(int i=0;i<n;i++)
    {
        fileinput<<rand()<<endl;
        A[i]=rand();
    }

    fileinput.close();

    clock_t startTime=clock();
    bubblesort(A,n);

    clock_t endTime=clock();

    ofstream fileoutput;
    fileoutput.open("outputn1m.txt");
    for(int i=0;i<100000;i++)
    {
        fileoutput<<A[i]<<endl;
    }
    //count the lapse
    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"timelapse: "<<timelapse<<endl;
    fileoutput<<"timelapse: "<<timelapse<<endl;
    fileoutput.close();
    delete[] A;
}
