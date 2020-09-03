#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider& otherBody, float push)
{
	sf::Vector2f otherPostion = otherBody.GetPosition();
	sf::Vector2f otherHalfSize = otherBody.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPostion.x - thisPosition.x;
	float deltaY = otherPostion.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		// clamping
		push = std::min(std::max(push, 0.0f), 1.0f);

		// intersect x and y are negative
		// if x > y, move x axis because the y collision area is higher
		if (intersectX > intersectY) {
			// if going to the right
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				// we need to move both bodies so they are no longer in collision 
				otherBody.Move(-intersectX * push, 0.0f);
			}
			// else going left
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				otherBody.Move(intersectX * push, 0.0f);
			}
		}
		else {
			// if going down
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				otherBody.Move(0.0f , -intersectX * push);
			}
			// else going up
			else {
				Move(0.0f , -intersectY * (1.0f - push));
				otherBody.Move(0.0f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}
