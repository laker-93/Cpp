#include <string>
#include <string.h> //for c style program
#include <iostream>


int string_play() {
    std::string t = "test";


    int counter = 0;
    for(size_t i = counter; i <= t.size(); i++) {
        if(i == t.size()) { 
            std::cout << "eof" << std::endl;
            break;
        }
        std::cout << t.at(i) << std::endl;
    }
    return 0;
}


bool match_cpp(std::string &pattern, std::string &file, size_t pattern_count,
        size_t file_count) {
    for(; pattern_count < pattern.size(); pattern_count++) {
    std::cout << "start of for loop with file count = " << file_count 
        << " and pattern_count =  " << pattern_count << 
        " file.size() = " << file.size() <<
        " pattern.size() = " << pattern.size() << std::endl;
        switch(pattern.at(pattern_count)) {
            case '*':
                //if pattern terminates after * we are done since can then mat-
                //ch with any file
                if(pattern_count + 1 == pattern.size()) { return true; }
                //if not then need to increment file through all its chars whi-
                //lst comparing against next char in pattern
                for (size_t i = 0; i < file.size(); ++i) {
                    if (match_cpp(pattern, file, pattern_count + 1, 
                                file_count + i)) {
                        return true;
                    }
                }
                //if go through all of file without matching to next character
                //in pattern then we have failed to find a match
                return false;
                //note - no need to use break here since we return
            case '?':
                //found a ? in pattern so must have some characters left in file
                //to match with. If not, file does not match.
                if(file_count == file.size()) { return false; }
                ++file_count;
                break;
            default:
                //case where no wildcard is found in pattern, Therefore must
                //require a like for like match with char in file. If
                //file_count has exceeded file.size() then also return false
                if(file_count >= file.size()) { return false; }
                if(file.at(file_count) != pattern.at(pattern_count)) {
                    return false;
                }
                ++file_count;
        }
        //at this point, iterated through entirity of pattern and so file must
        //be over too
    }

    std::cout << "exited for loop with file count = " << file_count 
        << " and pattern_count =  " << pattern_count << 
        " file.size() = " << file.size() <<
        " pattern.size() = " << pattern.size() << std::endl;
    return (file_count == file.size()); 
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
    char const *pat = "*?a***.txt";
    char const *fl = "fileb?a*******.txt";
    bool matched = match(pat, fl);

    std::string pattern = "*?a****b*.txt";
    std::string file = "fileb?a*ajahaihuf*aofij***b.txt";
    size_t pattern_count = 0;
    size_t file_count = 0;
    bool matched_cpp = match_cpp(pattern, file, pattern_count, file_count);
    std::cout << true << " c match? " << matched <<
       " cpp match? " << matched_cpp << std::endl;

    return 0;
}
