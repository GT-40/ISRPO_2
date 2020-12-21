#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include<stdlib.h>
#include<unistd.h>

struct Data
{
	int ID;
	char* date;
	char* time;
	char* object;
	char* applicant;
	char* application;
	char* answerDate;
	char* answerText;
};

char* addDate(){
	char* date;
	int err;
	int month=0;
	int day=0;
	bool isFebruary=false;
	bool isBigMonth=false;
	err=0;
	while((month<1||month>12)&&err==0){
		printf("Введите месяц: ");
		scanf("%d",&month);
		if(errno!=0) err=errno;
		printf("\n");
	}
	if(err!=0){
		printf("error: %s", strerror(err));
	}
	else
	{
                err=0;                      
		if(month==2) isFebruary=true;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) isBigMonth==true;
		if(isFebruary){
			while((day<1||day>28)&&err==0){
				printf("Введите день: ");
				scanf("%d",&day);
				if(errno!=0) err=errno;
				printf("\n");
			}
			if(err!=0){
			       printf("error: %s", strerror(err));
			}
			else{
				//strcat(date,day)
				sprintf(date,"%d%c%d", day, '.',month);
			}
		}
			else if(isBigMonth){
				err=0;
				while((day<1||day>31)&&err==0){
					printf("Введите день: ");
					scanf("%d",&day);
					if(errno!=0) err=errno;
					printf("\n");
				}
				if(err!=0){
					printf("error: %s",strerror(err));
				}
				else{
					sprintf(date, "%d%c%d",day,'.',month);
				}
			}
			else{
				err=0;
				while((day<1||day>30)&&err==0){
					printf("Введите день: ");
					scanf("%d",&day);
					if(errno!=0) err=errno;
					printf("\n");
				}
				if(err!=0){
					printf("error: %s", strerror(err));
				}
				else{
					sprintf(date,"%d%c%d",day,'.', month);
				}
			}
	}
	if(date!=NULL) return date;
	else return "-1";
}

char* addTime(){
	char* time;
	int hour;
	int min;
	int err;
	do{
		printf("Введите минуты: ");
		scanf("%d",&min);
		if(errno!=0) err=errno;
	}while((min<0||min>59)&&err==0);
	if(err!=0){ 
		printf("error: %s",strerror(err));
		return "-1";
	}
	else{
		err=0;
		do{
			printf("Введите часы: ");
			scanf("%d",&hour);
			if(errno!=0) err=errno;
		}while((hour<0||hour>23)&&err==0);
		if(err!=0){
			printf("error: %s",strerror(err));
			return "-1";
		}
		else{
			sprintf(time, "%d%c%d", hour,':',min);
			return time;
		}
	}
}

char* addObjct(){
	char* obj;
	printf("Укажите объект: ");
	scanf("%200s",obj);
	if(errno!=0)
	{
		printf("error: %s", strerror(errno));
		return "-1";
	}
	else
	return obj; 
}

char* addApplicant(){
	char* applicant;
	printf("Укажите заявителя: ");
	scanf("%200s", applicant);
	if(errno!=0)
	{
		printf("error: %s",strerror(errno));
		return "-1";
	}
	else return applicant;
}

char* addApplication(){
	char* app;
	printf("Текст:\n");
	scanf("%255s",app);
	if(errno!=0)
	{
		printf("error: %s",strerror(errno));
		return "-1";
	}
	else
	return app;
}



