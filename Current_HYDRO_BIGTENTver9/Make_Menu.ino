


/*
  How to make a new menu item, first go to Display() page then make a menuitem with the next coresponding number in the list and call it page 1. if the menu needs to have a sub menu make
  this under page 2. if the new menu item needs to be saved to EEPROM make a new position in memory in the setup with spaces of 8 bytes EG EEPROM.get(0,newitem) EEPROM.get(8,newitem) so
  on, this will allow the program to retrive the data from memory incase of power loss.
  Second go to encoderRotation() and add the next menuitem using the next coresponding number do this twice for up and down and then add number to lastmenuitem, it will become clear 
  when you see it. Also it will need to have an EEPROM.put to save the integer to memory.
  if the new menuitem has a sub catagory, page2 then it will also need to be added to the enter pressed, to enter and exit that part of the menu making them global.

*/
