#pragma once
#include "Asteroid.h"
#include "player.h"
#include "Parent.h"
#include "Gravbullet.h"

// go through and make every single collison

void PlayerAsteroidCollision(Playership &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void PlayerChildCollision(Playership &player, Parent &parent);

void bigmamaCollision(Playership &player, Parent &parent);

void BulletBossCollision(GravBullet &bullet, Parent &parent);