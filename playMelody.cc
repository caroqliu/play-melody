// Play a melody on a Piezo Buzzer

/*-------------

This program will blink an led on and off every second.
It blinks the D7 LED on your Particle device. When it is off, the piezo buzzer will play a melody.

-------------*/

// variables
int soundPin = D0; // piezo buzzer
int led = D7; // blue LED on board

// an array for the notes in the melody (in frequency)
// C4,G3,G3,A3,G3,0,B3,C4
int melody[] = {1908,2551,2551,2273,2551,0,2024,1908};

// an array for the duration of notes.
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4,8,8,4,4,4,4,4 };

// setup (one pass)
void setup() {

  // D0 and D7 (soundPin and led respectively) are going to be output
  // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)

  pinMode(soundPin, OUTPUT);
  pinMode(led, OUTPUT);

}

// loop (runs continuously)
void loop() {
  // Turn on LED / turn off sound
  digitalWrite(soundPin, LOW);
  digitalWrite(led, HIGH);

  // Wait .25 seconds
  delay(250);

  // Turn off LED / play melody
  digitalWrite(led, LOW);
  playNotes();

  // Wait 1 second
  delay(1000);

  // And repeat!
}

// function to play all notes
void playNotes()
{
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // calculate note duration = 1s divided by note type.
      // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      tone(soundPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop playing tone
      noTone(soundPin);
    }
}
