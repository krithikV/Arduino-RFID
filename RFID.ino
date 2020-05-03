#include<MFRC522.h>
#include<SPI.h>
MFRC522 mfrc522(10,9);
void setup()
{
  pinMode(7, OUTPUT);
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan Tag");
  digitalWrite(A0, HIGH);
}

void loop()
{
  if(!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  String uid="";
  Serial.println();
  Serial.print("UID=");
  for(int i=0;i<mfrc522.uid.size;i++)
  {
    Serial.print(mfrc522.uid.uidByte[i]<0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i],HEX);
    uid.concat(String(mfrc522.uid.uidByte[i]<0x10 ? "0" : ""));
    uid.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
  uid.toUpperCase();
  if(uid=="A9CA9343")
  {
    digitalWrite(A0, LOW);
    Serial.print(" :Krithik");
    Serial.print(" Access Granted");
    digitalWrite(7, HIGH);
    delay(5000);
    digitalWrite(7, LOW);
    digitalWrite(A0, HIGH);
 
  }
 
  else
  {
    Serial.print("ACCESS DENIED");
  }
  delay(5000);
  return;
}
