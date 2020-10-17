//Controll FVD "WINCOR NIXDORF BA66 RS232"

void DeleteDisplayVFD(){
  Serial.write(0x1B);
  Serial.write(0x5B);
  Serial.write(0x32);
  Serial.write(0x4A);
}

void DeleteEndLineVFD(){
  Serial.write(0x1B);
  Serial.write(0x5B);
  Serial.write(0x30);
  Serial.write(0x4B);
}

void PositionCursorVFD(int y, int x){
  Serial.write(0x1B);
  Serial.write(0x5B);
  Serial.print(y);
  Serial.write(0x3B);  
  Serial.print(x);
  Serial.write(0x48);
}

void BigClock(int cyfra, int x){ //displayed digit
 if (cyfra==0){
   PositionCursorVFD(1, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xBA);
   Serial.write(0xFF);
   Serial.write(0xBA);
   PositionCursorVFD(3, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xBC);
  }
 if (cyfra==1){
   PositionCursorVFD(1, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xBA);
   PositionCursorVFD(3, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xCA);
 }
 if (cyfra==2){
   PositionCursorVFD(1, x);
   Serial.write(0xCD);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xBC);
   PositionCursorVFD(3, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xCD);
 }
  if (cyfra==3){
   PositionCursorVFD(1, x);
   Serial.write(0xCD);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xFF);
   Serial.write(0xCD);
   Serial.write(0xB9);
   PositionCursorVFD(3, x);
   Serial.write(0xCD);
   Serial.write(0xCD);
   Serial.write(0xBC);
 }
 if (cyfra==4){
   PositionCursorVFD(1, x);
   Serial.write(0xCB);
   Serial.write(0xFF);
   Serial.write(0xCB);
   PositionCursorVFD(2, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xB9);
   PositionCursorVFD(3, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xCA);
 }
 if (cyfra==5){
   PositionCursorVFD(1, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xCD);
   PositionCursorVFD(2, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(3, x);
   Serial.write(0xCD);
   Serial.write(0xCD);
   Serial.write(0xBC);
 }
 if (cyfra==6){
   PositionCursorVFD(1, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xCD);
   PositionCursorVFD(2, x);
   Serial.write(0xCC);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(3, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xBC);
 }
 if (cyfra==7){
   PositionCursorVFD(1, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xBA);
   PositionCursorVFD(3, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xCA);
 }
 if (cyfra==8){
   PositionCursorVFD(1, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xCC);
   Serial.write(0xCD);
   Serial.write(0xB9);
   PositionCursorVFD(3, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xBC);
  }
 if (cyfra==9){
   PositionCursorVFD(1, x);
   Serial.write(0xC9);
   Serial.write(0xCD);
   Serial.write(0xBB);
   PositionCursorVFD(2, x);
   Serial.write(0xC8);
   Serial.write(0xCD);
   Serial.write(0xB9);
   PositionCursorVFD(3, x);
   Serial.write(0xCD);
   Serial.write(0xCD);
   Serial.write(0xBC);
  }
  if (cyfra == -1){ //null to blink
   PositionCursorVFD(1, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xFF);
   PositionCursorVFD(2, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xFF);
   PositionCursorVFD(3, x);
   Serial.write(0xFF);
   Serial.write(0xFF);
   Serial.write(0xFF);
 }
}
