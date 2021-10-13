class Euclid{
    // Declare any variables you may need

    public:
    Euclid(int a, int b);   // The Constructor, initialized by the numbers you want to calculate the GCD for
    void ExtendedEuclid();         // Run Extended Euclid's on the concerned numbers to calculate reqd. coefficients
    void Positify();            

    /* ax+by = gcd(a,b), would be solved by Extended Euclid's Algorithm, 
    but its not guaranteed that the x,y you reach at are both positive, but you do require them to be so!
    Hence, you need a function to do that!
    */ 
};