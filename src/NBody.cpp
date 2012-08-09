/*
 * NBody.cpp
 *
 *  Created on: Aug 10, 2012
 *      Author: Antoine Grondin
 */

#include "NBody.h"
#include "VectorMath.h"

using std::cout; using std::cerr; using std::endl;

///////////////////////////////////////////////////////////////////////
// Setup

int main(int argc, char **argv){
   if(D) cout << ":main";

   if(TEST){
      if( !testVectorMath() ){
         cerr << "Test VectorMath failed.";
         return -2;
      }

      cout << "All test OK" << endl;
   }


   printGreetings();
   setupWindow(argc, argv);
   registerCallbacks();

   // Initialize GLEW
   GLenum anError = glewInit();
   if( anError != 0 ){
      fprintf( stderr, "GLEW Error: %s\n",
               glewGetErrorString( anError ));
      if(D) cerr << " done" << endl;
      return 1;
   }

   setupRenderContext();
   glutMainLoop();
   if(D) cout << " done" << endl;
   return 0;
}

void setupWindow(int argc, char **argv){
   if(D) cout << ":setupWindow";
   gltSetWorkingDirectory( argv[0] );
   glutInit(&argc, argv);
   glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize( APP_WIDTH, APP_HEIGHT );
   glutCreateWindow( APP_NAME );
   if(D) cout << " done" << endl;
}

void registerCallbacks(){
   if(D) cout << ":registerCallbacks";
   glutReshapeFunc( onChangeSize );
   glutDisplayFunc( onRenderScene );
   if(D) cout << " done" << endl;
}

void setupRenderContext(){
   if(D) cout << ":setupRenderContext";
   sShaderManager.InitializeStockShaders();
   glEnable( GL_DEPTH_TEST );
   setupBodies();


   glClearColor( sBackgroundColor[0],
            sBackgroundColor[1],
            sBackgroundColor[2],
            sBackgroundColor[3] );

   glEnable( GL_LINE_SMOOTH );
   if(D) cout << " done" << endl;

}

void setupBodies(){
   if(D) cout << ":setupBodies";
   gltMakeSphere( sBodyBatch, sBodyRadius, 20, 40 );
   for( int i = 0; i < BODY_COUNT; i++ ){
      sBodyFrames[i].SetOrigin( sBodyPosition[i] );
   }
   if(D) cout << " done" << endl;
}

///////////////////////////////////////////////////////////////////////
// Callbacks

void onChangeSize(int aNewWidth, int aNewHeight){
   if(D) cout << ":onChangeSize";
   glViewport(0,0,aNewWidth, aNewHeight);
   sViewFrustrum.SetPerspective( APP_CAMERA_FOV,
            float( aNewWidth ) / float( aNewHeight ),
            APP_CAMERA_NEAR,
            APP_CAMERA_FAR );
   sProjectionMatrixStack.LoadMatrix(
            sViewFrustrum.GetProjectionMatrix() );
   sTransformPipeline.SetMatrixStacks(sModelViewMatrixStack,
            sProjectionMatrixStack);
   if(D) cout << " done" << endl;
}

void onRenderScene(void){
   if(D) cout << ":onRenderScene";
   // Clear the buffer
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   static CStopWatch timeKeeper;
   // Place camera
   M3DMatrix44f mCamera;
   sCameraFrame.GetCameraMatrix( mCamera );
   sModelViewMatrixStack.PushMatrix( mCamera );
   // Transform the light position into eye coordinates
   M3DVector4f lightPos = { sMainLightPos[0],
            sMainLightPos[1],
            sMainLightPos[2],
            sMainLightPos[3]};
   M3DVector4f lightEyePos;
   m3dTransformVector4( lightEyePos, lightPos, mCamera );

   // Call the drawing functions
   drawBody( &timeKeeper, lightPos );

   // Switch the buffers to bring the drawing on screen
   glutSwapBuffers();
   glutPostRedisplay();
   if(D) cout << " done" << endl;

}

///////////////////////////////////////////////////////////////////////
// Drawing

void drawBody( CStopWatch *timeKeeper, M3DVector4f lightPosition ){
   if(D) cout << ":drawBody";
   // compute displacement and new vectors

   for(int i = 0; i < BODY_COUNT; i++){
      // Save
      sModelViewMatrixStack.PushMatrix();

      // update position with regard to new values

      // draw
      sModelViewMatrixStack.MultMatrix( sBodyFrames[i] );
      sShaderManager.UseStockShader( GLT_SHADER_POINT_LIGHT_DIFF,
               sTransformPipeline.GetModelViewMatrix(),
               sTransformPipeline.GetProjectionMatrix(),
               lightPosition,
               sBodyColors[i]);
      sBodyBatch.Draw();

      // Restore
      sModelViewMatrixStack.PopMatrix();
   }

   if(D) cout << " done" << endl;
}
