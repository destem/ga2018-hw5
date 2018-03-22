#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_mat4f.h"

#include <chrono>
#include <climits>
#include <vector>

/*
** A single joint in a skeleton.
** Contains a name, a parent index which is the parent joint's index
** in a skeleton's joint list.
** It also contains three transforms:
**		world - The joint's transform in model space.
**		inverse bind - The joint's inverse binding matrix.
**		skin - The joint's skinning matrix.
*/
struct ga_joint
{
	char _name[32];

	ga_mat4f _world;
	ga_mat4f _inv_bind;
	ga_mat4f _skin;

	uint32_t _parent = INT_MAX;
};

/*
** A skeleton made up of multiple joints.
** The joints are stored in a vector in the order they are parsed.
*/
struct ga_skeleton
{
	static const uint32_t k_max_skeleton_joints = 75;

	std::vector<ga_joint*> _joints;
};

/*
** A single pose within a complete animation.
** The vector of transforms is meant to be parallel to the vector of joints
** in a skeleton. For example, transform 0 corresponds to joint 0 in the
** skeleton.
*/
struct ga_skeleton_pose
{
	std::vector<ga_mat4f> _transforms;
};

/*
** An animation which consists of multiple poses that represent frames.
** Also stored are the length of the animation in seconds, and the
** framerate of the animation.
*/
struct ga_animation
{
	float _length;
	uint32_t _rate;

	std::vector<ga_skeleton_pose> _poses;
};

/*
** A simple structure to represent the current state of animation
** playback on an entity.
** Stores the playing animation and the local time of the animation.
*/
struct ga_animation_playback
{
	ga_animation* _animation;
	std::chrono::milliseconds _time;
};
