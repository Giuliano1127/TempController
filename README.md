# TempController (Wokwi)

## Objetivo
Projeto de treino utilizando o simulador online Wokwi. O sistema lê a temperatura de um sensor NTC virtual, exibe no display LCD 16x2 e aciona um servo motor quando a temperatura ultrapassa um limite definido. Ideal para praticar integração de sensores, atuadores e displays em Arduino sem hardware físico.

## Componentes simulados no Wokwi
- Arduino Uno
- Sensor NTC
- Servo motor
- LCD I2C 16x2
- Resistores e cabos de conexão

## Funcionamento
1. Leitura do valor do sensor NTC no pino A3.
2. Cálculo da temperatura em Celsius.
3. Exibição da temperatura no display LCD.
4. Acionamento do servo motor:
   - Se a temperatura > 50°C → servo vai para 180°
   - Caso contrário → servo vai para 0°

## Observações
- Projeto de treino no Wokwi, não requer hardware físico.
- Pode ser expandido para controle proporcional do servo ou outras aplicações práticas.

## Link para simulação
[Rodar no Wokwi][(https://wokwi.com/projects/444251818270026753)]
