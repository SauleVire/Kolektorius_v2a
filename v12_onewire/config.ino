
boolean LoadConfig(){
  if ((EEPROM.read(0) == 27) && (EEPROM.read(1) == 28) && 
     (EEPROM.read(2) == 13) && (EEPROM.read(3) == 18)) {

    if (EEPROM.read(4) == EEPROM.read(5)) k_ijungimo_skirtumas = EEPROM.read(4);  
    if (EEPROM.read(6) == EEPROM.read(7)) k_isjungimo_skirtumas = EEPROM.read(6);
    if (EEPROM.read(8) == EEPROM.read(9)) temperatura_1 = EEPROM.read(8);  
    if (EEPROM.read(10) == EEPROM.read(11)) temperatura_2 = EEPROM.read(10);
    if (EEPROM.read(12) == EEPROM.read(13)) T_busena = EEPROM.read(12);
    return true;
  }
  return false;
}

void SaveConfig(){
  EEPROM.write(0,27);
  EEPROM.write(1,28);
  EEPROM.write(2,13);
  EEPROM.write(3,18);
  EEPROM.write(4,k_ijungimo_skirtumas);EEPROM.write(5,k_ijungimo_skirtumas);  // almacenamos los valores 2 veces
  EEPROM.write(6,k_isjungimo_skirtumas); EEPROM.write(7,k_isjungimo_skirtumas);  // almacenamos los valores 2 veces
  EEPROM.write(8,temperatura_1);EEPROM.write(9,temperatura_1);  // almacenamos los valores 2 veces
  EEPROM.write(10,temperatura_2); EEPROM.write(11,temperatura_2);  // almacenamos los valores 2 veces
  EEPROM.write(12,T_busena); EEPROM.write(13,T_busena);  // almacenamos los valores 2 veces

}


