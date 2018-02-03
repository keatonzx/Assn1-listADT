/*
 * An implemenatation of a List ADT in C 
 *   Input:  via the test drivers
 *   Output: outputs what is called, printed onto stdout
 *
 * Author: Keaton Armstrong
 * Date:   Feb 01 2018
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "intlist.h"

#define BLOCK_SIZE 10
//const int BLOCK_SIZE = 10;
//CREATE NEW EMPTY LIST
void main(){
  printf("compiles\n");
  IntList l = ilistNew();
  ilistAppend(&l,2);
  ilistPrint(l);  
}
IntList ilistNew( )
{
  IntList list;
  list.data = calloc(BLOCK_SIZE, sizeof(int));
  list.len = 0;
  list.capacity = BLOCK_SIZE;
  return list;

}

//RETURN LIST LENGTH
int ilistLen( IntList list )
{
  return list.len;
}

//Append one value to list
void ilistAppend( IntList *list, int item )
{
 //check to see if we need to grow the list
  checkSize(list);
  
  int i;
  
  list->len++;
  
  for(i = 0; i <= list->len; i++){
    if(i == list->len){
      list->data[i-1] = item;
    }
  }
}

//PRINT LIST
void ilistPrint( IntList list  )
{
  int i;
  
  for(i = 0; i < list.len; i++){
    printf("Element %d is %d\n", i, list.data[i]);
  }
}

//INSERT ITEM INTO POSITION
void ilistInsert( IntList *list, int at, int item )
{
  ilistShiftRight(list,at);
  list->data[at] = item;
}
//remove element from list, shrink by one
void ilistRemove( IntList *list, int at )
{
  ilistShiftLeft(list,at);
}

//find element and return index found at 
int ilistFind( IntList list, int item )
{
  int i;
  
  for(i = 0; i<list.len; i++){
    if(list.data[i] == item ){
      return i;
    }
  }
  
  return -1;
}

//return item at index
int ilistGet( IntList list, int at )
{
  return list.data[at];
}

//return frequency of item in list 
int ilistCount( IntList list, int item )
{
  int i;
  
  int count = 0;
  
  for(i = 0; i<list.len; i++){
    if (list.data[i] == item){
      count++;
    }
  }
  return count;
}

//join list, increases size by l2.len
void ilistJoin( IntList *list1, IntList list2 )
{
   int i;
   
   for (i=0; i<list2.len; i++){
      ilistAppend(list1,list2.data[i]);
   }
}

//reverse a list!
void ilistReverse( IntList *list )
{
  int i;
  int temp;
  
  int end = list->len-1;
  
  for (i = 0; i<list->len/2; i++){
    temp = list->data[i];
    list->data[i] = list->data[end];
    list->data[end] = temp;
    end--;
  }
}

//delete list, fix pointers etc
void ilistDelete( IntList *list )
 {
   free(list->data);
   list->data = NULL;
   list->len = 0;
   list->capacity = 0;
 }


//HELPER FUNCTIONS BELOW


//SHIFT RIGHT
void ilistShiftRight( IntList *list, int index )
{
  checkSize(list);
  
  list->len++;
  
  int temp;
  int i;
  for (i = list->len; i >= index; i--){
    list->data[i] = list->data [i-1];
  }
}
//SHIFT LEFT
void ilistShiftLeft( IntList *list, int index)
{
  int i;
  
  for(i = index; i< list->len; i++){
    list->data[i] = list->data[i+1];
  }
  
  list->len--;
}

//checks size and capacity to determine if we need to grow the list
void checkSize(IntList *list)
{
  if(list->capacity == list->len){
   // printf("length %d = capacity %d\n", list->len, list->capacity);
   // printf("GROWING THE LIST...\n");
    listGrow(list);
  }
}

//GROW LIST 
void listGrow(IntList *list)
{
  list->data = realloc(list->data, (list->len + BLOCK_SIZE) * sizeof(int));
  list->capacity = list->len + BLOCK_SIZE;
}  
