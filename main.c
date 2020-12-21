#include <stdio.h>
#include<errno.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"addFunc.h"
#include"funcs.h"

struct list{
	struct Data d;
	struct list *next;
};

struct list *init(struct Data _d){
	struct list *head;
	head=(struct list*)malloc(sizeof(struct list));
	head->d=_d;
	head->next=NULL;
	return head;
}

struct list *add(struct Data _d,struct list *lastElem){
	struct list *newOne;
	newOne=(struct list*)malloc(sizeof(struct list));
	newOne->d=_d;
	newOne->next=NULL;
	lastElem->next=newOne;
	return newOne;
}

void *delete(struct list *head, int _d){
	if(head!=NULL){
		struct list *t = head;
		if(t->d.ID==_d){
			head=t->next;
			free(t);
		}
		struct list *t1=t->next;
		while(t1!=NULL)
		{
			if(t1->d.ID==_d)
			{
				t->next=t1->next;
				free(t1);
			}
		}
	}
	else
	{
		printf("Список пуст");
	}
}

void *findAndChange(struct list *head, int _d)
{
	struct list *p = head;
	while(p!=NULL)
	{
		if(p->d.ID==_d)
			p->d=addData(_d);
		p=p->next;
	}
}

void PrintList(struct list *head)
{
	struct list *p = head;
	while(p!=NULL){
		printf("%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s",p->d.ID, p->d.date, p->d.time, p->d.object, p->d.applicant, p->d.application, p->d.answerDate, p->d.answerText);
		p=p->next;
	}
}

int main(){
	int command;
	int i=-1;
	int err;
	int ID;
	struct list* head=NULL;
	struct list* lastItem=NULL;
	struct Data d;
	printf("Выберите команду\n1-добавить\n2-удалить\n3-изменить\n4-вывести на экран\n5-выход");
	do{
	do{
		scanf("%d",&command);
		if(errno!=0)err=errno;
	}while(command<1||command>6);
	if(err!=0) printf("error: %s", strerror(err));
	else{
		if(command==1){
			i++;
			d=addData(i);
			if(d.ID==-1)printf("input failed");
			else{
				if(head==NULL) head=init(d);
				else{
					if(lastItem==NULL) lastItem=add(d,head);
					else{
						lastItem=add(d,lastItem);
					}
				}	
			}
		}
		else if(command==2){
			printf("Введите ID элемента для удаления\n");
			scanf("%d",&ID);
			if(errno!=0)printf("error: %s",strerror(errno));
			else{
				delete(head,ID);
			}
		}
		else if(command==3){
			printf("Введите ID элемента для изменения");
			scanf("%d",&ID);
			if(errno!=0) printf("error: %s", strerror(errno));
			else{
				findAndChange(head, ID);
			}
		}
		else if(command==4){ 
			PrintList(head);
		}
	}
	}while(command!=5);

	return 0;
}




