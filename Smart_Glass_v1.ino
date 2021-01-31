
#include "settings.h"
#include "isr.h"
#include "img_detect.h"
#include "save_to_sd.h"
#include "img_capture.h"



void setup() {
  // Turn-off the 'brownout detector'
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  Serial.begin(115200);
  
  pinMode(33,OUTPUT); //Built-in-LED
  touchAttachInterrupt(click, gotTouch1, touch_threshold);
  //esp_sleep_enable_ext0_wakeup(GPIO_NUM_13,0);

  
  //Wi-Fi Connect
  WiFi.begin(ssid, password);
  int i=0;
  while (WiFi.status() != WL_CONNECTED) {
    i++;
    if(i==50)  ESP.restart(); //Restart after 5 Sec.
    delay(100); 
    digitalWrite(33,!digitalRead(33));
  }
  delay(5000);
  digitalWrite(33,1);
  Serial.print("IP Address: http://");
  Serial.println(WiFi.localIP());
  
  //Camera initiate
  setup_cam();
  //setup_sd();///Problem with interrupt!!
}

void loop() {
  
  //Uncomment if not sd save
  if(touch1detected){
    capture_image();
    delay(50);
    touch1detected = false;
  }
  

}
