#include "Gamestate.h"
#include <cmath>

void Gamestate::spawnBullet(const Transform & t, float impulse, bool playerOwned)
{
	int i = 0;
	for (i = 0; i < 100; ++i)
		if (!bullet[i].isAlive)
			break;

	if(i < 100)
	{
		bullet[i].isAlive = true;
		bullet[i].timer = 5;
		bullet[i].rigidbody.velocity = impulse * t.getDirection();
		bullet[i].transform.m_position = t.getGlobalPosition();
		bullet[i].transform.m_facing = t.m_facing;
		bullet[i].fromPlayer = playerOwned;
	}



}

void Gamestate::playerspawnBullet(const Transform & t, float impulse)
{
	int i = 0;
	for (i = 0; i < 100; ++i)
		if (!playerBullet[i].isAlive)
			break;

	if (i < 100)
	{
		playerBullet[i].isAlive = true;
		playerBullet[i].timer = 10;
		playerBullet[i].rigidbody.velocity = impulse * t.getDirection();
		playerBullet[i].transform.m_position = t.m_position;
		playerBullet[i].transform.m_facing = t.m_facing;
		
	}

}



void Gamestate::init()
{

	for (int i = 0; i < 100; ++i)
		bullet[i].timer = 0;

	for (int i = 0; i < 100; ++i)
		playerBullet[i].timer = 0;

	//player
	player.transform.m_position = vec2{ 200, 200 };
	player.transform.m_facing = 0;

	invisbar[0].transform.m_position = vec2{ -500, 950 };
	invisbar[1].transform.m_position = vec2{ 900, 950 };



	for (int i = 1; i < BOSS_COUNT; ++i)
	{
		parent[i].transform.m_parent = &parent[0].transform;
	}
	
	resetParent();




}

void Gamestate::resetParent()
{
	//big mama
	for (int m = 0; m < 1; m++)
	{
		parent[0].rigidbody.addImpulse(parent[0].forcepower);
		parent[m].health.health = 100;
		parent[m].health.isAlive = true;
		parent[0].transform.m_position = vec2{ 200, 950 };
		

	}
	// left arm
	for (int i = 1; i < 10; i++)
	{
		parent[i].health.health = 100;
		parent[i].health.isAlive = true;
		parent[i].transform.m_position = vec2{ (-13.f * i), (-10.f * i) };
		spawnBullet(parent[i].transform, 100);

	}

	//right arm
	
	for (int j = 11; j < BOSS_COUNT; j++)
	{
		parent[j].health.health = 100;
		parent[j].health.isAlive = true;
		parent[j].transform.m_position = vec2{ ((j-10) * 13.f ), ((j-10) * -10.f ) };
		spawnBullet(parent[j].transform, 100);

	
	}
	


	

	


}

void Gamestate::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	
	
	for (int i = 0; i < 100; ++i)
		bullet[i].update(deltaTime, *this);

	for (int i = 0; i < 100; ++i)
		playerBullet[i].update(deltaTime, *this);

	


	for (int i = 0; i < BOSS_COUNT; ++i)
	{
		parent[i].update(deltaTime, *this);
	}




	for (int i = 1; i < BOSS_COUNT; ++i)
	{
		PlayerChildCollision(player, parent[i]);

	}

	for (int j = 0; j < 1; ++j) 
	{
		bigmamaCollision(player, parent[j]); 
	}



	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 1; ++j)
			if(bullet[i].fromPlayer)
			{
			BulletBossCollision(bullet[i], parent[j]);
			}

	for (int i = 0; i < 100; ++i)
		for (int j = 1; j < BOSS_COUNT; ++j)
			if (bullet[i].fromPlayer)
			{
				BulletChildCollision(bullet[i], parent[j]);
			}

	for (int i = 0; i < 2; ++i)
	{
		barCollision(invisbar[i], parent[0]);	
	}

	for (int i = 0; i < 100; ++i)
		for (int j = 1; j < BOSS_COUNT; ++j)
			{
				playerbossbullet(parent[j], playerBullet[i]);
			}
}

void Gamestate::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam);
	
	for (int i = 0; i < 100; ++i)
		bullet[i].draw(cam);

	for (int i = 0; i < 100; ++i)
		playerBullet[i].draw(cam);


	invisbar[0].draw(cam);
	invisbar[1].draw(cam);


	for (int i = 0; i < BOSS_COUNT; ++i)
	{
		if(parent[i].health.isAlive)
			parent[i].draw(cam);
	}
}

