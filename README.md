# n-body simulation
## An homemade planetarium
The aim of this demo is to try out OpenGL with a topic that I dig.

## To build and run it!
The Makefile is setup to build from a linux box (mine is Arch Linux)
 using `clang`, but you can easily change that line (`clang++`) for
 `g++`, and it will compile just as well.  Also note that you must have
library `freeglut` installed in your system.  You can look at the
Makefile to see where `freeglut` can be installed.

``` shell
    cd opengl-demo-nbody
    make
    ./n-body-sim    # runs the demo (will start in fullscreen, `alt+F4 to exit`)
```

You can safely ignore the warnings (2 of them) produced.

## What is this math?!
Meh, I suck at calculus and stuff.  In fact, I hope this project will
motivate me in mastering it by giving me a purpose to learn.

## What is this C++?!
I'm learning C++ with this project.  However, `freeglut` (the library I 
use to manage the basic OpenGL stuff) makes it really hard to use OO
 programming, thus the procedural style.

If I keep working on this side-project long enough, I'll eventually port
it to use SDL.

## TODO
* Create a scene with 2-bodies.
* Give physic properties to the bodies.
    * Must include mass; (*done*)
    * Must include volume; (*done*)
    * Must include position/speed/acceleration; (*done*)
    * Must include collision detection (to avoid near-zero 
            anomalities[1]). (_remains to be implemented[2]_)
* Animate the bodies as a function of time. (*done*)
* EXTRA: Trace the future trajectory of the body
* EXTRA++: Make this trace time-colored (so if two trajectories cross at
        a similar color, I can predict a collision!)
* Increase to 3-bodies. (*done*)
* Increase to n-bodies. (*done*)
* Enter the properties of the Solar system and try to simulate it.
* Separate the computation of the n-bodies from the graphic rendering
loop, to permit variable precision in the simulation step.

[1] When two bodies get too close, the influence they have over one
another greatly increase, while the calculation step doesn't, leading to
huge approximation errors.  The most common effect is that the two
bodies will be greatly accelerated at t\_n, then be computed to a new
much greater distance at t\_n+1.  Because the two bodies at t\_n+1 are
now so far from each other, the new force they exert on one another will
not be sufficient enough to sufficiently slow back the two bodies.
Although the two bodies will eventually come back closer, it will be
at a great speed and the effect will only amplify with time.

[2] There are two ways I expect to do this.  Either I will remove all
velocity/acceleration in the direction of the collision between the two
bodies (that is, the normal of the two touching surface).  This would
make the bodies start rolling around one another.  Adding friction would
simulate, I expect, bubble-like collisions.  The other way would be to
break the bodies in smaller bodies when they collide, and define some
rule for the force they receive when they 'explode'.  This would let me,
     I expect, simulate the formation of more complex systems based on
     particle-like behaviors.  I expect it could form asteroid-like
     belts and some aggregate of particles would reform planet-like
     shapes.  Both ways are interesting.
