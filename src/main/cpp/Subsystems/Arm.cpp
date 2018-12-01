/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Arm.h"

Arm::Arm() : Subsystem("ExampleSubsystem") 
{
  arm->ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 10);
  arm->Config_kP(0, 0.1, 10);
  arm->Config_kI(0, 0, 10);
  arm->Config_kD(0, 0, 10);
  arm->Config_kF(0, 0, 10);
  
}

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Arm::moveArm(double moveVal)
{
  arm->Set(moveVal);

}

WPI_TalonSRX* Arm::getArm()
{
  return arm;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
