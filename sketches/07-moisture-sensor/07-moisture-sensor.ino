// Dit is de VOCHT SENSOR applicatie
// We lezen hierbij de grond vocht sensor uit.

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

  // Configureer A1 als analoge ingang
  pinMode(A1, INPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop()
{
  // Eerst moeten we de analoge spanning meten (getal tussen 0 en 1023)
  int vochtgehalte = analogRead(A1);

  SerialUSB.print("Grondvocht: ");
  SerialUSB.println(vochtgehalte);

  delay(1000);
}
