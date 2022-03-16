const int pinDATA		10;
const int pinCLOCK	9;
const int pinLATCH	8;

void setup() {
	pinMode(pinDATA, OUTPUT);
	pinMode(pinCLOCK, OUTPUT);
	pinMode(pinLATCH, OUTPUT);
}

void loop() {
	// 1) Montar o número binário que vai representar as saídas que devem ser acionadas
	// 1.1) Q1 Q5 Q8
	// 1.2) Montar um número binário que seja igual a
	//				Q1	Q2	Q3	Q4	Q5	Q6	Q7	Q8
	//				1		0		1		0		1		0		0		1
	// index:	0		1		2		3		4		5		6		7
	int outputs[8];
	
	for (int i = 0; i < 8; i++) {
		outputs[i] = 0;
	}
	
	outputs[0] = HIGH;
	outputs[2] = HIGH;
	outputs[4] = HIGH;
	outputs[7] = HIGH;

	// 2) Carregar número na memória do registrador
	for (int i = 7; i >= 0; i--) {
		digitalWrite(pinDATA, outputs[i]);
		delay(20);
		
		// Fazer um pulso de LOW para HIGH em pinCLOCK
		digitalWrite(pinCLOCK, HIGH);
		delay(10);
		digitalWrite(pinCLOCK, LOW);
		delay(10);
	}
	
	// 3) Atualizar as saídas do componente
	digitalWrite(pinLATCH, HIGH);
	delay(10);
	digitalWrite(pinLATCH, LOW);
}
