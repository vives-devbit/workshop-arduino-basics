// Dit is de BUTTON applicatie
// We lezen hierbij de toestand uit van de drukknop.

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

  // Configureer D2 als een digitale uitgang
  pinMode(2, OUTPUT);
  
  // Configureer D3 als een digitale ingang
  pinMode(3, INPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop() {

  int knop = digitalRead(3);
  SerialUSB.print("De toestand van de knop is: ");
  SerialUSB.println(knop);

  // Zet de uitgang gelijk aan de stand van de knop
  digitalWrite(2, knop);

  delay(1000);    // Even wachten (1000ms = 1s)

}
