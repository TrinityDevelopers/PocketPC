#pragma once

#include "Vec3.h"

class Matrix {
public:
  char filler0[40]; // from Matrix::identity
	void translate(Vec3 const&);
};

class MatrixStack {
public:
	char filler0[28]; // MatrixStack::World
	class Ref {
	public:
   	MatrixStack* stack;
		Matrix* matrix; // see the calls to MatrixStack::push
		~Ref();
  };
	
	static MatrixStack World;
	static MatrixStack Projection;
	static MatrixStack View;
	Ref push();
};