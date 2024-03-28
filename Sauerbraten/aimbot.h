#pragma once
#include <cstdint>
#include <math.h>
#include <numbers>
#include <stdio.h>
#include "vector.h"

float toAngle(float radians);
float calcYaw(Vector3 resultingVector3);
float calcPitch(Vector3 resultingVector3);
float calcDistance(Vector3 resultingVector3);
void overwriteAngles(std::uintptr_t* yawPtr, std::uintptr_t* pitchPtr, Vector3 localPlayerPos, Vector3 entityPos) noexcept;
