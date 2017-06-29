#include "goal.h"
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;


void min(int exec[], int n) 
{
	//Assigning a vector named "arr" of type integer
	vector<int> arr;
	
	//Array elements are pushed into the arr vector
	for (int i = 1; i <= n; i++)
	{
		arr.push_back(exec[i-1]);
	}

	int p = 0;
	
	//The last horizantal line of coins are collected
	for (auto j = arr.begin(); j != arr.end(); j++)
	{
		if (*j > 0)
		{
			arr[p] = *j - 1;
			p++;
		}
	}

	int count = 0;
	count++;
	
	//The sum of the vector is calculated here 
	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	
	int ref = 0,check = 0,num = 0;
		
	//The loop runs till the sum of the vector elements is not equal to zero, 
	//and the coins are collected horixantlly and vertically based on the condition.
	// It is made sure that the collection of coins either vertically or horizantlly is continous.
	while (sum != 0)
	{
		//Two iterators are assigned to the 1st and the 2nd element of the arr vector
		auto k = arr.begin();
		auto l = k + 1;
		cout <<"Step"<<count <<":" << *k << *l << *(k+2)<<*(l+2)<<*(l+3)<<endl;

		//Checks whether the first 2 adjacent elements aren't null
		//if the condition is true, then the coins are removed horizantlly and updated in the vector.
		if (*k != 0 && *l != 0) 
		{
			arr[ref] = *k - 1;
			arr[ref+1] = *l - 1;
		}
		//If the previous consition fails, both th iterators are moved 2 positions ahead
		//If they aren't null, the coins are collected horizanttly
		else if (*(k + 2) != 0 && *(l + 2) != 0)
		{
			arr[ref+2] = *(k+2) - 1;
			arr[ref+3] = *(l+2) - 1;
		}
		//When no 2 adjacent elements aren't null, then this comes.
		else
		{
			int cou = 0;
			while (cou == 0)
			{
				if (arr[check] != 0)
				{
					arr[check] = *k - *k;
					cou++;
				}
				else
				{
					check++;
				}
			}
		}
		
		//The sum of the vector elements is updated after each collection of coins.
		sum = std::accumulate(arr.begin(), arr.end(), 0);
		count++;
	}
		
	cout << "The Minimun number of steps : " << count << endl;

}


void main()
{
	int exec[] = { 2,1,2,5,1 };
	min(exec, sizeof(exec) / sizeof(exec[0]));
}



