#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _thing { 
	char *item;
	struct _thing *next;
} THING;

THING *start = NULL;

THING *NewElement(char *text){
    THING *newp;
    newp = (THING *) malloc (sizeof(THING));
    newp -> item = (char *)malloc(strlen(text) + 1);
    strcpy(newp -> item, text);
    newp -> next = NULL;
    return newp;
}  

void InsertThing(THING **head, THING *newp){
	THING **tracer = head;

	while((*tracer) && strcmp((*tracer)->item, newp -> item) < 1){
		tracer = &(*tracer)->next;
	}

	newp -> next = *tracer;
	*tracer = newp;
}

void RemoveThing(THING **head, char *text){
	BOOL present = FALSE;
	THING *old;
	THING **tracer = head;
	
	while((*tracer) && !(present = (strcmp(text,(*tracer)->item) == 0 )  ))
		tracer = &(*tracer)->next;

	if(present){
		old = *tracer;
		*tracer = (*tracer)->next;
		free(old -> item);
		free(old);
	}
}

void PrintList(THING **head){
	THING **tracer = head;
	while (*tracer) {
		printf("%s \n",(*tracer)->item);
		tracer = &(*tracer)->next;
	}
}

int main(int argc, char **argv){
	InsertThing(&start, NewElement("chips"));
	InsertThing(&start, NewElement("wine"));
	InsertThing(&start, NewElement("burgers"));
	InsertThing(&start, NewElement("beer"));
	InsertThing(&start, NewElement("pizza"));
	InsertThing(&start, NewElement("zucchini"));
	InsertThing(&start, NewElement("burgers"));
	InsertThing(&start, NewElement("slaw"));
	printf("\nINITIAL LIST\n");
	PrintList (&start);
	RemoveThing(&start, "pizza");
	RemoveThing(&start, "zucchini");
	RemoveThing(&start, "burgers");
	printf("\nALTERED LIST\n");
	PrintList(&start);         
}                  