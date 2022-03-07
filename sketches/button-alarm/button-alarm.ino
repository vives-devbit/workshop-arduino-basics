// Dit is de oplossing voor de button-alarm applicatie.

/////////////////////////////////////////////////////////
// Hier komen onze "globale" variabelen.
// Deze kunnen we overal in onze applicatie gebruiken.
/////////////////////////////////////////////////////////

int secondenIngedrukt = 0;

/////////////////////////////////////////////////////////
// Initializatie code
// Wordt 1x uitgevoerd bij het opstarten
/////////////////////////////////////////////////////////
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  Serial.begin(9600);

  // Configureer D3 als een digitale ingang (de knop)
  pinMode(3, INPUT);

  // Configureer D4 als een digitale uitgang (de buzzer)
  pinMode(4, OUTPUT);
}

/////////////////////////////////////////////////////////
// Het hoofdprogramma
// Dit wordt telkens opnieuw uitgevoerd
/////////////////////////////////////////////////////////
void loop() {

  int knop = digitalRead(3);

  if (knop == HIGH) {
    secondenIngedrukt = secondenIngedrukt + 1;    // 1 seconde bijtellen

    Serial.print("Je hebt de knop nu ");
    Serial.print(secondenIngedrukt);
    Serial.println(" seconden ingedrukt!");
  } else {
    // Loslaten is actie ondernemen

    if (secondenIngedrukt >= 3) {
      Serial.println("We zetten het alarm aan");
      digitalWrite(4, HIGH);    // Uitgang (buzzer) aanzetten
    }

    if (secondenIngedrukt == 1) {
      Serial.println("We zetten het alarm uit");
      digitalWrite(4, LOW);    // Uitgang (buzzer) aanzetten
    }

    secondenIngedrukt = 0;    // Teller terug op 0 zetten
  }

  delay(1000);    // Even wachten (1000ms = 1s)

}
