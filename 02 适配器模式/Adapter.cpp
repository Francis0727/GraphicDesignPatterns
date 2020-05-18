#include "Adapter.h"

Adaptee::Adaptee(int english,int math,int chinese){
    this->m_english = english;
    this->m_chinese = chinese;
    this->m_math = math;
}

double  Adaptee::getScore(){
    return 0.2 * m_english + 0.3 * m_chinese + 0.5 * m_math;
}

Adapter::Adapter(int english,int math,int chinese){
    this->m_Adaptee = new Adaptee({english,math,chinese});
}

char Adapter::getScoreGrade(){
    // 1. 复用原先接口的功能
    double score = m_Adaptee->getScore();
    // 2. 对原先功能进行扩展
    if (score >= 90 && score <= 100){
        return 'A';
    }

    if (score >= 80 && score < 90){
        return 'B';
    }
    
    if (score >= 60 && score < 80){
        return 'C';
    }
    
    return 'D';
}