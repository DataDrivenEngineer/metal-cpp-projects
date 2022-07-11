//
//  Math.hpp
//  cameras
//
//  Created by Dmitrii Belousov on 7/3/22.
//

#pragma once

#include "glm/mat4x4.hpp"
#include "glm/vec4.hpp"
#include "glm/trigonometric.hpp"

class Math
{
  public:
	static const Math & getInstance();
	Math(Math const &) = delete;
	void operator=(Math const &) = delete;
	
	inline const glm::mat4x4 translation(const float_t & trX, const float_t & trY, const float_t & trZ) const
	{
	  glm::mat4x4 mat = _identity;
	  mat[3].x = trX;
	  mat[3].y = trY;
	  mat[3].z = trZ;
	  return mat;
	}
	
	inline const glm::mat4x4 translation(const glm::vec3 & tr) const
	{
	  glm::mat4x4 mat = _identity;
	  mat[3].x = tr.x;
	  mat[3].y = tr.y;
	  mat[3].z = tr.z;
	  return mat;
	}
	
	inline const glm::mat4x4 scaling(const float_t & scaleX, const float_t & scaleY, const float_t & scaleZ) const
	{
	  glm::mat4x4 mat = _identity;
	  mat[0].x = scaleX;
	  mat[1].y = scaleY;
	  mat[2].z = scaleZ;
	  return mat;
	}
	
	inline const glm::mat4x4 scaling(const float_t & scale) const
	{
	  glm::mat4x4 mat = _identity;
	  mat[3].w = 1 / scale;
	  return mat;
	}
  
	inline const glm::mat4x4 rotationX(const float_t & angleDegrees) const
	{
//	  float_t angleRad = glm::radians(angleDegrees);
	  const float_t angleRad = angleDegrees;
	  glm::mat4x4 mat = _identity;
	  mat[1].y = cosf(angleRad);
	  mat[1].z = sinf(angleRad);
	  mat[2].y = -sinf(angleRad);
	  mat[2].z = cosf(angleRad);
	  return mat;
	}
	
	inline const glm::mat4x4 rotationY(const float_t & angleDegrees) const
	{
//	  float_t angleRad = glm::radians(angleDegrees);
	  const float_t angleRad = angleDegrees;
	  glm::mat4x4 mat = _identity;
	  mat[0].x = cosf(angleRad);
	  mat[0].z = -sinf(angleRad);
	  mat[2].x = sinf(angleRad);
	  mat[2].z = cosf(angleRad);
	  return mat;
	}
  
	inline const glm::mat4x4 rotationZ(const float_t & angleDegrees) const
	{
//	  float_t angleRad = glm::radians(angleDegrees);
	  const float_t angleRad = angleDegrees;
	  glm::mat4x4 mat = _identity;
	  mat[0].x = cosf(angleRad);
	  mat[0].y = sinf(angleRad);
	  mat[1].x = -sinf(angleRad);
	  mat[1].y = cosf(angleRad);
	  return mat;
	}
  
	inline const glm::mat4x4 rotation(const float_t & angleDegrees) const
	{
	  return rotationX(angleDegrees) * rotationY(angleDegrees) * rotationZ(angleDegrees);
	}
	
	inline const glm::mat4x4 rotation(const glm::vec3 & rotationDegrees) const
	{
	  return rotationX(rotationDegrees.x) * rotationY(rotationDegrees.y) * rotationZ(rotationDegrees.z);
	}
	
	inline const glm::mat4x4 perspective(const float_t & fovDegrees, const float_t & near, const float_t & far, const float_t & aspect) const
	{
	  float_t fovRad = glm::radians(fovDegrees);
	  glm::mat4x4 mat = _identity;
	  // Left-handed coordinate system
	  mat[1].y = 1 / tanf(fovRad * 0.5f);
	  mat[0].x = mat[1].y / aspect;
	  mat[2].z = far / (far  - near);
	  mat[2].w = 1;
	  mat[3].z = mat[2].z * -near;
	  mat[3].w = 0;
	  return mat;
	}
  
  private:
	Math();
	const glm::mat4x4 _identity;
	inline const glm::mat4x4 identity() const { return _identity; }
};
