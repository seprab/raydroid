#include "entity.h"

entity::entity()
{
	
}
entity::entity(int _id):id(_id)
{
	Load();
	dirty = true;
}

entity::~entity()
{
	UnloadTexture(texture);
}

Vector2 entity::GetPosition() const
{
	return Vector2{drawBox.x, drawBox.y };
}

void entity::SetPosition(Vector2 _position)
{
	position = _position;
	drawBox.x = _position.x;
	drawBox.y = _position.y;
	dirty = true;
}

void entity::Damage(float _damage)
{
	health -= _damage;
	if (health < 0) health = 0;
	dirty = true;
}

void entity::Load()
{
	//TODO: Load json here
	texture = LoadTexture(textPath.c_str());
}

float entity::GetHealth() const
{
	return health;
}

int entity::GetID() const
{
	return id;
}
