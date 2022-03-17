#include <main.h>
#include <led.h>

bool led_state = false;
unsigned long previous_millis = 0;
unsigned long current_millis;

Led::Led()
{
    FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds,NUM_LEDS);
    pinMode(LED_BUILTIN, OUTPUT);
}

Led::Led(int pin_led)
{
    pinMode(pin_led,OUTPUT);
}

void Led::led_off(int pin_led)
{
    digitalWrite(pin_led, LOW);
}

void Led::led_on(int pin_led)
{
    digitalWrite(pin_led, HIGH);
}

void Led::led_rainbow(int hue)
{
    fill_rainbow(leds, NUM_LEDS, 0, hue);
    FastLED.show();
}

void Led::rgb_blink(unsigned long blink_time)
{
    current_millis = millis();
    
    if((current_millis - previous_millis) >= blink_time)
    {
        //Serial.print("Toogle led");
        previous_millis = millis();

        for (int i = 0; i < 4; i++)
        {
            if(led_state == true) leds[i] = 0x000000;
            else leds[i] = 0x00FF0000;
        }

        FastLED.show();
        
        if(led_state == true) led_state = false;
        else led_state = true;
    }
    
}

void Led::rgb_set_color(char led, char R, char G, char B)
{
    uint32_t rgb = 0;
    uint32_t temp = 0;
    //Conversion % (int) -> 255 (char)
    R = convert_pourcent_to_charvalue(R);
    /*
    Serial.print("char R :");
    Serial.println(R, BIN);
    */
    rgb = R << 16;
    /*
    Serial.print("uint32 rgb :");
    Serial.println(rgb, BIN);
    Serial.println();
    */
    G = convert_pourcent_to_charvalue(G);
    /*
    Serial.print("char G : ");
    Serial.println(G,BIN);
    */
    temp = G << 8;
    /*
    Serial.print("char temp : ");
    Serial.println(temp, BIN);
    */
    rgb = rgb | temp;
    /*
    Serial.print("char rgb : ");
    Serial.println(rgb, BIN);
    Serial.println();
    */
    B = convert_pourcent_to_charvalue(B);
    /*
    Serial.print("char B :");
    Serial.println(B, BIN);
    */
    temp = B;
    rgb = rgb | temp;
    /*
    Serial.print("uint 32 rgb : ");
    Serial.println(rgb,BIN);
    */
    if(led == LED_all)
    {
        for (int i = 0; i < 4; i++)
        {
            leds[i] = rgb;
        }
        
    }
    else leds[led] = rgb;

    FastLED.show();
}

char convert_pourcent_to_charvalue(char value)
{
    return value = 255*value/100;
}