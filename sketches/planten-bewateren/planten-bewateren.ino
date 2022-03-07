// Dit is de oplossing voor de button-alarm applicatie.

/////////////////////////////////////////////////////////
// Hier komen onze "globale" variabelen.
// Deze kunnen we overal in onze applicatie gebruiken.
/////////////////////////////////////////////////////////

int knopGedrukt = 0;

// Dit zijn parameters nodig bij de berekening van
// de temperatuur. Die vinden we in de datasheet of online.
int B = 4275;       // B waarde van de thermistor
int R0 = 100000;    // R0 = 100k weerstand

/////////////////////////////////////////////////////////
// Initialisatie code
// Wordt 1x uitgevoerd bij het opstarten
/////////////////////////////////////////////////////////
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  Serial.begin(9600);

  // // Configureer D3 als een digitale ingang (de knop)
  // pinMode(3, INPUT);

  // // Configureer D4 als een digitale uitgang (de buzzer)
  // pinMode(4, OUTPUT);

  // Een digitale uitgang voor de LED
  pinMode(2, OUTPUT);

  // Een digitale input voor de knop
  pinMode(3, INPUT);

  // Een digitale uitgang voor het alarm
  pinMode(4, OUTPUT);

  // Een analoge ingang voor de temperatuur sensor
  pinMode(A0, INPUT);

  // Een analoge ingang voor de vochtsensor
  pinMode(A1, INPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop() {

  int vochtgehalte = analogRead(A1);
  int knop = digitalRead(3);

  Serial.print("Vochtgehalte: ");
  Serial.println(vochtgehalte);

  // Bepalen van de temperatuur
  int voltage = analogRead(A0);
  double R = ((1023.0 / voltage) - 1.0 ) * R0;
  double temperatuur = (1.0 / ((log(R/R0)/B) + (1/298.15))) - 273.15;

  Serial.print("Temperatuur: ");
  Serial.print(temperatuur);
  Serial.println("°C");

  if (vochtgehalte < 10) {
    // Droog, dan geven we alarm
    Serial.println("Te droog. Alarm AAN !");

    if (knop == HIGH) {
      knopGedrukt = 1;
    }
    
    // Enkel alarm aan als er niet op de knop werd gedrukt
    if (knopGedrukt == 0) {
      // Dit geeft een "tut"
      digitalWrite(4, HIGH);
      delay(10);
      digitalWrite(4, LOW);
    } else {
      digitalWrite(4, LOW);
    }
    
    // LED uit
    digitalWrite(2, LOW);

  } else if (vochtgehalte > 30) {
    // Te nat, alarm uit en LED aan
    Serial.println("Te nat. Rode LED aan.");

    // Led aan en alarm uit
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    knopGedrukt = 0;
    
  } else {
    Serial.println("Alles OK. Alarm uit, rode LED uit.");

    // Alles uit en knop gedrukt ook op 0
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    knopGedrukt = 0;
  }

  // Voor de grafiek
  Serial.print(temperatuur);
  Serial.print(",");
  Serial.println(vochtgehalte);

  delay(1000);    // Even wachten (1000ms = 1s)

}
