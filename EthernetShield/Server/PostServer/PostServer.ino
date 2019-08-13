//Programa : Arduino Ethernet Shield W5100 e HC-SR04
//Alteracoes e adaptacoes : FILIPEFLOP
//
//Baseado no programa exemplo de
//by David A. Mellis e Tom Igoe
#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>



//Definicoes de IP, mascara de rede e gateway
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 100, 88);       //Define o endereco IP
IPAddress gateway(192, 168, 100, 255);  //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

//Inicializa o servidor web na porta 80
//EthernetServer server(80);

void setup()
{
  //Inicializa a interface de rede
  Ethernet.begin(mac, ip, gateway, subnet);

  // Initialize Serial port
  Serial.begin(9600);
  while (!Serial) continue;

   String data="temp1=2";

  Serial.println(Ethernet.localIP());
  if(client.connect("192.168.0.1", 80)) {
    client.println("POST /home/visualisation.php HTTP/1.1");
    client.println("Host:  192.168.0.1");
    //client.println("User-Agent: Arduino/1.0");
    //client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded;");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.print(data);
    //Serial.println(data);
    Serial.println("We have connection");
  }

  if(client.connected()) {    
    Serial.println("We have abc");
    client.stop();
  }

  

  // Disconnect
  client.stop();

}

void loop() {

}
