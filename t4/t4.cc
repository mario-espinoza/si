#include <unistd.h>
#include <math.h>

using namespace std;

//minkowski(h = 3, 4 y 5)
template <typename fp_type> fp_type minkowskiDistance(const fp_type & p, const std::vector<fp_type> & ds) {
    // ds contains d[i] = v[i] - w[i] for two vectors v and w

}

//euclideana
double euclideanDistance(vector<int> a,vector<int>b)
{

}

//Manhattan
double manhattanDistance()
{

}

//Euclideana cuadrada
double euclideanSquaredDistance()
{

}


//Chebychev
double chebychevDistance()
{

}


//Canberra
double canberraDistance()
{

}

//Cord al cuadrado
double cordSquaredDistance()
{

}

//Chi-squared al cuadrado.
double chiSquaredDistance()
{

}

pureza,
double purity()
{}

//entropía,
double getEntropy(double probCatA, double ProbCatB)
{
    double entropy;
    entropy = -(probCatA)*log
}

double precision()
{}

double getAccuracy()
{
    double accuracy;
    int correctCases,testCases;

    accuracy = correctCases/testCases;
    return accuracy;
}

double recall()
{
    double recall;

    int
}

//F1-Score
double f1score(){

}

void randIndex()
{

}

double variance()
{}

double dunnIndex(){
}

int main (int argc, char **argv)
{

    int aflag = 0;
    int bflag = 0;
    char *iterValue = NULL;
    char *startValue = NULL;
    char *cvalue = NULL;
    int index;
    int c;

    opterr = 0;
    while ((c = getopt (argc, argv, "abcis:")) != -1)
        switch (c){
            case 'a':
                aflag = 1;
                break;
            case 'b':
                bflag = 1;
                break;

            case 'c':
                cvalue = optarg;
                break;

            case 'i':
                iterValue = optarg;;
                break;
            case 'b':
                startValue = optarg;
                break;
            case '?':
                if (optopt == 'c')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                        fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                    else
                        fprintf (stderr,"Unknown option character `\\x%x'.\n", optopt);
                    return 1;
            default:
                abort ();
        }
    printf ("aflag = %d, bflag = %d, cvalue = %s\n",
            aflag, bflag, cvalue);

    for (index = optind; index < argc; index++)
            printf ("Non-option argument %s\n", argv[index]);
    return 0
}
