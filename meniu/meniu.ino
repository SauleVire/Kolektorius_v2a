    /*
    MOJE Przykładowe MENU: (w sumie 19 opcji w trzech poziomach - rodzic, dziecko, wnuk)

           PLIK            EDYCJA          SZKIC           NARZEDZIA            POMOC
              Nowy            Kopiuj          Kompiluj         Temperatura
              Zapisz          Wklej           Importuj            Odczyt
              Exit            Zaznacz            EEPROM           Ustaw
                                                 GSM           Wilgotnosc

    rodzice (poziom 0) : PLIK, EDYCJA, SZKIC, NARZEDZIA, POMOC
    dzieci  (poziom 1) : Nowy, Zapisz, Exit, Kopiuj, Wklej, Zaznacz,
                         Kompiluj, Importuj, Temperatura, Wilgotnosc
    wnuki   (poziom 2) : EEPROM i GSM dla Importuj oraz Odczyt i Ustaw dla Temperatura
    */                                             
    #include <LiquidCrystal.h>
    LiquidCrystal lcd(8,9,4,5,6,7); // konfiguracja pinów dla LCD
    uint8_t arrowUpDown[8] = {0x4,0xe,0x15,0x4,0x15,0xe,0x4}; // strzałka góra-dół
    const int ILE=20;      // ilość opcji +1
    int poz=1;             // nr aktualnej pozycji menu
    int popm=1;            // nr poprzedniej pozycji menu
    int pop=-1;            // poprzedni odczyt stanu klawiatury
    int akt=-1;            // aktualny odczyt stanu klawiatury
    char opcje[ILE][16]={  // tablica nazw opcji
      "              ",    // jedna pusta linia, dla czyszczenia LCD
      "     PLIK     ",    // 1   // numer opcji
      "     Nowy     ",    // 2
      "    Zapisz    ",    // 3
      "     Exit     ",    // 4
      "    EDYCJA    ",    // 5
      "    Kopiuj    ",    // 6
      "     Wklej    ",    // 7
      "    Zaznacz   ",    // 8
      "     SZKIC    ",    // 9
      "   Kompiluj   ",    // 10
      "   Importuj   ",    // 11
      "    EEPROM    ",    // 12
      "      GSM     ",    // 13
      "   NARZEDZIA  ",    // 14
      "  Temperatura ",    // 15
      "    Odczyt    ",    // 16
      "    Ustaw     ",    // 17
      "  Wilgotnosc  ",    // 18
      "     POMOC    ",    // 19
    };
    /* Poniżej specyficzna tablica do nawigacji po menu.
    Znaczenie poszczególnych składników:
    index 0 - nr pozycji powyżej - UP (w stosunku do obecnej)
    index 1 - numer pozycji dla RIGHT ( na prawo)
    index 2 - numer pozycji dla DOWN (poniżej)
    index 3 - numer pozycji dla LEFT ( na lewo)
    index 4 - numer pozycji dla OK ( dla -1 skok do funkcji akcjaOK )
    index 5 - poziom menu 0 - rodzic( poziom 0), 1 - dziecko (poziom 1) ,2 - wnuk (poziom2)
     przykłady:
     Zapisz (opcja nr 3) ma : UP-2, RIGHT-0, DOWN-4, LEFT-0, OK (-1) , 1 - bo to poziom 1 menu
     Temperatura (opcja 15) ma: UP-14, RIGHT-0, DOWN-18, LEFT-0, OK-16, 1 bo to poziom 1 menu
     Ustaw (opcja 17) ma: UP-16, RIGHT-0, DOWN-0, LEFT-0, OK (-1), 2, bo to poziom 2 menu
    */
    int navi[ILE][6]={       // tablica opcji nawigacji po menu
    {0,0,0,0,0,0},           // dla pustej linii
    {0,5,0,19,2,0},          // PLIK
    {1,0,3,0,-1,1},          // Nowy
    {2,0,4,0,-1,1},          // Zapisz
    {3,0,0,0,-1,1},          // Exit
    {0,9,0,1,6,0},           // EDYCJA
    {5,0,7,0,-1,1},          // Kopiuj
    {6,0,8,0,-1,1},          // Wklej
    {7,0,0,0,-1,1},          // Zaznacz
    {0,14,0,5,10,0},         // SZKIC
    {9,0,11,0,-1,1},         // Kompiluj
    {10,0,0,0,12,1},         // Importuj
    {11,0,13,0,-1,2},        // EEPROM
    {12,0,0,0,-1,2},         // GSM
    {0,19,0,9,15,0},         // NARZEDZIA
    {14,0,18,0,16,1},        // Temperatura
    {15,0,17,0,-1,2},        // Odczyt
    {16,0,0,0,-1,2},         // Ustaw
    {15,0,0,0,-1,1},         // Wilgotnosc
    {0,1,0,14,-1,0}          // POMOC
    };
    //--- odczyt stanu klawiatury ---------------------------------------
    volatile int klawisz(int analog)
    {
       int stan_Analog = analogRead(analog);delay(30);
       if (stan_Analog > 1000) return -1; // dla wartosci poza zakresem
       if (stan_Analog < 50)   return 0;  // w prawo 
       if (stan_Analog < 150)  return 1;  // do gĂłry
       if (stan_Analog < 350)  return 2;  // w dĂłĹ‚
       if (stan_Analog < 550)  return 3;  // w lewo 
       if (stan_Analog < 750)  return 4;  // OK
       return -1;                         // nic nie wcisnieto
    }
    // --- akcja po wcisnięciu klawisza OK ------------------------------
    void akcjaOK()
    {
      Serial.println("  - WYKONANO -  ");
      lcd.setCursor(0,1);lcd.print("  - WYKONANO -  ");
      switch(poz)
        {
        case 2:       // obsługa opcji Nowy (funkcja obsługi do napisania)
              break;
        case 3:       // obsługa opcji Zapisz (wszędzie poniżej funkcje obsługi)       
              break;
        case 4:       // obsługa opcji Exit
              break;
        case 6:       // obsługa opcji Kopiuj
              break;
        case 7:       // obsługa opcji Wklej
              break;
        case 8:       // obsługa opcji Zzanacz
              break;
        case 10:      // obsługa opcji Kompiluj     
              break;
        case 12:      // obsługa opcji Importuj -> EEPROM
              break;
        case 13:      // obsługa opcji Importuj -> GSM
              break;
        case 16:      // obsługa opcji Temperatura -> Odczyt       
              break;
        case 17:      // obsługa opcji Temperatura -> Ustaw
              break;
        case 18:      // obsługa opcji Wilgotność
              break;
        case 19:      // obsługa opcji POMOC       
              break;   
        }
      delay(1000);    // opcjonalne aby zobaczyć komunikat"  - WYKONANO - "
      ekran();        // powrót do ostatniej opcji
    }
    // --- funkcja ekran ------------------------------------------------
    void ekran()
    {
      if(navi[poz][5]==0) // jeśli rodzic to wyświetlamy w pierwszej linii LCD
        {
        lcd.clear();
        lcd.setCursor(0,0);lcd.print("<");lcd.print(opcje[poz]);lcd.print(">");
        }
      else               // jeśli dziecko lub wnuk to w drugiej linii
        {
          lcd.setCursor(0,0);lcd.print(" ");lcd.setCursor(15,0);lcd.print(" ");
          lcd.setCursor(0,1);lcd.print("                ");
          lcd.setCursor(0,1);lcd.print((char)0);lcd.print(opcje[poz]);lcd.print((char)0);
        }
      Serial.println(opcje[poz]);  // opcjonalnie także na serialu
    }
    // --- funkcja menu -------------------------------------------------
    void menu()
    {
      akt=klawisz(0); // odczyt stanu klawiatury analogowej podpiętej do Analog 0
      if(akt!=pop)    // jeśli zmiana (naciśnięto coś)
        {
          switch(akt)
          {
          case 0: if(navi[poz][1]!=0)poz=navi[poz][1];break;  // klawisz w prawo
          case 1: if(navi[poz][0]!=0)poz=navi[poz][0];break;  // w górę
          case 2: if(navi[poz][2]!=0)poz=navi[poz][2];break;  // w dół
          case 3: if(navi[poz][3]!=0)poz=navi[poz][3];break;  // w lewo
          case 4: if(navi[poz][4]!=-1)poz=navi[poz][4];else akcjaOK();break;  // OK
          }
        if(akt!=-1 && poz!=popm){ekran();popm=poz;} // przy zmianie pozycji menu
                                                    // aktualizujemy LCD
        }
      pop=akt; // przypisanie aby nie generować autopowtarzania
    }
    // --- funkcja setup ------------------------------------------------
    void setup()
    {
      Serial.begin(9600);
      lcd.begin(16,2);               // inicjacja LCD
      lcd.createChar(0,arrowUpDown); // tworzymy nietypowy znak w pamięci LCD
      ekran();                       // wyświetlamy na LCD
    }
    // --- neverending story --------------------------------------------
    void loop()
    {
      menu(); // wywołujemy menu
    }
    // === KONIEC ========================================================
     

