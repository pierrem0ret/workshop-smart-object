void neuterHappy() { 
    /////////////////////// OEIL 1 /////////////////////////////
  ring1.setPixelColor(0, ring1.Color(155,155,155));
  ring1.setPixelColor(1, ring1.Color(155,155,155));
  ring1.setPixelColor(4, ring1.Color(155,155,155));
  ring1.show();

  
  /////////////////////// OEIL 2 /////////////////////////////
  ring2.setPixelColor(0, ring2.Color(155,155,155));
  ring2.setPixelColor(1, ring2.Color(155,155,155));
  ring2.setPixelColor(4, ring2.Color(155,155,155));
  ring2.show();


  /////////////////////// BOUCHE /////////////////////////////
  mouth.setPixelColor(1, ring2.Color(155,155,155));
  mouth.setPixelColor(2, ring2.Color(155,155,155));
  mouth.setPixelColor(3, ring2.Color(155,155,155));
  mouth.setPixelColor(4, ring2.Color(155,155,155));
  mouth.setPixelColor(10, ring2.Color(155,155,155));
  mouth.setPixelColor(11, ring2.Color(155,155,155));
  mouth.setPixelColor(0, ring2.Color(155,155,155));
  mouth.show();

}

void verryHappy(){
      /////////////////////// OEIL 1 /////////////////////////////
  ring1.setPixelColor(1, ring2.Color(155,155,155));
  ring1.setPixelColor(2, ring2.Color(155,155,155));
  ring1.setPixelColor(3, ring2.Color(155,155,155));
  ring1.setPixelColor(4, ring2.Color(155,155,155));
  ring1.show();

  
  /////////////////////// OEIL 2 /////////////////////////////
  ring2.setPixelColor(1, ring2.Color(155,155,155));
  ring2.setPixelColor(2, ring2.Color(155,155,155));
  ring2.setPixelColor(3, ring2.Color(155,155,155));
  ring2.setPixelColor(4, ring2.Color(155,155,155));
  ring2.show();


  /////////////////////// BOUCHE /////////////////////////////
  mouth.setPixelColor(1, ring2.Color(155,155,155));
  mouth.setPixelColor(2, ring2.Color(155,155,155));
  mouth.setPixelColor(3, ring2.Color(155,155,155));
  mouth.setPixelColor(4, ring2.Color(155,155,155));
  mouth.setPixelColor(10, ring2.Color(155,155,155));
  mouth.setPixelColor(11, ring2.Color(155,155,155));
  mouth.setPixelColor(0, ring2.Color(155,155,155));
  mouth.show();

}

void sleepyHappy(){
    /////////////////////// OEIL 1 /////////////////////////////
  ring1.setPixelColor(1, ring2.Color(155,155,155));
  ring1.setPixelColor(4, ring2.Color(155,155,155));
  ring1.setPixelColor(5, ring2.Color(155,155,155));
  ring1.setPixelColor(6, ring2.Color(155,155,155));
  ring1.show();

  
  /////////////////////// OEIL 2 /////////////////////////////
  ring2.setPixelColor(1, ring2.Color(155,155,155));
  ring2.setPixelColor(4, ring2.Color(155,155,155));
  ring2.setPixelColor(5, ring2.Color(155,155,155));
  ring2.setPixelColor(6, ring2.Color(155,155,155));
  ring2.show();


  /////////////////////// BOUCHE /////////////////////////////
  mouth.setPixelColor(1, ring2.Color(155,155,155));
  mouth.setPixelColor(2, ring2.Color(155,155,155));
  mouth.setPixelColor(3, ring2.Color(155,155,155));
  mouth.setPixelColor(4, ring2.Color(155,155,155));
  mouth.setPixelColor(10, ring2.Color(155,155,155));
  mouth.setPixelColor(11, ring2.Color(155,155,155));
  mouth.setPixelColor(0, ring2.Color(155,155,155));
  mouth.show();

}

