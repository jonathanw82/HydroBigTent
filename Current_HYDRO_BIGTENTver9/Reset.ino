
void Reset() {

  if (ButReset == true) {
    ButReset = false;
   delay(2000);
  }
}

void DailyReset() {                                                                             // The system may be unmaned for days on end so it rests every 24 hours while dormant to ensure smoth constant running 

  dailyreset = dailyresethour + (dailyresetmin + dailyresetSecond);

  if (dailyreset >= 120 && dailyreset < 124)
  {
    delay(2000);
  }
}
