# bubble_sort

The function prototype for bubble is shown in line 11. The third parameter in the prototype
could have been written as: int (*)( int, int );
without the function-pointer name and parameter names.
The function passed to bubble is called in an if statement (line 60) as follows:
if if((*compare)(work[j],work[j+1]))
Just as a pointer to a variable is dereferenced to access the value of the variable, a pointer to
a function is dereferenced to use the function.
The call to the function could have been made without dereferencing the pointer as in
if ( compare( work[ j ], work[ j + 1 ] ) )
which uses the pointer directly as the function name. We prefer the first method of calling
a function through a pointer because it explicitly illustrates that compare is a pointer to a
function that’s dereferenced to call the function. The second method of calling a function
through a pointer makes it appear as if compare is an actual function. This may be confusing
to a programmer reading the code who would like to see the definition of function
compare and finds that it’s never defined in the file.
