/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// BumperE              bumper        E               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "funciones.h"

using namespace vex;

competition Competition;



void pre_auton(void) {
  vexcodeInit();
  detener1();
}


void autonomous(void) {
  avanzar(1, 28, 100);
  detener1();
  PD.set(1);
  task::sleep(200);
  bd(150);
  task::sleep(200);
  avanzar(2, 17, 100);
  task::sleep(200);
  girar(-90,20);
  task::sleep(200);
  JH.set(1);
  /*avanzar(1, 5, 60);
  task::sleep(200);
  bd(-120);
  task::sleep(200);
  PD.set(0);
  task::sleep(200);
  JH.set(1);
  task::sleep(200);*/
  pararBumper1();
  task::sleep(200);
  JH.set(0);
  task::sleep(200);
  avanzar(1, 10, 100);
  task::sleep(200);
  girar(-90, 30);
  task::sleep(200);
  bandaveloz(80);
  banda(1);
  task::sleep(2000);
  banda(3);
  cicloT(9);
  task::sleep(200);
  girar(-90, 30);


  
  
  /*girar(90, 30);
  task::sleep(200);
  Bum.pressed(pararBumper);
  avanzarhasta(2, 70, 6);
  task::sleep(200);
  JH.set(0);
  task::sleep(200);*/
  /*bandaveloz(80);
  banda(1);
  task::sleep(2000);
  banda(3);
  cicloT(9);
  girar(-180, 3);
  avanzar(2, 8, 20);
  JH.set(1);
  avanzar(1, 6, 50);*/
 
}



void usercontrol(void) {
  resetea();
  parar();
  velocidad(100,100);
  int x=1;
  int y=1;
  
  while (true) {
    LeftDriveSmart.spin(forward,Controller1.Axis3.value(),percent); 
    RightDriveSmart.spin(forward,Controller1.Axis2.value(),percent);

    if(Controller1.ButtonR1.pressing()){
      BD.spin(forward);
    }
    else if (Controller1.ButtonR2.pressing()) {
      BD.spin(reverse);
    }
    else{
      BD.stop(hold);
    }
    
    if(Controller1.ButtonL1.pressing()){
      BI.spin(forward);
    }
    else if (Controller1.ButtonL2.pressing()) {
      BI.spin(reverse);
    }
    else{
      BI.stop(hold);
    }

   if(Controller1.ButtonUp.pressing() && x==1){
      PI.set(1);
      task::sleep(200);
      x=2;
    }
  else if (Controller1.ButtonUp.pressing() && x==2) {
      PI.set(0);
      task::sleep(200);
      x=1;
    }

   
   if(Controller1.ButtonX.pressing() && y==1){
      PD.set(1);
      task::sleep(200);
      y=2;
    }
    else if (Controller1.ButtonX.pressing() && y==2) {
      PD.set(0);
      task::sleep(200);
      y=1;
    }
    //banda
    if(Controller1.ButtonLeft.pressing()){
      Banda.spin(forward);
    
    }
    else if(Controller1.ButtonRight.pressing()){
      Banda.spin(reverse);
      
    }
    else if (Controller1.ButtonY.pressing()) {
      Banda.stop();
      task::sleep(200);
      x=1;
    }

    if(Controller1.ButtonB.pressing() && x==1){
      JH.set(0);
      task::sleep(200);
      x=2;
    }
    else if (Controller1.ButtonB.pressing() && x==2) {
      JH.set(1);
      task::sleep(200);
      x=1;
    }
    
    
    wait(20, msec); 
  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
