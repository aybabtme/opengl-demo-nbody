#ifndef VECTORMATH_H_
#define VECTORMATH_H_

#include <iostream>

// Physics and math constants
#define PI (3.141592653589f)
#define G (6.67e-11f)



// Vectors
typedef double Vector;
typedef Vector Force;
typedef Vector Acceleration;
typedef Vector Position;
typedef Vector Velocity;

typedef struct Vector3D{ Vector x; Vector y; Vector z; };
typedef Vector3D Force3D;
typedef Vector3D Acceleration3D;
typedef Vector3D Velocity3D;
typedef Vector3D Position3D;

// Scalar
typedef double Scalar;
typedef Scalar Mass;
typedef Scalar Time;

// Vector operations
inline Scalar magnitude( const Vector3D &aVector ){
   Scalar squareOfLength;
   squareOfLength += aVector.x * aVector.x;
   squareOfLength += aVector.y * aVector.y;
   squareOfLength += aVector.z * aVector.z;
   return sqrt(squareOfLength);
}

inline void normalize( Vector3D &aVector ){
   Scalar length = magnitude( aVector );

   aVector.x = aVector.x / length;
   aVector.y = aVector.y / length;
   aVector.z = aVector.z / length;
}


// Physics operations

inline Force forceNewtonianGravity(Mass lhsMass, Mass rhsMass,
         Position lhsPosition, Position rhsPosition){

   Scalar distance = fabs(rhsPosition - lhsPosition);

   Force result = G * ( lhsMass * rhsMass ) /
            ( distance * distance );

   return result;
}

inline Acceleration computeAccel( Mass mass, Force force){
   return mass * force;
}

inline Velocity computeVelo( Acceleration current,
         Velocity previous,
         Time deltaT ){
   return previous + (current * deltaT);
}

inline Position computePos( Velocity current,
         Position previous,
         Time deltaT ){
   return previous + (current * deltaT);
}

inline Force3D forceNewtonianGravity3D(Mass lhsMass, Mass rhsMass,
         Position3D lhsPosition, Position3D rhsPosition){
   Force3D aForceVector = {0.0, 0.0, 0.0};

   aForceVector.x = forceNewtonianGravity(lhsMass, rhsMass,
            lhsPosition.x, rhsPosition.x);
   aForceVector.y = forceNewtonianGravity(lhsMass, rhsMass,
            lhsPosition.y, rhsPosition.y);
   aForceVector.z = forceNewtonianGravity(lhsMass, rhsMass,
            lhsPosition.z, rhsPosition.z);

   return aForceVector;
}

inline Acceleration3D computeAccel3D( Mass mass, Force3D force ){
   Acceleration3D anAccelVector;
   anAccelVector.x = computeAccel( mass, force.x );
   anAccelVector.y = computeAccel( mass, force.y );
   anAccelVector.z = computeAccel( mass, force.z );
   return anAccelVector;
}

inline Velocity3D computeVelo3D( Mass mass, Acceleration3D accel,
         Time deltaT){
   Velocity3D aVelocityVector;
   aVelocityVector.x = computeVelo( mass, accel.x, deltaT);
   aVelocityVector.y = computeVelo( mass, accel.y, deltaT);
   aVelocityVector.z = computeVelo( mass, accel.z, deltaT);
   return aVelocityVector;
}

inline Position3D computePos3D( Mass mass, Velocity3D velo,
         Time deltaT){
   Position3D anPositionVector;
   anPositionVector.x = computeVelo( mass, velo.x, deltaT);
   anPositionVector.y = computeVelo( mass, velo.y, deltaT);
   anPositionVector.z = computeVelo( mass, velo.z, deltaT);
   return anPositionVector;
}

bool testVectorMath(void){

   double tolerateError = 0.01;

   Mass firstMass = 6.0;
   Mass secondMass = 4.0;
   Position firstPos = 0.0;
   Position secondPos = 0.02;

   double expected = 4.00e-6;
   double result = forceNewtonianGravity(firstMass, secondMass,
                     firstPos, secondPos);


   if( fabs(expected - result) > tolerateError ) return false;

   return true;
}

#endif
