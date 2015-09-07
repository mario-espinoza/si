import subprocess
import threading
import logging
import time

logging.basicConfig( level=logging.DEBUG, format='[%(levelname)s] - %(threadName)-10s : %(message)s')

def worker(x):
    logging.debug('Lanzado')
    print "We're on time %d" % (x)
    systemcall = 'bin/mallet %s' % (x*x)
    print systemcall

    importer = '.bin/mallet import-svmlight --input archivo%s.txt --output training%s.mallet' % (x,x)
    print importer

    classifiers = ['Bayes', 'DecisionTree', 'BalancedWinnow', 'MaxEntL1','MaxEnt', 'BalancedWinnow', 'Winnow']
    for j in range(len(classifiers)):
        trainer= '.bin/mallet train-classifier --input training%s.mallet --output-classifier output%s_%s.classifier --trainer %s' % (x,x,classifiers[j],classifiers[j])
        print trainer
        classify = '.bin/mallet classify-file --input archivo%s.txt --output output%s.txt --classfier output%s_%s.classifier' % (x,x,x,classifiers[j])
        print classify
    time.sleep(2)
    logging.debug('Deteniendo')
    return

threads = list()

for i in range(1,10):
    t = threading.Thread(target=worker, args=(i,))
    threads.append(t)
    t.start()
