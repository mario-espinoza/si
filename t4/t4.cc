#include <unistd.h>
#include <math.h>

using namespace std;

typedef struct node{

}

typedef struct cluster{
}

//minkowski(h = 3, 4 y 5)
template <typename fp_type> fp_type minkowskiDistance(const fp_type & p, const std::vector<fp_type> & ds) {
    // ds contains d[i] = v[i] - w[i] for two vectors v and w
    fp_type ex = 0.0;
    fp_type min_d = std::numeric_limits<fp_type>::infinity();
    fp_type max_d = -std::numeric_limits<fp_type>::infinity();
    for (int i = 0 ; i < ds.size() ; ++i) {
        fp_type d = std::fabs(ds[i]);
        ex += std::pow(d, p);
        min_d = std::min(min_d, d);
        max_d = std::max(max_d, d);
    }

    return std::isnan(ex) ? ex
         : !std::isnormal(ex) && std::signbit(p) ? min_d
         : !std::isnormal(ex) && !std::signbit(p) ? max_d
         : std::pow(ex, 1.0/p);
}

//euclideana
float euclideanDistance(node a, node b)
{

}

//Manhattan
float manhattanDistance()
{

}

//Euclideana cuadrada
float euclideanSquaredDistance()
{

}


//Chebychev
float chebychevDistance()
{

}


//Canberra
float canberraDistance()
{

}

//Cord al cuadrado
float cordSquaredDistance()
{

}

//Chi-squared al cuadrado.
float chiSquaredDistance()
{

}

pureza,
double purity()
{}

//entropía,
double getEntropy(double probCatA, double ProbCatB)
{
    double entropy;
    entropy =
}

double precision()
{}

double getAccuracy()
{
    double = accuracy;
    int correctCases,testCases;

    accuracy = correctCases/testCases;
    return accuracy;
}

double recall()
{}

//F1-Score
double f1score(){

}

void randIndex()
{}

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
