#include<stdio.h> 
#include<iostream> 
#include<algorithm> 
#include<set> 


using namespace std;

int main() { 
	set<int> test; 

	for(int i=0 ;i<10; i++) test.insert(10-i); 

	for(int el : test ) printf("%d ",el); 
}
