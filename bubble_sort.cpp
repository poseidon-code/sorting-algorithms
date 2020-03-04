#include<iostream>

using namespace std;

class BS
{
	private:	int *a;
			int size;
	
	public:		BS(int n)
			{
				size = n;
				a = new int[size];
				input();
			}
				
			~BS()
			{
				delete a;
			}
			
			void input();
			void display();
			void bubblesort();
};

// input function
void BS :: input()
{
	cout<<"Enter "<<size<<" elements : ";
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	cout<<"\n: ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	
	bubblesort();
}

// display function
void BS :: display()
{
	cout<<"\n\n: SORTED ARRAY : \n";
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

// bubble_sort
void BS :: bubblesort()
{
	int i, j, flag, n;
	i = 0;
	n = size;
	flag = 1;
	int temp;
	while(i<n-1 && flag==1)
	{
		j = 0;
		flag = 0;
		while(j<n-i-1)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	display();
}


// driver code
int main()
{
	int n;
	cout<<"-----BUBBLE SORT----- \n";
	cout<<"Enter the size of the ARRAY : ";
	cin>>n;
	BS a(n);
	return 0;
}
