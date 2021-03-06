// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/app/App.h>
#include <cinder/audio/audio.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

#include <chrono>
#include <list>

#include "../src/Asteroid.h"
#include "../src/Laser.h"
#include "../src/Leaderboard.h"
#include "../src/Ship.h"
#include "cinder/Area.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
#include "../src/Utilities.h"

namespace myapp {
using cinder::Timer;

enum class GameState {
  kPlaying,
  kRules,
  kGameOver,
  kTitleScreen,
};

class MyApp : public cinder::app::App {
struct Point {
  float x, y;
};
struct Line {
  Point p1, p2;
};
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
 private:
  vec2 ship_start_location = vec2(getWindowWidth() / 2, 700);
  std::list<asteroid::Asteroid> asteroid_list;
  std::list<laser::Laser> laser_list;
  ship::Ship ship;
  utilities::Utilities utilities;
  leaderboard::LeaderBoard leaderboard_;
  std::string input = "";
  const std::string player_name_;
  gl::Texture2dRef background;
  cinder::Timer timer;
  int score = 1;
  int asteroid_counter = 0;
  int asteroid_spacing = 60;
  int laser_counter = 0;
  int asteroid_width = 40;
  int asteroid_radius = 20;
  int laser_spacing = 100;
  int asteroid_number = 14;
  int laser_number = 8;
  int laser_x_start_point = 50;
  int laser_y_start_point = 70;
  int random_height_range = 600;
  int window_height = 800;
  GameState state_;
  cinder::audio::VoiceRef mVoice;

  // Methods
  void DisplayText(const char font[], int textbox_width, int textbox_height,
      int font_size, ColorA color, std::string text, vec2 location);
  void PopulateLaserList();
  void PopulateAsteroidList();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

