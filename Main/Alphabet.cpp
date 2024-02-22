#include "Alphabet.h"
#include <Arduino.h>
#include "Parameters.h"

Letter::Letter(string structure, string definition)  //Konstruktor
{
    this->structure = structure; 
    this->definition = definition;
}

A=Letter(".-","Alpha");
B=Letter("-...","Bravo");
C=Letter("-.-.","Charlie");
D=Letter("-..","Delta");
E=Letter(".","Echo");
F=Letter("..-.","Foxtrott");
G=Letter("--.","Golf");
H=Letter("....","Hotel");
I=Letter("..","India");
J=Letter(".---","Juliett");
K=Letter("-.-","Kilo");
L=Letter(".-..","Lima");
M=Letter("--","Mike");
N=Letter("-.","November");
O=Letter("---","Oscar");
P=Letter(".--.","Papa");
Q=Letter("--.-","Quebec");
R=Letter(".-.","Romeo");
S=Letter("...","Sierra");
T=Letter("-","Tango");
U=Letter("..-","Uniform");
V=Letter("...-","Victor");
W=Letter(".--","Whiskey");
X=Letter("-..-","X-Ray");
Y=Letter("-.--","Yankee");
Z=Letter("--..","Zulu");

1_M=Letter(".----","Eins");
2_M=Letter("..---","Zwei");
3_M=Letter("...--","Drei");
4_M=Letter("....-","Vier");
5_M=Letter(".....","Fünf");
6_M=Letter("-....","Sechs");
7_M=Letter("--...","Sieben");
8_M=Letter("---..","Acht");
9_M=Letter("----.","Neun");
0_M=Letter("-----","Null");


//Quellen: https://www.marinecom.ch/e-learning/seefunk-alphabet/
//Quellen: https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/


