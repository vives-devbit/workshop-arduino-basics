// Dit is de hello world applicatie
// Hier gaan we om de seconde "Hello World!" naar de computer sturen.


// Initializatie code
// Wordt 1x uitgevoerd bij het opstarten
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  SerialUSB.begin(9600);

}

// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
void loop() {

  // Tekst versturen naar de computer
  SerialUSB.println("Hello World!");

  // Even wachten (1000ms = 1s)
  delay(1000);

}
