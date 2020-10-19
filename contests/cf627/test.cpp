#include<iostream> 
#include<stdio.h> 
#include<set> 

using namespace std; 

int main(){ 
	set<int> ts; 
	set<int, greater<int> > tss; 

	for(int i=0 ;i<10; i++) ts.insert(i); 
	for(int i=0 ;i<10; i++) tss.insert(i); 

	for(int el : ts) cout<<el<<" "; 
	cout<<endl; 

	for(int el : tss) cout<<el<<" "; 
	cout<<endl; 
	
}
