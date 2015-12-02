#ifndef ROSTER_MANAGER_H_INCLUDED
#define ROSTER_MANAGER_H_INCLUDED

#include "player.h"
#include <vector>

class RosterManager {
    public:
        std::string get_filename() { return filename_; }
        void set_filename(std::string filename) { filename_ = filename; }

        void run();
        void set_current_year(int year) { current_year_ = year; }
        void start_new_season();
        void add_player();
        Player search_player(std::string player_name);
        void edit_player(Player & p);
        void list_players(std::string category,std::string output_file);

    private:
        bool open();
        bool close();

        std::string filename_;
        std::vector<Player> player_list_;
        int current_year_;
    };

#endif // ROSTER_MANAGER_H_INCLUDED
