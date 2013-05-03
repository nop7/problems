#include<stdio.h>
#include<stdlib.h>

float x[4] = {0.0,1.0,1.0,0.0};
float y[4] = {0.0,0.0,1.0,1.0};

struct vec{
  vec():x(0),y(0){}
	vec(float x1, float y1): x(x1), y(y1){}
	float x, y;		
};
vec operator -(const vec& a, const vec& b){
	return vec(a.x - b.x, a.y - b.y);
}
vec operator +(const vec& a, const vec& b){
	return vec(a.x + b.x, a.y + b.y);
}

float cross(const vec& a, const vec& b){
	return a.x*b.y - a.y*b.x;
}

bool point_in_tri(const vec& a1, const vec& a2, const vec& a3, const vec& p){
	if (cross(a2 - a1, p - a1) < 0)
		return false;
	if (cross(a3 - a2, p - a2) < 0)
		return false;
	if (cross(a1 - a3, p - a3) < 0)
		return false;
	return true;
}

bool is_convex(float* x, float* y){
	vec p[4];

	for (int i = 0; i < 4; i++){
		p[i] = vec(x[i], y[i]);
	}

	vec a = p[1] - p[0];
	vec b = p[2] - p[0];
	vec c = p[3] - p[0];

	for (int i = 0; i < 4; i++){
		vec p1 = p[i];
		vec p2 = p[(i+1)%4] - p[i];
		vec p3 = p[(i+2)%4] - p[i];
		vec p4 = p[(i+3)%4] - p[i];
		if (point_in_tri(p1,p2,p4,p3))return false; 
	}
	return true;
}

int main(){
	if (is_convex(x, y))
		printf("YES\n");
	else
		printf("NO\n");
}
