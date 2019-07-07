#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
void Merze(int A[],int p, int q,int r)
{

	int n1=q-p+1,i,j,k;

	int n2=r-q;

	int L[n1],R[n2];

	for(i=0;i<n1;i++)

	{
		L[i]=A[p+i];
	}

	for(j=0;j<n2;j++)
	{
		R[j]=A[q+j+1];
	}

	i=0,j=0;

	for(k=p;i<n1&&j<n2;k++)
	{
		if(L[i]<R[j])
		{
			A[k]=L[i++];
		}
		else
		{
			A[k]=R[j++];
		}
	}

	while(i<n1)
	{
		A[k++]=L[i++];
	}

	while(j<n2)
	{
		A[k++]=R[j++];
	}
}

void MerzeSort(int A[],int p,int r)
{
	int q;

	if(p<r)
	{
		q=(p+r)/2;
		MerzeSort(A,p,q);
		MerzeSort(A,q+1,r);
		Merze(A,p,q,r);
	}

}
clock_t startTime=clock();
int main()
{


    ofstream fileinput;
    srand(time(NULL));
    fileinput.open("100k.txt");
    int n=100000;

   int A[n];

    for(int i=0;i<n;i++)
    {
         A[i]=rand()%5000;
        fileinput<<rand()<<endl;

    }
    fileinput.close();

      MerzeSort(A,0,n-1);

    ofstream fileoutput;
    fileoutput.open("100koutput.txt");
 clock_t endTime=clock();
    for(int i=0;i<100000;i++)
    {

        fileoutput<<A[i]<<endl;
    }
    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<timelapse<<endl;

    fileoutput.close();
    delete[] A;
}
