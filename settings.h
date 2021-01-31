/*__________________LIBRARIES__________________________*/

#include "Arduino.h"
#include "esp_camera.h"
#include <WiFi.h>

#include <HTTPClient.h>
#include <ArduinoJson.h>

#include <base64.h>
#include "FS.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "driver/rtc_io.h"
#include "esp_timer.h"

#include "SD_MMC.h"
#include <EEPROM.h>

/*___________________Wi-Fi Settings_________________________*/
const char* ssid = "sourav";
const char* password = "12345678";

/*_________________MODEL API______________________*/
// Generic model
//String model_id = "aaa03c23b3724a16a56b629203edc62c"; 
//String app_key = "891e0781c55e4175920094840204a5dc";

//Text recog.
String model_id = "9fe78b4150a52794f86f237770141b33";  
String app_key = "6a71075ee96040df9c653dbf8fd86153" ;


/*_____________________EEPROM Setting___________________________*/
#define EEPROM_SIZE 1

/*_____________________Other Setting___________________________*/
String sd_path = "";  //"/32cam";
#define click T5  //Touchpin-5
#define touchPin2 T6
int touch_threshold = 25;






/*_________________CAMERA PINs______________________*/
// OV2640 camera module pins (CAMERA_MODEL_AI_THINKER)
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22
