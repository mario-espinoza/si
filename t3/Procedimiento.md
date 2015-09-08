Caso 1:
ParaPrueba: archivo1.txt
Entrenamiento: archivo23456789A.txt

import[x] 1...10
i: Entrenamiento
o: training1.mallet

Res: 10 nuevos

trainer [x] 1...10
i:    training1.mallet
o: output%s_%s.classifier

Res: 10 nuevos

classify[x,Modelo] x 6
i: ParaPrueba
o: output.txt
c: output1_Modelo.classifier

Res: 6 x 10 nuevos

['Bayes', 'DecisionTree', 'BalancedWinnow', 'MaxEntL1','MaxEnt', 'BalancedWinnow', 'Winnow']

Caso 2:
T
Entrenamiento: 2
ParaPrueba: 13456789A
