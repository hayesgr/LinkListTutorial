#include <stdio.h>
#include <stdlib.h>

struct s_Node{
	int data;
	struct s_Node* next;
};

struct d_Node{
	int data;
	struct d_Node* next;
	struct d_Node* prior;
};

int main()
{
    struct s_Node* start=NULL;
    struct s_Node* last=NULL;
    struct s_Node* A = (struct s_Node*)malloc(sizeof(struct s_Node));

    start = A;
    A->data = 1;
    A->next = last;
    //Now A is the start and end of the list

    struct s_Node* B = (struct s_Node*)malloc(sizeof(struct s_Node));
    //Well place B after A
    A->next = B;
    B->data = 2;
    B->next = last;
    //A is now the start of the list and B is at the end;
    //Lets create another pointer and traverse the list and check the order
    struct s_Node* current = (struct s_Node*)malloc(sizeof(struct s_Node));
    current=start;
    while (current!=last){
        printf("%d\n",current->data);
        current=current->next;
    }
    //As you can see by the data coming out B was placed in After A
    //Lets create C and place it before B but after A
    struct s_Node* C = (struct s_Node*)malloc(sizeof(struct s_Node));
    A->next = C;
    C->data = 3;
    C->next = B;
    //Lets print it again
    printf("Second Run\n");
    current=start;
    while (current!=last){
        printf("%d\n",current->data);
        current=current->next;
    }
    //as you can see in the second run the order is now 1 3 2
    //Remove C
    A->next=B;
    printf("B removed\n");
    current=start;
    while (current!=last){
        printf("%d\n",current->data);
        current=current->next;
    }

    free(A);
    free(B);
    free(C);

    /*
    Double Linked Lists
    */
    printf("\n\nDouble Linked Lists\n");
    //Well start by making two new pointers Begin and End
    struct d_Node* begin=NULL;
    struct d_Node* end=NULL;
    //Well use I J K for our nodes this time
    struct d_Node* I = (struct d_Node*)malloc(sizeof(struct d_Node));
    I->data = 1;
    begin = I;
    end = I;
    I->prior=NULL;
    I->next=NULL;

    struct d_Node* J = (struct d_Node*)malloc(sizeof(struct d_Node));
    J->data = 2;
    //Well place it after I
    I->next = J;
    J->prior = I;
    J->next = NULL;
    end = J;
    //well create a pointer to run through it from begin to end similar to above
    struct d_Node* present = (struct d_Node*)malloc(sizeof(struct d_Node));
    printf("Begin to End\n");
    present = begin;
    while (present!=NULL){
        printf("%d\n",present->data);
        present=present->next;
    }
    //Well go from end to present
    printf("End to begin\n");
    present = end;
    while (present!=NULL){
        printf("%d\n",present->data);
        present=present->prior;
    }
    //Lets Set K between I and J
    struct d_Node* K = (struct d_Node*)malloc(sizeof(struct d_Node));
    K->data = 3;
    I->next = K;
    K->next = J;
    K->prior = I;
    J->prior = K;
    printf("Begin to End\n");
    present = begin;
    while (present!=NULL){
        printf("%d\n",present->data);
        present=present->next;
    }
    //Well go from end to present
    printf("End to begin\n");
    present = end;
    while (present!=NULL){
        printf("%d\n",present->data);
        present=present->prior;
    }

    //removing K
    I->next=J;
    J->prior = I;
    printf("K removed\n");
    printf("Begin to End\n");
    present = begin;
    while (present!=NULL){
        printf("%d\n",present->data);
        present=present->next;
    }
    //Well go from end to present
    printf("End to begin\n");
    present = end;
    while (present!=NULL){
        printf("%d\n",present->data);
        present=present->prior;
    }


    free(I);
    free(J);
    free(K);

    return 0;
}
