#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;

}


int partition (int arr[], int low, int high, int*total)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			if(i!=j&& arr[i]!=arr[j]){*total=*total+1;}

		}
	}
	swap(&arr[i + 1], &arr[high]);
	if(i+1!=high&& arr[i+1]!=arr[high]){*total=*total+1;}

	return (i + 1);
}

void quickSort(int arr[], int low, int high, int* total)
{


	if (low < high)
	{

		int pi = partition(arr, low, high,total);
		quickSort(arr, low, pi - 1,total);

		quickSort(arr, pi + 1, high,total);

	}

}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++){
        if(arr[i]==1){
          cout<<"XS ";}
        else
          if (arr[i]==2)
            cout<<"S ";
          else
            if (arr[i]==3)
               cout<<"M ";
            else
              if (arr[i]==4)
                cout<<"L ";
              else
                if (arr[i]==5){
                  cout<<"XL ";}
                else
                  if (arr[i]==6)
                    cout<<"XXL ";
                  else
                    if (arr[i]==7)
                      cout<<"XXXL ";


	}

	cout << "\n";
}

// Driver Code
int main()
{
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    // freopen("output.txt", "w", stdout);
	#endif
	string str;
    int t,n;
    cin>>t;
    for(int j=0;j<t;j++){
    cin>>n;
	int arr[n],total=0;
      for (int i=0;i<n;i++){
        cin>>str;
        if(str=="XS"){
        arr[i]=1;}
        else
          if (str=="S")
            arr[i]=2;
          else
            if (str=="M")
              arr[i]=3;
            else
              if (str=="L")
                arr[i]=4;
              else
                if (str=="XL"){
                  arr[i]=5;}
                else
                  if (str=="XXL")
                    arr[i]=6;
                  else
                    if (str=="XXXL")
                      arr[i]=7;


}
	quickSort(arr, 0, n - 1,&total);
	cout<<total<<"\n";
	printArray(arr, n);
	}return 0;
}


