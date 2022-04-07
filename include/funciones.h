#include "componentes.h"

void vexcodeInit(void) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}

void calibra(){
  DrivetrainInertial.calibrate();
}

void parar(){
  Drivetrain.stop();
  BI.stop(hold);
  BD.stop(hold);
  Banda.stop(hold);
}
void detener(){
  Drivetrain.stop(hold);
  BI.stop(hold);
  BD.stop(hold);
  Banda.stop(hold);
}
void detener1(){
  Drivetrain.stop(brake);
  BI.stop(hold);
  BD.stop(hold);
  Banda.stop(hold);
}

void resetea(){
  LeftDriveSmart.resetPosition();
  LeftDriveSmart.resetRotation();
  RightDriveSmart.resetPosition();
  RightDriveSmart.resetRotation();
  BI.resetPosition();
  BI.resetRotation();
  BD.resetPosition();
  BD.resetRotation();
}

void velocidad(int ea, int giro) {
  Drivetrain.setDriveVelocity(ea, pct);
  Drivetrain.setTurnVelocity(giro, pct);
  BI.setVelocity(100, pct);
  BD.setVelocity(100, pct);
  Banda.setVelocity(100, pct);
  Drivetrain.stop(hold);
}

void torqe() {
  LeftDriveSmart.setMaxTorque(100, pct);
  RightDriveSmart.setMaxTorque(100, pct);
  BI.setMaxTorque(100, pct);
  BD.setMaxTorque(100, pct);
  Banda.setMaxTorque(100, pct);
}

void avanzar(int dir, int dis, int vel){
  if(dir==1){
    Drivetrain.setDriveVelocity(vel, pct);
    Drivetrain.driveFor(forward, dis, inches);
  }
  else if(dir==2){
    Drivetrain.setDriveVelocity(vel, pct);
    Drivetrain.driveFor(reverse, dis, inches);
  }
}

void avanzarSTO(int dir, int dis, int vel, int sto){
  if(dir==1){
    Drivetrain.setDriveVelocity(vel, pct);
    Drivetrain.setTimeout(sto, sec);
    Drivetrain.driveFor(forward, dis, inches);
  }
  else if(dir==2){
    Drivetrain.setDriveVelocity(vel, pct);
    Drivetrain.setTimeout(sto, sec);
    Drivetrain.driveFor(reverse, dis, inches);
  }
}
void avanzarhasta(int dir,int vel){ //int sto){
  if(dir== 1){
    Drivetrain.setDriveVelocity(vel, pct);
    Drivetrain.drive(forward);
    //Drivetrain.setTimeout(sto, sec);
  }
  else if(dir== 2){
    Drivetrain.setDriveVelocity(vel, pct);
    Drivetrain.drive(reverse);
    //Drivetrain.setTimeout(sto, sec);
  }
  else if(Bum.pressing()){
    Drivetrain.stop(hold);
    Controller1.Screen.print("Presionando...");
    Controller1.Screen.newLine();
  }

}

void girar(int grad, int vel){
  Drivetrain.setTurnVelocity(vel, pct);
  Drivetrain.turnToRotation(grad,degrees);
}


void bi(int grad){
  BI.rotateFor(grad, degrees);
}

void bd(int grad){
  BD.rotateFor(grad, degrees);
}

void banda(int dir){
  if(dir==1){
    Banda.spin(forward);
  }
  else if(dir==2){
    Banda.spin(reverse);
  }
  else{
    Banda.stop(hold);
  }
}
void bandaveloz(int v){
  Banda.setVelocity(v,pct);
}
void cicloT(int cantidad){
  Banda.spin(forward,70,percent);
  repeat(cantidad){
    avanzar(1, 8, 20);
    avanzar(2, 8, 20);
  }
  Banda.stop();
}

void pararBumper(){
  Drivetrain.stop();
}
void pararBumper1(){
  bool estado=true;
      Drivetrain.setDriveVelocity(60, pct);

  while(estado==true){
    if(Bum.pressing()==false){
    Drivetrain.drive(reverse);
    }
    else{
      Drivetrain.stop(hold);
      estado=false;
    }
  }
}