#include <stdio.h>


typedef struct  node{
	int data;
	struct node *next;
}node;

typedef struct LinkedList{
	struct node *head;
	struct node *last;
	int size;
} LinkedList;

LinkedList* create_link_list(){
	LinkedList *list=(LinkedList*) malloc(sizeof(LinkedList));
	list->size=0;
	list->head=NULL;
	list->last=NULL;
}

node* get_new_node(int data, node *next){
	node* n=(node *)malloc(sizeof(node));
	n->data=data;
	n->next=next;
	return n;
}

int insert_to_linked_list(LinkedList* list, int newdata){
	if (list->size==0){
		list->head=get_new_node(newdata,NULL);
		list->last=list->head;
		list->size+=1;
	}
	else{
		list->last->next=get_new_node(newdata,NULL);
		list->last=list->last->next;
		list->size+=1;
	}
	return 0;
}

int delete_element(LinkedList *list,int elem){
	int found=0;
	node* prev=NULL;
	for (node* i=list->head;i!=NULL;i=i->next){
		if (i->data==elem){
			if (prev==NULL){
				free(i);
				list->head=list->head->next;
			}
			else{
				prev->next=i->next;
				free(i);
			}
			found=1;
			break;
		}
		prev=i;
	}
	return found;
}

void print_list(LinkedList *list){
	for (node *a=list->head;a!=NULL;a=a->next){
		printf(" %d",a->data);
	}
}


int main(){
	LinkedList* list=create_link_list();
	insert_to_linked_list(list,5);
	insert_to_linked_list(list,6);
	insert_to_linked_list(list,7);
	insert_to_linked_list(list,8);
	delete_element(list,7);
	delete_element(list,5);
	print_list(list);
}
