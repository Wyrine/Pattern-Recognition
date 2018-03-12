#include <iostream>
#include "mat.hpp"

using namespace std;

Mat::Mat(const char* tr, const char* te, const uint& _features, 
            const uint& _classes, double (*_compFunc)(const string &))
{

    classes = _classes;
    features = _features;
    compFunc = _compFunc;
    readFile(tr, X);
    readFile(te, Xte);
    nX = subMatrix(X, 0, 0, X.getRow() -1, features - 1);
    nXte = subMatrix(Xte, 0, 0, Xte.getRow() -1, features -1);
    normalize(nX, nXte, features, 1);

    setParams(mu, sig, nX, nXte);
}

void
Mat::generateEvals(const Matrix & results) const
{
    double accuracy, precision, sens, spec, tp=0, tn=0, fp=0, fn=0;

    for(int i = 0; i < results.getRow(); i++)
    {
        if(results(i, 0) == results(i, 1))
        {
            if( results(i, 0) ) tp++;
            else tn++;
        }
        else
        {
            if( results(i, 0) ) fp++;
            else fn++;

        }
    }
    tp /= results.getRow();
    tn /= results.getRow();
    fp /= results.getRow();
    fn /= results.getRow();
    accuracy = (tp + tn) / (tp + tn + fp + fn);
    sens = tp / (tp + fn);
    spec = tn / (tn + fp);
    precision = tp / (tp + fp);
    printf("TP: %lf | TN: %lf | FP: %lf | FN: %lf | \n\tAcc: %lf | Sens: %lf | Spec: %lf | Prec: %lf\n", 
                    tp, tn, fp, fn, accuracy, sens, spec, precision);
}

void
Mat::readFile(const char* fName, Matrix &_X)
{
    vector<Sample> d;
    double samp[features+1];
    string tmp;
    ifstream input(fName);

    if(! input.is_open() )
    {
        fprintf(stderr, "Unable to open %s, exiting.\n", fName);
        exit(1);
    }
    getline(input, tmp);
    while( getSamp(input, samp) )
    {
        Sample s(features, samp);
        d.push_back(s);
    }
    input.close();
    buildMatrix(d, _X);
}

bool
Mat::getSamp(ifstream &input, double samp[])
{
    int i;
    string tmp;

    for(i = 0; i < features && (input >> samp[i]); i++);
    if( i < features) return false;

    input >> tmp;
    samp[i] = compFunc(tmp);
    
    return true;
}

void
Mat::buildMatrix(vector<Sample> &c, Matrix & _X)
{
    int sz = c.size();
    _X.createMatrix(sz, features+1);
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < features + 1; j++)
            _X(i, j) = c[i][j];
}

void
Mat::PCA(float maxErr)
{
    pX = nX;
    pXte = nXte;
    int numDrop = pca(pX, pXte, features, maxErr, 1);
    pX = subMatrix(pX, 0, 0, pX.getRow() - 1, numDrop - 1);
    pXte = subMatrix(pXte, 0, 0, pXte.getRow() - 1, numDrop - 1);
    setParams(pMu, pSig, pX, pXte);
}

void
Mat::addLabels(Matrix &dest, const Matrix & src)
{
    Matrix tmp(dest.getRow(), dest.getCol() + 1);
    uint lab_ind = src.getCol() - 1;
    uint i, j;
    for(i = 0; i < dest.getRow(); i++)
    {
        for(j = 0; j < dest.getCol(); j++)
            tmp(i, j) = dest(i, j);
        tmp(i, j) = src(i, lab_ind);
    }
    dest = tmp;
}

void
Mat::FLD()
{
    Matrix mVec;
    mVec = mu[0];
    fW = (sig[0].getRow() - 1) * sig[0];
    for(uint i = 1; i < classes; i++)
    {
        mVec = mVec - mu[i];
        fW = fW + (sig[i].getRow() - 1) * sig[i];
    }
    Matrix sW = fW;
    fW = inverse(fW) ->* mVec;
    mVec = mVec ->* transpose(mVec);
    Matrix lossFunc = ( transpose(fW) ->* mVec ->* fW)
                    / ( transpose(fW) ->* sW ->* fW);

    //projecting
    fX = subMatrix(nX, 0, 0, nX.getRow() - 1, features - 1) ->* fW;
    fXte = subMatrix(nXte, 0, 0, nXte.getRow() - 1, features - 1) ->* fW;
    //getting means
    setParams(fMu, fSig, fX, fXte);
}

void
Mat::setParams(vector<Matrix> & Mean, vector<Matrix> & Cov, Matrix & _X, Matrix & _Xte)
{
    Matrix m;
    
    addLabels(_Xte, Xte);
    addLabels(_X, X);
    for(int i = 0; i < classes; i++)
    {
        m = getType(_X, i);
        Mean.push_back( mean(m, m.getCol() ) );
        Cov.push_back( cov(m, m.getCol() ) );
    }
}

