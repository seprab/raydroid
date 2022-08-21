#pragma once

#include <string>
#include "raylib.h"

class entity
{
public:
	entity(int _id);
	~entity();
	int GetID() const;
	Vector2 GetPosition() const;
	float GetHealth() const;
	
	void SetPosition(Vector2 _position);
	void Damage(float _damage);
	
	virtual void Load();
	virtual void Spawn() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	
private:
	
	std::string name;
	std::string textPath;
	Texture2D texture;
	Rectangle hitbox;
	Rectangle drawBox;
	
	int id{ 0 };
	float maxHp{ 100.f };
	float health{ 100.f };
	bool destroyable{ false };
	bool dirty{ true };
	Vector2 scale{ 0,0 };
	Vector2 position{ 0,0 };
};

