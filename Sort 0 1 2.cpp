#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
	//both approach are almost same.
//     int zero=0,two=n-1;
// 	while(arr[zero]==0)zero++;
// 	while(arr[two]==2)two--;
// 	int i=0;
// 	while(i<n)
// 	{
// 		if(arr[i]==0)
// 		{
// 			if(i>zero)
// 			{
// 				swap(arr[i],arr[zero]);
// 				while(arr[zero]==0)zero++;
// 				if(arr[i]!=2)i++;
// 			}
// 			else i++;
// 		}
// 		else if(arr[i]==2)
// 		{
// 			if(i<two)
// 			{
// 				swap(arr[i],arr[two]);
// 				while(arr[two]==2)two--;
// 				if(arr[i]!=0)i++;
// 			}
// 			else i++;
// 		}
// 		else i++;
// 	}
	int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		if(arr[mid]==1)mid++;
		else if(arr[mid]==0)
		{
			swap(arr[mid++],arr[low++]);
		}
		else
		{
			swap(arr[mid],arr[high--]);
		}
	}
}