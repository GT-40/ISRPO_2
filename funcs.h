#ifndef FUNCS_H
#define FUNCS_H


struct Data{
	int ID;
	char* date;
	char* time;
	char* object;
	char* applicant;
	char* application;
	char* answerDate;
	char* answerText;
};
char* addDate();

char* addTime();

char* addObjct();

char* addApplicant();

char* addApplication();

#endif
