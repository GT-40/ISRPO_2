#include <stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"funcs.h"


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
	if(date=="-1") fail = true;
	else{
		time = addTime();
		if(time=="-1") fail = true;
		else{
			object = addObjct();
			if(object=="-1") fail = true;
			else{
				applicant = addApplicant();
				if(applicant=="-1") fail=true;
				else{
					application=addApplication();
					if(application=="-1") fail = true;
					else{
						printf("Ввод даты ответа\n");
						answerDate=addDate;
						if(answerDate=="-1") fail= true;
						else{
							printf("Ввод текста ответа\n");
							answerText=addApplication;
							if(answerText=="-1") fail=true;
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
