#include <stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"funcs.h"


Data addData(int i){
	Data d;
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
						printf();
						answerDate=addDate;
						if(answerDate=="-1") fail= true;
						else{
							printf();
							answerText=addApplication;
							if(answerText=="-1") fail=true;
							else if(fail==true) return NULL;
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
