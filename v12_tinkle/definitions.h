/* @@@@@@@@@@@@@@@@@@@@@@ testavimui @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
// #define DEBUG 

//#define DEBUGds18b20 // temperatÅ«rÅ³ matavimo testavimui 
// #define DEBUGbusena

/* ********************** Laikai *************************************** */
unsigned long Meniu_praleistas_neaktyvus_laikas;
#define neaktyvus_meniu 20000
unsigned long temperaturu_matavimo_laikas_1 = 0;
unsigned long Reliu_junginejimo_laikas = 0;
unsigned long temperaturu_matavimo_laikas_3 = 0;
#define temperaturu_matavimo_pertrauka_1 5000
#define Reliu_junginejimo_pertrauka 5000
#

unsigned long Ekrano_pasvietimo_ijungimo_laikas;
unsigned long  Ekrano_pasvietimo_pertrauka = 600000;
unsigned long Ekrano_rodmenu_atnaujinimo_laikas = 0;
#define Ekrano_rodmenu_atnaujinimo_pertrauka 5000


/* ************** LKLAVIATUROS KINTAMIEJI ************************************* */
#define Key_Pin 0
volatile int klaviaturos_pasikeitimas =-1;               // Tikrinti ar pasikeitÄ— klaviatÅ«ros reikÅ�mÄ—
volatile int x=-1;                 // 
volatile int stan_Analog;          // 
/* ********** LCD aprasymas ******************* */
#define BackLight_Pin 8 //LCD pasvietimo isvadas (standart LCD KeeyPad use pin 10)
byte lcd_pasvietimas = 10; // lcd_pasvietimas * 25 = MAX LCD apsviestumas
boolean Backlighting = true; // zyme ekrano pasvietimui
//Siurblio ÄÆjungimo simbolis (rodyklÄ— ÄÆ virÅ�Å³)
byte arrow_up[8]={ B00100,B01110,B11111,B00100,B00100,B00100,B00100,B00100};
//Siurblio ÄÆÅ�ungimo simbolis (rodyklÄ— ÄÆ Å¾emyn)
byte arrow_down[8]={ B00100,B00100,B00100,B00100,B00100,B11111,B01110,B00100};

/* ******************** reles *********************************** */
#define Rele_K A1 // Kolektorius
#define Rele_T A2 // Termostatas
/* ************************** davikliai *********************** */
#define ONE_WIRE_BUS1 2 // Kolektorius
#define ONE_WIRE_BUS2 9 // Boileris
#define ONE_WIRE_BUS3 A3 // Termostatas

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
//OneWire K_t(ONE_WIRE_BUS1); //katilo isejimas
//OneWire B_t(ONE_WIRE_BUS2); //saules kolektorius
//OneWire T_t(ONE_WIRE_BUS3); //pamaisymo voztuvas

// Pass our oneWire reference to Dallas Temperature. 
//DallasTemperature K_sensor(&K_t);
//DallasTemperature B_sensor(&B_t);
//DallasTemperature T_sensor(&T_t);

//kintamieji saugoti ismatuotoms temperaturu reiksmems
float K,B,T; 
/* ********** kintamieji Kieto kuro katilui ******************* */
/* ********** kintamieji Dujiniam katilui ******************* */
/* ********** kintamieji saulÄ—s kolektoriui ******************* */
byte k_ijungimo_skirtumas = 5;
byte k_isjungimo_skirtumas = 3;
boolean k_uzsalimas = false;
boolean SK_nuorinimas = false; // Å½ymÄ— rankiniam SK siurblio valdymui (nuorinimas)
/* ********** kintamieji Termostatui ******************* */
byte temperatura_1 = 20;
byte temperatura_2 = 25;
byte T_busena =1;
/* *************************************************************** */
/* ********** kintamieji Akumuliacinei talpai ******************* */
/* ********************************************************************** */
/* ************************************************************************ */
/* ********** kintamieji siurbliams ******************* */
/* ---------------- kintamieji motorizuotiems voÅ¾tuvams -------------------- */



