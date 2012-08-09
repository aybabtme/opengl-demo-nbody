/*
 * NBody.h
 *
 *  Created on: Aug 10, 2012
 *      Author: Antoine Grondin
 */

#ifndef NBODY_H_
#define NBODY_H_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

// Project libs
#include <GLTools.h>
#include <GLFrustum.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <GLShaderManager.h>
#include <StopWatch.h>
#include <math3d.h>
// Local
#include "Constants.h"

const static bool D = DEBUG;

// Variables
// - Matrices and shaders
static GLShaderManager sShaderManager;
static GLFrustum sViewFrustrum;
static GLMatrixStack sProjectionMatrixStack;
static GLMatrixStack sModelViewMatrixStack;
static GLGeometryTransform sTransformPipeline;

////////////////////////////////////////////////////////////////////////
// MODELS
////////////////////////////////////////////////////////////////////////
static GLFrame sCameraFrame;

const static GLclampf sBackgroundColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const static M3DVector4f sMainLightPos = { 0.0f, 10.0f, 5.0f, 1.0f };

static GLTriangleBatch sBodyBatch;
static GLFrame sBodyFrames[BODY_COUNT];
const static GLfloat sBodyRadius = 15.0f;

const static GLclampf sBodyColors[BODY_COUNT][4] = {
         {1.0f, 0.5f, 0.5f, 1.0f},
         {0.5f, 0.5f, 1.0f, 1.0f}
};

static M3DVector3f sBodyPosition[BODY_COUNT] = {
         { -200.0f, -200.0f, -1000.0f },
         { 200.0f, 200.0f, -1000.0f }
};
static M3DVector3f sBodyVelocity[BODY_COUNT] = {
         { 0.0f, 0.0f, 0.0f },
         { 0.0f, 0.0f, 0.0f }
};
static M3DVector3f sBodyAcceleration[BODY_COUNT] = {
         { 0.0f, 0.0f, 0.0f },
         { 0.0f, 0.0f, 0.0f }
};
static GLfloat sBodyMass[BODY_COUNT] = {
         10.0f,
         10.0f
};


///////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////

// Setup
void setupWindow(int argc, char **argv);
void registerCallbacks();
void setupRenderContext();
void setupBodies();

// Callbacks
static void onChangeSize(int aNewWidth, int aNewHeight);
static void onRenderScene();

// Drawing
static void drawBody( CStopWatch *timeKeeper,
         M3DVector4f lightPosition );

// Misc
inline void printGreetings(){
   std::cout << APP_NAME << std::endl << APP_VERSION << std::endl;
}

#endif
