// Created by Anil Dara on 4/21/20.
//

#ifndef FINALPROJECT_ASTEROID_H
#define FINALPROJECT_ASTEROID_H

#include "cinder/app/RendererGl.h"
#include <cinder/app/App.h>
#include "cinder/gl/gl.h"
using namespace ci;
namespace asteroid {
class Asteroid {
 private:
  vec2 location;
  int radius;
  gl::Texture2dRef asteroidImage = gl::Texture2d::create(loadImage(cinder::app::loadAsset("asteroid3.png")));
 public:
  Asteroid(vec2 loc, int rad) {
    location = loc;
    radius = rad;
  }
  void update(vec2 dir, float speed);
  void draw();
  vec2 getLocation() {
    return location;
  }
  gl::Texture2dRef GetImage() {
    return asteroidImage;
  }

};

} // namespace asteroid

#endif //FINALPROJECT_ASTEROID_H