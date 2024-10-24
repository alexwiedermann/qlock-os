#include "app_wifi_connect.h"
#include "os_config.h"
#include "resources/icons.h"
#include "resources/fonts/InterRegular16.h"
#include "resources/fonts/InterRegular24.h"

#include "WiFi.h"

void AppWifiConnect::setup() { 
  done = false;
  skipFirstRefresh = true;
}

void AppWifiConnect::drawUI(TFT_eSPI tft) {
  if (!done) {
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("Generating AP...", 160, 10, 2);

    WiFiManager wm;
  
    bool res = wm.autoConnect("QLock", "qlock1234");
    if (res) {
      tft.fillScreen(TFT_BLACK); // Clear the screen with black color
      tft.drawString("Connected! IP: " + WiFi.localIP().toString(), 160, 90, 2);
      tft.drawString("Press ESC..", 160, 105, 2);
    } else {
      tft.drawString("Failed to connect.", 160, 90, 2);
    }

    done = true;
  }
}

std::unique_ptr<AppWifiConnect> appWifiConnect(new AppWifiConnect("Connect to WiFi", icon_wifi.pixel_data, 30, 30));