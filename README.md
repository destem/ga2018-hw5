# ga2018-homework5
Fifth homework for RPI Game Architecture.

This homework adds a simple animation framework to the source code.
The key additions are in ga_animation.h, ga_animation_component.h, and
ga_animation_component.cpp.  At a high level, it's architected as follows:

* ga_animation_component is responsible for storing and updating playing
  animations, and contains an entity's skeleton.
* ga_skeleton stores the joint structure of an entity.
* ga_joint is the fundamental building block of a skeleton.
* ga_animation stores animation data as a vector of ga_skeleton_poses, each of
  which is a vector of transforms, one for each joint in the skeleton.
* ga_egg_parser is a (sorta?) complete .egg file parser.

In this homework you will complete the implementation for basic skinned
animation.  You'll implement the following pieces:

* Skeleton update.
* Vertex shader skinning.

You will find the pieces of code you need to implement by searching for
"// TODO: Homework 6" comments in the depot.

When you're done, you should have a bending bar that looks like the one in
golden.gif.

## Skeleton Update

For this part, you'll need to recalculate the world and skinning matrices of
each joint in the skeleton given the current time of the animation.

For five bonus points, interpolate between frames of animation.

To calculate the current frame of animation given the local animation time, you
may use this code snippet:

	_playing->_time += std::chrono::duration_cast<std::chrono::milliseconds>(params->_delta_time);
	
	float local_time = (_playing->_time.count() % 1000) / 1000.0f;
	uint32_t frame = (uint32_t)(local_time * _playing->_animation->_rate);
	// Safety.
	frame = frame % _playing->_animation->_rate;

## Vertex Shader Skinning

For this part, you'll need to write the majority of a vertex shader which skins
the animated model.

You must specify input attributes and bind them to the appropriate locations to
receive the corresponding data. (Look at the vertex attrib pointers in ga_model_component.cpp) You must also create an array to capture the model's skinning matrices.

Finally, you must calculate a vertex's skinned position by summing the results
of transforming it by each joint that influences it, weighted by the influence
value for that joint.
