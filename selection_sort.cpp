#include<iostream>

using namespace std;

class SS
{
	private:	int *a;
			int size;
	
	public:		SS(int n)
			{
				size = n;
				a = new int[size];
				input();
			}
			
			~SS()
			{
				delete a;
			}
			
			void input();
			void display();
			void selectionsort();
};

// input function
void SS :: input()
{
	cout<<"Enter "<<size<<" elements : ";
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	cout<<"\n: ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	
	selectionsort();
}

// display function
void SS :: display()
{
	cout<<"\n\n: SORTED ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}


// selection sort
void SS :: selectionsort()
{
	int i, j, min, pos, n;
	n = size;
	int temp;
	for(i=0;i<n-1;i++)
	{
		min = a[i];
		pos = i;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min = a[j];
				pos = j;
			}
		}
		if(i!=pos)
		{
			temp = a[i];
			a[i] = a[pos];
			a[pos] = temp;
		}
	}
	display();
}


// driver code
int main()
{
	int n;
	cout<<"-----SELECTION SORT----- \n";
	cout<<"Enter the size of the ARRAY : ";
	cin>>n;
	SS a(n);
	return 0;
}
