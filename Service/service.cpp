#include "service.h"
#include "domain.h"
#include <algorithm>
#include <exception>

Service::Service(Repository &repo): repository(repo) {}

std::vector<Event>& Service::getAllService() {
    return this->repository.getRepo();
}

unsigned int Service::getSizeService() {
    return this->repository.getSize();
}

void Service::add_service(std::string title, std::string description, std::string date_time, unsigned int number_people, std::string link){
    Event event = Event(title, description, date_time, number_people, link);
    this->repository.add_repo(event);
}

void Service::remove_service(const std::string link) {
    int index = this->repository.search(link);
    this->repository.remove_repo(index);
}

void Service::update_service(const std::string newTitle, const std::string newDescription, const std::string newDate_Time, int new_number_people, const std::string oldLink, const std::string newLink) {
    int index = this->repository.search(oldLink);
    Event event = Event(newTitle, newDescription, newDate_Time, new_number_people, newLink);
    this->repository.update_repo(index, event);
}

/*unsigned int Service::get_number_of_events_for_month(unsigned int month) {
    unsigned int events_counter = 0;
    Event* events = this->list_all_events();
    for(int i = 0; i <= this->event_repo.get_events_number() - 1; i++){
        if(events[i].get_month() == month)
            events_counter++;
    }
    return events_counter;
}*/

/*void Service::random_events() {
    std::string title[11] = {"Untold", "Electric Castle", "NeverSea", "Coachella",
                             "Kendrick Lamar", "Astroworld Festival", "The Weeknd",
                             "NBA", "Mr. Olympia", "EE Comic-Con", "Kanye West"};

    std::string link[11] = {"www.untold.com", "www.electriccastle.com", "www.neversea.com",
                            "www.coachella.com", "www.kendricklamar.com", "www.astroworldfest.com",
                            "www.theweeknd.com", "www.nba.com", "www.mrolympia.com", "www.comic-con.ro",
                            "www.kanyewest.com"};

    std::string date_time[11] = {"30/03/2022 20:00", "01/04/2022 21:30", "14/05/2022 18:00",
                                 "19/05/2022 18:30", "26/06/2022 19:00", "30/06/2022 19:30",
                                 "07/07/2022 20:00", "26/07/2022 20:15", "13/09/2022 20:40",
                                 "24/12/2022 22:00", "11/07/2022 23:00"};

    std::string description[5] = {"Music Festival", "Concert", "Sports", "Bodybuilding", "Pop Culture"};

    unsigned int title_id, link_id, date_id, description_id, nr_people;
    while(this->event_repo.get_events_number() != 10){
        title_id = rand() % 11;
        if(title_id == 0){
            link_id = 0;
            description_id = 0;
        }
        else if(title_id == 1){
            link_id = 1;
            description_id = 0;
        }
        else if(title_id == 2){
            link_id = 2;
            description_id = 0;
        }
        else if(title_id == 3){
            link_id = 3;
            description_id = 0;
        }
        else if(title_id == 4){
            link_id = 4;
            description_id = 1;
        }
        else if(title_id == 5){
            link_id = 5;
            description_id = 0;
        }
        else if(title_id == 6){
            link_id = 6;
            description_id = 1;
        }
        else if(title_id == 7){
            link_id = 7;
            description_id = 2;
        }
        else if(title_id == 8){
            link_id = 8;
            description_id = 3;
        }
        else if(title_id == 9){
            link_id = 9;
            description_id = 4;
        }
        else if(title_id == 10){
            link_id = 10;
            description_id = 1;
        }
        date_id = rand() % 11;
        nr_people = rand() % 2000;
        try{
            add_service(title[title_id], description[description_id], date_time[date_id], nr_people, link[link_id]);
        }
        catch(RepoError &re) {}
    }

}*/
void Service::writeToFileService() {
    this->repository.writeToFileRepo();
}

int Service::searchService(const std::string &link) {
    int index = repository.search(link);
    return index;
}

Service::~Service() =default;