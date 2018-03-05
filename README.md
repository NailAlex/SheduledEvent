# SheduledEvent

## Sheduled cycled and runonce events library for Arduino with ZeroPoint time correct processing

by Niskorodnov Alexander aka NailAlex(NailMan)

License: MIT License
https://mit-license.org/ 

Sheduled Events for Arduino platforms with Create/Start/Stop/Update and time checking function with the correct processing of the transition through zero.
Mostly used for periodical cycled events(render data to serial ports, graphics, etc.) and for RunOnce events with delayed start.

Supporting all Arduino platforms  and including example sketch to obtain . 

Download the latest version (version 1.1) here :
https://github.com/NailAlex/SheduledEvent


## HOW TO USE

```c++
void SetEvent(unsigned long aDelayTime, unsigned long aCycleTime, void(*pCallbackFunction)(void), uint8_t aType);
```
Set event parameters
aDelayTime - time from Start() to start running(also-called delayed start); Use EVENT_DELAYED for set thist event type
aCycledTime - cycle period time for cycled event(such as Render function); If the A flag EVENT_DELAYED is used, it starts to work after a delay else Run immidiately;
pCallbackFunction - mandatory external function for Callback;
aType - Setup flags. Use EVENT_RUNONCE, EVENT_DELAYED, EVENT_CYCLED with "or" operand, example:

```c++
uEvent.SetEvent(5000, 1000, RenderToSerial, EVENT_CYCLED | EVENT_DELAYED);
```
Setup Event for 1 time per second render to serial port with 5 seconds delay.

Also, time constants are provided for specifying the time:
EVENT_SEC - one second (1000ms)
EVENT_MIN - ome min (60000ms)
EVENT_HOUR - one hour (3600000ms)

and use it for setup 2 hour 14 min 12 sec delay with these call RunOnce event
```c++
uEvent.SetEvent(EVENT_HOUR * 2 + EVENT_MIN * 14 + EVENT_SEC * 12, 0, ChangeTheCounter, EVENT_RUNONCE | EVENT_DELAYED);
```

- Also you can use the time checking function with the correct processing of the transition through zero (~ 70 day work period)
```c++
bool CheckTime(unsigned long lastt, unsigned long idelay);
```
Where:
lastt - Time value (millis) at start(last) position
idelay - Delay period for event
Result - if current time > Last Time + Delay (with ZeroPoint correct) then return "True"

## History
(Feb 2018) v1.1 First release with CheckTime function. 