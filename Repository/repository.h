#pragma once
#include "vector"
#include "domain.h"

class Repository{
private:
    std::vector<Event> database;
    std::string eventFile;

public:

    void loadEventsFromFile();

    void writeEventsToFile();

    /// Function to find an event by it's unique link
    /// \param link The link
    /// \return The position of the event if it's found, -1 otherwise
    int search(const std::string& link);

    ///Constructor for Repository class
    explicit Repository(std::vector<Event>& repo_vector, std::string& eventFile);

    ///Function to initialise the repo
    void initialiseRepo();

    ///Function to get the repo
    std::vector<Event>& getRepo();

    ///Function that returns the size
    unsigned int getSize();

    /// Function to add an event to the dynamic vector
    /// \param event The event we want to add
    void add_repo(Event &event);

    /// Function to remove an event from the repo
    void remove_repo(int index);

    /// Function to update an event from the dynamic vector
    void update_repo(int index, Event& event);


    ///Destructor
    ~Repository();

    void writeToFileRepo();
};

class RepositoryException: public std::exception{
private:
    std::string message;
public:
    explicit RepositoryException(std::string& _message);

    const char* what() const noexcept override;
};