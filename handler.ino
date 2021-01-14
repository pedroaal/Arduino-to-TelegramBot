// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));
 
  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
     
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);
 
    String from_name = bot.messages[i].from_name;
 
    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Arduino Uno Pedro.\n";
      welcome += "Use the following commands to control your outputs. \n\n";
      welcome += "/state to request current IOT devices conected to bot \n";
      welcome += "/temp to request current temperature from all IOT devices \n";
      welcome += "/temp_{id} to request current temperature from a single id IOT device \n";
      bot.sendMessage(chat_id, welcome, "");
    }
     
    if (text == "/state") {
      bot.sendMessage(chat_id, "Pedro Connected to Pool", "");
    }
    
    if (text == "/temp") {
      bot.sendMessage(chat_id, getTemp(), "");
    }
  }
}
