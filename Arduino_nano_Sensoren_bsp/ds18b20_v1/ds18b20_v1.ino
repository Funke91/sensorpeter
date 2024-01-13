#include <OneWire.h>            // OneWire-Bibliothek einbinden
#include <DallasTemperature.h>  // DS18B20-Bibliothek einbinden

#define DS18B20_PIN 2   // Pin für DS18B20 definieren Arduino D2

OneWire oneWire(DS18B20_PIN);          // OneWire Referenz setzen
DallasTemperature sensors(&oneWire);   // DS18B20 initialisieren

void setup() {

	// Serielle Ausgabe starten 
	Serial.begin(9600);
	Serial.println("Temperaturmessung mit dem DS18B20 - blog.simtronyx.de");
  
	sensors.begin();  // DS18B20 starten
	Serial.print("Sensoren: "); 
	
	Serial.println(sensors.getDeviceCount());
}


void loop(){

	sensors.requestTemperatures(); // Temperatursensor(en) auslesen
	for(byte i=0;i<sensors.getDeviceCount();i++){	// Temperatur ausgeben
		show_temperature(i+1,sensors.getTempCByIndex(i));  
	}
	
	delay(5000);	// 5s Pause bis zur nächsten Messung
}

// Temperatur ausgeben
void show_temperature(byte num,float temp){
  
  Serial.print("Sensor ");
  Serial.print(num);
  Serial.print(": ");
  Serial.print(temp);
  Serial.print(" ");  // Hier müssen wir ein wenig tricksen
  Serial.write(176);  // um das °-Zeichen korrekt darzustellen
  Serial.println("C");
}