#include <IRremote.h>
//Önce alıcı pini tanımlıyoruz
//Deine the Ir pin
const int IR_RECEIVE_PIN = 2;


//Alıcımızı başlatıyoruz
//init the receiver
IRrecv IRrecv(IR_RECEIVE_PIN);

//Ir alıcımız için kurulum kodlarını yazıyoruz
//We setup our ır receiver
void setup() {
  Serial.begin(9600);
  //IR alıcımızı başlatıyoruz
  //Begin our receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

}
//IR alıcımızın eylem planını yazıyoruz
//we write implementing codes
void loop() {
  //kodumuzu decode ediyoruz
  if (IrReceiver.decode ()){
     //Elde ettiğimiz değerleri ekrana yazdırmak için Serial.println kodunu kullanıp hex formunda almak için HEX ekini ekliyoruz
     // We use Serial.println code for write screen. We use HEX form beacuse for easy implement
      Serial.println(IrReceiver.decodedIRData.decodedRawData ,HEX);
      //Bir sonraki değeri alması için kodu loopa sokar 
      //Puts the code in the loop to get the next value
      IRrecv.resume();
  }
}
