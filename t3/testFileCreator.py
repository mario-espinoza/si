numbers = range(1,11)
#with open('./', 'w') as outfile:
inputfilename='archivo'
for number in numbers:
    trainingfilename='archivoEntrenamiento'
    for number2 in numbers:
        if (number == number2):
            print '%s == %s' % (number2,number)
        else:
            trainingfilename = trainingfilename+'%s' % (number2)
    trainingfilename+='.txt'
    print trainingfilename

    with open('./'+trainingfilename, 'w') as outfile:
        for number2 in numbers:
            if (number == number2):
                print '%s == %s' % (number2,number)
            else:
                actualFile=inputfilename+'%s.txt' % (number2)
                with open(actualFile) as infile:
                    for line in infile:
                        outfile.write(line)

    testingfilename = 'archivoPrueba%s' % (number)

    print testingfilename+'.txt'
    print inputfilename+'%s.txt' % (number)

    #
