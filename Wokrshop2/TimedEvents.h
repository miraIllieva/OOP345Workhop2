#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <chrono>
#include <string>

namespace seneca {

    const size_t MAX_EVENTS = 10;

    class TimedEvents {
        size_t currentEvent{ 0 };
        std::chrono::steady_clock::time_point startTime;
        struct Event {
            std::string eventName;
            std::string unitsOfTime;
            std::chrono::steady_clock::duration duration;
        } events[MAX_EVENTS];
    public:
        TimedEvents() = default;
        void startClock();
        void stopClock();
        void addEvent(const char* event);
        friend std::ostream& operator<<(std::ostream& os, const TimedEvents& events);
    };

}

#endif // SENECA_TIMEDEVENTS_H
