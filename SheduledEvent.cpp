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


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "SheduledEvent.h" 



bool CheckTime(unsigned long lastt, unsigned long idelay)
{
 bool r = false;
 unsigned long t = millis();
  if (t<lastt)  
   {lastt=4294967295-lastt;   
    if ((t+lastt)>=idelay) r=true;
   } 
  else 
   {if (t-lastt>=idelay) r=true;}  
  return r;
}



SheduledEvent::SheduledEvent(void)
{
   _LastTime=millis();
   _CycleTime=0; 
   _DelayTime=0;
    Started=false;
    Delayed=false;
    isCycled=false;
    Type=EVENT_RUNONCE;
}

void SheduledEvent::SetEvent(unsigned long aDelayTime, unsigned long aCycleTime, void(*pCallbackFunction)(void), uint8_t aType)
{
  pCallback = pCallbackFunction;
  _DelayTime=aDelayTime;
  _CycleTime=aCycleTime;
  Started=false;
  Type=aType;
  if (Type & EVENT_DELAYED) Delayed=true; else Delayed=false;
  if (Type & EVENT_CYCLED)  isCycled=true; else isCycled=false;
}


void SheduledEvent::Update()
{
    if (Delayed) {
           if (CheckTime(_LastTime,_DelayTime)) {Started=true; Delayed=false;_LastTime= millis();}
    }
   else 
    {if (Started){  
          if (CheckTime(_LastTime,_CycleTime)) {
             if (isCycled) {Started=true; _LastTime=millis(); }         //if Event isCycled then restart Cycle
            else Started=false;                                        //else stop Running.
           pCallback();           //activate CallBack function if time to Run it
          }
     } 
    }
}


void SheduledEvent::Start()
{
_LastTime=millis();
   if (Type & EVENT_DELAYED) {
    Delayed=true;
    Started=false;
   } 
   else {
    Delayed=false;
    Started=true; 
   }
}


void SheduledEvent::Stop()
{
_LastTime=millis();
 Started=false;
 Delayed=false;
}

