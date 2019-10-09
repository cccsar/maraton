-------------------------------theory
-all ines beggining with # are called 'directive; include directives are processed by the preprocessor:(a program invoked by the compiler).
-headerfiles:
<iostream> - objects: cout,cin,cerr <-- all of these belong to the ostream class
<iomanip> -  
<fstream> - 
-source code -preprocessors-> expanded source code -compiler-> object code -linker-> executable file 
preprocessor directives tell the compiler to preprocess the program before complining.
MACROS(#|template|expansion|arguments): piece of code that is given some name and whenever the compiler encounters that name it replaces it by the piece of code. 
FILE INCLUSION(#|<>|""):allows to include pre-defined functions into our files or our very own allowing modularity.
-------------------------------functions
-To define a function:
returntype funcname(formal parameters and type) { staments..; return }

function declaration: to say the type of parameters --> function definition: what the function does with the parameters.

sizeof(args) <-- returns the length of the given arg. 

-------------------------------objects
endl <-- returns newline.

-------------------------------blahblah
#include<iostream> <--incluve directive asks the computer to include a file
int main() { content } <-- function declaration, returns int 
std::cout<<somestatement <-- It prints the statement to stdout (i'm guessing)
cout<<statement | cin>>variable <-- insertion operators

	Whenever using a variable it has to be declared alongside with its type.
-------------------------------loop's boilerplate code
*for:
for(inizialization expr; test expr; update expr) { statements }

*while:
inizialization expr
while(test expr) {
	statements;
	update expr;
}

*do while: 
do {
	statements;
	update expr;
} while (test expr);

if-else if-else:

if (condition) {
	staments..;
else if (condition) {
	staments..;
else 
	staments..;
}

-------------------------------array
-declaration by size: type name[size];
-declaration by extension: type name[]={elements..};
#the last two can be combined



---------------- Booknotes: Programacion en C++ ---------------- 

*--Entry 25/06/2019:

The order of included files does matter, since they must go at the beggining of the program (thus the name "header files")

Use " " rounding filenames to include them if they don't belong to the "include" directory (absolute pathname may be necessary). This may turn usefull when handling several files. 

/-- Everything before main is regarded as global --/

Apparently, functions are declared by convention in the "global area" and then it is possible to define them after the main. 

Similarly to Java, C++ posseses library functions, accessed through header files such as iostream(.h)

interesting :p When going from source code to executable files, in the last step (linking), the object code of library functions included in the source code is 'linked' with the object code from our source code. 

/-- Remeber: Source --> Compiled | header files --> Assembled --> Object --> Linked | library funct.--> Executable --/ 

interesing :p The type 'char' is really a 1-1 mapping to ASCII code (oddly with (-128, 127) range) , hence, we are actually representing integer. Adittionally, the string type is (worth the simplification) an array of characters.

*-- Entry 26/06/2019: 

/--	Since 'char' characters are simply a mapping to integers, one can combine integers with char. 
	Here, octal numbers are preceded by a leading 0 (and their 3 digits, of course). 
	U, and L at the end of an asignation represents "unsigned" and "long" respectively.	--/ 

Character constant are enclosed in ' ' single quotes and string constant are enclosed in " " double quotes <-- does this matter?: yes, it fucking does.

It is also possible to define constant using "#define " directive.

/-- there's an especial data type called enum which seems usefull for making list of thing to iterate through --/ 

One can use the extraction operator repeatedly over a single input stream to assign values to variables. 
	e.g.: cin>>a>>b; //'a' and 'b' are now defined. 


Interesting :p this "operators" n++, n--, add and substract 1 respesctively from n. 

It is possible to compare characters using comparison operators, since the compiler uses their ASCII code.

These are &, ||, ^, ~, <<, >> bitwise operators and they only apply to char, int and long :D. They include abreviated versions of themselves such as: a &= b to assign to a the result of a & b <-- dull. 

/-- There is a third conditional and comma operator simply sequenciates in the same line... since coma does the same as ';' is kinda irrellevant buuut it is the operator with higher precendence so we must not forget :D --/ 

The :: (scope) operator is used to tell to which object we refer in the case of a namespace conflict.

sizeof() operator is important :p it is also a compilation time operator since every ocurrence of it in a program is replaced at compilation time by an unsigned integer.

Finally, there's a cast operator (), which allows to make explicit type change on variables. e.g.: int i = 0; (float)i; 

---------------- (Booknotes: Programacion en C++) ---------------- 


Since this all seemed boring cause it was intended for begginers, I skipped it and left it as a reference manual. Now, the following notes are from tutorial from G4G and cplusplus.com and they may come as presented in the page, or as needed by some competitive programing problem. See ya.


This is supossed to be a cool introduction to C++ STL (standard templates library), but I'm still learning what a template (and a template class is) so I'll keep us updated.

To be "plain" as possible, **templates** are used to create functions or classes whose operations are generic for several data-types. e.g: we could find maximum for two given integers or doubles.

Some special keyword when using templates are 'typename' or 'class' to declare the generic datatype we'll be working with. One can also include a different type from those when creating a template. e.g: template<typename/class T,int/char/.. i> 

Another interesting thing about templates is how they record values of "static" variables accross calls from different type. This is, for each type a template function/class is called/instantiated, a different copy of static variables is made and maintained. But in the end this is a consequence of "static" variable, which I don't handle yet... pffff this is hard, yet entertaining.

Interesting structures: So, as I normally would call the following "structures" since they're abstractions of real life objects to easily identify their behavior, they're known in C++ as **container** and if I find the reason of that, I'll let you know... well, they're also called container-classes.

/-- Stack --/ #include <stack>

Capacity:
	empty()->bool ~ O(1) 		size()->int ~ O(1)		

Element access: 
	top()->typename ~ O(1)		

Modifiers: 
	push(typename)->void ~ O(1)	pop()->void ~ O(1)


/-- Queue --/ #include<queue>
	
Capacity:
	empty()->bool 		size()->int		

Element access:
	front()->typename		back()->typename 

Modifiers: 
	push(typename)->void		pop()->void		


/-- Set --/ #include<set> : as a regular set, all elements are different, and this is an implementation of an ordered set.  
It is oddly declared like this: set < typename, greater/less <typename> >
	In my torough search for knowlege, I discovered that greater/less identifier represent the type of order stablished in the set, hence, if one wants a set ordered increasingly, one much choose less so the smallest elements is placed first.

Iterators: 
	begin()->iterator		end()->iterator			rbegin()->reverse_iterator		
	rend()->reverse_iterator	upper_bound(typename)->itr	lower_bound(typename)->iterator	find(typename)->itr

Capacity:
	size()->int			max_size()->int			empty()->bool				

Element access:
	count(typename)->bool			

Modifiers:
	insert(typename)->void		erase->void			


-/comments 
	-yes, there's a thing called reverse iterator, it is probably a type and I asume it acts as a "prev" pointer over memory locations. 
	-max_size() returns maximum available size for the structure
	-the difference between find() and count() is that the second tells wether an element is in the set or not, and the first returns either an iterator to the found element or (if the search fails) an iterator to end.
	-end() returns an iterator to the next-to-last element, just as rend() returns an iterator to the previous-to-first element.
	-upper_bound() is sort of a floor for the paramenter given, returning the closest element less or equal than argument, lower_bound() does the analogous work


/-- Vector --/ #include<vector> 

Iterators: 
	begin()->itr		end()->itr		rbegin()->r_itr		rend()->r_itr

Capacity: 
	size()->int		max_size()->int		capacity()->int		resize(int)->void //# of elements
	empty()->bool		reserve(int)->void //capacity

Element access
	[int]->typename		at(int)->typename	front()->typename	back()->typename

Modifiers: 
	assign(itr, int//offset)->void		push_back(typename)->void 		pop_back(typename)->void
	erase(int[, int])->void			clear()->void


/-comments 
	-This is the most marvellous and organized clasification I've found for a STL container, I should've begun from here..
	-size() concerns number of elements whilst capacity() is an upper bound for them (which double each time is reached)
	-Supossedly, max_size() gives the maximum amount of element for any vector.. (we'll have to check it).
	-reserve() does something similar to arr[t], it allocates space to be used and serves both for initiallizacion and size expansion
	-Speaking of size expansion, what is the diference betwen resize() and reserve()?? resize pushes both the capacity and the size, this meaning even if there are no elements, the vector is fuelled with 0 until reached requested size. On the other hand, reserve() only does memory allocation
	-Of course we'll use [int] rather than at().
	-I'm delighted about this


/-- Bitset --/ #include<bitset> ... bitset<const t> //t represent the size of the bit string

So, this structure seemed usefull for bits manipulation since manages to save a lot of space to store individual bits and easily performs bitwise operations. It has a peculiarity though, wenever we're instanciating an object, the template argument must be an intenger constant (not const or n = const) which is either explicitly written betwen '<>' or created by using "#define". This constant is the size of the bit string (it pads with zeroes all the way to the left if the given bit string is smaller than this constant).

//Like with processors, bits are indexed from right to left. 

Capacity: 
	count()->int		size()->int		test()->bool 		
	
Cool operatrions:
	to_string()->string		to_ulong()->unsigned long		to_ullong()->unsigned long long	

/-comments: 
	-Cool operations may be desirable for future programming problems. 
	-The actual juice of this is accessing bits with the '[]' operator, performing bitwise operation and the space optimization.


/-- Priority Queue --/ #include <queue> ... priority_queue<typename> 

It's odd to make an statement about this cause it encompasses sort of advance OOP in C++, but the idea is that some underlying container class template that support some operations (alongside with other requirements.. we're getting chessy), serve as a base for this structure. And of course, the behaviour is that we already know of a (greater) priority queue, implemented as a "max binary heap"

Capacity:
	size()->int		empty()->bool 		

Element access: 
	top()->typename
	
Modifiers: 
	push()->void		pop()->void


/-- Pair --/: #include<utility> 

This is actually not a complex structure, it's only a container that helps holding together two objects with (possibly) different types, whose order, in the structure is fixed and accesses through keywords .first and .second. 


Element access: 
	.first->typename			.second->typename

Modifiers; 
	make_pair(typename, typename)->void

And yes, that's all what is to it. It might have some non-interesting features such as support for logical operators and various types of inicialization, but we get the point, it works as a mathematical 2-tuple (or an R^2 vector). 


/-- List --/: #include<list> 

This structure incorporates all possible functions from vector, besides, in their documentation is emphasis on how the doubly linked list implementation causes linear time insertion and deletion and better performance when searching. Additionaly, their set to be located at not necessarily contiguous memory positions, but after some tests.. every object seems to be after the other.

Iterators: 
	begin()->it		end()->int		rbegin()->r_it		rend()->r_it

Capacity: 
	empty()->bool 		size()->int		max_size()->int

Element access: 
	front()->typename	back()->typename

Modifiers: 
	push_back(typename)->void		pop_back()->void		push_front(typename)->void
	pop_front()->void			insert(iterator, typename)->void

/- comments: 
	-insert takes an iterator representing the place at the list where one wishes to insert the element. There are different ways of using this. 
	-sorting it is a pain in the ass... well not quite, but I don't yet understand it. 


**Juicy library with cool functions: 

/-- Algorithms --/  #include<algorithms> 

sort(array[+offset] ,array+[offset1] [, comparator] )->int* //implementation of mergesort
	This sorts arrays of any valid type from index array[offset] to array[offset - 1], in other words only i in the range: 
		offset <= i < offset1 are ordered (with i being an index of course)

binary_search(array ,array+size ,value )->bool 


It turns out that there's is a rational order for all of this "structures"<-actually container, check a previous update. And since I despice ordered stuff, I'll present to you:


	Sequence containters: Data structures that can be accesed in a sequential manner.
		vector	list	deque	array	forward_list

	Adaptor containers: DS that provide a different interface for sequence containers.
		queue	priority_queue	stack

	Associative containters: Implement sorted DS that can be searched in O(log(n)).
		set	multiset	mat	multimap
	
	Unordered Associative containers: Unordered DS that can be quickly searched.
		unordered_set	unordered_multiset	unordered_map	unordered_multimap

I just found out that only containers that are not adaptor have a max_size() function returning the maximum element input per structure.


Had to jump to OOP in C++ cause a problem required so.. here we go.

		data abstraction -- polymorphism -- encapsulation -- inheritance -- classes and objects

I'll only walk through the concepts I don't handle. 

<>Main concepts

>>Data abstraction: An analogy of frontend/backend landscape of web desing (isn't clear yet). 
>>Polymorphism: Perform the same task in various ways. This is, a function behaves differently depending on the parameters it is 
given.It consists of function overloading and function overrinding. 
>>Encapsulation: Binding data and functions under a single unit (imagie a pill). 
>>Inheritance: Classes deriving things to classes in several ways: multilevel, hierarchical, hybrid, multiple.. 

<>C++ OOP features

>>Types of polymorfism
	Compile time
		function overloading		function overriding
	Run time
		Virtual function

>>class structure 

class class_name
{
	access_specifier
	data_members; 
	member_functions; 
}

/-- member functions can be declared within the class, or outside of it using the scope "::" operator. --/ 

>>inline functions: C++ feature that allows function code (preferably with few instructions) to be rewritten every place the funtion
is called instead of calling it (wich might produce overhead). This of course happens when preprocessing the source code (as with 
macros). They're created using the token **inline**.

/-- every member function is by default inline --/ 

>>constructors
	default -- parametrized -- copy

default and parametrized constructors are straightforward .. 

copy: It is a member function that initialices an object using another object of the same class. It is created by default (convenion 
is using the className as the constructor name), and unless user defined, it performs shadow copying (points existing object memory 
addresses). When user defined, it  performs shadow copying (allocates memory and copies). 


>>destructor: special member funnction that is called by the compiler when the scope of an object ends. Syntax is ~class_name(){}

>>access modifiers
	public -- private -- protected
/-- default is private --/ 

private: Can only be accessed by member functions of a class. 
protected: Similar to private, but can be accessed by subclasses.

>>friend class/function: class that can access private and protected data members of another class declared friend.
In an analogous way, a friend function can be a member function or global function and has the same privileges. 

/-- Recall that the friend token serves to grant permission, thus it is the class/function declared as friend who
can no access private and protected data member/member functions from the class it is declared into --/ 


.. aaand this is it. For now.

In C++ class attributes (Java) are known as data members and methods (Java) are known as member functions.
---------------- Booknoes C++ Primer (5th Edition) ---------------- 

Ok, I've been out for some time from G4G and cplusplus.com only to gather a new baseline from a textbook I think might provide a necessary solid ground in my process of learning C++. So, I shall proceed to write down whatever I recall from my read and stop writing like a victorian idiot.


It turns out going from C to C++ was quite a big change. Both languages were conceived on AT&T bell labs and the mayor improvement that C++ included was OOP plus generic programming (which is the feature included by templates and yes, a programming paradigm). 

An important point is made on programming paradigms: procedural programming is algorithm centered, hence in this spirit the solution of a problem is attacked breaking it down on several small solutions (top - down approach), which we fondly remember as functions. On the other hand, OOP enphasizes data, hence it relies on creating advantegeous representations of the data to solve a problem; to leave it clear, they're not mutualy exclusive, since they're problem solving/programming approaches to computational (or daily) problems both can be combined and we'll benefit from it. Oh, I need to say, the process of going from a bunch (a great bunch) of classes, to an entiry whole proyect could be the ressult of applying bottom-up approach, and yes, OOP eases this.

Now on an historical note, spaguetti code comes from jump statements making programmers unable to trace the flow of a function on assembly-like languages, situation that led to the development of control structures (we remember them better as foor, while and do-while loops), which in general acquired the name of structured programming.

I'll continue adding notes as I read... Aaaand here it goes (25/07/2019)

There's an emphasis on prototyping functions on source files, right after the include (and using) directives. This seems like a good practice for short programs altough repetitive (since callee functions will be written under the main, thus we'll be writting the function firm twice in the same file). I assume this is done to avoid having the main at the bottom of the program.. yet, not good for competitive programming. 

Another cool "modular thing" is that what we know as header files (.h,.hpp), merely contain prototypes of the functions/classes they provide, the actual function/classes are held as compiled code within library files.

In c++ slang, a function is both a procedure and, well, a function. Now ,speaking of return values, main's function return value is given to the OS itself, and as a convention, whatever nonzero value it returns is regarded as an error. 

//Whenever writing a serious proyect, limit the use of std namespace// 

Names beginning with two underscores or with an underscore and an uppercase are reserved for the implementation, this is, don't fucking use them. 

**climits** is a cool header file (constant naming [U,S]TYPE_[BIT/MIN/MAX])

Variables initialized wherever but main, hold whatever there was on that memory location, while on main they're set to 0. 

#define is a preprocessors directive that allows the creation of symbolic constant, and at preprocessor time, each ocurrence of a defined contstant is searched and replaced by it's value (this is for C programs, C++ uses const) 


