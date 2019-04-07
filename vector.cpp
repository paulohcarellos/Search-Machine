#include "vector.h"
#include <cmath>

Vector::Vector(){

	x_ = 0;
	y_ = 0;

}

Vector::Vector(double x, double y) {

	x_ = x;
	y_ = y;

}

double Vector::x() {

	return x_;

}

double Vector::y() {

	return y_;

}

double Vector::size() {

	return sqrt((x_ * x_) + (y_ * y_));

}

Vector Vector::operator+(Vector v) {

	Vector sum = Vector();

	sum.x_ = x_ + v.x_;
	sum.y_ = y_ + v.y_;

	return sum;

}

Vector Vector::operator-(Vector v) {

	Vector subtraction = Vector();

	subtraction.x_ = x_ - v.x_;
	subtraction.y_ = y_ - v.y_;

	return subtraction;

}

Vector Vector::scalar(double k) {

	Vector multiple = Vector();

	multiple.x_ = x_ * k;
	multiple.y_ = y_ * k;

	return multiple;

}

