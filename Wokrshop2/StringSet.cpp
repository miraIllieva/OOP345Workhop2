#include "StringSet.h"
#include <fstream>
#include <sstream>
#include <vector>

namespace seneca {

    StringSet::StringSet() : strings(nullptr), num_strings(0) {}

    StringSet::StringSet(const char* filename) : strings(nullptr), num_strings(0) {
        std::ifstream file(filename);
        std::string word;
        std::vector<std::string> temp;

        while (file >> word) {
            temp.push_back(word);
        }

        num_strings = temp.size();
        strings = new std::string[num_strings];

        for (size_t i = 0; i < num_strings; ++i) {
            strings[i] = temp[i];
        }
    }

    StringSet::StringSet(const StringSet& rhs) : strings(nullptr), num_strings(rhs.num_strings) {
        if (rhs.strings) {
            strings = new std::string[num_strings];
            for (size_t i = 0; i < num_strings; ++i) {
                strings[i] = rhs.strings[i];
            }
        }
    }

    StringSet& StringSet::operator=(const StringSet& rhs) {
        if (this != &rhs) {
            delete[] strings;
            num_strings = rhs.num_strings;
            strings = new std::string[num_strings];

            for (size_t i = 0; i < num_strings; ++i) {
                strings[i] = rhs.strings[i];
            }
        }
        return *this;
    }

    StringSet::StringSet(StringSet&& rhs) noexcept : strings(rhs.strings), num_strings(rhs.num_strings) {
        rhs.strings = nullptr;
        rhs.num_strings = 0;
    }

    StringSet& StringSet::operator=(StringSet&& rhs) noexcept {
        if (this != &rhs) {
            delete[] strings;

            strings = rhs.strings;
            num_strings = rhs.num_strings;

            rhs.strings = nullptr;
            rhs.num_strings = 0;
        }
        return *this;
    }

    StringSet::~StringSet() {
        delete[] strings;
    }

    size_t StringSet::size() const {
        return num_strings;
    }

    std::string StringSet::operator[](size_t index) const {
        if (index >= num_strings) {
            return std::string();
        }
        return strings[index];
    }

}

