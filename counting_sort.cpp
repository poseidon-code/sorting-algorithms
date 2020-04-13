#include<iostream>

using namespace std;

class CS
{
	private :	int *a;
				int size;
                int *temp;
                int max;

	public :	CS(int n)
				{
					size = n;
					a = new int[n];
                    temp = new int[n];
					input();
				};
		
				~CS()
				{
					delete a;
				}
				
				void input();
                void findMax();
                void countingsort();
				void display();
};

// input function
void CS :: input()
{
	cout<<"Enter "<<size<<" elements : ";
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	cout<<"\n: ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
    
    findMax();
}

//maximum value finder
void CS :: findMax()
{
    max = a[0];
    int i;
    for(i=1;i<size;i++)
        if(a[i]>max)
            max = a[i];
    max += 1;
    countingsort();
}

//counting sort
void CS :: countingsort()
{
    int i;
    int count[10] = {0};
    for (i=0;i<size;i++)
        count[a[i]]++;
    for(i=1;i<10;i++)
        count[i] = count[i] + count[i-1];
    for(i=size-1;i>=0;i--)
    {
        /*
        t = a[i];
        pos =--count[t]
        temp[pos] = a[i];
        */
        temp[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for(int i=0;i<size;i++)
        a[i] = temp[i];
}

// display function
void CS :: display()
{
	cout<<"\n\n: SORTED ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}


// driver code
int main()
{
	int n;
	cout<<"-----COUNTING SORT----- \n";
	cout<<"Enter the size of the ARRAY : ";
	cin>>n;
	CS a(n);
	a.display();
	return 0;
}