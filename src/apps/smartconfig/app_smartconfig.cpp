#include "app_smartconfig.h"
#include "os_config.h"
#include "resources/icons.h"
#include "resources/fonts/InterRegular16.h"
#include "resources/fonts/InterRegular24.h"

#include "WiFi.h"

void AppSmartconfig::setup() { 
  done = false;
  skipFirstRefresh = true;
}

void AppSmartconfig::drawUI(TFT_eSPI tft) {
  if (!done) {
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("Generating AP...", 160, 10, 2);

    WiFiManager wm;
    tft.drawString("Reset STA Configurations...", 160, 25, 2);
    wm.resetSettings();

    tft.drawString("Connect to AP. SSID: QLock, Password: qlock1234", 160, 40, 2);
    tft.drawString("And configure a wifi settings on portal.", 160, 55, 2);
    tft.drawString("Portal IP: 192.168.4.1", 160, 75, 2);
    
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

std::unique_ptr<AppSmartconfig> appSmartconfig(new AppSmartconfig("Reset WiFi", icon_wifi.pixel_data, 30, 30));