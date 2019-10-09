#include<iostream> 
#include<utility> 
	
using namespace std; 

int for_christ_sake(int val[], int sizes[], int ac, int stop, int total_s, int current); 
pair<int, int>  max_p(int a[], int b[], int size); 

/* Wrong Answer
 *
 * 	This failed cause I was only using a greedy aproach, this is, at every step of the algorithm I only looked for	
 * 	the maximum object value and added it up, not considering that this might not work in spite of the nature
 * 	of the problem (the size has a bound, but sizes and values are not directly correlated, and we wish to maximize
 * 	value). 
 *
 * 	A simple counter example for my solution is: 
 * 	10 7
 * 	10 2
 * 	10 2
 * 	10 2
 * 	10 2
 * 	10 2
 * 	24 5
 * 	30 5
 *
 * 	... The greedy approach would take 30 and 24 and then finish since the bound was reached, but taking the first
 * 	5 given element would give 50, and 50 > 49
 *
 * 	The proper approach involves consideran each "state" as the maximum sum for a set size k, such that 1<=k<=S. That
 * 	way we force the inclusion of the two elements value and size, rather than using the size as a stop condition.
 */

int main() 
{
	int s,n; 

	cin>>s>>n; 
	int val[n], tam[n]; 

	int p,q; 
	for (int i=0; i<n; i++) {

		cin>>p>>q; 
		tam[i] = p; 
		val[i] = q; 
	}

	cout<<for_christ_sake(val, tam, 0, s, n, 0)<<endl; 

	return 0; 
}

int for_christ_sake(int values[], int sizes[], int ac, int stop, int total_s, int current)
{
	pair<int, int> something; 
	int aux, total; 	
	total = 0;

	if (ac == stop)
	{
		return 0; 
	}
	if (ac < stop) { 
		something = max_p(values, sizes, total_s); 

		if (something.first != -1 && current != total_s-1) 
		{
			if (something.second+ac <= stop) 
			{ 	
				ac += something.second;
				total = for_christ_sake(values, sizes, ac, stop, total_s, current+1) + something.first; 
			}
			else { 
				total = for_christ_sake(values, sizes, ac, stop, total_s, current+1) ; 
			}
			
		}
		else { 
			return 0; 
		}
	}

	return total; 

}
	

pair<int,int>  max_p(int a[], int b[], int size)
{
	pair<int, int> ret; 
	int k, ind; 
       	k = ind = -1; 	
	for(int c=0; c<size; c++) { 

		if (k < a[c])
		{ 
			k = a[c]; 
			ind = c; 
		}
	}
	
	ret.first = a[ind]; 
	ret.second = b[ind]; 

	a[ind] = -1; 
	
	return ret; 
}


