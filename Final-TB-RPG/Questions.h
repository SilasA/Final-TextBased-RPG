#ifndef QUESTIONS_H
#define QUESTIONS_H

#include "SubSystem.h"

#include <vector>
#include <map>
#include <string>

//
class Question
{

};

//
class Questions : public SubSystem
{
private:
	std::map<std::string, Question> m_questions;


public:
	Questions(const std::string& id);

	virtual void Update() override;
};


#endif // QUESTION_H
