#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;

int main(int argc, char*argv[])
{
	srand(time(NULL));
	unsigned int i;
	long long int num;
	num = (long long int)atoll(argv[1]);
	//printf("%u\n",i);
	ofstream fout;
	fout.open("AVL/data.txt");
	long long int j;
	for(j=0;j<num-1;j++)
	{
		i = rand() % (num*10);
		fout<<i<<endl;
	}
	i = rand() % num*10;
	fout<<i;
	fout.close();
	return 0;
}