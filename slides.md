---
marp: true
---

# Workshop Arduino Basics <!-- fit -->

---

# Wie zijn wij

TODO:

![bg fit right](./img/devbit_rocket.png)

---

# Doel van vandaag

- Vandaag zijn we hier om iets bij te leren over
  - Arduino
  - Programmeren
  - Hardware (sensoren en actuatoren)

![bg right fit](./img/seeed-arduino-sensor-kit-base.png)

---

# Hoe pakken we dit aan?

- Heel praktisch
- Kleine stukjes theorie
- Veel zelf doen
- Experimenteren

![bg left:45% fit](./img/hands-on.jpg)

---

# Wat is Arduino

TODO: Wat is Arduino ? Wat is Arduino IDE
TODO: Welke Arduino's bestaan er allemaal
TODO: Wat is nu eigenlijk een microcontroller?

---

# Wat is Programmeren

- Programmeren is instructies geven aan een computer
- Die verstaat echter onze taal niet
  - Verstaat enkel een obscure taal van 1'en en 0'en

![bg right fit](./img/computer-instructions.jpg)

---

## Programmeertaal

- Dit is echter veel te complex (low-level) om mee te werken
- Vandaar dat we een "hogere" programmeertaal gebruiken

![bg left:35% fit](./img/programming-language.png)

---

## Compileren

- Wij schrijven dan een programma in die programmeertaal
- Dit wordt dan **vertaald in computer instructies**
  - Dit noemen we compileren

![bg right:40% fit](./img/compiling.png)

---

## Binary

- Het resultaat van het compilatie-proces is een **binary**
  - Die moeten we wegschrijven naar de microcontroller
    - Dit noemen we **flashen**

![bg right:40% fit](./img/Arduino-ATMEGA328-1024x576.jpg)

---

## Programmeren met Arduino

- Arduino's programmeren doen we met C++
  - ✅ Heel populair voor microcontroller
  - ✅ Krachtig en snel
  - ❌ Niet de gemakkelijkste taal om mee te starten

![bg left:40% fit](./img/arduino-programming.png)

---

# Starten met "Hello World"

- In de wereld van programmeren starten we altijd met "Hello World"
  - Simpel programma
  - Toont aan dat alles werkt

![bg right:30% fit](./img/hello_world.png)

---

## Hello World - Openen Sketch

- Sketch = programma bij Arduino
- Ga naar `Bestand => Openen` en selecteer `01-hello-world`


![bg right:40% fit](./img/01-hello-world-open.png)

---

## Hello World - Bord kiezen

TODO: Kiezen van correcte board

