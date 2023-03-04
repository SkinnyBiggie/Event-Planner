#pragma once
#include "repository.h"
#include <string>

class Service{
    Repository& repository;
public:

    explicit Service(Repository& repo);

    ///Function to get the repository in service
    std::vector<Event>& getAllService();

    ///Function to get the size in service
    unsigned int getSizeService();

    /// Calls the repository and the validator to check and add an event
    /// \param title The title of the event
    /// \param description The description of the event
    /// \param date_time The date and time of the event
    /// \param number_people The number of people attending the event
    /// \param link The link of the event
    void add_service(std::string title, std::string description, std::string date_time, unsigned int number_people, std::string link);

    /// Removes an event by it's unique link
    /// \param link The link of the event we want to remove
    void remove_service(const std::string link);

    /// Updates an event
    /// \param title The title of the event
    /// \param description The description of the event
    /// \param date_time The date and time of the event
    /// \param number_people The number of people attending the event
    /// \param link The link of the event
    void update_service(const std::string newTitle, const std::string newDescription, const std::string newDate_Time, int new_number_people, const std::string oldLink, const std::string newLink);

    /// Function to generate random events
    void random_events();

    /// Function to get the number of events in a given month
    /// \param month The given month
    /// \return The number of events
    unsigned int get_number_of_events_for_month(unsigned int month);

    ///Destructor for the service class
    ~Service();

    void writeToFileService();

    int searchService(const std::string &link);
};
