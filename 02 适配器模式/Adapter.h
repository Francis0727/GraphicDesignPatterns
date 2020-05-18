#ifndef _ADAPTER_H
#define _ADAPTER_H

#include <iostream>

class Adaptee{
public:
	Adaptee(int english,int math,int chinese);
	double getScore();
private:
	int m_english;
	int m_math;
	int m_chinese;
};

class Target{
public:
	virtual char getScoreGrade() = 0;
};

class Adapter : public Target {
public:
	Adapter(int english,int math,int chinese);
	virtual char getScoreGrade();
private:
	Adaptee* m_Adaptee;
};

#endif