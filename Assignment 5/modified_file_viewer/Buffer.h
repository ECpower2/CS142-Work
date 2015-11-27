// Buffer.h

#include <vector>
#include <string>

class Buffer {
public:
    void display() const;
    const std::string & get_file_name() const { return file_name; }
    void move_to_next_page();
    void move_to_previous_page();
    bool jump(const int & line_num);
    bool open(const std::string & file_name);
    void set_window_height(int h) { window_height = h; }

private:
    std::vector<std::string> v_lines;
    int ix_top_line = 0;
    std::string file_name;
    int window_height;
};

inline void Buffer::move_to_next_page() {
    if (ix_top_line + window_height < v_lines.size())
        ix_top_line += window_height;
}

inline void Buffer::move_to_previous_page() {
    if (ix_top_line > 0) {
        if ((ix_top_line - window_height) < 0) { //In case of a jump
            ix_top_line = 0;
            }
        else {
            ix_top_line -= window_height;
            }
        }
    }

inline bool Buffer::jump(const int & line_num) {
    bool valid_jump = true;
    if (line_num < v_lines.size()) { //If the line number is valid
        ix_top_line = line_num - 1; //Account for index-0
        }
    else {
        valid_jump = false;
        }
    return valid_jump;
    }
