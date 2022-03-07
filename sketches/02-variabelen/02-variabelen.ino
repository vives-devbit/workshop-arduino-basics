// Dit is de variabel applicatie
// Hier tonen we hoe we variabelen declareren
// en hoe we deze dan kunnen uitprinten.
// Tevens tonen we hoe we de waarde aanpassen.

/////////////////////////////////////////////////////////
// Hier komen onze "globale" variabelen.
// Deze kunnen we overal in onze applicatie gebruiken.
/////////////////////////////////////////////////////////

// int = een getal
int leeftijd = 34;

// String = tekst
String naam = "Nico";

// double = komma-getal
double pi = 3.14;

// Een variable als teller
int teller = 0;

/////////////////////////////////////////////////////////
// Initializatie code
// Wordt 1x uitgevoerd bij het opstarten
/////////////////////////////////////////////////////////
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  Serial.begin(9600);

  // pi aanpassen naar nauwkeurigere waarde
  pi = 3.1415;

}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop() {

  leeftijd = 35;

  // Een String variabel uitprinten
  // met tekst vooraan
  Serial.print("Hallo, ik ben ");
  Serial.println(naam);

  // Een int variabel uitprinten en daarna
  // nog wat tekst erachter
  Serial.print("Ik ben ");
  Serial.print(leeftijd);
  Serial.println(" jaar oud.");

  // Een double variabel uitprinten met
  // een extra lege lijn ervoor en erachter
  Serial.println();
  Serial.print("PI = ");
  Serial.println(pi);
  Serial.println();

  // Een teller als variabel
  Serial.print("De variabel teller heeft de waarde ");
  Serial.println(teller);

  // Even wachten (1000ms = 1s)
  delay(1000);

}
