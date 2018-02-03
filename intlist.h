/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
typedef struct  {
    int capacity;    // current list capacity -- currnt size of the data array -- current max. len of list
    int* data;       // the actual list data, a dyanmic, resizable array of int
    int len;         // the current length of the list -- the number of elements in the list
} IntList;

/*********************
 *  PUBLIC INTERFACE
 *********************/
//START OF HELPER FUNCTIONS:

/*checks the size and capacity to see of we need to grow the list 
//PRE: len=capacity
*/
  void checkSize(IntList *list);
  
/* 
// shift list elements,from index onward,1 place to right, 
//  "creating" an "empty" slot at pos. index.
*/
  void ilistShiftRight( IntList *list, int index );
  
/*
//shift list elements following index1 place to left,
//  "overwriting" theitem at pos. index, shortening list by 1
*/
  void ilistShiftLeft( IntList *list, int index);

/*
// GROW THE LIST BY ONE BLOCK_SIZE
// PRE: length = capacity
// POST: capacity = capacity + 10 
*/
  void listGrow(IntList *list);
  
//   
// 
//END OF HELPER FUCNTIONS 

/*
 * Constructor - return a new, empty list 
 * POST:  ilistLen(list) == 0 done
 */
IntList ilistNew( );

/*
 * Destructor - remove all data and free all memory associated with the list 
 * POST: ilistLen(list) == 0 done 
 */
 void ilistDelete( IntList *list ); 


/*
 * Print a text representation of this list on STDOUT done
 */
void ilistPrint( IntList list  ); 

/*
 * Return the number of items in the list done
 */
int ilistLen( IntList list );

/*
 * Return the item at the given index from the list done
 * PRE: 0<=at && at<ilistLen(list)
 */
int ilistGet( IntList list, int at );


/*
 * Return the number of times the given item occurs in the list done
 */
int ilistCount( IntList list, int item );

/*
 * Search the list for the given item done
 * RETURN: the position, pos, such that ilistGet(list, pos)==item OR -1 if the item is not found
 */
int ilistFind( IntList list, int item );


/*
 * Append the given item to the list 
 * POST: ilistGet( ilistLen(list)-1 ) == item done
 */
void ilistAppend( IntList *list, int item );

/*
 * Insert the given item into the list at the given location
 * POST: length of list is increased by one, and ilistGet( list, at ) == item done
 */
void ilistInsert( IntList *list, int at, int item );

/*
 * Remove the given item at the given location from the  list 
 * POST: length of list is reduced by one, item at given location has been removed. done
 */
void ilistRemove( IntList *list, int at );

/*
 * Append all items from list2 to list1  done
 * POST: length of list1 increased by size of list2 and all items from list2 are appended to list1.
 */
void ilistJoin( IntList *list1, IntList list2 );

/*
 * Reverse the order of items in the list done
 * POST: items in the list are in reversed order (e.g., first item is now last and visa versa)
 */
void ilistReverse( IntList *list );

/*
 * Return a "deep copy" of the list, with it's own, independent set of data.
 */
IntList ilistCopy( IntList list );
