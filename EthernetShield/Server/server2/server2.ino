#include <SPI.h>
#include <Ethernet.h>
//Mac e ip da maquina. 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 
byte ip[] = {192,168,0,160}; // defina aqui seu ip de acordo com a faixa definida no seu roteador. 
//Porta de acesso 
EthernetServer server(80); 
String readString; 
void setup(){ 
  Ethernet.begin(mac, ip); 
  server.begin(); 
  Serial.begin(9600); } 
  
  void loop(){ 
    EthernetClient client = server.available(); 
    if (client) { 
      while (client.connected()) { 
        if (client.available()) { 
           Serial.write("deu baooo");
         } 
      }
    }
    else {
      Serial.write("cliente Off\n");
      delay(50000);
    }
    
 } 
