#include "Gamestate.h"
#include <cmath>

char buffer[64] = { 0 };

void Gamestate::spawnBullet(const Transform & t, float impulse, bool playerOwned)
{
	for (int i = 0; i < 100; ++i)
	{
		// skip over bullets that are currently in play
		if (bullet[i].isAlive)
			continue;

		bullet[i].isAlive = true;
		bullet[i].timer = 10;
		bullet[i].rigidbody.velocity = impulse * normal(player.transform.getGlobalPosition() - t.getGlobalPosition());
		bullet[i].transform.m_position = t.getGlobalPosition();
		bullet[i].fromPlayer = playerOwned;

		break;
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
	player.transform.m_facing = 1.57;
	player.health.health = 500;
	player.health.maxHealth = 500;
	player.health.visualWidth = 35;
	

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
		parent[m].health.health = 180;
		parent[m].health.maxHealth = 180;
		parent[0].health.visualWidth = 15;
		parent[m].health.isAlive = true;
		parent[0].transform.m_position = vec2{ 200, 950 };
		

	}
	// left arm
	for (int i = 1; i < 10; i++)
	{
		parent[i].health.health = 100;
		parent[i].health.isAlive = true;
		parent[i].health.maxHealth = 100;
		parent[i].transform.m_position = vec2{ (-13.f * i), (-10.f * i) };
		spawnBullet(parent[i].transform, 100);

	}

	//right arm
	
	for (int j = 11; j < BOSS_COUNT; j++)
	{
		parent[j].health.health = 100;
		parent[j].health.isAlive = true;
		parent[j].health.maxHealth = 100;
		parent[j].transform.m_position = vec2{ ((j-10) * 13.f ), ((j-10) * -10.f ) };
		spawnBullet(parent[j].transform, 100);

	
	}
	


	

	


}

void Gamestate::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	
	//updates boss bullet
	for (int i = 0; i < 100; ++i)
		bullet[i].update(deltaTime, *this);

	//updates playerbullets
	for (int i = 0; i < 100; ++i)
		playerBullet[i].update(deltaTime, *this);

	

	//updates all parents/children
	for (int i = 0; i < BOSS_COUNT; ++i)
	{
		parent[i].update(deltaTime, *this);
	}



	//allows player to ram children
	for (int i = 1; i < BOSS_COUNT; ++i)
	{
		PlayerChildCollision(player, parent[i]);

	}

	//keeps player from running bigmamma off the map
	for (int j = 0; j < 1; ++j) 
	{
		bigmamaCollision(player, parent[j]); 
	}


	//keeps bosses bullets from killing himself
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 1; ++j)
			if(bullet[i].fromPlayer)
			{
			BulletBossCollision(bullet[i], parent[j]);
			}

	////junk code useful in old bullet system
	//for (int i = 0; i < 100; ++i)
	//	for (int j = 1; j < BOSS_COUNT; ++j)
	//		if (bullet[i].fromPlayer)
	//		{
	//			BulletChildCollision(bullet[i], parent[j]);
	//		}

	// invisible wall allows boss to move back and forth
	for (int i = 0; i < 2; ++i)
	{
		barCollision(invisbar[i], parent[0]);	
	}

	//player does damage to boss
	for (int i = 0; i < 100; ++i)
		for (int j = 1; j < BOSS_COUNT; ++j)
			{
				playerbossbullet(parent[j], playerBullet[i]);
			}

	//bulelts attack player
	for (int i = 0; i < 100; ++i)
	{
			bossbulletplayer(bullet[i], player);
	}

	//bullet on bullet collision
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			{
			gbulletbulletCollision(bullet[i], playerBullet[j]);
			}

	
	//bullets attack player
	for (int i = 0; i < 100; ++i)
	{
		bossbulletplayer(bullet[i], player);
	}

	//bullet on bullet collision
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
		{
			gbulletbulletCollision(bullet[i], playerBullet[j]);
		}





	if (player.transform.m_position.x < -800) player.transform.m_position.x = 1000;
	else if (player.transform.m_position.x > 1000) player.transform.m_position.x = -800;
	
	if (player.health.health <= 0)
	{
		sprintf_s(buffer, "Game over");
		sfw::drawString(d, buffer, 325, 575, 17, 17);
	}

	if (parent[0].health.health <= 0)
	{
		sprintf_s(buffer, "You win");
		sfw::drawString(d, buffer, 325, 575, 17, 17);
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


	//invisbar[0].draw(cam);
	//invisbar[1].draw(cam);


	for (int i = 0; i < BOSS_COUNT; ++i)
	{
		if(parent[i].health.isAlive)
			parent[i].draw(cam);
	}
}

