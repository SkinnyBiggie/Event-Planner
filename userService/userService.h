#pragma once
#include "repository.h"
#include "userRepo.h"

class UserService{
private:
    Repository& repository;
    UserRepository* userRepository;

public:
    ///Constructor for the user service
    UserService(Repository& repository1, UserRepository& userRepository1);

    explicit UserService(Repository& repository1);

    ///Function to get the repo in service
    std::vector<Event> getAllUsersService();

    ///Function to get the size of service
    unsigned int getSizeService();

    ///Function to add an event to the repo in service
    void addUserService(Event& event);

    std::string& getFileService();

    void RepositoryType(const std::string& fileType);

    ///Destructor for the user service class
    ~UserService();

    ///Function to remove an event from the repo
    void removeUserService(std::string &link);

    ///Function to filter events by the month
    int filterByMonth(std::vector<Event>& events, std::string& filter_month);
};