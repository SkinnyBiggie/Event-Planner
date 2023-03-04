#pragma once
#include <vector>
#include "domain.h"

class UserRepository{
protected:
    std::vector<Event> list;
    std::string userFilename;

public:
    ///Constructor for the user repo
    explicit UserRepository(std::vector<Event>& list1);

    UserRepository();

    ///Function to get the repo
    virtual std::vector<Event>& getAllUsersRepo() = 0;

    ///Function to get the size
    virtual unsigned int getSize() = 0;

    ///Function to get the capacity
    virtual unsigned int getCapacity() = 0;

    ///Function to add an event to the repo
    virtual void addUserRepo(const Event& event) = 0;

    ///Function to remove an event from a position of the repo
    virtual void removeUserRepo(unsigned int index) = 0;

    ///Function to find an  event by it's link in the repo
    virtual int search(const std::string &link) = 0;

    ///Destructor for the user repo
    ~UserRepository();

    virtual void writeToFile() = 0;
    virtual std::string& getFilename() = 0;
};

class UserException: public std::exception{
private:
    std::string message;
public:
    explicit UserException(std::string& _message);
    const char *what() const noexcept override;
};