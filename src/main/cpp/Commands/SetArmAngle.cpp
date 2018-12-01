/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/SetArmAngle.h"

SetArmAngle::SetArmAngle(double position) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
    targetVal = position;
}

// Called just before this Command runs the first time
void SetArmAngle::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void SetArmAngle::Execute() 
{
  Robot::arm->getArm()->Set(ControlMode::Position, targetVal);
  
}

// Make this return true when this Command no longer needs to run execute()
bool SetArmAngle::IsFinished()
{
  if(Robot::arm->getArm()->GetLastError() < 5)
   return true;
  else
   return false; 
}

// Called once after isFinished returns true
void SetArmAngle::End() 
{
  Robot::arm->getArm()->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmAngle::Interrupted() {}
