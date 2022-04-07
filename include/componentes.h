#include "vex.h"

using namespace vex;


brain Brain;

motor l1 = motor(PORT1, ratio18_1, false);
motor l2 = motor(PORT2, ratio18_1, true);
motor l3 = motor(PORT3,ratio18_1,false);
motor l4 = motor(PORT5,ratio18_1,true);
motor l5 = motor(PORT15,ratio18_1,false);
motor_group LeftDriveSmart = motor_group(l1,l2,l3,l4,l5);

motor r1 = motor(PORT4, ratio18_1, true);
motor r2 = motor(PORT12, ratio18_1, false);
motor r3 = motor(PORT13, ratio18_1, true);
motor r4 = motor(PORT14, ratio18_1, false);
motor r5 = motor(PORT10, ratio18_1, true);
motor_group RightDriveSmart = motor_group(r1, r2,r3,r4,r5);

inertial DrivetrainInertial = inertial(PORT7);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 299.24, 322.58, 292.1, mm, 1);

controller Controller1 = controller(primary);

motor BI1 = motor(PORT19, ratio36_1, false);
motor BI2 = motor(PORT20, ratio36_1, false);
motor_group BI = motor_group(BI1, BI2);

motor BD1 = motor(PORT17, ratio36_1, true);
motor BD2 = motor(PORT18, ratio36_1, true);
motor_group BD = motor_group(BD1, BD2);

motor Banda = motor(PORT8, ratio36_1, true);

digital_out PI = digital_out(Brain.ThreeWirePort.C);
digital_out PD = digital_out(Brain.ThreeWirePort.B);
digital_out JH = digital_out(Brain.ThreeWirePort.A);
//Bumper
bumper Bum = bumper(Brain.ThreeWirePort.E);