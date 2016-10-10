#pragma once
//flops deals with floating point operations, curves


bool fequal(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

float linearHalf(float x);

float slowStart(float x);

float fastStart(float x);

float invert(float x);

float Bounce(float x);

float flipBounce(float x);

float parabFlip(float x);

float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha);

float cardinalSpline(float start, float mid, float end, float tightness, float alpha);

float catRomSpline(float start, float mid, float end, float alpha);