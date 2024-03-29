// X is depth
// Y is horizontal
// Z is height
#include "aimbot.h"

float toAngle(float radians) {
	return (radians * 180.f) / std::numbers::pi_v<float>;
}

// Fix it, doesnt work correctly
float calcYaw(Vector3 resultingVector3) {
	if (resultingVector3.x < 0 and resultingVector3.y < 0) {
		return fabsf(toAngle(atanf((resultingVector3.x / resultingVector3.y))) - 180.f);
	}
	else if (resultingVector3.y < 0)
	{
		return fabsf(toAngle(atanf((resultingVector3.x / resultingVector3.y)))) + 180.f;
	}
	return 360.f - toAngle(atanf((resultingVector3.x / resultingVector3.y)));
}

float calcPitch(Vector3 resultingVector3) {
	float hypothenuse = calcDistance(resultingVector3);
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

void aimAtSpecific(Entity LocalPlayer, Entity Enemy, std::uintptr_t* yawPtr, std::uintptr_t* pitchPtr) noexcept
{

	if (!LocalPlayer.isAlive() or !Enemy.isAlive()) {
		return;
	}

	Vector3 LocalPlayerPos = LocalPlayer.getPos();
	Vector3 EnemyPlayerPos = Enemy.getPos();

	Vector3 resultingVector3 = EnemyPlayerPos - LocalPlayerPos;

	float pitch = calcPitch(resultingVector3);
	float yaw = calcYaw(resultingVector3);

	*reinterpret_cast<float*>(yawPtr) = yaw;
	*reinterpret_cast<float*>(pitchPtr) = pitch;
}

void aimAtNearest(Entity LocalPlayer, std::uintptr_t* yawPtr, std::uintptr_t* pitchPtr) noexcept {

}
