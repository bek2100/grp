#include "polygon.h"
#include <functional>

polygon::polygon()
{
}


polygon::~polygon()
{
}

line polygon::Normal(bool given){ 
	vec4 start;
	vec4 end;
	if (points.size() >= 3)
		start = (points[0] + points[2]) / 2;
	else
		start = points[0];

	if (given){
		end = start + Plane;
	}
	else {
		vec4 a = points[1] - points[0];
		vec4 b = points[2] - points[1];

		vec4 plane;
		plane[0] = a[1] * b[2] - a[2] * b[1];
		plane[1] = a[2] * b[0] - a[0] * b[2];
		plane[2] = a[0] * b[1] - a[1] * b[0];
		plane[3] = 0;

		end = start + plane / (sqrt(pow(plane[0], 2) + pow(plane[1], 2) + pow(plane[2], 2)));
	}
	return line(start, end);
}

bool polygon::operator==(const polygon &another_polygon) const{
	bool eq = true;
	for (unsigned int p = 0; p < points.size(); p++){
		eq = (eq && (points[p] == another_polygon.points[p]));
	}

	return eq;
}

