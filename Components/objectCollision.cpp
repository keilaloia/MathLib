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
	if (!bullet.isAlive) return;

	CollisionData result =
		DynamicCollision(bullet.transform, bullet.rigidbody, bullet.Collider,
			parent.transform, parent.rigidbody, parent.Collider, .2);

	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		bullet.timer = 0;
	}

}

