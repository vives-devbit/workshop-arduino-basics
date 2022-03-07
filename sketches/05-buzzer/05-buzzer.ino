// Dit is de BUZZER applicatie
// We sturen hierbij de buzzer aan.

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
  Serial.begin(9600);

  // Configureer D4 als een digitale uitgang
  pinMode(4, OUTPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop() {

  Serial.println("We zetten de BUZZER aan");
  digitalWrite(4, HIGH);    // Uitgang aanzetten (HOOG = 5V)
  delay(1000);    // Even wachten (1000ms = 1s)

  Serial.println("We zetten de BUZZER uit");
  digitalWrite(4, LOW);    // Uitgang uitzetten (LAAG = 0V)
  delay(1000);    // Even wachten (1000ms = 1s)

}
