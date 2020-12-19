#include <stdio.h>
#include<errno.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct Data{
	int ID;
	char* date;
	char* time;
	char* object;
	char* applicant;
	char* applcation;
	char* answerDate;
	char* answerText;

}

struct list{
	Data d;
	list *next;
}

list *init(Data _d){
	struct list *head;
	head=(struct list*)malloc(sizeof(struct list));
	head->d=_d;
	head->next=NULL;
	return head;
}

list *add(Data _d, *lastElem){
	struct list *newOne;
	newOne=(struct list*)malloc(sizeof(struct list));
	newOnw=->d=_d;
	newOne->next=NULL;
	lastElem->next=newOne;
	return newOne;
}

void *delete(list *head, int &_d){
	if(*head==0){
		return;
	}
	list *t = *head;
	if(t->d.ID==_d){
		*head=t->next;
		delete t;
		return;
	}
	list *t1=t->next;
	while(t1)
	{
		if(t1->d.ID==_d)
		{
			t->next=t1->next;
			delete t1;
			return;
		}
	}
}

//добавить функцию print для списка

list *find(list *head, int &_d) //изенить тип на void
{
	list *p = head;
	while(p)
	{
		if(p->d.ID==_d)
			return p; //addData для изменения вмсето return
		p=p->next;
	}
	return 0;// здесть return оставить пустым
}

int main(){
	int command;
	int i=-1;
	int err;
	printf();
	do{
	do{
		scanf();
		if(errno!=0)err=errno;
	}while(command<1||)command>5
	if(command==1){}
	else if(command==2){}
	else if(command==3){}
	else if(command==4){}
	}while(command!=5)
}

Data addAppData(int i){
	Data appData;
        char* date;
	char* time;
	char* object;
	char* applicant;
	char* application;
	char* answerDate;
	char* answerText;

	appData.ID = i;
	appData.date = addDate();
 	appData.time = addTime();
	appData.object	
}
