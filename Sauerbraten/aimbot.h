#pragma once
#include <cstdint>
#include <math.h>
#include <numbers>
#include <stdio.h>
#include "vector.h"
#include "entity.h"
#include "entitylist.h"

float toAngle(float radians);
float calcYaw(Vector3 resultingVector3);
float calcPitch(Vector3 resultingVector3);
float calcDistance(Vector3 resultingVector3);
void aimAtSpecific(Entity LocalPlayer, Entity Enemy, std::uintptr_t* yawPtr, std::uintptr_t* pitchPtr) noexcept;
void aimAtNearest(Entity LocalPlayer, std::uintptr_t* yawPtr, std::uintptr_t* pitchPtr) noexcept;
