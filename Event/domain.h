#pragma once
#include <string>
#include <vector>

class Event{
private:
    std::string title;
    std::string description;
    std::string date_time;
    std::string link;
    unsigned int number_people{};

public:

    Event() : title{""}, description{""}, date_time{""}, number_people{0 }, link{""}{};
    //Destructor
   // ~Event();
    Event(const std::string& title, const std::string& description,
         const std::string& date_time, unsigned int number_people,const std::string& link);

    /// Getter for the title
    /// \return The event's title
    std::string get_title() const { return this->title; }

    /// Getter for the description
    /// \return The event's description
    std::string get_description() const { return this->description; }

    /// Getter for the date and time
    /// \return The event's date and time
    std::string get_date_time() const {return this->date_time; }

    /// Getter for the link
    /// \return The event's link
    std::string get_link() const {return this->link; }

    /// Getter for the month
    /// \return The month that the event takes place
    unsigned int get_month();

    /// Getter for the number of people
    /// \return The number of people that attend an event
    unsigned int get_number_people() const {return this->number_people; }

    /// Setter for the title
    /// \param new_title The new title of the event
    //void set_title(std::string& new_title);

    /// Setter for the description
    /// \param new_description The new description of the event
    //void set_description(std::string& new_description);

    /// Setter for the date and time
    /// \param new_date_time The new date and time of the event
    //void set_date_time(std::string& new_date_time);

    /// Setter for the number of people
    /// \param new_number_people The new number of people that attend the event
    void set_number_people(unsigned int new_number_people);


    /// Function to overwrite the == operator to compare 2 objects
    bool operator==(const Event& event);

    /// Function for the format we want to print an event
    std::string toString() const;

    friend std::istream& operator>>(std::istream& inputStream, Event& event);

    friend std::ostream& operator<<(std::ostream& outputStream, const Event& event);
};
