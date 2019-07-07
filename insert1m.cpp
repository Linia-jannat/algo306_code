#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void insertsort(int A[],int n)
{
    int i,k,N;
    for(i=1;i<n;i++)
    {
      k=A[i];
      N=i-1;
      while((N>=0) &&  (A[N]>k))
      {
          A[N+1]=A[N];
          N=N-1;
      }
      A[N+1]=k;
    }
}
int main()
{


    ofstream fileinput;
    srand(89345);
    fileinput.open("10.txt");
    int n=100000;

    int*A=new int[n];

    for(int i=0;i<n;i++)
    {
        fileinput<<rand()<<endl;
        A[i]=rand();
    }

    fileinput.close();

    clock_t startTime=clock();
    insertsort(A,n);

    clock_t endTime=clock();

    ofstream fileoutput;
    fileoutput.open("output10nm.txt");
    for(int i=0;i<100000;i++)
    {
        fileoutput<<A[i]<<endl;
    }

    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"timelapse: "<<timelapse<<endl;
    fileoutput<<"timelapse: "<<timelapse<<endl;
    fileoutput.close();
    delete[] A;
}
