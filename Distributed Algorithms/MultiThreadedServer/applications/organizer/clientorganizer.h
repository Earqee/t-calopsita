#ifndef PROJECT_BIRD_CLIENT_ORGANIZER_H
#define PROJECT_BIRD_CLIENT_ORGANIZER_H

#include "../../util/header.h"
#include "../../util/log.h"

class ClientOrganizer {
public:

    ClientOrganizer(){}

    std::string askMenu() {
        return "MENU";
    }

    std::string HandleMenu() {

        std::string input;
        std::cin >> input;

        if(input == "1") return addTask();
        if(input == "2") return removeTask();
        if(input == "3") return editTask();
        if(input == "4") return viewDay();
        if(input == "5") return viewWeek();
        return quit();
    }

    std::string addTask() {
        printf("Enter <day> <title>: ");
        std::string day, title;
        std::cin >> day;
        getline(std::cin, title);
        return "ADD " + day + " " + title;
    }

    std::string removeTask() {
        printf("Enter <day> <index>: ");
        std::string day, index;
        std::cin >> day >> index;
        return "DEL " + day + " "+ index;
    }

    std::string editTask() {
        printf("Enter <day> <index> <title>: ");
        std::string day, index, title;
        std::cin >> day >> index;
        getline(std::cin, title);
        return "EDIT " + day + " " + index + " " + title;
    }

    std::string viewDay() {
        printf("Enter <day>: ");
        std::string day;
        std::cin >> day;
        return "DAY " + day;
    }

    std::string viewWeek() {
        return "WEEK";
    }

    std::string quit() {
        return "QUIT";
    }

};

#endif