void
Mat::runCase1(const double prior[])
{
    cout << "Case 1 Scores:\n";
    vector<Matrix> tmpSig;
    Matrix identity(features, features);
    for(int i = 0; i < features; i++)
        identity(i, i) = 1;
    for(int i = 0; i < classes; i++)
        tmpSig.push_back( sqrt(sig[1](0, 0)) * identity );
    Matrix rv(nXte.getRow(), 1);
    getProb(nXte, prior, tmpSig, mu, rv);
    cout << "Normalized X: \n";
    generateEvals(rv);

    tmpSig.clear();
    rv.createMatrix(pXte.getRow(), 1);
    identity.createMatrix(pXte.getCol() -1, pXte.getCol() -1 );
    for(int i = 0; i < pXte.getCol() - 1; i++)
        identity(i, i) = 1;

    for(int i = 0; i < classes; i++)
        tmpSig.push_back( sqrt(pSig[1](0, 0) ) * identity );
    getProb(pXte, prior, tmpSig, pMu, rv);
    cout << "PCA: \n";
    generateEvals(rv);


    tmpSig.clear();
    rv.createMatrix(fXte.getRow(), 1);
    identity.createMatrix(1, 1);
    identity(0, 0) = 1;
    for(int i = 0; i < classes; i++)
        tmpSig.push_back( sqrt( mtod(fSig[1]) ) * identity );
    getProb(fXte, prior, tmpSig, fMu, rv);
    cout << "FLD: \n";
    generateEvals(rv);

    cout << "\n\n\n\n\n";
}

void
Mat::runCase2(const double prior[])
{
    cout << "Case 2 Scores:\n";
    vector<Matrix> tmpSig;
    for(int i = 0; i < classes; i++)
        tmpSig.push_back(sig[0]);
    Matrix rv(nXte.getRow(), 1);
    getProb(nXte, prior, tmpSig, mu, rv);
    cout << "Normalized X: \n";
    generateEvals(rv); 
    tmpSig.clear();
    rv.createMatrix(pXte.getRow(), 1);

    for(int i = 0; i < classes; i++)
        tmpSig.push_back(pSig[0]);
    getProb(pXte, prior, tmpSig, pMu, rv);
    cout << "PCA: \n";
    generateEvals(rv);
    
    tmpSig.clear();
    rv.createMatrix(fXte.getRow(), 1);
    for(int i = 0; i < classes; i++)
        tmpSig.push_back( fSig[0] );
    getProb(fXte, prior, tmpSig, fMu, rv);
    cout << "FLD: \n";
    generateEvals(rv);
    cout << "\n\n\n\n\n";
}

void
Mat::runCase3(const double prior[])
{
    cout << "Case 3 Scores:\n";
    Matrix rv(nXte.getRow(), 1);
    getProb(nXte, prior, sig, mu, rv);
    cout << "Normalized X: \n";
    generateEvals(rv); 

    rv.createMatrix(pXte.getRow(), 1);
    getProb(pXte, prior, pSig, pMu, rv);
    cout << "PCA: \n";
    generateEvals(rv);
    
    rv.createMatrix(fXte.getRow(), 1);
    getProb(fXte, prior, fSig, fMu, rv);
    cout << "FLD: \n";
    generateEvals(rv);
    cout << "\n\n\n\n\n";
}

Matrix &
Mat::getProb(Matrix &testData, const double prior[], const vector<Matrix> & _sig,
                const vector<Matrix>& _mean, Matrix & result)
{
	int samples = testData.getRow(), choice;
	Matrix xVec(testData.getCol() - 1, 1), diff;
    double post, tmp;
	
    for(int i = 0; i < samples; i++)
    {
        post = tmp = 0;
        choice = -1;
        for(int j = 0; j < testData.getCol() - 1; j++)
		    xVec(j, 0) = testData(i, j);
        for(int j = 0; j < classes; j++)
        {
            diff = xVec - _mean[j];
            tmp = PI_CONST * 1 / sqrt(det(_sig[j])) * prior[j];
            tmp *= exp(- mtod(transpose(diff) ->* inverse(_sig[j]) ->* diff) / 2.0);
            if (tmp >= post) { post = tmp; choice = j; }
        }
        result(i, 0) = choice;
    }
    
    addLabels(result, Xte);
	return result;
}

ostream& 
operator<<(ostream &os, const Sample &s)
{
    for(int i = 0; i < s.sample.size(); i++)
        os << s.sample[i] << " ";
    os << endl;
    return os;
}
