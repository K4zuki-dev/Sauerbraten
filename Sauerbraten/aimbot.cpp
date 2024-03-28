// X is depth
// Y is horizontal
// Z is height
#include "aimbot.h"

float toAngle(float radians) {
	return (radians * 180) / std::numbers::pi_v<float>;
}
// Fix it, doesnt work correctly
float calcYaw(Vector3 resultingVector3) {
	float hypothenuse = sqrtf(
		(powf(resultingVector3.y, 2) + powf(resultingVector3.x, 2))
	);
	return toAngle(asinf((resultingVector3.x / hypothenuse)));
}

// Fix it, doesnt work correctly
float calcPitch(Vector3 resultingVector3) {
	float hypothenuse = sqrtf(
		(powf(resultingVector3.x, 2) +powf(resultingVector3.z, 2))
	);
	return toAngle(asinf((resultingVector3.z / hypothenuse)));
}

float calcDistance(Vector3 resultingVector3) {
	float distance = sqrtf(
		(
		powf(resultingVector3.x, 2) + 
		powf(resultingVector3.y, 2) + 
		powf(resultingVector3.z, 2)
		)
	);

	return distance;
}

void overwriteAngles(std::uintptr_t* yawPtr, std::uintptr_t* pitchPtr, Vector3 localPlayerPos, Vector3 entityPos) noexcept
{
	Vector3 resultingVector3 = entityPos - localPlayerPos;
	float distance = calcDistance(resultingVector3);

	float pitch = calcPitch(resultingVector3);
	float yaw = calcYaw(resultingVector3);

	*reinterpret_cast<float*>(yawPtr) = yaw;
	*reinterpret_cast<float*>(pitchPtr) = pitch;

	// printf("Yaw: %f ---- Pitch: %f\n", yaw, pitch);
}
