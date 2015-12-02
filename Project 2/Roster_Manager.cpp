
#include "Roster_Manager.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string.h>

bool RosterManager::open() {
    std::ifstream ifs_file(filename_);
    if (!ifs_file) return false;

    player_list_.clear();

    Player holder;
    while (ifs_file >> holder) {
        player_list_.push_back(holder);
        }

    ifs_file.close();
    return true;
    }

bool RosterManager::close() {
    std::ofstream ofs_file(filename_);
    if (!ofs_file) return false;

    std::vector<Player>::iterator itr = player_list_.begin();
    for (itr = player_list_.begin(); itr != player_list_.end(); ++itr) {
        ofs_file << *itr;
        }

    ofs_file.close();
    return true;
    }

std::string calculate_category(const int & age) {
    std::string category;
    if (age < 4) { category = "invalid"; }
    else if (age < 6) { category = "U6"; }
    else if (age < 8) { category = "U8"; }
    else if (age < 10) { category = "U10"; }
    else if (age < 12) { category = "U12"; }
    else if (age < 14) { category = "U14"; }
    else if (age < 17) { category = "U17"; }
    else if (age >= 17) { category = "invalid"; }

    return category;
    }

// ---- FUNCTION: START NEW SEASON --------------------------------------------
void RosterManager::start_new_season() {
    std::cout << "Enter the season year: ";
    std::string year_str;
    getline(std::cin,year_str);
    int year =std::atoi(year_str.c_str());

    std::cout << "Starting a new season will delete the current roster. ";
    std::cout << "Continue? (y/n) ";

    std::string command;
    getline(std::cin,command);

    char choice= command.at(0);
    if (choice = 'y') {
        current_year_ = year;
        player_list_.clear();
        }
    }

// ---- FUNCTION: ADD PLAYER --------------------------------------------------
void RosterManager::add_player() {
    std::cout << "Enter the player information below:\n";
    Player p;

    std::string name,year_of_birth,reg_status;

    std::cout << "Player name: ";
    getline(std::cin,name);
    std::cout << "Year of Birth: ";
    getline(std::cin,year_of_birth);
    std::cout << "Registration Status: ";
    getline(std::cin,reg_status);

    int yob = std::atoi( year_of_birth.c_str() );
    int age = current_year_ - yob;
    std::string category = calculate_category(age);
    if (category.compare("invalid") == 0) {
        std::cout << "Error: player is ineligible to join the league.\n";
        }
    else {
        p.set_name(name);
        p.set_year_of_birth(yob);
        p.set_category(category);
        p.set_reg_status(reg_status);
        player_list_.push_back(p);
        }
    }

// ---- FUNCTION: SEARCH PLAYER -----------------------------------------------
Player RosterManager::search_player(std::string player_name) {
    Player p;

    std::vector<Player>::iterator itr = player_list_.begin();
    for (itr = player_list_.begin(); itr != player_list_.end(); ++itr) {
        if (itr->get_name() == player_name) p = *itr;
        }

    return p;
    }

// ---- FUNCTION: EDIT PLAYER -------------------------------------------------
void RosterManager::edit_player(Player & p) {
    std::string new_name,new_age_str,new_reg_status;
    int age,yob;

    std::cout << "Press ENTER to bypass any of the prompts:\n";
    std::cout << "Name: ";
    getline(std::cin,new_name);

    std::cout << "Age: ";
    getline(std::cin,new_age_str);

    std::cout << "Registration Status: ";
    getline(std::cin,new_reg_status);

    age = std::atoi(new_age_str.c_str());
    yob = current_year_ - age;
    std::string category = calculate_category(age);

    if (category.compare("invalid") == 0) {
        std::cout << "Error: player is ineligible to join the league.";
        }
    else {
        if (new_name != "")
            p.set_name( new_name );
        if (new_reg_status != "")
            p.set_reg_status( new_reg_status );
        p.set_year_of_birth(yob);
        }
    }

// ---- FUNCTION: LIST PLAYERS ------------------------------------------------
void RosterManager::list_players(std::string category,std::string file) {
    std::vector<Player> players;
    Player p;

    std::vector<Player>::iterator itr = player_list_.begin();
    for (itr = player_list_.begin(); itr != player_list_.end(); ++itr) {
        if ( (itr->get_category()).compare(category)  == 0) {
            p = *itr;
            players.push_back(p);
            std::cout << "Wrote a player to file\n";
            }
        }

    std::ofstream ofs_file(file);
    if (!ofs_file) std::cout << "Error: could not open file\n";

    for (itr = players.begin(); itr != players.end(); ++itr) {
        p = *itr;
        ofs_file << p;
        }

    ofs_file.close();
    std::cout << "Successfully wrote players to " << file << std::endl;
    }

// ---- FUNCTION: RUN --------------------------------------------------------
void RosterManager::run() {
    std::cout << "Welcome to the Roster Manager:\n";
    std::cout << "Enter the current year: ";
    std::string usr_year_str;
    getline(std::cin,usr_year_str);
    set_current_year(std::atoi( usr_year_str.c_str() ));

    std::cout << "Please specify the file containing your roster: ";
    getline(std::cin,filename_);

    if (!open()) {
        std::cout << "Could not open roster file. Exiting program...\n";
        return;
        }

    bool done = false;
    while (!done) {
        std::cout << "Please select an option from the list below:\n";
        std::cout << "1) Start a new season\n" <<
                     "2) Add a player\n" <<
                     "3) Look up a player\n" <<
                     "4) Edit a player's information\n" <<
                     "5) List all players in a category\n" <<
                     "6) Exit program\n";

        std::cout << "Enter the corresponding number to make your selection: ";
        std::string command;
        std::cin >> command;
        std::cin.get(); //Get newline character

        char command_char = command.at(0);

        switch (command_char) {
            case '1' : { //Start a new season
                start_new_season();
                break;
                }
            case '2' : { //Add a player
                add_player();
                break;
                }
            case '3' : { //Look up a player
                std::string player_name;
                std::cout << "Enter the name of the player you wish to look up: ";
                getline(std::cin,player_name);

                Player p = search_player(player_name);
                if (p.get_name() == "No Name")
                    std::cout << "Could not find the specified player.\n";
                else
                    std::cout << "Found the following player:\n";
                    std::cout << p << std::endl;
                break;
                }
            case '4' : { //Edit a player's information
                std::string player_name;
                std::cout << "Enter the name of the player you wish to look up: ";
                getline(std::cin,player_name);

                Player p = search_player(player_name);
                if (p.get_name() == "No Name")
                    std::cout << "Could not find the specified player.\n";
                else
                    edit_player(p);
                break;
                }
            case '5' : { //List all players in a category
                std::string category;
                std::cout << "Enter a category to sort players by:\n";
                getline(std::cin,category);

                std::string output_file;
                std::cout << "Enter an output file to write to:\n";
                getline(std::cin,output_file);

                list_players(category,output_file);

                break;
                }
            case '6' : { //Exit program
                done = true;
                break;
                }
            }
        }

    close();
    }
