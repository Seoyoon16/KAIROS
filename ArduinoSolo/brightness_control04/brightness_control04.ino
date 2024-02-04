const unsigned int led[] = {3,5,6,9,10};

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<=4; i++) {
    if (i%2 != 0) {
      for (int j=0; j<=255; j+=25) {
        analogWrite(led[i], j);
        delay(100);
        if (j >= 250) {
          analogWrite(led[i], 0);
        }
      }
    }
  }

  for (int i=0; i<=4; i++) {
    if (i%2 == 0) {
      for (int j=0; j<=255; j+=25) {
        analogWrite(led[i], j);
        delay(100);
        if (j >= 250) {
          analogWrite(led[i], 0);
        }
      }
    }
  }  
}

// for (int i=0; i<4; i++) {
//     if ( (i+k)%2 == 0 ) {
//       for (int j=0; j<=255; j++) {
//         analogWrite(led[i], j);
//         delay(4);
//       }
//       analogWrite(led[i], 0);
//     }
//   }
//   if (k == 0) {
//     k = 1;
//   }
//   else if (k == 1) {
//     k = 0;
//   }

