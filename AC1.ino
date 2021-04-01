const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;


const int botao1 = 2;
const int botao2 = 3;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int botaoDelay = 100;

//Função setup (função inicial), executado uma vez ao ligar o Arduino.

void setup()
{
  //Lê o pino analógico A0
  pinMode(A0, INPUT);
  //Lê o pino analógico A1
  pinMode(A1, INPUT);
  
  //Ativando o serial monitor que exibirá os valores lidos no sensor.	
  Serial.begin(9600);

  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: ----->  QUINTETO FANTÁSTICO  <-------           ");
}

//Função loop, executado enquanto o Arduino estiver ligado.
void loop()
{	
	//Inicio do processo do botão1 			
	  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
		Serial.println("Processo Inciado");
	    ledVermelho(true);
		lastDebounceTime1 = millis();
	  }

	{	
	//Inicio do processo do botão2 			
	  if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){
		Serial.println("Processo Paralisado");
	    ledVermelho(false);
		lastDebounceTime2 = millis();
	  }

	//REGRA DE DECISÃO DE OPERAÇÃO DO LED AZUL
	  if(getTemperatura() > 30){
		ledAzul(true);
		Serial.println("Temperatura acima do esperado");  
	  }else{
		ledAzul(false); 
		Serial.println("Temperatura esperada")	    
	  }

	//REGRA DE DECISÃO DE OPERAÇÃO DO LED VERDE
	  if(getTemperatura() > 25){
		ledVerde(true);
		Serial.println("Temperatura acima do esperado");	  
	  }else{
		ledVerde(false); 
		Serial.println("Temperatura esperada")	    
	  }
	//REGRA DE DECISÃO DE OPERAÇÃO DO LED VERMELHO
	  if(getTemperatura() < 25){
		ledVermelho(true);
		Serial.println("Temperatura abaixo do esperado");	  
	  }else{
		ledVermelho()
		Serial.println("Temperatura esperada")	    
	  }

	  delay(10);
}

void ledAzul(bool estado){
digitalWrite(azul,estado); 
}
void ledVerde(bool estado){
  digitalWrite(verde,estado);
}
void ledVermelho(bool estado){
  digitalWrite(vermelho,estado);
}
	
//Fazendo o cálculo da temperatura em graus Celcius
int getTemperatura(){
  	int temperaturaC;
	//cálculo em graus Celcius
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
} 

//Ativando a luninosidade
int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
