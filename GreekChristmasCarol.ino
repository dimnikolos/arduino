/*Greek christmas carol
http://www.arduino.cc/en/Tutorial/Tone
*/
#include "pitches.h"
int greekNYMelody[] = {
NOTE_R,
NOTE_E5,
NOTE_E5,
NOTE_E5,
//------------
NOTE_E5,
NOTE_D5,
NOTE_C5,
NOTE_B4,
//-----------
NOTE_D5,
NOTE_C5,
NOTE_B4,
//-----------
NOTE_A4,
//-----------
NOTE_R,
NOTE_E5,
NOTE_E5,
NOTE_E5,
//------------
NOTE_E5,
NOTE_D5,
NOTE_C5,
NOTE_B4,
//-----------
NOTE_D5,
NOTE_C5,
NOTE_B4,
//-----------
NOTE_A4,
//-----------
NOTE_B4,
NOTE_C5,
NOTE_D5,
NOTE_E5,
//----------
NOTE_D5,
NOTE_D5,
//----------
NOTE_G5,
NOTE_F5,
NOTE_E5,
NOTE_D5,
//----------
NOTE_C5,
NOTE_B4,
//----------
NOTE_D5,
NOTE_D5,
//----------
NOTE_C5,
NOTE_B4,
NOTE_A4,
//----------
NOTE_G4,
NOTE_A4,
NOTE_B4,
NOTE_C5,
//----------
NOTE_A4,
NOTE_A4};

float greekNYDurations[] = {
8,
8,
8,
8,
//------------
8,
8,
8,
8,
//-----------
4,
8,
8,
//-----------
2,
//-----------
8,
8,
8,
8,
//------------
8,
8,
8,
8,
//-----------
4,
8,
8,
//-----------
2,
//-----------
8,
8,
8,
8,
//----------
8/3,
8,
//----------
8,
8,
8,
8,
//----------
4,
4,
//----------
4,
4,
//----------
4,
8,
8,
//----------
8,
8,
8,
8,
//----------
4,
4};

int greekChristmasMelody1[] = {
NOTE_G4,
NOTE_A4,
NOTE_B4,
//----------
NOTE_C5,
NOTE_B4,
NOTE_A4,
//----------
NOTE_G4,
NOTE_F4,
//----------
NOTE_E4,
//----------
NOTE_G4,
NOTE_F4,
NOTE_E4,
//----------
NOTE_D4,
NOTE_D4,
//----------
NOTE_E4,
NOTE_F4,
NOTE_G4,
NOTE_A4,
//----------
NOTE_G4,
NOTE_A4,
//----------
NOTE_G4,
};
int greekChristmasMelody2[]= {
NOTE_G4,
NOTE_A4,
NOTE_B4,
//----------
NOTE_C5,
NOTE_B4,
NOTE_A4,
//----------
NOTE_G4,
NOTE_F4,
//----------
NOTE_E4,
//----------
NOTE_A4,
NOTE_G4,
NOTE_F4,
NOTE_E4,
//----------
NOTE_D4,
NOTE_D4,
//----------
NOTE_E4,
NOTE_F4,
NOTE_G4,
NOTE_A4,
//----------
NOTE_G4,
NOTE_B4,
//----------
NOTE_C5
};

float greekChristmasDurations1[]= {
8,
8,
8,
//----------
4,
8,
8,
//----------
4,
4,
//----------
2,
//----------
4,
8,
8,
//----------
8/3,
8,
//----------
8,
8,
8,
8,
//----------
4,
4,
//----------
8,
};
float greekChristmasDurations2[] = {
8,
8,
8,
//----------
4,
8,
8,
//----------
4,
4,
//----------
2,
//----------
8,
8,
8,
8,
//----------
8/3,
8,
//----------
8,
8,
8,
8,
//----------
4,
4,
//----------
2};





int speakerPin = 9;

void playmelody(int melody[],float duration[], int repetitions)
{
	int melodyLength = sizeof(melody)/sizeof(int);
	for (int i=0; i<repetitions; i++)	{
		for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
		    int noteDuration = 1000 / duration[thisNote];
		    tone(speakerPin, melody[thisNote], noteDuration);
		    int pauseBetweenNotes = noteDuration * 1.30;
		    delay(pauseBetweenNotes);
		    noTone(8);
		}
    }

}

void setup() {
}
	
void loop(){
playmelody(greekChristmasMelody1,greekChristmasDurations1,4);
playmelody(greekChristmasMelody2,greekChristmasDurations2,1);
playmelody(greekNYMelody,greekNYDurations,4);
}