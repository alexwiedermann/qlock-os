#pragma once

#include "apps.h"

#include <WiFiManager.h>
#include "TFT_eSPI.h"


class AppSmartconfig : public App {
public:
  bool done;
  using App::App;
  void setup() override;
  void drawUI(TFT_eSPI tft) override;
};

extern std::unique_ptr<AppSmartconfig> appSmartconfig;