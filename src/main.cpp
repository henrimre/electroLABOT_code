#include <main.h>
#include <FastLED.h>
#include <elabot.h>
#include <esp_now.h>
#include <WiFi.h>

#define piezzo 15

Elabot billy;
int dutycycle = 0;

uint8_t rainbow_state = 0;

uint8_t rouge, vert, bleu;

enum command{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  BP1,
  BP2,
  BP3,
  BP4,
  BP5,
  BP6,
  BP7,
  BP8,
  BP9,
  BP10,
  STOPP
};

typedef struct communication{
  command button;
  bool state;
} communication;

communication data;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&data, incomingData, sizeof(communication));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("button: ");
  Serial.println(data.button);
  Serial.print("   state: ");
  Serial.println(data.state);
  Serial.println();

  switch (data.button)
  {
  case BP1:
  if(data.state == 1) vert = 100;
  else vert = 0;
  break;

  case BP2:
  if(data.state == 1)digitalWrite(piezzo,HIGH);
  else digitalWrite(piezzo,LOW);
  break;

  case BP3:
  if(data.state == 1) rouge = 100;
  else rouge = 0;
  break;

  case BP4:
  if(data.state == 1){
    billy.move(LEFT_WHEELS_FORWARD, 20);
    billy.move(RIGHT_WHEELS_BACKWARD, 20);
    delay(400);
    billy.stop_move(ALL_WHEELS_STOP);
  }
  break;

  case BP5:
  if(data.state == 1) bleu = 100;
  else bleu = 0;
  break;

  case BP6:
  if(data.state == 1){
    billy.move(LEFT_WHEELS_BACKWARD, 20);
    billy.move(RIGHT_WHEELS_FORWARD, 20);
    delay(400);
    billy.stop_move(ALL_WHEELS_STOP);
  }
  break;

  case  BP7:
  rainbow_state = data.state;
  break;

  case BP8:
  if(data.state == 1){
    billy.move_head(0);
    delay(400);
    billy.move_head(180);
    delay(700);
    billy.move_head(0);
    delay(700);
    billy.move_head(90);
  }
  break;

  case FORWARD:
  if(data.state == 1) billy.move(ALL_WHEELS_FORWARD, 20);
  else billy.stop_move(ALL_WHEELS_STOP);
  break;

  case BACKWARD:
  if(data.state == 1) billy.move(ALL_WHEELS_BACKWARD, 20);
  else billy.stop_move(ALL_WHEELS_STOP);
  break;

  case LEFT:
  if(data.state == 1){
    billy.move(LEFT_WHEELS_BACKWARD, 20);
    billy.move(RIGHT_WHEELS_FORWARD, 20);
  }
  else{
    billy.stop_move(ALL_WHEELS_STOP);
  } 
  break;

  case RIGHT:
  if(data.state == 1){
    billy.move(LEFT_WHEELS_FORWARD, 20);
    billy.move(RIGHT_WHEELS_BACKWARD, 20);
  }
  else billy.stop_move(ALL_WHEELS_STOP);
  break;

  
  default:
    break;
  }
}

void setup() 
{
  Serial.begin(115200);

  pinMode(piezzo, OUTPUT);

  WiFi.mode(WIFI_STA);

  //Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
  
  billy.rgb_set_color(LED_all, 100, 0, 0);
  delay(100);
  billy.rgb_set_color(LED_all, 0, 100, 0);
  delay(100);
  billy.rgb_set_color(LED_all, 0, 0, 100);
  delay(100);
}

void loop() 
{
  if(rainbow_state == 1){
    while(true){
      billy.rgb_set_color(LED_all, 100, 0, 0);
      if(rainbow_state == 0) break;
      delay(50);
      if(rainbow_state == 0) break;
      billy.rgb_set_color(LED_all, 0, 100, 0);
      if(rainbow_state == 0) break;
      delay(50);
      if(rainbow_state == 0) break;
      billy.rgb_set_color(LED_all, 0, 0, 100);
      if(rainbow_state == 0) break;
      delay(50);
      if(rainbow_state == 0) break;
    }
  }
  else{
    billy.rgb_set_color(LED_all, rouge, vert, bleu);
  }
}