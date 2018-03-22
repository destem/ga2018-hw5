#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include <functional>

const int k_invalid_vertex_index = 0xffffffff;

/*
** State related to parsing data.
*/
struct ga_egg_parser_state
{
	int _first_vertex_index = k_invalid_vertex_index;
	std::function<void(struct ga_vec3f&)> _vector_coordinate_conversion;
	std::function<void(struct ga_mat4f&)> _matrix_coordinate_conversion;
};

/*
** Read an EGG file, get the model data.
*/
void egg_to_model(const char* filename, struct ga_model* model);

/*
** Read an EGG file, get the animation data.
*/
void egg_to_animation(const char* filename, struct ga_animation* animation, struct ga_model* model);
