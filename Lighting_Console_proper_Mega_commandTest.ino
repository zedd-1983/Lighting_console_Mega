#define         SUB1                A0
#define         SUB2                A1
#define         SUB3                A2
#define         SUB4                A3
#define         NUMBER_OF_SUBS      4
#define         LED                 10
#define         LED2                9
#define         LED3                8

#define         RECORD              'r'
#define         SUB                 's'
#define         CUE                 'c'

void setup() {

  pinMode(SUB1, INPUT);
  pinMode(SUB2, INPUT);
  pinMode(SUB3, INPUT);
  pinMode(SUB4, INPUT);

  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.begin(115200);
  Serial.setTimeout(50);
}

void loop() {

  int subs[NUMBER_OF_SUBS] = {SUB1, SUB2, SUB3, SUB4};                                                    // array to iterate through when reading the faders

  String commandArray = "";
                                                                               // initialize empty string array

  if(Serial.available())
  {
      commandArray = Serial.readString();                                                                 // read incoming characters and save them into commandArray

      if(commandArray[0] == RECORD)                                                                       // RECORD COMMANDS
      {
        if(commandArray[1] == SUB)                                                                        // SAVING SUBS
        {
          if(commandArray[3] == '1' && commandArray[4] == 'X') {}
            // save Sub 1
          else if(commandArray[3] == '2' && commandArray[4] == 'X') {}
            // save Sub 2
          else if(commandArray[3] == '3' && commandArray[4] == 'X') {}
            // save Sub 3
          else if(commandArray[3] == '4' && commandArray[4] == 'X') {}
            // save Sub 4
          else if(commandArray[3] == '5' && commandArray[4] == 'X') {}
            // save Sub 5
          else if(commandArray[3] == '6' && commandArray[4] == 'X') {}
            // save Sub 6
          else if(commandArray[3] == '7' && commandArray[4] == 'X') {}
            // save Sub 7
          else if(commandArray[3] == '8' && commandArray[4] == 'X') {}
            // save Sub 8
          else if(commandArray[3] == '9' && commandArray[4] == 'X') {}
            // save Sub 9
          else if(commandArray[3] == '1' && commandArray[4] == '0' && commandArray[5] == 'X')  {}
            // save Sub 10
        }
        else if(commandArray[1] == CUE)                                                                   // SAVING CUES
          {
            // save cues based on the number provided
            // in commandArray[2 and 3] --> up to 99 cues
            // if memory permits
          }
      }
  }

  for(int i = 0; i < NUMBER_OF_SUBS; i++)                                                                 // read values of faders and send it to Qt
  {
    int subValue = analogRead(subs[i]);
    Serial.print(subValue/4);
    Serial.print(",");
    Serial.flush();
    delay(10);
  }

}