![bg right:40% fit](https://via.placeholder.com/150)

---

## Hello World - Compileren en Flashen

- Het programma dient eerst te worden gecompileerd
- Vervolgens flashen we de computer instructies naar de microcontroller
- Druk op de pijl naar rechts ➡️

![bg right:30% fit](./img/01-hello-world-flash.png)

---

## Hello World - Het resultaat

- Het resultaat kunnen we zien in de seriele monitor
- Klik op `Hulpmiddelen => Seriele monitor` of op het vergrootglas 🔎 rechts


![bg right fit](./img/01-hello-world-monitor.png)

---

## Hello World - Analyse

- `setup()`:
  - Wordt 1x uitgevoerd wanneer de microcontroller start
  - Hier gaan we bv. hardware initializeren
    - Zoals de "baudrate" (snelheid) zetten van de seriele poort
      - `Serial.begin(9600);`
    - Dit is de connectie met de computer

---

## Hello World - Analyse

- `loop()`:
  - Wordt telkens opnieuw uitgevoerd
    - Heel snel na elkaar
    - Vandaar dat we een vertraging moeten plaatsen
    - `delay(1000)`, betekent `1000ms` wachten
  - We kunnen ook tekst sturen naar de computer
    - `Serial.println("Hello World");`
    - Merk op dat we tekst tussen dubbele aanhalingstekens plaatsen `"..."`

---

## Hello World - Oefening

- Probeer de hello world sketch aan te passen zodat:
  - Het jouw naam toont: `Hello World! Ik ben Nico`
  - Er 2 seconden wordt gewacht tussen elk bericht in plaats van 1 seconde
  - Probeer volgende tekst op een nieuwe lijn toe te voegen
    - `Ik studeer land- en tuinbouw`

---

## Hello World - Oplossing

```cpp
void loop() {

  // Tekst versturen naar de computer
  Serial.println("Hello World! Ik ben Nico");
  Serial.println("Ik studeer land- en tuinbouw");

  // Even wachten (2000ms = 2s)
  delay(2000);

}
```

---

# Variabelen

- Een variabel is een symbolische naam voor een geheugen locatie
- Een variabel kan een getal, tekst, karakter, ... bevatten
- Een variabel kan van waarde veranderen
- We kunnen er ook bewerkingen op uitvoeren

![bg left:25% fit](./img/variable.jpg)

---

## Variabelen - Declareren

- Variabelen moeten we eerst declareren = creeren
- We geven de variabel een **naam**
- Geven ook aan welk **type** het is
- En we kunnen ook een 1ste **waarde** meegeven

---

## Variabelen - Declareren

- Hoe?
  - `type naam = waarde;`

- Een paar voorbeelden:

```cpp
// int = een getal
int leeftijd = 34;

// String = tekst
String naam = "Nico";

// double = komma-getal
double pi = 3.14;
```

---

## Variabelen - Declareren

- Types: `int`, `double`, `String` (er zijn er nog andere)
- Kiezen van de naam
  - Geen spaties of speciale tekens
  - Beschrijvend

---

## Variabelen - Printen

- De waarde van een variabel kunnen we tonen door deze uit te printen

```cpp
// Eerst printen we een beetje tekst
Serial.print("De variabel naam: ");

// Dan kunnen we de waarde van de variabel printen
Serial.println(naam);
```

---

## Variabelen - Veranderen van waarde

- De waarde van een variabel kunnen we ook veranderen met `=`

```cpp
// Veranderen van de waarde van een variabel
naam = "Chuck Norris";

// Of van een getal variabel
leeftijd = 35;
```

- Merk op dat enkel de variabel naam links plaatsen (geen type)
- Als je deze nu opnieuw print zal je de nieuwe waarde zien


---

## Variabelen - Demo Sketch

- Ga naar `Bestand => Openen` en selecteer `02-variabelen`
- Bovenaan zie je een aantal variabelen gedeclareerd
- In `loop()` printen we de waarde van de variabelen

---

## Variabelen - Oefening

- Verander de waarde van de variabel `naam` door je eigen naam
  - Doe dit bij het maken van de variabel (helemaal bovenaan)
- Maak `pi` nauwkeuriger door er `3.1415` van te maken
  - Doe dit in `setup()`
- Verander `leeftijd` naar je eigen leeftijd
  - Doe dit in `loop()`

*Kan je verklaren wat het verschil is tussen deze 3 manieren?*

---

## Variabelen - Oplossing

- `naam` veranderen bovenaan

```cpp
// String = tekst
String naam = "Chuck Norris";
```

*Hier wordt de 1ste waarde aangepast op het moment dat we de variabel maken*

---

## Variabelen - Oplossing

- `pi` veranderen in `setup()`

```cpp
void setup() {

  // Instellen van de snelheid waarmee we data naar de computer sturen
  SerialUSB.begin(9600);

  // pi aanpassen naar nauwkeurigere waarde
  pi = 3.1415;

}
```

*`pi` is bij declaratie `3.14`, dan wordt `setup()` uitgevoerd en hier passen we de waarde aan naar `3.1415`*

---

## Variabelen - Oplossing

- `leeftijd` veranderen in `loop()`

```cpp
void loop() {

  leeftijd = 35;

// ...
```

*`leeftijd` is bij declaratie `34`. Dan gaan we elke keer dat `loop()` wordt uitgevoerd, de `leeftijd` aanpassen naar `35`.*

---

## Variabelen - Bewerkingen

- Hoe zouden we de leeftijd kunnen laten toenemen?

---

# TITEL

- bullet
- bullet
- bullet
- bullet

![bg right fit](https://via.placeholder.com/150)
