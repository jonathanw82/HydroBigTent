

void StartUp(){

  lcd.setCursor(1, 0);
  lcd.print(F(" Initialising"));
  delay(200);
  lcd.setCursor(0, 2);
  lcd.print (F("#"));
  delay(200);
  lcd.setCursor(2, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(4, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(6, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(8, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(10, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(12, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(14, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.setCursor(16, 2);
  lcd.print (F("#"));
  delay(200);
  lcd.setCursor(18, 2);
  lcd.print(F("#"));
  delay(200);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(F(" Software Ver"));
  lcd.setCursor(0, 1);
  lcd.print(F("  BigTent Ver8 "));
  delay(800);
}
