#include "TimedEvents.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    void TimedEvents::startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        auto stopTime = std::chrono::steady_clock::now();
        events[currentEvent].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
    }

    void TimedEvents::addEvent(const char* event) {
        if (currentEvent < MAX_EVENTS) {
            events[currentEvent].eventName = event;
            events[currentEvent].unitsOfTime = "nanoseconds";
            ++currentEvent;
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedEvents& events) {
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (size_t i = 0; i < events.currentEvent; ++i) {
            os << std::setw(21) << std::left << events.events[i].eventName
                << std::setw(13) << std::right << events.events[i].duration.count() << ' '
                << events.events[i].unitsOfTime << '\n';
        }
        os << "--------------------------\n";
        return os;
    }

}
