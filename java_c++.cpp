
#include<iostream>
#include<stdio.h> 
#include<string> 
	
using namespace std; 

bool isUpper(char c) { 
	
	if ( 60 <= (int)c && (int)c < 91 ) 
	{
		return true; 
	}

	return false; 		
}


bool isLower(char c) { 

	if ( 97<= (int)c && (int)c<123 ) 
	{
		return true; 
	}
	
	return false; 
}

bool notAlpha(char c) { 

	if ( !isUpper(c) ) 
	{
		if ( !isLower(c) )
		{
			return true;
		}
	}
	
	return false;
}


char changeCase(char letra) {

	int aux = (int)letra; 

	if ( isLower((char)aux) ) 
	{
		aux -= 32; 
	} 
	else if ( isUpper((char)aux) ) 
	{
		aux += 32; 
	}

	return (char)aux;
}


bool isJava(string some_string) {
	
	if ( isUpper(some_string[0]) ) 
	{
		return false; 
	}

	for (int j=0; j<some_string.length() ; j++)  {
		
		if ( notAlpha(some_string[j]) )
		{
			return false; 
		}
	}
	return true;
}


bool isCpp(string some_string) { 
	

	if (some_string[0] == 95 || some_string[ some_string.length()-1 ] == 95 || isUpper( some_string[some_string.length()-1] ) ) 
	{
		return false; 
	}

	//single number exception for christ sake
	
	if ( notAlpha(some_string[0]) )
	{	
		return false; 
	}
	
	for (int k=0; k<some_string.length()-1; k++) {
		
		if ( isUpper(some_string[k]) ) 
		{	
			return false; 
		}
		if ( notAlpha(some_string[k]) && some_string[k] != 95 ) 
		{
			return false; 
		}

		if ( some_string[k] == 95 && some_string[k+1] == 95 ) 
		{
			return false; 
		}
	}
	return true;
}	


string jTcpp(string ident) { 
	string aux ; 

	for (int i=0; i<ident.length(); i++) { 
			
		if ( isUpper(ident[i]) )
		{
			aux = '_';
			aux += changeCase(ident[i]);
			ident.replace(i,1,aux); 
		}
	
	}
	return ident;
}

string cppTj(string ident) { 
	string aux; 
		
	for (int j=0; j<ident.length(); j++) {
		
		if (ident[j] == 95) 
		{
			aux = changeCase(ident[j+1]);
			ident.replace(j,2,aux);
		}
	}
	
	return ident;
}	

int main() 
{
	string identifiers[100];
	int c=0;
	
	while (cin>>identifiers[c]) {
		c++;
	}

	for (int j=0; j<c; j++) { 

		if ( isCpp(identifiers[j]) ) 
		{
			cout<<cppTj( identifiers[j] )<<endl; 
		} 
		else if ( isJava(identifiers[j]) ) {
			cout<<jTcpp( identifiers[j] )<<endl; 
		}
		else { 
			cout<<"Error!"<<endl; 
		}
	}

	return 0; 
}
