//practice 4.1: prc_buble_sort_4.1
//Multipurpose sorting program using function pointers.
//More details: C-how to program 7th edition by Paul Deitel, 
//Harvey Deitel page311,312
#include<stdio.h>
#define SIZE 10

/*prototype*/
int ascending(int a, int b);
int decending(int a, int b);
int bubble(int work[], size_t size, int (*compare)(int a, int b));

int main(void){
	int counter;
	int choice;
	int arr[] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	printf("Enter 1 to ascending order, 2 decending order");
	scanf("%d",&choice);
  
  puts( "\nData items in original order" );
  
  // output original array
  for ( counter = 0; counter < SIZE; ++counter ) {
 	printf( "%5d", arr[ counter ] );
 	} // end for
  
  // sort array in ascending order; pass function ascending as an
  // argument to specify ascending sorting order
	if(choice == 1){
		bubble(arr,SIZE,ascending);//passing function name as the last argument
		puts( "\nData items in ascending order" );
	}
  
	else{// pass function descending
		bubble(arr,SIZE,decending);//passing function name as the last argument
		puts( "\nData items in descending order" );
	}
  
  // output sorted array
	for ( counter = 0; counter < SIZE; ++counter ) {
 	printf( "%5d", arr[ counter ] );
 	} // end for
}
/*******************************************************************************/
This tells bubble to expect a parameter (compare) that’s a pointer to a function 
that receivestwo integer parameters and returns an integer result. Parentheses are
needed around *compare to group the * with compare to indicate that compare is a
pointer. If we had not included the parentheses, the declaration would have been
                        int *compare( int a, int b )
which declares a function that receives two integers as parameters and returns a 
pointer to an integer.
/*******************************************************************************/
int bubble(int work[], size_t size, int (*compare)(int a, int b)){
	void swap(int* a, int* b);
	int i;//pass counter
  int j;//comparision counter
	for(i = 0; i < size - 1; i++){//loop to control passes
		for(j = 0; j < size - 1; j++){//loop to control number of comparisions per pass
    // if adjacent elements are out of order, swap them
				if((*compare)(work[j],work[j+1]))
					swap(&work[j],&work[j+1]);
		}//end for
	}//end for
}//end function

void swap (int*a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int ascending(int a, int b){
	return a > b;
}
int decending(int a, int b){
	return b > a;
}
