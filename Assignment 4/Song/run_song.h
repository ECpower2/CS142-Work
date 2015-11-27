#ifndef RUN_SONG_H_INCLUDED
#define RUN_SONG_H_INCLUDED

class SongError {
    public:
        SongError(const std::string & d) : description_(d) {}
        const std::string & what() const { return description_; }
    private:
        std::string description_;
    };

void constructor_test_driver();

void input_test_driver();

#endif
