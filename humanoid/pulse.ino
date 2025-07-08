void pulse_chest(byte red, byte green, byte blue) {

  for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST1; i++) {
        strip_chest.setPixelColor(CHEST_PATTERN1[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
    }
    strip_chest.show();
    }

    for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
     
        strip_chest.setPixelColor(CHEST_PATTERN2[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
      
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
   
        strip_chest.setPixelColor(CHEST_PATTERN3[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }

for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
   
        strip_chest.setPixelColor(CHEST_PATTERN4[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
    
        strip_chest.setPixelColor(CHEST_PATTERN5[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
    
        strip_chest.setPixelColor(CHEST_PATTERN6[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
 
        strip_chest.setPixelColor(CHEST_PATTERN7[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
   
        strip_chest.setPixelColor(CHEST_PATTERN8[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
  
        strip_chest.setPixelColor(CHEST_PATTERN9[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
    
        strip_chest.setPixelColor(CHEST_PATTERN10[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
   
        strip_chest.setPixelColor(CHEST_PATTERN11[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
   
        strip_chest.setPixelColor(CHEST_PATTERN12[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
   
        strip_chest.setPixelColor(CHEST_PATTERN13[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }


for (float bright = 1; bright < 256; bright=bright+5) {
    for (int i = 0; i < CHEST2; i++) {
    
        strip_chest.setPixelColor(CHEST_PATTERN14[i], strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }
}

void dimming_ALL(byte red, byte green , byte blue){

for (float bright = 0; bright < 256; bright=bright+5) {
    for (int i = 0; i < strip_chest.numPixels() ; i++) {
    
        strip_chest.setPixelColor(i, strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }

    for (float bright = 250; bright > -1; bright=bright-10) {
    for (int i = 0; i < strip_chest.numPixels() ; i++) {
    
        strip_chest.setPixelColor(i, strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         
    }
    strip_chest.show();
    }

}