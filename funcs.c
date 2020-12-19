#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include<stdlib.h>
#include<unistd.h>
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
				else if(!isBigMonth){
					while((day<1||day>30)&&err==0){
						printf("Введите день: ");
						scanf("%d",&day);
						if(errno!=0) err=errno;
						printf("\n");
					}
					if(err!=0){
						printf("error: %s",strerror(err));
					}
					else{
						sprintf(date, "%d%c%d", day, '.', month);

					}
				}
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
	do{
		scanf("%d",&min);
	}while(min<0||min>59);
	do{
		scanf("%d",&hour);
	}while(hour<0||hour>23)	;
	sprintf(time, "%d%c%d", hour,':',);
	return time;
}

char* addOnjct(){
	char* obj;
	printf();
	scanf("%s",&obj);
	return obj; 
}

char* addApplicant(){
	char* applicant
}

char* addApplication(){
	char* app;
	printf();
	scanf("%s",&app);
	return app;
}



