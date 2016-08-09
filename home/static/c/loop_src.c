#include <stdio.h>
 
void simple (){
  unsigned int rawData = 0U;
  int i = 0;
  /* we assume that receiveInterfaceData() function returns the sensored data  or received data from CAN networks. */
  rawData = receiveInterfaceData();

  for(i=0;i<rawData; i++){ //@violation TAINTED_LOOP_BOUND
    steeringUnit();
  }
}
  

void publishSteering (unsigned int cnt,  unsigned short  direction)
{
  unsigned int  i = 0U;
  for(i = 0 ; i< cnt; i++) 
    {
      steeringUnit();
    }
}

void publishSteering2 (unsigned int cnt,  unsigned short  direction)
{
  unsigned int  i = 0U;

  if (cnt < 0) cnt = 0;
  else if (cnt > 5000) cnt = 5000;
  
  for(i = 0 ; i< cnt; i++)
    {
      steeringUnit();
    }
}

unsigned int retrieveSteering ( void )
{
  unsigned int preprocessedSteering = 0U;
  unsigned int rawData = 0U;
  
  /* we assume that receiveInterfaceData() function returns the sensored data  or received data from CAN networks. */
  rawData = receiveInterfaceData();
  
  preprocessedSteering = preprocessSteering(rawData);
  
  return preprocessedSteering;
}

int main (void)
{
  unsigned int steeringCnt = 0U;
  steeringCnt = retrieveSteering();
  publishSteering(steeringCnt, 0); //@violation TAINTED_LOOP_BOUND
  steeringCnt = retrieveSteering();
  publishSteering2(steeringCnt, 0); //@violation(NOT_EXPECTED) TAINTED_LOOP_BOUND
  return  0;
}
