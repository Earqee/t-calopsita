#ifndef PROJECT_BIRD_WEEK_H
#define PROJECT_BIRD_WEEK_H

#include "../../util/header.h"
#include "../../util/log.h"
#include "../../applications/organizer/task.h"

class Week {

private:
    std::vector< std::vector<Task> > days;

public:
    Week(){
        days.resize(7);
    }

    bool addTask(std::string &title, int &day) {
    	if(days.size() <= day)
    		return false;
        days[day].push_back(Task(title));
        return true;
    }

    bool removeTask(int &day, int &index) {
    	if(days.size() <= day || days[day].size() <= index)
    		return false;
        days[day].erase(days[day].begin()+index);
        return true;
    }

    bool editTask(int &day, int &index, std::string &title)
    {
    	if(days.size() <= day || days[day].size() <= index)
    		return false;
        days[day][index].refTitle() = title;
        return true;
    }

    std::string getDaySchedule(int &day) {
        std::string response;
        for(int i = 0; i < days[day].size(); ++i)
            response.append("|  Activity <" + std::to_string(i) + ">: " + days[day][i].refTitle() + "\n");
        return response;
    }

    std::string getWeekSchedule() {
        std::string response;
        for (int i = 0; i < days.size(); ++i)
            response.append("| Day <" + std::to_string(i) + ">\n" + getDaySchedule(i));
        return response;
    }

};

#endif
