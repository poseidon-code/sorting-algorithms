#include<iostream>

using namespace std;

class RS
{
	private :	int *a;
				int size;
				int max;
                int *temp;
                int exp;
	
	public :	RS(int n)
				{
					size = n;
                    exp = 1;
					a = new int[n];
                    temp = new int[n];
					input();
				};
		
				~RS()
				{
					delete a;
				}
				
				void input();
				void findMax();
                void sort();
                void radixsort();
				void display();
};

// input function
void RS :: input()
{
	cout<<"Enter "<<size<<" elements : ";
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	cout<<"\n: ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";

    findMax();
}

// display function
void RS :: display()
{
	cout<<"\n\n: SORTED ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

//maximum value finder
void RS :: findMax()
{
    max = a[0];
    int i;
    for(i=1;i<size;i++)
        if(a[i]>max)
            max = a[i];
    radixsort();
}

//counting sort
void RS :: sort()
{
    int i, t, pos;
    int count[10] = {0};
    for (i=0;i<size;i++)
    {
       t = (a[i]/exp)%10;
       count[t]++;
    }
    for(i=1;i<10;i++)
        count[i] = count[i] + count[i-1];
    for(i=size-1;i>=0;i--)
    {
        t = (a[i]/exp)%10;
        pos = --count[t];
        temp[pos] = a[i];
    }
    for(int i=0;i<size;i++)
        a[i] = temp[i];
}

//radix sort
void RS :: radixsort()
{
    int cntdigit = 0;
    int i;
    while (max>0)
    {
        max = max/10;
        cntdigit++;
    }
    for(i=1;i<=cntdigit;i++)
    {
        sort();
        exp = exp*10;
    }
    
}

// driver code
int main()
{
	int n;
	cout<<"-----RADIX SORT----- \n";
	cout<<"Enter the size of the ARRAY : ";
	cin>>n;
	RS a(n);
	a.display();
	return 0;
}
