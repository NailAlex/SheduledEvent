/* 
 DESCRIPTION
 ====================
 Simple example of the SheduledEvent library that run three Events with these parameters:
 - RunOnce Event with delayed start(after 15 sec from start)
 - Cycled Event for render to serial port (1 time per second)
 - Cycled and delayed Event(run every 0.5 second after 10 second from start)
*/ 

#include <SheduledEvent.h>
#include <SheduledEvent.h>

SheduledEvent uEvent1,uEvent2,uEvent3;

bool flag = false;

void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
 //Set RunOnce event with 15 sec delay from start
 uEvent1.SetEvent(EVENT_SEC * 15, 0, Event1_handler, EVENT_RUNONCE | EVENT_DELAYED);
 //Set event for render data to serial with 1 sec cycle
 uEvent2.SetEvent(0, EVENT_SEC, Event2_handler, EVENT_CYCLED);
 //Set cycled and delayed event with 0.5s cycle and 10sec delay 
 uEvent2.SetEvent(EVENT_SEC * 10, 500, Event3_handler, EVENT_CYCLED | EVENT_DELAYED);

  //Start all Events!
 uEvent1.Start();
 uEvent2.Start();
 uEvent3.Start();
}

void Event1_handler(){
 Serial.println("This is RunOnce Event! It should be only one!");
}


void Event2_handler(){
 int val = analogRead(A0); 
 Serial.print("This is Cycled Event! A0 value = "); Serial.println(val); 
}

void Event3_handler(){
 int val = analogRead(A1);  
   Serial.print("This is fast cycled and delayed Event! A1 value = "); Serial.println(val); 
     if (flag) digitalWrite(13,HIGH); else digitalWrite(13,LOW);
 flag=!flag;
}


void loop() {
 //Update Events
 uEvent1.Update();
 uEvent2.Update();
 uEvent3.Update();
}
