numbers = range(1,11)

inputfilename='archivo'
for number in numbers:
    trainingfilename='archivoEntrenamiento%s.txt' % (number)
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
    print inputfilename+'%s.txt' % (number)
