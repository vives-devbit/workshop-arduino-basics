// Dit is de TEMPERATUUR applicatie
// We lezen hierbij de temperatuur sensor uit en zetten
// de analoge waarde om naar een echte temperatuur

// De bibliotheek hebben we nodig voor logaritmen te berekenen
#include <math.h>

/////////////////////////////////////////////////////////
// Hier komen onze "globale" variabelen.
// Deze kunnen we overal in onze applicatie gebruiken.
/////////////////////////////////////////////////////////

// Dit zijn parameters nodig bij de berekening van
// de temperatuur. Die vinden we in de datasheet of online.
int B = 4275;       // B waarde van de thermistor
int R0 = 100000;    // R0 = 100k weerstand

/////////////////////////////////////////////////////////
// Initializatie code
// Wordt 1x uitgevoerd bij het opstarten
/////////////////////////////////////////////////////////
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  SerialUSB.begin(9600);

  // Configureer A0 als analoge ingang
  pinMode(A0, INPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop()
{
  // Eerst moeten we de analoge spanning meten (getal tussen 0 en 1023)
  int voltage = analogRead(A0);

  // Dan berekenen we de waarde van de thermistor
  double R = ((1023.0 / voltage) - 1.0 ) * R0;

  // Dan zetten we dit om naar een temperatuur
  double temperatuur = (1.0 / ((log(R/R0)/B) + (1/298.15))) - 273.15;

  SerialUSB.print("Temperatuur: ");
  SerialUSB.print(temperatuur);
  SerialUSB.println("°C");

  delay(1000);
}
