#include "objectCollision.h"

void PlayerAsteroidCollision(Playership & player, Asteroid & as)
{
	CollisionData result =
		DynamicCollision(player.transform, player.Rigidbody, player.Collider,
			as.transform, as.rigidbody, as.Collider, 1);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		player.transform.m_scale *= .9f;
	}
}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicCollision(as1.transform, as1.rigidbody, as1.Collider,
		as2.transform, as2.rigidbody, as2.Collider, 1);

}

void PlayerChildCollision(Playership & player, Parent & parent)
{
	if (parent.health.isAlive == false)
	{
		return;
	}

	CollisionData result =
	DynamicCollision(player.transform, player.Rigidbody, player.Collider,
		parent.transform, parent.rigidbody, parent.Collider, .65);
}

void bigmamaCollision(Playership & player, Parent & parent)
{
		CollisionData result =
		StaticCollision (player.transform, player.Rigidbody, player.Collider,
		parent.transform, parent.Collider, 0);
}

void BulletBossCollision(GravBullet & bullet, Parent & parent)
{
	if (!bullet.isAlive ) return;

	CollisionData result =
		StaticCollision(bullet.transform, bullet.rigidbody, bullet.Collider,
			parent.transform, parent.Collider, .2);

	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		bullet.timer = 0;
	}


}

void BulletChildCollision(GravBullet &bullet1, Parent &parent)
{
	if (parent.health.isAlive == false)
	{
		return;
	}

	CollisionData result =
		StaticCollision(bullet1.transform, bullet1.rigidbody, bullet1.Collider,
			parent.transform, parent.Collider, .65);

	if (result.penetrationDepth >= 0 && parent.health.health)
	{
		parent.health.health -= 10;
		
	}

}

void barCollision(Invisbar & invis, Parent & parent)
{
		
	CollisionData result =
		StaticCollisionBox(parent.transform, parent.rigidbody, parent.Collider,
		invis.transform, invis.Collider, 0);		
}

void playerbossbullet(Parent & parent, Pbullet & pbullet)
{

	if (parent.health.isAlive == false)
	{
		return;
	}

	CollisionData result =
		StaticCollision(pbullet.transform, pbullet.rigidbody, pbullet.Collider,
			parent.transform, parent.Collider, .65);

	if (result.penetrationDepth >= 0 && parent.health.health)
	{
		parent.health.health -= 10;

	}
}

void bossbulletplayer(GravBullet & gbullet, Playership & player)
{
	if (!gbullet.isAlive) return;

	CollisionData result =
		StaticCollision(gbullet.transform, gbullet.rigidbody, gbullet.Collider,
			player.transform, player.Collider, .2);

	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		gbullet.timer = 0;
	}

}

void gbulletbulletCollision(GravBullet & gbullet, Pbullet & pbullet)
{
	if (!gbullet.isAlive) return;
	if (!pbullet.isAlive) return;



	CollisionData result =
		DynamicCollision(pbullet.transform, pbullet.rigidbody, pbullet.Collider,
			gbullet.transform, gbullet.rigidbody, gbullet.Collider, .65);

	//allows gbullet to hurt boss
	if (result.result())
	{
		gbullet.transform = pbullet.transform;
		gbullet.rigidbody = pbullet.rigidbody;
		gbullet.Collider = pbullet.Collider;
	}
}


