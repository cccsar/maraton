#include <stdio.h> 
#include <unistd.h> // cstuff 
#include <iostream>
#include <string.h> 
#include <queue> 
#include <utility> 

using namespace std; 

typedef pair <int, int> pi; 

const char * one = "one";

int main() { 
	priority_queue< pi > qk ;

	qk.push( {1,9} ) ; 
	qk.push( {2,9} ) ;


	cout << qk.top().first << " " << qk.top().second << endl; 
	qk.pop() ; 
	cout << qk.top().first << " " << qk.top().second << endl; 
}