void justHappySeyes(){
  /////////////////////// OEIL 1 /////////////////////////////
  ring1.setPixelColor(0, ring2.Color(155,155,155));

  ring1.show();

  
  /////////////////////// OEIL 2 /////////////////////////////
  ring2.setPixelColor(0, ring2.Color(155,155,155));

  ring2.show();


  /////////////////////// BOUCHE /////////////////////////////
  mouth.setPixelColor(1, ring2.Color(155,155,155));
  mouth.setPixelColor(2, ring2.Color(155,155,155));
  mouth.setPixelColor(3, ring2.Color(155,155,155));
  mouth.setPixelColor(4, ring2.Color(155,155,155));
  mouth.setPixelColor(10, ring2.Color(155,155,155));
  mouth.setPixelColor(11, ring2.Color(155,155,155));
  mouth.setPixelColor(0, ring2.Color(155,155,155));
  mouth.show();

}

void justHappyBeyes(){
    /////////////////////// OEIL 1 /////////////////////////////
  for (int i=1; i<NUMPIXELS; i++){
  ring1.setPixelColor(i, ring1.Color(155,155,155));

  ring1.show();
  }
  
  /////////////////////// OEIL 2 /////////////////////////////
  for (int i=1; i<NUMPIXELS; i++){
  ring2.setPixelColor(i, ring2.Color(155,155,155));

  ring2.show();
  }


  /////////////////////// BOUCHE /////////////////////////////
  mouth.setPixelColor(1, ring2.Color(155,155,155));
  mouth.setPixelColor(2, ring2.Color(155,155,155));
  mouth.setPixelColor(3, ring2.Color(155,155,155));
  mouth.setPixelColor(4, ring2.Color(155,155,155));
  mouth.setPixelColor(10, ring2.Color(155,155,155));
  mouth.setPixelColor(11, ring2.Color(155,155,155));
  mouth.setPixelColor(0, ring2.Color(155,155,155));
  mouth.show();

}

void shook(){
    /////////////////////// OEIL 1 /////////////////////////////
  for (int i=1; i<NUMPIXELS; i++){
  ring1.setPixelColor(i, ring1.Color(155,155,155));

  ring1.show();
  }
  
  /////////////////////// OEIL 2 /////////////////////////////
  for (int i=1; i<NUMPIXELS; i++){
  ring2.setPixelColor(i, ring2.Color(155,155,155));

  ring2.show();
  }


  /////////////////////// BOUCHE /////////////////////////////
      for(int i=0;i<NUMPIXELS_BIG;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    mouth.setPixelColor(i, mouth.Color(155,155,155)); // Moderately bright green color.

    mouth.show(); // This sends the updated pixel color to the hardware.

  }
}

void happyBlinker(){
  /////////////////////// OEIL 1 /////////////////////////////
  ring1.setPixelColor(1, ring2.Color(155,155,155));
  ring1.setPixelColor(4, ring2.Color(155,155,155));
  ring1.setPixelColor(5, ring2.Color(155,155,155));
  ring1.setPixelColor(6, ring2.Color(155,155,155));
  ring1.show();

  
  /////////////////////// OEIL 2 /////////////////////////////
  ring2.setPixelColor(1, ring2.Color(155,155,155));
  ring2.setPixelColor(2, ring2.Color(155,155,155));
  ring2.setPixelColor(3, ring2.Color(155,155,155));
  ring2.setPixelColor(4, ring2.Color(155,155,155));
  ring2.show();


  /////////////////////// BOUCHE /////////////////////////////
  mouth.setPixelColor(1, ring2.Color(155,155,155));
  mouth.setPixelColor(2, ring2.Color(155,155,155));
  mouth.setPixelColor(3, ring2.Color(155,155,155));
  mouth.setPixelColor(4, ring2.Color(155,155,155));
  mouth.setPixelColor(10, ring2.Color(155,155,155));
  mouth.setPixelColor(11, ring2.Color(155,155,155));
  mouth.setPixelColor(0, ring2.Color(155,155,155));
  mouth.show();

}
