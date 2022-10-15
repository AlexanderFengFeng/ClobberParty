// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCamera.h"
#include "Camera/CameraComponent.h"

ALevelCamera::ALevelCamera()
{
    GetCameraComponent()->SetConstraintAspectRatio(false);
}
