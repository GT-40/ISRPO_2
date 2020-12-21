#include <stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"funcs.h"
#include"funs1.h"


struct Data addData(int i){
        struct Data d;
	char* date;
	char* time;
	char* object;
	char* applicant;
	char* application;
	char* answerDate;
	char* answerText;
	bool fail=false;

	date=addDate();
	if(strcmp(date,"-1")==0) fail = true;
	else{
		time = addTime();
		if(strcmp(time,"-1")==0) fail = true;
		else{
			object = addObjct();
			if(strcmp(object,"-1")==0) fail = true;
			else{
				applicant = addApplicant();
				if(strcmp(applicant,"-1")==0) fail=true;
				else{
					application=addApplication();
					if(strcmp(application,"-1")==0) fail = true;
					else{
						printf("Ввод даты ответа\n");
						answerDate=addDate;
						if(strcmp(answerDate,"-1")==0) fail= true;
						else{
							printf("Ввод текста ответа\n");
							answerText=addApplication;
							if(strcmp(answerText,"-1")==0) fail=true;
							else if(fail==true) d.ID = -1;
							else{
								d.ID=i;
								d.date=date;
								d.time=time;
								d.object=object;
								d.applicant=applicant;
								d.application=application;
								d.answerDate=answerDate;
								d.answerText=answerText;

								return d;
							}
						}
					}
				}
			}
		}
	}
}
