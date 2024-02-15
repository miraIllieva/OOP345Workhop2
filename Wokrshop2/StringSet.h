#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <string>

namespace seneca {

    class StringSet {
        std::string* strings{ nullptr };
        size_t numStrings{ 0 };

    public:
        StringSet(); // Default constructor
        StringSet(const std::string& file); // 1-arg constructor
        StringSet(const StringSet& other); // Copy constructor
        StringSet& operator=(const StringSet& other); // Copy assignment operator
        StringSet(StringSet&& other) noexcept; // Move constructor
        StringSet& operator=(StringSet&& other) noexcept; // Move assignment operator
        ~StringSet(); // Destructor

        size_t size() const;
        std::string operator[](size_t index) const;
    };

}

#endif // SENECA_STRINGSET_H
