import threading
import logging
import time
import os

logging.basicConfig( level=logging.DEBUG, format='[%(levelname)s] - %(threadName)-10s : %(message)s')

def worker(x):
    logging.debug('Lanzado')

    importer = 'bin/mallet import-svmlight --input archivoEntrenamiento%s.txt --output training%s.mallet' % (x,x)
    #print importer

    os.system(importer)

    classifiers = ['NaiveBayes', 'DecisionTree','MaxEntL1','MaxEnt', 'BalancedWinnow', 'Winnow']
    for j in range(len(classifiers)):
        trainer= 'bin/mallet train-classifier --input training%s.mallet --output-classifier output%s_%s.classifier --trainer %s' % (x,x,classifiers[j],classifiers[j])
        #print trainer
        os.system(trainer)
        classify = 'bin/mallet classify-file --input archivo%s.txt --output output%s_%s.txt --classifier output%s_%s.classifier' % (x,x,classifiers[j],x,classifiers[j])
        #print classify
        os.system(classify)

        

    logging.debug('Deteniendo')
    return

threads = list()

for i in range(1,11):
    t = threading.Thread(target=worker, args=(i,))
    threads.append(t)
    t.start()
