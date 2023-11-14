#ifndef PROJECT_BIRD_TASK_H
#define PROJECT_BIRD_TASK_H

#include "../../util/header.h"
#include "../../util/log.h"

class Task {
private:
    std::string title;
public:

    Task(std::string name){
        this->title = name;
    }

    std::string& refTitle() {
    	return title;
    }
};

#endif
