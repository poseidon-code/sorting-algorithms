#include<iostream>

using namespace std;

class IS
{
	private:	int *a;
				int size;
	
	public:		IS(int n)
				{
					size = n;
					a = new int[size];
					input();
				}
				
				~IS()
				{
					delete a;
				}
				
				void input();
				void display();
				void insertionsort();
};

// input function
void IS :: input()
{
	cout<<"Enter "<<size<<" elements : ";
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	cout<<"\n: ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	
	insertionsort();
}

// display function
void IS :: display()
{
	cout<<"\n\n: SORTED ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}


// insertion sort
void IS :: insertionsort()
{
	int i, j, n;
	n = size;
	int temp;
	for(i=1;i<n;i++)
	{
		temp = a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--)
			a[j+1] = a[j];
		a[j+1] = temp;
	}
	display();
}


// driver code
int main()
{
	int n;
	cout<<"-----INSERTION SORT----- \n";
	cout<<"Enter the size of the ARRAY : ";
	cin>>n;
	IS a(n);
	return 0;
}
