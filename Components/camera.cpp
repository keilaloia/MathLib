#include "camera.h"
#include "Gamestate.h"

Camera::Camera()
{
	projection = translate(400, 400) * scale(.5, .5);
}

mat3 Camera::getCameraMatrix() const
{
	return projection * translate(-transform.m_position.x, -transform.m_position.y);
}

void Camera::update(float deltaTime, Gamestate & gs)
{
	//transform.m_position = gs.player.transform.getGlobalPosition();
}
