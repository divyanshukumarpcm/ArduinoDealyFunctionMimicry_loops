#include<arduino.h>
void createDelayMILSec(int milliSeconds){

  /** Since atmega328p can parallel process, it means it can reach 1 MIPS at 1 Mhz clock. Arduino has
  16 Mhz crystal, so in 1 seconds - 16,000,000 (approx) instructions should be executed. So, in milli
  second 16,000 insrtuctions so, run 16,000 * no of milliseconds **/
  
  for(int i=0;i<milliSeconds;++i){
    for(int j=0;j<16000;++j)
      ;
  }
}

void createDelayMICSec(int microSeconds){

  /** Since atmega328p can parallel process, it means it can reach 1 MIPS at 1 Mhz clock. Arduino has
  16 Mhz crystal, so in 1 seconds - 16,000,000 (approx) instructions should be executed. So, in micro
  second 16 insrtuctions so, run 16 * no of microseconds **/
  
  for(int i=0;i<microSeconds;++i){
    for(int j=0;j<16;++j)
      ;
  }
}

void setup(){
  pinMode(13, OUTPUT);
  digitalWrite(13,0);
}

void loop(){
  digitalWrite(13,1);
  createDelayMILSec(500); //call createDelayMICSec() for delay in micro seconds.
  digitalWrite(13,0);
  createDelayMILSec(500);
}
