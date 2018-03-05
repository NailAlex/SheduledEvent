/*
The MIT License (MIT)

Copyright (c) 2018 NailAlex aka NailMan

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code by NailAlex aka NailMan
 http://nailalex.dyndns.org
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Version: 1.1
+ Initial Event Class and check time func with ZeroPoint correct
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

#ifndef SheduledEvent_h
#define SheduledEvent_h 

#include <inttypes.h> 

#define EVENT_RUNONCE        B00000000
#define EVENT_CYCLED            B00000001
#define EVENT_DELAYED          B00000010

#define EVENT_SEC  1000
#define EVENT_MIN  60000
#define EVENT_HOUR  3600000


bool CheckTime(unsigned long lastt, unsigned long idelay);


class SheduledEvent 
{
  public:
  // constructor
  SheduledEvent(void);
  //vars
  bool    isCycled;
  bool    Started;
  bool    Delayed;
  uint8_t Type;
  //methods
  void Update();
  void SetEvent(unsigned long aDelayTime, unsigned long aCycleTime, void(*pCallbackFunction)(void), uint8_t aType);
  void Start();
  void Stop();
  private:
  unsigned long _CycleTime;
  unsigned long _DelayTime;
  unsigned long _LastTime;
  void (*pCallback)(void);
 };

#endif
