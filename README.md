SheduledEvent
=====================

Sheduled cycled and runonce events library for Arduino with ZeroPoint time correct processing

by Niskorodnov Alexander aka NailAlex(NailMan)

DOWNLOAD
=====================

Download the latest version (version 1.1) here :
https://github.com/NailAlex/SheduledEvent


HOW TO USE
=====================

- Create Event instance
- Create Event handler for callback
- Setup event for your needs (RunOnce, RunOnce+Delay, Cycle, Cycle+Delay)
- Start it!...and update

See simple uncluded example!

- Also you can use the time checking function with the correct processing of the transition through zero (~ 70 day work period)

bool CheckTime(unsigned long lastt, unsigned long idelay);

lastt - Time value (millis) at start position
idelay - checked pause for event
Result - if current time > Last Time + Delay (with ZeroPoint correct) then return "True"

