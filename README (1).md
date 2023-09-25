# Projeto de Monitoramento de Luminosidade

Este é um projeto de monitoramento de luminosidade usando Arduino, um sensor LDR (Light Dependent Resistor) e LEDs para sinalização visual. O projeto é ideal para monitorar as condições de luminosidade em um ambiente, como uma vinheria, onde a qualidade do vinho é influenciada pelas condições de armazenamento.

![Imagem do Circuito](https://raw.githubusercontent.com/Kaiomeireles/Kaiomeireles/main/Incredible%20Duup-Jaagub.png)

## Passo a Passo

Siga este guia passo a passo para montar e configurar o projeto:

### 1. Componentes Necessários

- Arduino Uno ou placa Arduino compatível.
- Sensor LDR.
- LEDs (verde, amarelo e vermelho).
- Buzzer (ou piezoelétrico).
- Resistores para limitação de corrente.
- Fios de conexão.
- Computador para programação.

### 2. Montagem do Circuito

Monte o circuito conforme o esquema abaixo:

const int LDRPin = A0;
const int greenLEDPin = 8;
const int yellowLEDPin = 9;
const int redLEDPin = 10;
const int buzzerPin = 7;

int luminosityValue;
int alertThreshold = 200; // Ajuste esse valor de acordo com suas necessidades
bool alertActive = false;

void setup() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  luminosityValue = analogRead(LDRPin);

  if (luminosityValue < alertThreshold) {
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);

    if (!alertActive) {
      tone(buzzerPin, 1000); // Ativa o buzzer
      alertActive = true;
    }
  } else {
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);

    noTone(buzzerPin); // Desliga o buzzer
    alertActive = false;
  }

  Serial.print("Luminosidade: ");
  Serial.println(luminosityValue);

  delay(1000); // Aguarde um segundo antes de fazer a próxima leitura
}


## Licença

[MIT](https://choosealicense.com/licenses/mit/)


Certifique-se de conectar cada componente ao pino correto do Arduino e utilizar os resistores apropriados para limitação de corrente.

### 3. Configuração do Código

- Carregue o código-fonte no Arduino usando a IDE do Arduino.
- Ajuste o valor de `alertThreshold` no código para definir o limiar de luminosidade desejado para acionar o alerta.

### 4. Execução do Projeto

- Conecte o Arduino ao ambiente de armazenamento de vinhos.
- Observe o comportamento dos LEDs e do buzzer em relação à luminosidade.

### 5. Personalização

- Personalize o valor de `alertThreshold` para atender às condições de luminosidade desejadas para a vinheria.
- Adicione mais sensores (por exemplo, de temperatura e umidade) se necessário.

## Vídeo Explicativo

[Inserir Link para o Vídeo Explicativo aqui]

Assista ao vídeo para uma demonstração prática do projeto e mais detalhes sobre o seu funcionamento.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para melhorar este projeto e adicionar mais funcionalidades.

## Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE.md) para obter detalhes.

---

Siga este guia passo a passo para montar o projeto de monitoramento de luminosidade com sucesso. Se você tiver alguma dúvida ou precisar de assistência adicional, sinta-se à vontade para entrar em contato.

[Inserir Contato ou Informações Adicionais aqui]
