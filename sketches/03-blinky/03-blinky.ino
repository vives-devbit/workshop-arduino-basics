// Dit is de Blinky applicatie
// Dit is als het ware de "Hello World"
// van microcontroller applicaties.
// We laten hierbij een lichtje (LED) aan en uit
// gaan met een vertraging tussen beide standen.

/////////////////////////////////////////////////////////
// Hier komen onze "globale" variabelen.
// Deze kunnen we overal in onze applicatie gebruiken.
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// Initializatie code
// Wordt 1x uitgevoerd bij het opstarten
/////////////////////////////////////////////////////////
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  SerialUSB.begin(9600);

  // Configureer D2 als uit een digitale uitgang
  pinMode(2, OUTPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop() {

  SerialUSB.println("We zetten de LED aan");
  digitalWrite(2, HIGH);    // Uitgang aanzetten (HOOG = 5V)
  delay(1000);    // Even wachten (1000ms = 1s)

  SerialUSB.println("We zetten de LED uit");
  digitalWrite(2, LOW);    // Uitgang uitzetten (LAAG = 0V)
  delay(2000);    // Even wachten (1000ms = 1s)

}
