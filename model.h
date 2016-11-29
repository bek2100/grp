#pragma once
#include "polygon.h"
#include <vector>
#include "vec4.h"
#include "mat4.h"
#include "line.h"
#include <Windows.h>
#include <atlstr.h>

class model
{
public:
	model();
	~model();
	std::vector <polygon>  polygons;
	std::vector <line>  points_list;

	bool active_model;

	CString model_name;

	mat4 view_space_trans;
	mat4 obj_coord_trans;
	mat4 camera_trans;

	mat4 inv_obj_coord_trans;

	vec4 min_vec;
	vec4 max_vec;

	COLORREF color;
};


