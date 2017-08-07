#include <string>
#include <string.h> //for c style program
#include <iostream>


int string_play() {
    std::string t = "test";


    int counter = 0;
    for(int i = counter; i <= t.size(); i++) {
        if(i == t.size()) { 
            std::cout << "eof" << std::endl;
            break;
        }
        std::cout << t.at(i) << std::endl;
    }
    return 0;
}


bool match_cpp(std::string &pattern, std::string &file, size_t pattern_count, size_t file_count) {
    for(size_t i = pattern_count; i < pattern.size(); i++) {
        switch(pattern.at(i)) {
            case '?':
                //found a ? in pattern so must have some characters left in file
                //to match with. If not, file does not match.
                if(file_count == file.size()) { return false; }
                std::cout << "? found at index " << i << std::endl;
                break;
            case '*':
                if(pattern_count + 1 == pattern.size()) { return true; }
                std::cout << "* found at index" << i << std::endl;
                break;
        }
    }
    return true;
}


bool match(char const *pattern, char const *file) {
    for (; *pattern != '\0'; ++pattern) {
        switch (*pattern) {
        case '?': 
            //if we find a '?' in pattern then for file to match we must have
            //at least one following character. Thus if the character is the
            //null character, the file name terminates and thus does not 
            //correspond to our pattern.
            if (*file == '\0')
                return false;
            //if file does not terminate, iterate to the next character.
            ++file;
            break;
        case '*': {
            //if pattern terminates after * then file can be anything, thus
            //terminate and return true.
            if (pattern[1] == '\0')
                return true;
            //pattern doesn't terminate so cut off '*' from pattern,
            //increment file and repeat.
            size_t max = strlen(file);
            for (size_t i = 0; i < max; i++)
                if (match(pattern + 1, file + i))
                    return true;
            return false;
        }
        default:
            //if pattern doesn't specify a '?' or a '*', it must be a regular
            //character and so, must require a like for like match with file.
            if (*file != *pattern)
                return false;
            ++file;
        }
    }
    //we have iterated through the whole of pattern and so file must end too
    //if we are to match.
    return *file == '\0';
}

int main()
{

    string_play();
    char const *pat = "*.txt";
    char const *fl = "file.txt";
    bool matched = match(pat, fl);

    std::string pattern = "*?a.txt";
    std::string file = "fileb?a.txt";
    size_t pattern_count = 0;
    size_t file_count = 0;
    match_cpp(pattern, file, pattern_count, file_count);
    std::cout << true << " found match? " << matched << std::endl;

    return 0;
}
